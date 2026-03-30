#include <WiFi.h> 
#include "WiFiClientSecure.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "time.h"
#include "BluetoothSerial.h"
#include "Ultrasonic.h"

BluetoothSerial SerialBT;

/************************* Adafruit.io Setup *********************************/

#define AIO_SERVER "io.adafruit.com"

// Using port 1883 for MQTT
#define AIO_SERVERPORT 1883


/************ Global State (you don't need to change this!) ******************/

// WiFiFlientSecure for SSL/TLS support
WiFiClient client;

// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details.
char pseudo[50];
char key[50];
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, pseudo, key);

/****************************** Feeds ***************************************/
char path_lampe[60], path_cambriolage[60], path_soiree[60], path_bande_led[60], path_reveil_heure[60], path_soiree_bpm[60], path_notif[60], path_reveil[60];

// 2. On lie les objets MQTT à ces buffers
Adafruit_MQTT_Subscribe lampeSub = Adafruit_MQTT_Subscribe(&mqtt, path_lampe);
Adafruit_MQTT_Publish lampePub = Adafruit_MQTT_Publish(&mqtt, path_lampe);

Adafruit_MQTT_Subscribe cambriolageSub = Adafruit_MQTT_Subscribe(&mqtt, path_cambriolage);
Adafruit_MQTT_Publish cambriolagePub = Adafruit_MQTT_Publish(&mqtt, path_cambriolage);

Adafruit_MQTT_Subscribe soireeSub = Adafruit_MQTT_Subscribe(&mqtt, path_soiree);
Adafruit_MQTT_Publish soireePub = Adafruit_MQTT_Publish(&mqtt, path_soiree);

Adafruit_MQTT_Subscribe bande_ledSub = Adafruit_MQTT_Subscribe(&mqtt, path_bande_led);
Adafruit_MQTT_Publish bande_ledPub = Adafruit_MQTT_Publish(&mqtt, path_bande_led);

Adafruit_MQTT_Subscribe reveil_heureSub = Adafruit_MQTT_Subscribe(&mqtt, path_reveil_heure);
Adafruit_MQTT_Publish reveil_heurePub = Adafruit_MQTT_Publish(&mqtt, path_reveil_heure);

Adafruit_MQTT_Subscribe soiree_bpmSub = Adafruit_MQTT_Subscribe(&mqtt, path_soiree_bpm);
Adafruit_MQTT_Publish soiree_bpmPub = Adafruit_MQTT_Publish(&mqtt, path_soiree_bpm);

Adafruit_MQTT_Subscribe notifSub = Adafruit_MQTT_Subscribe(&mqtt, path_notif);
Adafruit_MQTT_Publish notifPub = Adafruit_MQTT_Publish(&mqtt, path_notif);

Adafruit_MQTT_Subscribe reveilSub = Adafruit_MQTT_Subscribe(&mqtt, path_reveil);
Adafruit_MQTT_Publish reveilPub = Adafruit_MQTT_Publish(&mqtt, path_reveil);

/*************************** Sketch Code ************************************/
bool initialisation1 = false;
bool initialisation2 = false;

// set pin numbers and variable
Ultrasonic ultrasonic1(19, 18); // Trig = 19, Echo = 18
int pin_led = 33;
int pin_bouton = 5;
int pin_led2 = 26;
int pin_relay = 23;
int pin_luminosity = 27;
bool bouton_appuye_previous = false;

int distance_detection_ultrasonic = 30;
bool etat_lumiere = false;
bool etat_capteur_ultrason = false;
bool interLum = false;
bool interBut = false;
bool varLum = false;
unsigned long lastMqttPing = 0;

const char* etat_lumiere_str_previous = "";
const char* reveil_str_previous = "";
const char* cambriolage_str_previous = "";
const char* soiree_str_previous = "";
const char* bande_led_str_previous = "";


bool cambriolage = false;
int delay_cambriolage = 500;
unsigned long previous_delay = 0;
bool cambriolageDetect = false;
bool cambriolage_previous = true;
bool notif_state = false;
bool notif_state_previous = false;

bool soiree = false;

bool bande_led = false;

