# 🧭 Test 1 
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
| Alimentation         | Régulateur 5V (LM7805) + batteries | 
| Câblage & support    | Breadboard, fils dupont  |
| Composants passifs   | Résistances, condensateurs |

---

## Schéma électronique

📎 Fichier KICAD : [`/Kicad/schema_test1.kicad_sch`](../Kicad/schema_test1.kicad_sch)  
📸 Image du schéma :  
![Schéma du montage](../Images/schema_montage.png)

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

## 💻 Code Arduino

📁 Code source : [`/Code/gyroscope_affichage.ino`](../Code/gyroscope_affichage.ino)

### Bibliothèques utilisées :
- `Wire.h` – Communication I2C
- `Adafruit_MPU6050.h` – Cilotage du capteur
- `Adafruit_Sensor.h` – Structures et abstractions
- `LiquidCrystal_I2C.h` – Gestion de l’écran LCD

```cpp
mpu.getAcceleration(&ax, &ay, &az);
mpu.getRotation(&gx, &gy, &gz);
```

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
-Appliquer nos compétences en électronique et en programmation.  
-Exploiter un capteur combinant accéléromètre et gyroscope pour détecter les mouvements et l’orientation. 
- Concevoir un circuit fonctionnel et interfacer un écran LCD pour afficher les mesures.  


---
