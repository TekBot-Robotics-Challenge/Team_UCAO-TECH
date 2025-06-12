# Test 1 
# Test Input : Détection d’Orientation avec Accéléromètre & Gyroscope

---

## Présentation du Test

Un capteur est un dispositif électronique conçu pour convertir des grandeurs physiques ou environnementales (mouvement, température, pression, etc.) en signaux électriques exploitables.  Parmi la diversité de capteurs disponibles, ce test se concentre sur l’accéléromètre et le gyroscope, des composants clés en robotique et en navigation autonome. Ces capteurs permettent aux robots de s’orienter et d’interagi avec leur environnement en temps réel, à l’image du sens de l’équilibre et de la proprioception chez l’humain.

##  Objectif du projet

Ce test a pour but de mesurer, interpréter et afficher en **temps réel l’orientation et l’accélération d’une main** à l’aide d’un capteur inertiel relié à un microcontrôleur. Les données sont visualisées sur un écran LCD via communication I2C.

---

##  Présentation des capteurs

### Accéléromètre (intégré au MPU6050)
L’accéléromètre mesure l’accélération linéaire sur un ou plusieurs axes (X, Y, Z), détectant ainsi les variations de vitesse et de position d’un objet.  
Rôles de l’accéléromètre :
-Détecter les mouvements (avancée, recul, inclinaison).  
- Corriger la trajectoire(montée, descente).  
- Reconnaître une chute ou un choc pour la sécurité d’un système.  

### Gyroscope (intégré au MPU6050)
Le gyroscope mesure la vitesse angulaire, c’est-à-dire le taux de rotation d’un objet autour de ses axes.
Rôles du gyroscope :
- Suivre l’orientation de l’objet.  
- Stabiliser les mouvements.  
- Améliorer la précision de navigation pour les applications robotiques et aéronautiques.

### Identification du capteur

Nous avons sélectionné le module GY-521, basé sur le capteur MPU6050, qui intègre un accéléromètre et un gyroscope dans un seul composant. Ce capteur permet de déterminer précisément l’orientation spatiale et les mouvements tout en offrant une interface simplifiée pour les microcontrôleurs.

![Capteur GY-521](Images/GY-521.png)

Fonctionnement du Capteur :
- Accéléromètre : Mesure l’accélération sur les trois axes (X, Y, Z) en m/s² ou en g. La mesure combine l’accélération due au mouvement et l’accélération gravitationnelle.  
- Gyroscope: Mesure la vitesse angulaire sur les trois axes en °/s, permettant de déterminer la vitesse et la direction de rotation.  
- Communication I2C : Le capteur utilise l’adresse par défaut 0x68 pour échanger des données avec le microcontrôleur.

---

## Matériel utilisé

| Composant            | Référence            |
|----------------------|----------------------|
| Microcontrôleur      | Arduino UNO (ATmega328P) |
| Capteur              | GY-521 (MPU6050)     |
| Afficheur            | Écran LCD 16x2 + module I2C |
| Alimentation         | Batterie de 9V | 
| Câblage & support    | Breadboard, jumpers  |
| Composants passifs   | Résistances 10 kΩ  |

  # Role des composants
   #  Microcontrôleur (Arduino UNO)
Le microcontrôleur **Arduino UNO**, basé sur la puce ATmega328P, est le cœur du système. Il exécute le programme, communique avec le capteur via I2C et pilote l’écran LCD. C’est lui qui reçoit les données d’accélération et de rotation, les interprète, puis déclenche l’affichage.
![Carte Arduino UNO](Images/ArduinoUNO.png)
   #  Ecran LCD
L’écran **LCD 16x2**, combiné à un module I2C, sert à afficher les informations détectées par le capteur : direction du mouvement et intensité de l’accélération. Grâce à l’interface I2C, seulement deux fils (SDA et SCL) sont nécessaires pour connecter l’écran à l’Arduino, ce qui simplifie beaucoup le câblage.

![Ecran LCD 16x2](Images/Lcd 16x2.png)

   #  Breadboard
Une **breadboard** est utilisée pour monter le circuit sans soudure. Cela permet de tester différentes configurations facilement et de modifier rapidement le câblage en cas d’erreur ou d’amélioration.

![Breadboard](Images/breadbord.png)

   # Jumpers
Les **jumpers** (mâle-mâle ou mâle-femelle) assurent les connexions électriques entre les broches de la carte, du capteur, du régulateur et de l’afficheur. Ils sont souples et facilitent les prototypages rapides et propres.
![Jumpers](Images/Jumpers.png)
  # Résistances
Deux résistances de tirage (pull-up) de 10 kΩ sont connectées aux lignes SDA et SCL. Ces résistances assurent la stabilité du bus I2C et évitent les erreurs de communication dues aux flottements logiques sur ces lignes.

  # Alimentation du système
Le système est alimenté par une **batterie 9V** connectée directement au port **Jack** de l’Arduino UNO. Cette approche permet d'exploiter le régulateur interne de la carte, qui convertit la tension d’entrée en un 5V stable distribué à l’ensemble du montage. Ce choix offre une solution portable, autonome et simple à mettre en œuvre, sans nécessiter de régulateur externe.

![Alimentation](Images/batterie.png)

