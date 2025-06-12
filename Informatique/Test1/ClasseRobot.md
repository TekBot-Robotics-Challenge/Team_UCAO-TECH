# 🤖 Test 1 – Classe de gestion d’un Robot autonome  
**Tekbot Robotics Challenge 2025 — Informatique**

---

## 🎯 Objectifs du test

Ce test vise à évaluer les compétences en **programmation orientée objet** (POO) en implémentant une **architecture modulaire** pour un robot. L’objectif est de :

- Modéliser une **classe principale `Robot`** et au moins **deux sous-classes spécialisées**
- Utiliser les concepts fondamentaux de la POO :  
  👉 **Encapsulation**, **Héritage**, **Polymorphisme**, **Abstraction**
- Implémenter et redéfinir une méthode `move()` dans les sous-classes
- Fournir une documentation claire, incluant un **diagramme UML explicatif**

---

## 🧠 Concepts abordés

- UML et modélisation logicielle
- Héritage et polymorphisme (`virtual`, `override`)
- Encapsulation (attributs privés, getters/setters)
- Composition (capteurs, navigation)
- Utilisation de `std::vector`

---

## 🛠️ Technologies utilisées

- **Langages** : C++  
- **IDE recommandé** : VS Code, Arduino IDE ou tout éditeur C++  
- **Diagramme UML** : Généré avec [draw.io](https://draw.io)  
- **Structure** : Projet modulaire avec séparation en `.h` / `.cpp`

---

## 🧩 Architecture des classes

| Classe           | Rôle                                                   | Concepts illustrés             |
|------------------|---------------------------------------------------------|-------------------------------|
| `Robot`          | Classe mère abstraite. Contient les propriétés générales. | Abstraction, Polymorphisme   |
| `RobotMobile`    | Gère les déplacements en translation (roues, direction) | Héritage, Redéfinition        |
| `BrasRobotique`  | Contrôle un bras articulé et sa pince                   | Héritage, Encapsulation       |
| `Capteur`        | Représente un capteur configurable (type, portée, etc.) | Composition                   |
| `Navigation`     | Gère la position et l’orientation spatiale du robot     | Agrégation                    |

---

## 📐 Diagramme UML

_(Insérer une image du diagramme UML ici)_

Ce diagramme présente :
- les relations d’héritage (flèches),
- les attributs privés `-` et les méthodes publiques `+`,
- la composition (`Robot` possède une liste de `Capteur`),
- l’agrégation avec la classe `Navigation`.

---

## 📁 Arborescence du dépôt
ClasseRobot/ ├── include/ │ ├── capteur.h │ ├── navigation.h │ ├── robot.h │ ├── robotMobile.h │ └── brasRobotique.h ├── src/ │ ├── capteur.cpp │ ├── navigation.cpp │ ├── robot.cpp │ ├── robotMobile.cpp │ └── brasRobotique.cpp ├── main.cpp ├── assets/ │ └── diagramme_UML.png ├── ClasseRobot.md └── README.md


---

## 📎 Exemple de redéfinition de `move()`

```cpp
class Robot {
public:
    virtual void move(double dx, double dy, double dz) = 0;
};

class RobotMobile : public Robot {
public:
    void move(double dx, double dy, double dz) override {
        std::cout << "RobotMobile avance de (" << dx << ", " << dy << ", " << dz << ")\n";
    }
};

---

##  Références pédagogiques
Documentation C++

UML Class Diagram - Guide complet

---