bool reveil = false;
bool reveilLum = false;
int reveil_minute = 0;
int reveil_heure = 0;
const char* timezone = "CET-1CEST,M3.5.0/2,M10.5.0/3"; 
// - CET = heure standard française (UTC+1)
// - CEST = heure d'été française (UTC+2)
// - M3.5.0/2 = passage heure d'été dernier dimanche de mars à 2h
// - M10.5.0/3 = retour à l'heure d'hiver dernier dimanche d'octobre à 3h
const char* ntpServer = "fr.pool.ntp.org";

int soiree_bpm = 100;
int delay_bpm = 60000/soiree_bpm;
unsigned long previous_delay_bpm = 0;

char notif[64] = "";

bool delai = false;


void lampeCallback(char* message, uint16_t len) {
  char messageBuffer[40];
  snprintf(messageBuffer, sizeof(messageBuffer), "lampe status is :: %s, len :: %u", message, len);
  Serial.println(messageBuffer);
  if (strcmp(message, "ON") == 0) {
    Serial.println("Turning ON lampe");
    digitalWrite(pin_relay, LOW);
    Serial.println("relay on");
    etat_lumiere = true;
  } else {
    Serial.println("Turning OFF lampe");
    digitalWrite(pin_relay, HIGH);
    Serial.println("relay off");
    etat_lumiere = false;
  }
}

void cambriolageCallback(char* message, uint16_t len) {
  char messageBuffer[40];
  snprintf(messageBuffer, sizeof(messageBuffer), "cambriolage status is :: %s, len :: %u", message, len);
  Serial.println(messageBuffer);
  if (strcmp(message, "ON") == 0) {
    cambriolage = true;
  } else {
    cambriolage = false;
  }
}

void soireeCallback(char* message, uint16_t len) {
  char messageBuffer[40];
  snprintf(messageBuffer, sizeof(messageBuffer), "soiree status is :: %s, len :: %u", message, len);
  Serial.println(messageBuffer);
  if (strcmp(message, "ON") == 0) {
    soiree = true;
  } else {
    soiree = false;
  }
}

void bandeLedCallback(char* message, uint16_t len) {
  char messageBuffer[40];
  snprintf(messageBuffer, sizeof(messageBuffer), "bande led status is :: %s, len :: %u", message, len);
  Serial.println(messageBuffer);
  if (strcmp(message, "ON") == 0) {
    bande_led = true;
  } else {
    bande_led = false;
  }
}

void reveilHeureCallback(char* message, uint16_t len) {
  char messageBuffer[40];
  snprintf(messageBuffer, sizeof(messageBuffer), "reveil heure status is :: %s, len :: %u", message, len);
  Serial.println(messageBuffer);

  sscanf(message, "%d:%d", &reveil_heure, &reveil_minute);
  Serial.print(reveil_heure);
  Serial.print(":");
  Serial.println(reveil_minute);

}

void soireeBpmCallback(char* message, uint16_t len) {
  char messageBuffer[40];
  snprintf(messageBuffer, sizeof(messageBuffer), "soiree bpm status is :: %s, len :: %u", message, len);
  Serial.println(messageBuffer);
  soiree_bpm = atoi(message);
  Serial.println(soiree_bpm);
}

void notifCallback(char* message, uint16_t len) {
  char messageBuffer[64];
  snprintf(messageBuffer, sizeof(messageBuffer), "notif status is :: %s, len :: %u", message, len);
  Serial.println(messageBuffer);


}

void reveilCallback(char* message, uint16_t len) {
  char messageBuffer[64];
  snprintf(messageBuffer, sizeof(messageBuffer), "reveil status is :: %s, len :: %u", message, len);
  Serial.println(messageBuffer);
  if (strcmp(message, "ON") == 0) {
    reveil = true;
  } else {
    reveil = false;
  }

}

void indicatorPublish() {

  const char* etat_lumiere_str = etat_lumiere ? "ON" : "OFF";
  if (strcmp(etat_lumiere_str_previous, etat_lumiere_str) != 0) {
    lampePub.publish(etat_lumiere_str);
    etat_lumiere_str_previous = etat_lumiere_str;
  }

  const char* reveil_str = reveil ? "ON" : "OFF";
  if (strcmp(reveil_str_previous, reveil_str) != 0) {
    reveilPub.publish(reveil_str);
    reveil_str_previous = reveil_str;
  }

  const char* cambriolage_str = cambriolage ? "ON" : "OFF";
  if (strcmp(cambriolage_str_previous, cambriolage_str) != 0) {
    cambriolagePub.publish(cambriolage_str);
    cambriolage_str_previous = cambriolage_str;
  }

  const char* soiree_str = soiree ? "ON" : "OFF";
  if (strcmp(soiree_str_previous, soiree_str) != 0) {
    soireePub.publish(soiree_str);
    soiree_str_previous = soiree_str;
  }

  const char* bande_led_str = bande_led ? "ON" : "OFF";
  if (strcmp(bande_led_str_previous, bande_led_str) != 0) {
    bande_ledPub.publish(bande_led_str);
    bande_led_str_previous = bande_led_str;
  }

}

