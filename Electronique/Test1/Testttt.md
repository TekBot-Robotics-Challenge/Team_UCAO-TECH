# 🧭 Test 1 – Détection d’Orientation avec Accéléromètre & Gyroscope (GY-521 / MPU6050)

---

## 🎯 Objectif du projet

Ce test a pour but de mesurer, interpréter et afficher en **temps réel l’orientation et l’accélération d’une main** à l’aide d’un capteur inertiel relié à un microcontrôleur. Les données sont visualisées sur un écran LCD via communication I2C.

---

## 🧪 Présentation des capteurs

### ⚡ Accéléromètre (intégré au MPU6050)
- Mesure de l’**accélération linéaire** sur 3 axes (X, Y, Z)
- Permet de détecter les **chocs**, **inclinasons**, **démarrages/brusques arrêts**

### 🔁 Gyroscope (intégré au MPU6050)
- Mesure la **vitesse angulaire** (°/s) sur les 3 axes
- Utile pour suivre la **rotation** et **stabiliser les mouvements**

### 🧠 Capteur utilisé

| Module    | Description                              | Protocole |
|-----------|------------------------------------------|-----------|
| GY-521    | Intègre un MPU6050 (gyro + accéléromètre)| I2C (addr: 0x68) |

---

## 🧰 Matériel utilisé

| Composant            | Référence            | Rôle                                                   |
|----------------------|----------------------|--------------------------------------------------------|
| Microcontrôleur      | Arduino UNO (ATmega328P) | Traitement des données capteur + affichage LCD        |
| Capteur              | GY-521 (MPU6050)     | Acquisition des données inertielle via I2C             |
| Afficheur            | Écran LCD 16x2 + module I2C | Affichage direction + accélération                     |
| Alimentation         | Régulateur 5V (LM7805) + batteries | Stabilisation de la tension d’alim                 |
| Câblage & support    | Breadboard, fils dupont  | Montage sans soudure                                   |
| Composants passifs   | Résistances, condensateurs | Protection contre bruit et fluctuations électriques     |

---

## 🔌 Schéma électronique

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
- `Wire.h` – communication I2C
- `Adafruit_MPU6050.h` – pilotage du capteur
- `Adafruit_Sensor.h` – structures et abstractions
- `LiquidCrystal_I2C.h` – gestion de l’écran LCD

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

## 🧪 Procédure de test physique

- Capteur tenu dans la paume de main à l’horizontale
- Mouvements simples dans 6 directions de référence (XYZ)
- L’écran change dynamiquement selon la direction et amplitude
- Ajout recommandé : **vidéo de démonstration** pour validation visuelle

---

## 🔍 Problèmes rencontrés et solutions

| Problème identifié              | Solution appliquée                                                  |
|-------------------------------|----------------------------------------------------------------------|
| Bruit dans les mesures         | Ajout de filtrage logiciel, délais (debounce) et moyenne glissante |
| Affichage incohérent           | Réglage des seuils de détection                                     |
| Mauvaise orientation détectée | Test de calibration sur axe Z à l’initialisation                    |
| LCD instable                  | Vérification de l’alimentation 5V et du module I2C                  |

---

## 📁 Structure du dépôt GitHub

```
📁 TRC25-UCAOTECH/
└── Electronique/
    └── Test1/
        ├── Code/
        │   └── gyroscope_affichage.ino
        ├── Docs/
        │   └── README.md (ce fichier)
        ├── Kicad/
        │   └── schema_test1.kicad_sch
        ├── Images/
        │   ├── schema_montage.png
        │   └── affichage_LCD.png
```

---

## ✅ Résultats attendus

- Compréhension du fonctionnement d’un **capteur inertiel combiné**
- Mise en œuvre d’une **communication I2C stable** avec un microcontrôleur
- Traitement des données capteur en **affichage en temps réel**
- Création d’un **circuit électronique fonctionnel** et **auto-alimenté**

---
