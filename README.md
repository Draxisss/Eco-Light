# L'Éco'Light 

---

Ceci est ma participation pour le concours innovez, vous trouverez dans ce repository tous les fichiers et explications nécessaires pour comprendre, mettre en place et même juger mon travail si vous faites parti du jury. Voici **l'Éco'Light**.  
La section [Installation](#installation) explique comment mettre l'Éco'Light en place chez soi.

## Présentation 

Tout d'abord, l'Éco'Light est un interrupteur autonome et connecté. C'est à dire qu'il remplace un interrupteur classique en lieu et place et surtout dans sa fonction. Voici la ![visualisation 3d](asset/3d/eco light.stl)

### Contraintes:

- Limiter la possibilité d'allumer la lumière en fonction de la luminosité
- Pouvoir allumer sans utiliser un bouton physique
- Rendre le tout entièrement connecté et utilisable dans le monde **entier**
- Etre compatible au maximum

### Composants :

- Le microcontrôleur : un ESP32
- Un capteur à ultrasons : un HC-SR04
- Un relais 5V
- Un module photorésistance
- Un bouton poussoir
- Deux LED (rouge et jaune)

<img width="470" height="678" alt="elec" src="https://github.com/user-attachments/assets/1f3d5177-7f69-4bd5-826b-81290b48d1e3" />

---

## Fonctionnement

Il suffit d'installer correctement l'Éco'Light à la place de l'interrupteur et via l'application dédiée et ensuite son fonctionnement est très simple : pour changer l'état du plafonnier il faut passer devant le capteur à ultrasons, la distance dépend de ce que l'utilisateur a choisi.

<img width="541" height="705" alt="ultra" src="https://github.com/user-attachments/assets/aae689f7-9560-4988-8249-ddde4992ec51" />

En fonction de la luminosité de la pièce le module photorésistance bloque ou non l'allumage ou éteint la lumière si elle était allumée losrque la luminosité a augmenté. Si le module photorésistance est activé alors la LED rouge s'allume pour indiquer à l'utilisateur que le seuil qu'il a fixé est dépassé.

<img width="743" height="830" alt="lum" src="https://github.com/user-attachments/assets/9999c47e-7e47-40ac-bb48-6136d6e0c6d9" />

On régle ce capteur avec n'importe quel tournevis cruciforme au plat.


Pour garder la main sur le système le bouton poussoir permet une commande "manuelle", c'est à dire d'allumer ou d'éteindre dans n'importe quelles conditons de luminosité

<img width="656" height="724" alt="comp" src="https://github.com/user-attachments/assets/e58b56f7-f2a1-4203-ab57-8f4cd83140d5" />

### Connectivité 

Faisant partie des contraintes générales qu'en est il de ce paramètre ?
Et bien un site web permet un contrôle total sur le projet **mais pas seulement** on peut aussi avoir accés à d'autre mode de fonctionnement :
- Un mode réveil, qui allume le plafonier à l'heure choisi
- Un mode campbriolage, qui, si quelque chose passe devant le capteur à ultrasons, envoie une notification et fait clignoter la lumière rapidement
- Un mode plus "fun" que j'ai nommé : mode soirée, qui allume/éteint la lampe au bpm séléctionné

<img width="2134" height="2062" alt="image" src="https://github.com/user-attachments/assets/a9cb4254-d218-4248-b1a4-08ab72fd4eea" />



Cette présentation est **personnalisable bien sur** malgré le fait que ça aurait du être une application mais j'en reparlerai.

---

## Installation 




