// Function to connect and reconnect as necessary to the MQTT server.
// Should be called in the loop function and it will take care if connecting.
void MQTT_connect() {
  int8_t ret;
  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }
  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 20;
  while ((ret = mqtt.connect()) != 0) {  // connect will return 0 for connected
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(2000);  // wait 2 seconds
    retries--;
    if (retries == 0) {
      SerialBT.print("XJ");
      esp_restart();
    }
  }
  Serial.println("MQTT Connected!");
}


void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(pin_led, OUTPUT); 
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_relay, OUTPUT);
  pinMode(pin_luminosity, INPUT);
  pinMode(pin_bouton, INPUT_PULLUP); //assignation des modes aux pins

  Serial.println(F("Concours Innovez version finale"));

  // Connect to WiFi access point.
  SerialBT.begin("Eco'light");  // Nom visible en Bluetooth
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println(); 

  // Set Adafruit IO's root CA
  //client.setCACert(adafruitio_root_ca);

  // Attacher les fonctions de callback
  lampeSub.setCallback(lampeCallback);
  cambriolageSub.setCallback(cambriolageCallback);
  soireeSub.setCallback(soireeCallback);
  bande_ledSub.setCallback(bandeLedCallback);
  reveil_heureSub.setCallback(reveilHeureCallback);
  soiree_bpmSub.setCallback(soireeBpmCallback);
  notifSub.setCallback(notifCallback);
  reveilSub.setCallback(reveilCallback);

}

// uint32_t x=0;


