# Gyroscope et Accéléromètre

## 🎯 Objectifdu Test
L’objectif est d’identifier et exploiter un capteur combinant accéléromètre et gyroscope, fonctionnant via communication I2C, afin d’afficher l’orientation et l’accélération de la main sur un écran LCD.
## . Présentation du Test
Un capteur est un dispositif électronique conçu pour convertir des grandeurs physiques ou environnementales (mouvement, température, pression, etc.) en signaux électriques exploitables.  Parmi la diversité de capteurs disponibles, ce test se concentre sur l’accéléromètre et le gyroscope, des composants clés en robotique et en navigation autonome. Ces capteurs permettent aux robots de s’orienter et d’interagi avec leur environnement en temps réel, à l’image du sens de l’équilibre et de la proprioception chez l’humain.
# Accéléromètre
L’accéléromètre mesure l’accélération linéaire sur un ou plusieurs axes (X, Y, Z), détectant ainsi les variations de vitesse et de position d’un objet.  
# Rôles de l’accéléromètre :
-Détecter les mouvements (avancée, recul, inclinaison).  
- Corriger la trajectoire(montée, descente).  
- Reconnaître une chute ou un choc pour la sécurité d’un système.  
## Gyroscope
Le gyroscope mesure la vitesse angulaire, c’est-à-dire le taux de rotation d’un objet autour de ses axes.

# Rôles du gyroscope :
- Suivre l’orientation de l’objet.  
- Stabiliser les mouvements.  
- Améliorer la précision de navigation pour les applications robotiques 



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
