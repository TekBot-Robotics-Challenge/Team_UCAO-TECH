# Gyroscope et Accéléromètre

## 🎯 Objectif

Utiliser un capteur gyroscope + accéléromètre pour détecter l’orientation et la vitesse de mouvement d’un objet dans l’espace, et afficher ces données sur un écran LCD.

---

## 🔧 Matériel utilisé

| Composant | Référence | Rôle |
|-----------|-----------|------|
| Microcontrôleur | Arduino Uno / ATmega328P | Traitement des données |
| Capteur | MPU6050 (I2C) | Mesure d’orientation et d’accélération |
| Afficheur | Écran LCD 16x2 | Affichage du mouvement |
| Divers | Breadboard, fils, alimentation | Connexions et test |

---

## 🧠 Fonctionnement du système

- Le capteur est placé dans la main d’un membre de l’équipe.
- Lorsqu’il bouge dans l’espace (haut, bas, gauche…), les données sont envoyées à l’Arduino.
- L’écran LCD affiche la direction du mouvement et la valeur d’accélération correspondante.

---

## 📷 Schéma de câblage

![Schéma du montage](../Images/schema_montage.png)


---

## 💻 Code source

Le code est disponible dans le dossier [`Code/`](../Code/gyroscope_affichage.ino).

> 🔍 Le code est commenté ligne par ligne pour faciliter la lecture et l’évaluation.

---

## 🖥️ Affichage à l’écran

![Affichage LCD](../Images/affichage_LCD.png)

---

## 🎥 Démonstration vidéo

📹 [Cliquez ici pour voir la démo](../Video/demo_gyro.mp4)

---

## 🔍 Résultats observés

- ✅ Les directions sont correctement détectées.
- ✅ L’accélération s’affiche avec une bonne réactivité.
- ⚠️ Quelques variations dues aux vibrations parasites.

---

## 🛠️ Difficultés rencontrées

| Problème | Solution apportée |
|----------|--------------------|
| Données bruyantes du capteur | Lissage avec une moyenne mobile |
| Affichage instable | Délais ajustés dans la boucle principale |
| Tension instable | Utilisation d’un régulateur + condensateurs |

---

## 📚 Ressources

- [Datasheet MPU6050](https://invensense.tdk.com/products/motion-tracking/6-axis/mpu-6050/)
- [Documentation Arduino LCD](https://www.arduino.cc/en/Tutorial/HelloWorld)

---

## 👥 Membres contributeurs

- **Nom A** – Capteurs et câblage
- **Nom B** – Programmation
- **Nom C** – Schéma électronique