L’ensemble des composants – le capteur MPU6050, l’afficheur LCD, et l’Arduino – sont ainsi protégés contre les variations de tension. Ce type d’alimentation est particulièrement adapté aux prototypes mobiles et aux tests manuels.

> ⚠️ Note : La batterie 9V doit être neuve ou bien chargée pour éviter une chute de tension pouvant entraîner des comportements erratiques sur l’écran ou les communications I2C.

---

## Schéma électronique

📎 Fichier KICAD : [📥 Télécharger le schéma KiCad](KICAD/test1_circuit.kicad_sch)  
📸 Image du schéma :  
![Schéma du montage](Images/Cap_circuit.png)

**Description** :
- **SDA :** A4 / **SCL :** A5 (bus I2C)
- Le régulateur alimente l’Arduino en 5V stable
- Condensateurs : 100nF en découplage sur VCC/GND
- Résistances de pull-up sur SDA/SCL si nécessaire

---

## ⚙️ Fonctionnement global

1. Initialisation du capteur et de l’écran LCD dans le `setup()`
2. Lecture des données brutes via I2C dans le `loop()`
3. Conversion des valeurs vers un format lisible
4. Analyse des variations pour détecter :
   - Orientation de la main : gauche, droite, haut, bas, avant, arrière
   - Accélération : amplitude en m/s² ou g
5. Affichage dynamique sur l’écran LCD

---

## ⚙️ Fonctionnement global du système

1. **Initialisation**
   - Mise sous tension via une batterie 9V (port Jack Arduino UNO).
   - Affichage d’un message de démarrage sur le LCD.
   - Initialisation du capteur MPU6050 via le protocole I2C.

2. **Calibration automatique**
   - Lors des premières secondes, le système lit les valeurs d’accélération actuelles.
   - Ces valeurs sont enregistrées comme référence (_offsets_) pour chaque axe.
   - Cela permet d’annuler les biais dus à une surface inclinée ou instable.

3. **Lecture et compensation**
   - Lecture continue des données d’accélération sur les axes X, Y, Z.
   - Soustraction des offsets de calibration pour obtenir une accélération relative.

4. **Détection de direction dominante**
   - Identification de l’axe présentant la plus forte variation.
   - Interprétation du sens (positif/négatif) pour déterminer la direction du mouvement :
     - Ex : `+Y` → Avant ; `−Y` → Arrière ; `+X` → Droite ; `−X` → Gauche ; `+Z` ou `−Z` → Haut/Bas
   - Application d’un seuil pour ignorer les mouvements faibles ou parasites.

5. **Affichage sur écran LCD**
   - Mise à jour de l’affichage toutes les 250–300 ms pour garantir la lisibilité.
   - Ligne 1 : direction détectée (`AVANT`, `GAUCHE`, etc.)
   - Ligne 2 : intensité de l’accélération dominante (ex : `Acc: 2.38 g`)

6. **Stabilisation**
   - Délai court (`delay(300)`) entre chaque boucle pour lisser l’affichage.
   - (Optionnel) : envoi des valeurs dans le moniteur série pour calibration ou analyse.

---

## 💻 Code Arduino

### Bibliothèques utilisées :
- `Wire.h` – Communication I2C
- `Adafruit_MPU6050.h` – Cilotage du capteur
- `Adafruit_Sensor.h` – Structures et abstractions
- `LiquidCrystal_I2C.h` – Gestion de l’écran LCD

📁 Code source : [`/Code/gyroscope_affichage.ino`](../Code/gyroscope_affichage.ino)

> 💡 Le code utilise des **seuils dynamiques** pour détecter la direction dominante et filtrer les variations faibles.

---

## 🖥️ Affichage LCD

📸 Image :  
![Affichage LCD](../Images/affichage_LCD.png)

Contenu affiché :
- Ligne 1 : Direction détectée (_ex : AVANT, GAUCHE, HAUT…_)
- Ligne 2 : Accélération dominante (_ex : “Acc : 2.3g”_)

---

## Procédure de test physique

- Capteur tenu dans la paume de main à l’horizontale
- Mouvements simples dans 6 directions de référence (XYZ)
- L’écran change dynamiquement selon la direction et amplitude
- Ajout recommandé : **vidéo de démonstration** pour validation visuelle

---

## 🔍 Problèmes rencontrés et solutions

| Problème identifié              | Solution appliquée                                                  |
|-------------------------------|----------------------------------------------------------------------|
| Affichage incohérent           | Réglage des seuils de détection                                     |
| Mauvaise orientation détectée | Test de calibration sur axe Z à l’initialisation                    |
| LCD instable                  | Vérification de l’alimentation 5V et du module I2C                  |

---


## Conclusion

Ce test nous a permis de :
- Appliquer nos compétences en électronique et en programmation.  
- Exploiter un capteur combinant accéléromètre et gyroscope pour détecter les mouvements et l’orientation. 
- Concevoir un circuit fonctionnel et interfacer un écran LCD pour afficher les mesures.  


---
## 📚 Ressources

- [Datasheet MPU6050](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/)
- [Documentation Arduino LCD](https://www.arduino.cc/en/Tutorial/HelloWorld)

---

## 👥 Membres contributeurs

- **TCHIDEHOU Dodji Virgile** 
- **ADAHE Christelle** 
- **HOUNNOUVI Hermes** 
