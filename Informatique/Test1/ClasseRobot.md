# 🤖 Test 1 – Conception et implémentation orientée objet d’un robot autonome

Projet : **Tekbot Robotics Challenge 2024**  
Filière : Génie Électrique / Informatique Industrielle  
Année universitaire : 2024–2025

## 🎯 Objectifs du projet

- Concevoir un robot modulaire en C++ selon les principes de la programmation orientée objet.
- Appliquer les concepts d’abstraction, d’héritage, d’encapsulation et de polymorphisme.
- Modéliser les entités robotiques à l’aide de diagrammes UML.
- Simuler un système capable de se déplacer, manipuler et percevoir l’environnement.

## 🧠 Concepts abordés

- UML et modélisation logicielle
- Héritage et polymorphisme (`virtual`, `override`)
- Encapsulation (attributs privés, getters/setters)
- Composition (capteurs, navigation)
- Utilisation de `std::vector`

## 🧱 Architecture orientée objet

| Classe           | Rôle                              | Liens OOP                 |
|------------------|-----------------------------------|---------------------------|
| `Robot`          | Classe abstraite principale       | Abstraction, interface    |
| `RobotMobile`    | Déplacement au sol                | Héritage                  |
| `BrasRobotique`  | Manipulation d’objets             | Héritage                  |
| `Capteur`        | Représente un capteur ajouté      | Composition               |
| `Navigation`     | Gère la position du robot         | Agrégation                |

## 📐 Diagramme UML

![Diagramme UML](diagramme_UML.png)

_Légende : 🔺 héritage | 🔷 agrégation | 🔐 privé | 📥 getter/setter | 🔑 méthode virtuelle_

## 💻 Compilation & exécution

### Compilation (g++) :

```bash
g++ -std=c++17 main.cpp robot.cpp robot_mobile.cpp bras_robotique.cpp capteur.cpp navigation.cpp -o robot_test
Execution
./robot_test
Demonstration
Robot: Explorer-1
Position: (10.5, 5.2, 0.0)
Capteurs actifs: 2
---

Fonctionnalités :

Ajout dynamique de capteurs (ajouterCapteur)

Redéfinition de la méthode move() selon le type de robot

Affichage des informations avec obtenirInfos()

🚧 Défis rencontrés
Traduction UML → C++ : évitement de l’héritage multiple

Encapsulation vs performance
Mémoire : choix entre pointeurs bruts et std::vector

Mise en place d’une architecture extensible

✅ Perspectives d’évolution
Interface graphique de simulation

Intégration d’une IA embarquée

Module de simulation physique

Génération de logs via fichier .txt

📎 Annexes
diagramme_UML_vectorise.svg

Captures : annexes/captures_console.png
Fichiers source : .cpp / .h
