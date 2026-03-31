# L'Éco'Light 

---

Ceci est ma participation pour le concours Innovez, vous trouverez dans ce dépôt tous les fichiers et explications nécessaires pour comprendre, mettre en place et même juger mon travail si vous faites partie du jury. Voici **l'Éco'Light**.  

La section [montage](#montage) explique comment **vous** pouvez mettre l'Éco'Light chez vous.

## Présentation 

Tout d'abord, l'Éco'Light est un interrupteur autonome et connecté. C'est à dire qu'il remplace un interrupteur classique en lieu et place et surtout dans sa fonction. Pour rapidement voir à quoi il ressemble, il y a la [visualisation 3d](assets/3d/eco-light.stl) 

<img width="1639" height="736" alt="image" src="https://github.com/user-attachments/assets/0fdb776b-821f-4e8b-afd9-7866708bebb3" />

Lors de la conception d'Éco'Light, le point de départ était un constat simple : l'interrupteur classique fonctionne bien mais on peut faire **mieux** et quelques limites sont évidentes : le fait d'oublier la lumière allumée en plein jour, ne pas pouvoir allumer les mains prises, l'absence de contrôle à distance et aussi, depuis la crise du Covid-19 où la question de l'hygiène est devenue un sujet central, or l'interrupteur est l'un des objets les plus touchés des espaces partagés, il accumule et transfère donc les microbes. L'Éco'Light est ici une solution parfaite ! Je voulais concevoir l'interrupteur qui répond à tous ces critères mais aussi qui soit abordable, open-source et fiable, bref qui s'installe comme un interrupteur normal mais fait **bien plus**.

### Contraintes:

- Faire des économies (limiter la possibilité d'allumer la lumière en fonction de la luminosité)
- Pouvoir allumer sans utiliser un bouton physique
- Rendre le tout entièrement connecté et utilisable dans le monde **entier**
- Être compatible au maximum

### Composants, (voir en [détail](#detail-des-composants))

- Le microcontrôleur : un ESP32
- Un capteur à ultrasons : un HC-SR04
- Un relais 5V
- Un module photorésistance
- Un bouton poussoir
- Deux LED (rouge et jaune)

<p align="right">
  <img width="769" height="565" alt="image" src="https://github.com/user-attachments/assets/630c32ba-c99f-405a-9dac-332f9c92067e" />
</p>

---

## Fonctionnement

Il suffit d'installer correctement l'Éco'Light à la place de l'interrupteur et via l'application dédiée et ensuite son fonctionnement est très simple : pour changer l'état du plafonnier il faut passer devant le capteur à ultrasons, la distance dépend de ce que l'utilisateur a choisi.

<img width="541" height="705" alt="ultra" src="https://github.com/user-attachments/assets/aae689f7-9560-4988-8249-ddde4992ec51" />

En fonction de la luminosité de la pièce le module photorésistance bloque ou non l'allumage ou éteint la lumière si elle était allumée lorsque la luminosité a augmenté. Si le module photorésistance est activé alors la LED rouge s'allume pour indiquer à l'utilisateur que le seuil qu'il a fixé est dépassé.

<img width="743" height="830" alt="lum" src="https://github.com/user-attachments/assets/9999c47e-7e47-40ac-bb48-6136d6e0c6d9" />

On règle ce capteur avec n'importe quel tournevis cruciforme ou plat.


Pour garder la main sur le système le bouton poussoir permet une commande "manuelle", c'est à dire d'allumer ou d'éteindre dans n'importe quelles conditons de luminosité

<img width="656" height="724" alt="comp" src="https://github.com/user-attachments/assets/e58b56f7-f2a1-4203-ab57-8f4cd83140d5" />

### Connectivité 

Faisant partie des contraintes générales qu'en est-il de ce paramètre ?
Et bien un site web permet de surveiller tous les paramètres mais aussi un contrôle total sur le projet **mais pas seulement** on peut aussi avoir accès à d'autre mode de fonctionnement :
- Un mode réveil, qui allume le plafonnier à l'heure choisi
- Un mode cambriolage, qui, si quelque chose passe devant le capteur à ultrasons, envoie une notification et fait clignoter la lumière rapidement
- Un mode plus "fun" que j'ai nommé : mode soirée, qui allume/éteint la lampe au bpm sélectionné

<img width="2134" height="2062" alt="image" src="https://github.com/user-attachments/assets/a9cb4254-d218-4248-b1a4-08ab72fd4eea" />



Cette présentation est **personnalisable bien sûr** malgré le fait que ça aurait dû être une application mais j'en reparlerai...

---

### Wiring Diagram 

<img width="1490" height="1100" alt="image" src="https://github.com/user-attachments/assets/1e379b79-7322-4989-b055-e740ff069586" />

---
## Composants

| Composant                         | Quantité |  Prix (EUR) | Lien                                                  |
|-----------------------------------|----------|-------------|-------------------------------------------------------|
| Capteur à Ultrasons (HC-SR04)     | 1        | 1.40        | https://fr.aliexpress.com/item/1005006039388853.html  |
| Module photorésistance            | 1        | 0.94        | https://fr.aliexpress.com/item/1005007038160433.html  |
| Microcontrôleur (ESP32)          | 1        | 4.39        | https://fr.aliexpress.com/item/1005008889768599.html   |
| Relais                            | 1        | 1.47        | https://fr.aliexpress.com/item/1005007109343076.html  |
| Bouton poussoir                   | 1 (20)   | 1.31        | https://fr.aliexpress.com/item/4001278311660.html     |
| LED                               | 2 (60)   | 2.89        | https://fr.aliexpress.com/item/1005008554748230.html  |
| Interrupteur                      | 1 (10)   | 1.69        | https://fr.aliexpress.com/item/1005007498633815.html  |
| Phase et masse commune            | 2 (20)   | 1.89        | https://fr.aliexpress.com/item/4000873858801.html     |
| Fils de branchements 10cm et 30cm | 40       | 6 en tout   | https://fr.aliexpress.com/item/1005002000655439.html  |
| Convertisseur 220v AC vers 5v DC  | 1        | 1.35        | https://fr.aliexpress.com/item/1005001970797548.html  |
| Fils électrique 220v              | 1        | 3.59        | https://fr.aliexpress.com/item/1005010779278423.html  |
| Connecteur Wago                   | 3        | 1.73        | https://fr.aliexpress.com/item/1005006963063019.html  |
| Vis (M4x30, Countersunk head)     | 2 (10)   | 3.09        | https://fr.aliexpress.com/item/1005007129209802.html  |
| Écrou                             | 2 (50)   | 2.44        | https://fr.aliexpress.com/item/1005010329406193.html  |  
| Résistances                        | 2 (20)   | 0.99        | https://fr.aliexpress.com/item/1005006424279944.html |
| Total                             |          | 35          | C'est seulement si vous achetez toutes les pièces, on peut faire de la récup sur certain composants  |

Pour ma part j'ai réutilisé le convertisseur 220V AC vers 5V DC d'un chargeur, le bouton poussoir d'un petit appareil, les leds d'un jouet pour bébé, les résistances d'un autre projet et les fils d'un starter pack arduino.


**PS :** Les quantités entre parenthèses sont les quantités minimum disponible pour ce produit. Vous pouvez très bien adapter du matériel que vous avez déjà j'ai simplement mis tout les éléments nécessaires a la conception de l'Éco'Light. Les liens proviennent tous d'aliexpress (plus simple pour l'électronique donc j'ai continué sur ma lancée) mais leur validité n'est pas certaine.
 
### Pour les retrouver vous même : 

- Capteur à Ultrasons : HC-SR04
- Module photorésistance : LDR, module photorésistance, sortie digitale
- Microcontrôleur : ESP32, module devkit, Wi-Fi/Bluetooth
- Relais : module relais, 5 V, 1 canal
- Bouton poussoir : bouton poussoir, 8-10mm, bistable/à verrouillage
- LED : LED 5 mm
- Interrupteur :  2.3 x 0.75 x 1.7cm environ
- Phase et masse commune : Board Pin Header que vous soudez ensemble
- Fils de branchements 10 cm et 30 cm : femelle/femelle
- Convertisseur 220 V → 5 V : module AC-DC, 5w
- Fils électrique 220 V : awg14-15
- Connecteur Wago triple
- Vis : M4x30, tête fraisée
- Écrou : écrou M4, 2-2.5mm d'épaisseur
- Résistance : 150-220Ω

## Montage
Matériel nécessaire : 
- tous les composants
- un tournevis cruciforme
- un fer à souder (aucune soudure n'est difficile)
- un pistolet à colle
- une pince ou quelque chose de similaire et une clé Allen pour les vis du bras
- et un peu d'huile de coude

Une fois toutes les pièces réunies, vous pouvez commencer à construire **votre** Éco'Light ! 


Il vous faudra imprimer en 3d le fichier [suivant](assets/3d/eco-light.stl). **Attention** ne surtout pas imprimer les deux corps, c'est seulement pour choisir entre un interrupteur à gauche ou à droite. De même avec les "bras" pour le capteur à ultrasons, imprimez en un seul j'ai modélisé 3 tailles : 8, 10 et 12cm.

Il faut ensuite récupérer le [code](assets/code/code_esp32.ino) pour l'ESP32 et le flasher sur votre microcontrôleur via Arduino IDE (un logiciel de programmation pour tout ces petits microcontrôleur)

Réalisez le montage ci-dessous soit directement dans le boîter fraichement imprimé si vous êtes confiant soit sur une breadboard pour être sûr : 

| Nom                     | Pin | "Complément"                     |
|-------------------------|-----|---------------------------------|
| Trig                    | 19  | Vcc + Gnd (capteur à ultrasons) |
| Echo                    | 18  | "        "                      |
| Led jaune               | 33  | Gnd                             |
| Led rouge               | 26  | Gnd                             |
| Relai                   | 23  | Vcc + Gnd                       |
| Photorésistance         | 27  | Vcc + Gnd                       |
| Bouton poussoir         | 5   | Gnd                             |
| Plus généralement : VCC | 5V  |                                 |
| GND                     | Gnd |                                 |
|                         |     |                                 |

Pour les leds, pensez bien à rajouter une résistance, sinon vous risquez de la griller.

Malheureusement n'ayant aucune connaissance en PCB je n'ai pas pu en faire une mais si ce projet marche je promet qu'elle sortira et alors on gagnera en taille de boitier et en facilité de montage.

Une fois que vous êtes sur du bon fonctionnement du projet alors vous pouvez passez au collage où le but va être de tout faire rentrer dans cette petite boîte. La mission peut être un peu technique mais devrait finir par ressembler à ça :

<img width="470" height="678" alt="elec" src="https://github.com/user-attachments/assets/1f3d5177-7f69-4bd5-826b-81290b48d1e3" />

À partir de là vous pouvez passer à la catégorie **installation** pour fixer et démarrer l'Éco'Light.

---
## Installation 

Très simplement vous allez le fixer à la place de l'interrupteur : l'Éco'Light respecte les dimensions standards, entraxe des vis de fixations de 60 mm (boite Ø67 mm).
Il n'y a que le câblage qui change puisqu'il faut alimenter le microcontrôleur en électricité. Rassurez-vous le travail à faire est minime : 

<img width="2251" height="1388" alt="image" src="https://github.com/user-attachments/assets/b1d9b910-2669-4536-8e72-22a44d03b7a2" />

On a donc ça du côté du boitier :

<img width="1485" height="1530" alt="image" src="https://github.com/user-attachments/assets/c346b55f-e590-4655-8d19-e3fcbc88a3ad" />

Si on représente tout schématiquement pour mieux comprendre la situation et éclaircir un petit peu les choses 

<img width="2828" height="953" alt="image" src="https://github.com/user-attachments/assets/890b4bcf-326f-40d2-b619-fdd49d725e37" />

 Aucune compétence en électricité n'est nécessaire même votre grand-mère pourrait le faire c'est dire ! (ps: je doute que beaucoup de grand-mères utilisent Github).
 Bref plutôt dire qu'il ne faut pas du tout s'inquiéter sur ce point.

 
 Ensuite vous vissez le tout (2 vis) et il n'y a plus qu'à allumer la machine via l'interrupteur latéral !

 
 Pour ensuite, magie, vous connecter à l'ESP32 avec votre téléphone pour finaliser la mise en place. Le but de cette application est d'informer le microcontrôleur de vos préférences (mdp wifi, distance détection...), il suffit de suivre ces étapes :

 <img width="1657" height="1478" alt="image" src="https://github.com/user-attachments/assets/862b827e-1409-442d-a580-c53dcf6f791f" />

 (à chaque fois il y aura la fenêtre d'erreur associée à l'étape correspondante)

 Page d'accueil donc, avant il faut appairer l'ESP32 avec votre téléphone (Paramètres → Connexions → Bluetooth → Sélectionner appareil (Éco'Light) → Appairer), après cette étape de complété et un temps de chargement plus ou moins long :
 
<img width="183" height="348" alt="image" src="https://github.com/user-attachments/assets/4c0207fe-4532-4985-85c6-78a841acc5b5" />
(Le bouton Reset sert si vous avez un problème durant le processus (freeze, erreur...), il redémarre l'ESP32 et vous renvoie à la page d'accueil)


 Vous arrivez sur :

 <img width="2159" height="1246" alt="image" src="https://github.com/user-attachments/assets/de1a1f6e-bfc3-435d-b1e1-4489f9e22163" />

Il faut donc choisir son réseau wifi et indiquer le mot de passe pour que l'ESP32 ait accès à internet


Pour ensuite choisir la distance de détection du capteur à ultrasons (votre choix dépendra de l'emplacement de votre interrupteur, de la position de votre capteur mais surtout si vous voulez qu'il vous détecte quand vous passez vou ou votre main. Par exemple je l'ai réglé moi pour que, quand je circule, le capteur ne détecte rien mais quand je me rapproche ou passe ma main devant il allume la lumière. C'est plus agréable je trouve surtout si vous vivez à plus, qu'il y a des va et vient dans la pièce concernée car on  peut quand même allumer la lumière les bras chargés). 

<img width="1383" height="1229" alt="image" src="https://github.com/user-attachments/assets/a3a22c9a-99ec-4529-913c-62465add9e92" />

(Ps : moi comme référence je l'ai donc réglé à 13cm avec un interrupteur plutôt proche du cadre de porte)


Vient ensuite la partie "API", créez un compte sur [Adafruit](https://io.adafruit.com) et rentrez vos informations (le nom d'utilisateur et la clé API peuvent être trouvés en cliquant sur l'icone de clé en haut à droite) et vous les rentrez ensuite ci-dessous :

<img width="2808" height="1619" alt="image" src="https://github.com/user-attachments/assets/6e652bd1-ef96-45c9-a380-cdfb5422da59" />

Il faudra ensuite respecter le tableau suivant lors de la création des feeds et du dashboard sur le site d'adafruit où vous irez ensuite après la mise en place de l'Écolight (à vous de personnaliser votre expérience).

| Fonction                        | Nom du feed  | Objet associé sur le dashboard             |
|---------------------------------|--------------|--------------------------------------------|
| Gérer l'allumage                | lampe        | Toggle                                     |
| Gérer le mode cambiolage        | cambriolage  | Toggle                                     |
| Gérer le message d'alerte       | notif        | Text (Show icon avec exclamation-triangle) |
| Gérer le mode réveil            | reveil       | Toggle                                     |
| Gérer l'heure du réveil         | reveil heure | Text                                       |
| Gérer le mode "soirée"          | soiree       | Toggle                                     |
| Gérer les bpm du mode "soirée"  | soiree bpm   | Text                                       |

Pour rentrer l'heure pour le réveil dans le bloc texte le format attrendu est le suivant : XX:XX (Ex: 7:15, 12:25, 22:55)

<img width="873" height="1211" alt="image" src="https://github.com/user-attachments/assets/fe43f993-40d4-485e-b076-43699543256a" />

Si tout s'est bien passé alors cette page apparait et vous êtes prêt à utiliser l'Éco'Light pour la première fois !
Maintenant que vous êtes sûr du bon fonctionnement du projet vous pouvez alors coller le couvercle et profiter pleinement de votre Éco'Light à la maison.


Si jamais un problème arrive ou vous voulez changer de taille de bras et aussi de distance de détection : relancez l'application et coupez et rallumez l'ESP32

---

Je voulais juste faire un point sur l'interface utilisateur, je trouve le dashboard adafruit très limitant et j'avais à la base créé une application beaucoup plus agréable que je veux quand même partager malgré le fait que l'API d'adafruit ne m'a pas permis de trouver une solution

<img width="2561" height="1208" alt="image" src="https://github.com/user-attachments/assets/42f5c4f8-0a02-4c72-a8df-f74e77b99a14" />

Donc voilà quelque chose de beaucoup plus attrayant mais que je n'ai pu finaliser malgré des heures de travail...


---

# Conclusion

Je me suis régalé pendant toute la conception, la création, le travail de recherche, la mise en forme ou encore les soirée passées à retourner dans tous les sens un problème que je n'arrivais pas à résoudre sur ce projet pour enfin aboutir. Je suis tellement heureux de pouvoir arriver le soir chez et de n'avoir plus, dans un coin de ma tête, une petite voix me disant de toujours peaufiner un détail que personne ne verra... Mais finalement en plus de l'aboutissement ça ne serait pas toutes les galères rencontrées qui compteraient le plus non ?

J'ai bien sur quelques idées d'amélioration en tête et je serais ravi de vous les partager. En tout cas j'espère (si vous êtes arrivé jusque là) que ce projet vous a plu et j'espère surtout vous avoir convaincu !

Voici la video du projet : 
























