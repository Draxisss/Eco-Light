# L'Éco'Light 

---

Ceci est ma participation pour le concours innovez, vous trouverez dans ce repository tous les fichiers et explications nécessaires pour comprendre, mettre en place et même juger mon travail si vous faites parti du jury. Voici **l'Éco'Light**.  

La section [montage](#montage) explique comment **vous** pouvez mettre l'Éco'Light chez vous.

## Présentation 

Tout d'abord, l'Éco'Light est un interrupteur autonome et connecté. C'est à dire qu'il remplace un interrupteur classique en lieu et place et surtout dans sa fonction. Voici la [visualisation 3d](assets/3d/eco-light.stl) 

### Contraintes:

- Faire des économies (limiter la possibilité d'allumer la lumière en fonction de la luminosité)
- Pouvoir allumer sans utiliser un bouton physique
- Rendre le tout entièrement connecté et utilisable dans le monde **entier**
- Etre compatible au maximum

### Composants, (voir en [détail](#detail-des-composants))

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

On régle ce capteur avec n'importe quel tournevis cruciforme ou plat.


Pour garder la main sur le système le bouton poussoir permet une commande "manuelle", c'est à dire d'allumer ou d'éteindre dans n'importe quelles conditons de luminosité

<img width="656" height="724" alt="comp" src="https://github.com/user-attachments/assets/e58b56f7-f2a1-4203-ab57-8f4cd83140d5" />

### Connectivité 

Faisant partie des contraintes générales qu'en est il de ce paramètre ?
Et bien un site web permet un contrôle total sur le projet **mais pas seulement** on peut aussi avoir accés à d'autre mode de fonctionnement :
- Un mode réveil, qui allume le plafonier à l'heure choisi
- Un mode campbriolage, qui, si quelque chose passe devant le capteur à ultrasons, envoie une notification et fait clignoter la lumière rapidement
- Un mode plus "fun" que j'ai nommé : mode soirée, qui allume/éteint la lampe au bpm séléctionné

<img width="2134" height="2062" alt="image" src="https://github.com/user-attachments/assets/a9cb4254-d218-4248-b1a4-08ab72fd4eea" />



Cette présentation est **personnalisable bien sur** malgré le fait que ça aurait du être une application mais j'en reparlerai...

---
## Composants

| Composant                         | Quantité |  Prix (EUR) | Lien                                                                                                                       |
|-----------------------------------|----------|-------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Capteur à Ultrasons (HC-SR04)     | 1        | 1.40        | https://fr.aliexpress.com/item/1005006039388853.html?spm=a2g0o.productlist.main.1.2d0c6c8d52AzUk&algo_pvid=384d68a4-5c3b-4b1a-b29c-8c3976cda4ec&algo_exp_id=384d68a4-5c3b-4b1a-b29c-8c3976cda4ec-0&pdp_ext_f=%7B%22order%22%3A%221384%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%211.39%211.40%21%21%2110.80%2110.80%21%40211b430817733470202753312e20cb%2112000035439724673%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&curPageLogUid=h6jnqPSwXk35&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006039388853%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                                                                                          |
| Module photorésistance            | 1        | 0.94        | https://fr.aliexpress.com/item/1005007038160433.html?spm=a2g0o.detail.pcDetailBottomMoreOtherSeller.1.57772ab2lNSoi3&gps-id=pcDetailBottomMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=86567c85-ec4a-418c-932d-581834655584&_t=gps-id:pcDetailBottomMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:86567c85-ec4a-418c-932d-581834655584,tpp_buckets:668%232846%238116%232002&pdp_ext_f=%7B%22order%22%3A%229140%22%2C%22eval%22%3A%221%22%2C%22orig_sl_item_id%22%3A%221005007038160433%22%2C%22orig_item_id%22%3A%221005008777843802%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21EUR%210.70%210.69%21%21%215.40%215.40%21%40210385a817733472779063563ed6b9%2112000039179188751%21rec%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&utparam-url=scene%3ApcDetailBottomMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A1005007038160433%7C_p_origin_prod%3A1005008777843802 |
| Microcontrolleur (ESP32)          | 1        | 4.39        | https://fr.aliexpress.com/item/1005008889768599.html?spm=a2g0o.productlist.main.8.4b137404J3ACVi&aem_p4p_detail=202603121325182245967177584970000285969&algo_pvid=e73375d5-83a0-477a-97ac-fbc9dc483e27&algo_exp_id=e73375d5-83a0-477a-97ac-fbc9dc483e27-7&pdp_ext_f=%7B%22order%22%3A%227555%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%212.17%212.17%21%21%2116.84%2116.84%21%40211b80c217733471181617230e9b8f%2112000047095028658%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&curPageLogUid=Yfsn6g6RywSI&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005008889768599%7C_p_origin_prod%3A&search_p4p_id=202603121325182245967177584970000285969_2                                                                                                                                                                                                                                                               |
| Relais                            | 1        | 1.47        | https://fr.aliexpress.com/item/1005007109343076.html?spm=a2g0o.productlist.main.3.33d04c5cz5fB9G&algo_pvid=bab6e95c-095b-45bc-8e2f-8ffa0aa1ac0f&algo_exp_id=bab6e95c-095b-45bc-8e2f-8ffa0aa1ac0f-2&pdp_ext_f=%7B%22order%22%3A%225069%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%211.24%211.24%21%21%219.65%219.65%21%40211b430817733473365761651e200b%2112000045560566017%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&curPageLogUid=G1qfFX8seVtD&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007109343076%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                                                                                                                                |
| Bouton poussoir                   | 1 (20)   | 1.31        | https://fr.aliexpress.com/item/4001278311660.html?spm=a2g0o.detail.pcDetailBottomMoreOtherSeller.3.19741BDu1BDun8&gps-id=pcDetailBottomMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=328f6173-26fb-492c-b8a5-0dbf60580e46&_t=gps-id:pcDetailBottomMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:328f6173-26fb-492c-b8a5-0dbf60580e46,tpp_buckets:668%232846%238116%232002&pdp_ext_f=%7B%22order%22%3A%22212%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21EUR%211.31%211.31%21%21%211.48%211.48%21%40211b680e17733475512757093e5e34%2110000015580469000%21rec%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&utparam-url=scene%3ApcDetailBottomMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A4001278311660%7C_p_origin_prod%3A                                                                                   |
| LED                               | 2 (60)   | 2.89        | https://fr.aliexpress.com/item/1005008554748230.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.2.2934IQupIQupWO&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=bbb6acab-8b4a-48ca-b359-1888ce5345e0&_t=gps-id:pcDetailTopMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:bbb6acab-8b4a-48ca-b359-1888ce5345e0,tpp_buckets:668%232846%238116%232002&pdp_ext_f=%7B%22order%22%3A%223953%22%2C%22eval%22%3A%221%22%2C%22orig_sl_item_id%22%3A%221005008554748230%22%2C%22orig_item_id%22%3A%221005008801232952%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21EUR%213.62%213.59%21%21%2128.10%2127.86%21%40211b680e17733477035993921e5e34%2112000045690083701%21rec%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A1005008554748230%7C_p_origin_prod%3A1005008801232952           |
| Interrupteur                      | 1 (10)   | 1.69        | https://fr.aliexpress.com/item/1005007498633815.html?spm=a2g0o.detail.pcDetailTopMoreOtherSeller.10.4b2b5e6fz8tB4i&gps-id=pcDetailTopMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=51e48658-b431-4154-a144-931c9ca8f9cf&_t=gps-id:pcDetailTopMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:51e48658-b431-4154-a144-931c9ca8f9cf,tpp_buckets:668%232846%238116%232002&pdp_ext_f=%7B%22order%22%3A%22264%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21EUR%211.69%211.69%21%21%2113.10%2113.10%21%40211b680e17733480259531366e5e34%2112000053573501008%21rec%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&utparam-url=scene%3ApcDetailTopMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A1005007498633815%7C_p_origin_prod%3A                                                                                      |
| Phase et masse commune            | 2 (20)   | 1.89        | https://fr.aliexpress.com/item/4000873858801.html?spm=a2g0o.productlist.main.3.48ea7af15vZUN7&algo_pvid=3d1f7902-88d5-47a4-89e3-be19c4262abf&algo_exp_id=3d1f7902-88d5-47a4-89e3-be19c4262abf-2&pdp_ext_f=%7B%22order%22%3A%228825%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%211.83%211.83%21%21%212.06%212.06%21%40210385a817733485040374814ed6bb%2110000010058190554%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&curPageLogUid=1brWeu82tN5F&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A4000873858801%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                                                                                                  |
| Fils de branchements 10cm et 30cm | 40       | 6 en tout   | https://fr.aliexpress.com/item/1005002000655439.html?spm=a2g0o.productlist.main.1.4d5e3f93wb5qzr&algo_pvid=61594ef2-0ffe-4dc6-9ab1-c09153508f51&algo_exp_id=61594ef2-0ffe-4dc6-9ab1-c09153508f51-0&pdp_ext_f=%7B%22order%22%3A%2210604%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%211.95%211.95%21%21%212.20%212.20%21%402103847817733486014087386e6a19%2112000018371624180%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&curPageLogUid=zrQAbLZVKrRh&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005002000655439%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                                                                                                                               |
| Convertisseur 220v AC vers 5v DC  | 1        | 1.35        | https://fr.aliexpress.com/item/1005001970797548.html?spm=a2g0o.detail.pcDetailBottomMoreOtherSeller.4.e61d198fMH9gRK&gps-id=pcDetailBottomMoreOtherSeller&scm=1007.40050.354490.0&scm_id=1007.40050.354490.0&scm-url=1007.40050.354490.0&pvid=2fbc145b-8b92-41bb-8277-08f70e744205&_t=gps-id:pcDetailBottomMoreOtherSeller,scm-url:1007.40050.354490.0,pvid:2fbc145b-8b92-41bb-8277-08f70e744205,tpp_buckets:668%232846%238116%232002&pdp_ext_f=%7B%22order%22%3A%228918%22%2C%22eval%22%3A%221%22%2C%22sceneId%22%3A%2230050%22%2C%22fromPage%22%3A%22recommend%22%7D&pdp_npi=6%40dis%21EUR%211.35%211.35%21%21%211.52%211.52%21%40211b680e17733487913888176e5e34%2112000021038968548%21rec%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&utparam-url=scene%3ApcDetailBottomMoreOtherSeller%7Cquery_from%3A%7Cx_object_id%3A1005001970797548%7C_p_origin_prod%3A                                                                                                                |
| Fils électrique 220v              | 1        | 3.59        | https://fr.aliexpress.com/item/1005010779278423.html?spm=a2g0o.productlist.main.15.1b1f32a6MBqURu&algo_pvid=6ba0fe34-8dab-436a-bdd4-16218fb9c19f&algo_exp_id=6ba0fe34-8dab-436a-bdd4-16218fb9c19f-14&pdp_ext_f=%7B%22order%22%3A%221237%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%213.44%213.39%21%21%2126.63%2126.28%21%40210384b217733491350511203e6f1e%2112000053482331302%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&curPageLogUid=Tpccef9IAn8x&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005010779278423%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                                                                                                                            |
| Connecteur Wago                   | 3        | 1.73        | https://fr.aliexpress.com/item/1005006963063019.html?spm=a2g0o.productlist.main.1.4c232RkB2RkB3v&algo_pvid=4cf9ecbb-464d-4071-873c-6d60e75f5276&algo_exp_id=4cf9ecbb-464d-4071-873c-6d60e75f5276-0&pdp_ext_f=%7B%22order%22%3A%226245%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%211.60%211.37%21%21%2112.41%2110.70%21%40211b813f17733494002655833e1c3f%2112000038871333794%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895%3BpisId%3A5000000201963006&curPageLogUid=HWIUbFlHGmkb&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006963063019%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                                                               |
| Vis (M4x30, Countersunk head)     | 2 (10)   | 3.09        | https://fr.aliexpress.com/item/1005007129209802.html?spm=a2g0o.productlist.main.2.3763183bd14ARA&algo_pvid=44045911-aa00-42d7-9914-d023d7003e4a&algo_exp_id=44045911-aa00-42d7-9914-d023d7003e4a-1&pdp_ext_f=%7B%22order%22%3A%22334%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%212.84%212.84%21%21%2122.04%2122.04%21%40210384cc17733501999015435eab32%2112000039500635014%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&curPageLogUid=CcgAKJmvaKPf&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005007129209802%7C_p_origin_prod%3A                                                                                                                                                                                                                                                                                                                                                                               |
| Écrou                             | 2 (50)   | 2.44        | https://fr.aliexpress.com/item/1005010329406193.html?spm=a2g0o.productlist.main.1.7be1123aTkznqO&algo_pvid=b27cb7e0-7958-4c3d-af21-8a07a8b9e726&algo_exp_id=b27cb7e0-7958-4c3d-af21-8a07a8b9e726-0&pdp_ext_f=%7B%22order%22%3A%221216%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%212.02%212.01%21%21%2115.64%2115.62%21%40211b81a317733503879693154e280d%2112000051980040866%21sea%21FR%214347473071%21X%211%210%21n_tag%3A-29919%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895&curPageLogUid=cvXic0RmJtV7&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005010329406193%7C_p_origin_prod%3A                               |  
| Résistances                        | 2 (20)   | 0.99        | https://fr.aliexpress.com/item/1005006424279944.html?spm=a2g0o.productlist.main.11.713863d6qiYR09&algo_pvid=82495c51-39f7-4fc9-99fa-ed466de5474c&algo_exp_id=82495c51-39f7-4fc9-99fa-ed466de5474c-10&pdp_ext_f=%7B%22order%22%3A%22357%22%2C%22spu_best_type%22%3A%22price%22%2C%22eval%22%3A%221%22%2C%22fromPage%22%3A%22search%22%7D&pdp_npi=6%40dis%21EUR%211.02%210.99%21%21%211.15%211.12%21%40211b629217742209876185818e83ad%2112000037116520774%21sea%21FR%210%21ABX%211%210%21n_tag%3A-29910%3Bd%3Aee3167b6%3Bm03_new_user%3A-29895%3BpisId%3A5000000197682715&curPageLogUid=0kTIJdFrYJ1f&utparam-url=scene%3Asearch%7Cquery_from%3A%7Cx_object_id%3A1005006424279944%7C_p_origin_prod%3A      |
| Total                             |          | 35          | C'est seulement si vous achetez toutes les pièces, on peut faire de la récup sur certain composants  |

Pour ma part j'ai réutilisé le convertisseur 220V AC vers 5V DC d'un chargeur, le bouton poussoir d'un petit appareil, les leds d'un jouet pour bébé, les résistances d'un autre projet et les fils d'un starter pack arduino.


**PS :** Les quantités entre partenthèses sont les quantités minimum disponible pour ce produit. Vous pouvez très bien adapter du materiel que vous avez déjà j'ai simplement mis tout les éléments nécessaire a la conception de l'Éco'Light. Les liens proviennent tous d'aliexpress (plus simple pour l'électronique donc j'ai continué sur ma lancée) mais leur validité n'est pas certaine.
 
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
- tout les composants
- un tournevis cruciforme
- un fer à souder (aucune soudure n'est difficile)
- un pistolet à colle
- une pince ou quelque chose de similaire et une clé Allen pour les vis du bras
- et un peu d'huile de coude

Une fois toutes les pièces réunis, vous pouvez commencer à construire **votre** Éco'Light ! 


Il vous faudra imprimer en 3d le fichier [suivant](assets/3d/eco-light.stl). **Attention** ne surtout pas imprimer les deux corps, c'est seulement pour choisir entre un interrupteur à gauche ou à droite. De même avec les "bras" pour le capteur à ultrasons, imprimez en un seul j'ai modélisé 3 tailles : 8, 10 et 12cm.

Il faut ennsuite récupérer le [code](assets/code/code esp32.ino) pour l'ESP32 et le flasher sur votre microcontrolleur via Arduino IDE (un logiciel de programmation pour tout ces petits microcontrolleur)

Réalisez le montage ci-dessous soit directement dans le boiter fraichement imprimé si vous êtes confiant soit sur une breadboard pour être sur : 

| Nom                     | Pin | "Compément"                     |
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

Une fois que vous êtes sur du bon fonctionnement du projet alors vous pouvez passer a la catégorie **installation** pour fixer et démarrer l'Éco'Light.

---
## Installation 

Très simplement vous allez le fixer à la place de l'interrupteur : l'Éco'Light respecte les dimensions standards, entraxe des vis de fixations de 60 mm (boite Ø67 mm).
Il n'y a que le cablage qui change puisqu'il faut alimenter le microcontrolleur en électricité. Rassurez vous le travail à faire est minime : 

<img width="2251" height="1388" alt="image" src="https://github.com/user-attachments/assets/b1d9b910-2669-4536-8e72-22a44d03b7a2" />

On a donc ça du coté du boitier :

<img width="1485" height="1530" alt="image" src="https://github.com/user-attachments/assets/c346b55f-e590-4655-8d19-e3fcbc88a3ad" />

Si on représente tout schématiquement pour mieux comprendre la situation et éclaircir un petit peu les choses 

<img width="2828" height="953" alt="image" src="https://github.com/user-attachments/assets/890b4bcf-326f-40d2-b619-fdd49d725e37" />

 Aucune compétence en électricité n'est nécessaire même votre grand-mère pourrait le faire c'est dire ! (ps: je doute que beaucoup de grand-mères utilisent Github).
 Bref plutôt qu'il ne faut pas du tout s'inquiéter sur ce point.

 
 Ensuite vous vissez le tout (2 vis) et il n'y a plus qu'à allumer la machine via l'interrupteur latéral !

 
 Pour ensuite, magie, vous connnecter à l'ESP32 avec votre téléphone pour finaliser la mise en place. Le but de cette application est d'informer le microcontrolleur de vos préférences (mdp wifi, distance détection...), il suffit de suivre ces étapes :

 <img width="1657" height="1478" alt="image" src="https://github.com/user-attachments/assets/862b827e-1409-442d-a580-c53dcf6f791f" />

 (à chaque fois il y aura la fenêtre d'erreur associée à l'étape correspondante)

 Page d'accueil donc, avant il faut appairer l'ESP32 avec votre téléphone (Paramètres → Connexions → Bluetooth → Sélectionner appareil (Éco'Light) → Appairer), après cette étape de complété et un temps de chargement plus ou moins long :
 
<img width="305" height="580" alt="image" src="https://github.com/user-attachments/assets/4c0207fe-4532-4985-85c6-78a841acc5b5" />
(Le bouton Reset sert si vous avez un problème durant le processus (freeze, erreur...), il redémarre l'ESP32 et vous renvoie à la page d'accueil)


 Vous arrivez sur :

 <img width="2159" height="1246" alt="image" src="https://github.com/user-attachments/assets/de1a1f6e-bfc3-435d-b1e1-4489f9e22163" />

Il faut donc choisir son réseau wifi et indiquer le mot de passe pour que l'ESP32 ait accès à internet

<img width="1383" height="1229" alt="image" src="https://github.com/user-attachments/assets/946bf85f-7728-4e50-a9ec-e87357b9a802" />

Pour ensuite choisir la distance de détection du capteur à ultrasons (votre choix dépendra de l'emplacement de votre interrupteur, de la position de votre capteur mais surtout si vous voulez qu'il vous détecte quand vous passez vou ou votre main. Par exemple je l'ai réglé moi pour que, quand je circule, le capteur ne détecte rien mais quand je me rapproche ou passe ma main devant il allume la lumière. C'est plus agréable je trouve surtout si vous vivez à plus, qu'il y a des va et vient dans la pièce concernée car on  peut quand même allumer la lumière les bras chargés). 

<img width="1383" height="1229" alt="image" src="https://github.com/user-attachments/assets/a3a22c9a-99ec-4529-913c-62465add9e92" />

(Ps : moi comme référence je l'ai donc réglé à 13cm avec un interrupteur plutôt proche du cadre de porte)


Vient ensuite la partie "API", créez un compte sur [Adafruit](https://io.adafruit.com) et rentrez vos informations (le nom d'utilisateur et la clé API peuvent être trouvés en cliquant sur l'icone de clé en haut à droite) :

<img width="2160" height="1245" alt="image" src="https://github.com/user-attachments/assets/6e652bd1-ef96-45c9-a380-cdfb5422da59" />

Il faudra ensuite respecter le tableau suivant lors de la création des feeds et du dashboard sur le site d'adafruit où vous irez ensuite après la mise en palce de l'Écolight (à vous de personaliser votre expérience).

| Fonction                        | Nom du feed  | Objet associé sur le dashboard             |
|---------------------------------|--------------|--------------------------------------------|
| Gérer l'allumage                | lampe        | Toggle                                     |
| Gérer le mode cambiolage        | cambriolage  | Toggle                                     |
| Gérer le message d'alerte       | notif        | Text (Show icon avec exclamation-triangle) |
| Gérer le mode réveil            | reveil       | Toggle                                     |
| Gérer l'heure du réveil         | reveil heure | Text                                       |
| Gérer le mode "soirée"          | soiree       | Toggle                                     |
| Gérere les bpm du mode "soirée" | soiree bpm   | Text                                       |

Pour rentrer l'heure pour le réveil dans le bloc texte le format attrendu est le suivant : XX:XX (Ex: 7:15, 12:25, 22:55)

<img width="873" height="1211" alt="image" src="https://github.com/user-attachments/assets/fe43f993-40d4-485e-b076-43699543256a" />

Si tout s'est bien passé alors cette page apparait et vous êtes prêt à utiliser l'Éco'Light pour la première fois !
Maintenant que vous êtes sûr du bon fonctionnement du projet vous pouvez alors coller le couvercle et profiter pleinement de votre Éco'Light à la maison.


Si jamais un problème arrive ou vous voulez changer de taille de bras et aussi de distance de détection : relancez l'application et coupez et rallumez l'ESP32

---

Je voulais juste faire un point sur l'interace utilisateur, je trouve le dashboard adafruit très limitant et j'avais à la base créé une application beaucoup plus agréable que je veux quand même partager malgré le fait que l'API d'adafruit ne m'a pas permit de trouver une solution

<img width="2561" height="1208" alt="image" src="https://github.com/user-attachments/assets/42f5c4f8-0a02-4c72-a8df-f74e77b99a14" />

Donc voilà quelque chose de beaucoup plus attrayant mais que je n'ai pu finaliser malgré des heures de travail...


---

# Conclusion

Je me suis régalé pendant toute la conception, la création, la travail de recherche, la mise en forme ou encore le soirée passées à retourner dans tous les sens un problème que je n'arrivais pas à résoudre sur ce projet pour enfin aboutir. Je suis tellement heureux de pouvoir arriver le soir chez et de n'avoir plus, dans un coin de mla tête, une petite voix me disant me disant de toujours peaufiner un détail que personne ne verra... Mais finalement en plus de l'aboutissement ça ne serait pas toutes les galères rencontrées qui compteraient le plus non ?

J'ai bien sur quelques idées d'amélioration en tête et je serais ravi de vous les partager. En tout cas j'espere (si vous êtes arrivé jusque là) que ce projet vous à plu et j'espere surtout vous avoir convaincu !

Voici la video du projet : 
