void loop() {
  if (SerialBT.hasClient()) {
    if (!initialisation1) {
      Serial.println("Scan start");
      // WiFi.scanNetworks will return the number of networks found.
      int n = WiFi.scanNetworks();
      Serial.println("Scan done");
      delay(1000);
      for (int i = 0; i < n; ++i) {
        String ssid = WiFi.SSID(i);
        int len = ssid.length();

        // Convertir la longueur en chaîne de 2 chiffres
        if (len < 10) {
          SerialBT.print("0");  // Ajouter un 0 devant
        }
        SerialBT.print(len);     // Envoyer la longueur (ex : "05")
        Serial.println(len);
        delay(500);
        SerialBT.print(ssid);    // Envoyer le SSID brut
        Serial.println(ssid);
        delay(500);
        Serial.println(i);
      }
      SerialBT.print("EN");
      Serial.println("EN");
      WiFi.scanDelete();
      initialisation1 = true;
      }
    }
    
      
    if (SerialBT.available()) {
      if (!initialisation2) {

        String ssid = SerialBT.readStringUntil('\n');
        ssid.trim();  // Supprime les espaces ou retours à la ligne
        // Vérifie si le premier caractère est '/'
        if (ssid.length() > 0 && ssid.charAt(0) == '/') {
        ssid.remove(0, 1); // Supprime le premier caractère
        }

        Serial.println();
        Serial.print("Connecting to ");
        Serial.println(ssid);

        // Attendre que le mot de passe arrive
        while (!SerialBT.available()) {
          delay(10);
        }
        String password = SerialBT.readStringUntil('\n');
        password.trim();

        Serial.print("Password: ");
        Serial.println(password);

        // Connexion WiFi
        WiFi.begin(ssid.c_str(), password.c_str());

        int attempts = 0;
        while (WiFi.status() != WL_CONNECTED && attempts < 20) {
          delay(500);
          Serial.print(".");
          attempts++;
        }

        if (WiFi.status() == WL_CONNECTED) {
          configTzTime(timezone, ntpServer); // configurer l'heure 
          Serial.println("WiFi connected");
          Serial.println("IP address: ");
          Serial.println(WiFi.localIP()); 
          SerialBT.print("AB");  // Confirmer à App Inventor
          digitalWrite(pin_led2, HIGH);
          digitalWrite(pin_led, HIGH);
          delay(1000);
          digitalWrite(pin_led2, LOW);
          digitalWrite(pin_led, LOW);
          delay(500);
          digitalWrite(pin_led2, HIGH);
          digitalWrite(pin_led, HIGH);
          delay(1000);
          digitalWrite(pin_led2, LOW);
          digitalWrite(pin_led, LOW);
          delay(500);
        } else {
          Serial.println("\nÉchec de connexion WiFi.");
          SerialBT.print("XI");
        }

        while (!SerialBT.available()) {
          delay(10);
        }
        String pseudostr = SerialBT.readStringUntil('\n');
        pseudostr.trim();
        pseudostr.toCharArray(pseudo, sizeof(pseudo));

        snprintf(path_lampe, sizeof(path_lampe), "%s/feeds/lampe", pseudo);
        snprintf(path_cambriolage, sizeof(path_cambriolage), "%s/feeds/cambriolage", pseudo);
        snprintf(path_soiree, sizeof(path_soiree), "%s/feeds/soiree", pseudo);
        snprintf(path_bande_led, sizeof(path_bande_led), "%s/feeds/bande-led", pseudo);
        snprintf(path_reveil_heure, sizeof(path_reveil_heure), "%s/feeds/reveil-heure", pseudo);
        snprintf(path_soiree_bpm, sizeof(path_soiree_bpm), "%s/feeds/soiree-bpm", pseudo);
        snprintf(path_notif, sizeof(path_notif), "%s/feeds/notif", pseudo);
        snprintf(path_reveil, sizeof(path_reveil), "%s/feeds/reveil", pseudo);

        // S'abonner à chaque feed
        mqtt.subscribe(&lampeSub);
        mqtt.subscribe(&cambriolageSub);
        mqtt.subscribe(&soireeSub);
        mqtt.subscribe(&bande_ledSub);
        mqtt.subscribe(&reveil_heureSub);
        mqtt.subscribe(&soiree_bpmSub);
        mqtt.subscribe(&notifSub);
        mqtt.subscribe(&reveilSub);

        while (!SerialBT.available()) {
          delay(10);
        }
        String keystr = SerialBT.readStringUntil('\n');
        keystr.trim();  
        keystr.toCharArray(key, sizeof(key));

        MQTT_connect();

        if (mqtt.connected()) {
          Serial.println("Adafruit connecté");
          Serial.printf("Pseudo: %s | Key: %s\n", pseudo, key);
          SerialBT.print("AC");  // Confirmer à App Inventor
          digitalWrite(pin_led2, HIGH);
          digitalWrite(pin_led, LOW);
          delay(1000);
          digitalWrite(pin_led2, LOW);
          digitalWrite(pin_led, HIGH);
          delay(500);
          digitalWrite(pin_led2, HIGH);
          digitalWrite(pin_led, LOW);
          delay(1000);
          digitalWrite(pin_led2, LOW);
          digitalWrite(pin_led, HIGH);
          delay(1000);
          digitalWrite(pin_led2, LOW);
          digitalWrite(pin_led, LOW);
          delay(500);
        } else {
          Serial.println("\nÉchec de connexion MQTT");
          SerialBT.print("XJ");
        }       

        while (!SerialBT.available()) {
          delay(10);
        }
        String ultra = SerialBT.readStringUntil('\n');
        ultra.trim(); 
        distance_detection_ultrasonic = ultra.toInt(); 

        initialisation2 = true;
      }
    }
  
  if (SerialBT.hasClient()) {
    if (SerialBT.available()) {
      if (SerialBT.read() == 'a') {
        ESP.restart();
      }
    }
  }
  if (initialisation2)  {
    //delay(3000);
    // Ensure the connection to the MQTT server is alive (this will make the first
    // connection and automatically reconnect when disconnected).  See the MQTT_connect
    // function definition further below.
    if (WiFi.status() == WL_CONNECTED) {
      MQTT_connect();
      mqtt.processPackets(50);
    } else {
      Serial.println("WiFi non connecté, MQTT ignoré");
    }

    indicatorPublish();

    if (millis() - lastMqttPing >= 10000) {
      lastMqttPing = millis();
      mqtt.ping();
    }

    // wait a couple seconds to avoid rate limit
    //delay(2000);


    // put your main code here, to run repeatedly:
    delai = false;
    int mesure_ultrasons = ultrasonic1.Ranging(CM);
    bool bouton_appuye = digitalRead(pin_bouton) == LOW; 
    bool luminosite_importante = digitalRead(pin_luminosity) == LOW;

    if (bouton_appuye) {
      interBut = true;
      Serial.println("le bouton est appuyé");
      digitalWrite(pin_led, HIGH);
      if (bouton_appuye != bouton_appuye_previous) {
        bouton_appuye_previous = bouton_appuye;
        delay(250);
      }
    }
    
    if (!bouton_appuye) {
      Serial.println("le bouton est relaché");
      digitalWrite(pin_led, LOW);
      interBut = false;
      if (bouton_appuye == bouton_appuye_previous) {
        bouton_appuye_previous = !bouton_appuye;
        delay(250);
      }
    }  
    
    if (!luminosite_importante) {
      interLum = true;
      digitalWrite(pin_led2, LOW);
    }

    if (luminosite_importante) {
      digitalWrite(pin_led2, HIGH);
      digitalWrite(pin_relay, HIGH);
      Serial.println("la lumiere est trop importante");
      if (!bouton_appuye) {
        etat_lumiere = false;
      }
      interLum = false;

    }
    
    if ((interLum || interBut)&& !soiree) {

      if (mesure_ultrasons < distance_detection_ultrasonic && !cambriolage) {
        etat_capteur_ultrason = true;
      } else if (etat_capteur_ultrason && mesure_ultrasons > distance_detection_ultrasonic) {       //boucle if pour recreer bouton poussoir avec le capteur ultrasons (etat_lumière passe de true a false)
        etat_capteur_ultrason = false;
        etat_lumiere = !etat_lumiere; 
        delai = true;
      }
    }

    if (etat_lumiere) {               //boucle qui gere l'allumage et l'exctinction de la lumière
      digitalWrite(pin_relay, LOW);
      Serial.println("relay on");
    } else {
      digitalWrite(pin_relay, HIGH);
      Serial.println("relay off");
    }

    //********************partie avec les variables de l'application*************************************//

    if (cambriolage) {

      if (mesure_ultrasons < 100) {
        cambriolageDetect = true;
      }

      if (cambriolageDetect) {
        notif_state = true;
        if (millis() - previous_delay > delay_cambriolage) {
          previous_delay = millis();
          digitalWrite(pin_relay, varLum ? HIGH : LOW);
          varLum = !varLum;
        }
      }

      if (notif_state && notif_state != notif_state_previous) {
        notifPub.publish("Attention quelqu'un est passé devant le capteur ultrason");
        notif_state_previous = notif_state;
      }

      cambriolage_previous = true;

    }else{
      notif_state = false;
      cambriolageDetect = false;
      varLum = false;
      notif_state_previous = false;
      if (cambriolage != cambriolage_previous) {
        notifPub.publish("Aucune alerte       ");
        cambriolage_previous = cambriolage;
      }     
    }

    if (bande_led){
    }else{
    }

    int delay_bpm = 60000/soiree_bpm; 

    if (soiree){
      if (millis() - previous_delay_bpm > delay_bpm) {
        previous_delay_bpm = millis();
        digitalWrite(pin_relay, varLum ? HIGH : LOW);
        varLum = !varLum;
      }
    }else{
      varLum = false;
    }

    if (reveil) {
      struct tm timeinfo;
      if (getLocalTime(&timeinfo, 200)) {
        Serial.printf("Date : %02d/%02d/%04d  Heure : %02d:%02d:%02d\n", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900, timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
        if (!reveilLum && timeinfo.tm_hour == reveil_heure && timeinfo.tm_min == reveil_minute) { 
          reveilLum = true;
          digitalWrite(pin_relay, HIGH);
          etat_lumiere = true;
          lampePub.publish("ON");
          Serial.println("relay on par reveil");
        }    
      } else {
        Serial.println("Impossible d'obtenir l'heure via NTP1");
      }
    }else{
      reveilLum = false;
    }
    
    struct tm timeinfo_reset;
    if (getLocalTime(&timeinfo_reset, 200)) {
      if (timeinfo_reset.tm_hour == 0 && timeinfo_reset.tm_min == 0) {
        reveilLum = false;
      }    
    } else {
      Serial.println("Impossible d'obtenir l'heure via NTP2");
    }
  }
}     
    
  
