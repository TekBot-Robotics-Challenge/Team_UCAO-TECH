# Programmation orientée objet : Classe Robot

## 🎯 Objectif

Créer une classe `Robot` en programmation orientée objet (C++ ou Python) avec au moins deux sous-classes dérivées. Implémenter une méthode `move()` dans la classe de base, puis la redéfinir dans chaque sous-classe.

---

## 🧠 Détails techniques

- Langage utilisé : Python / C++
- Concepts : Encapsulation, Héritage, Polymorphisme
- Méthodes clés :
  - `move()` redéfinie dans les sous-classes
  - Getters/Setters pour les attributs privés

---

## 📂 Fichiers présents

| Fichier | Rôle |
|--------|------|
| `robot.py` / `robot.cpp` | Classe de base + sous-classes |
| `main.py` / `main.cpp` | Fichier de test |
| `diagramme_UML.png` | Schéma UML de la structure des classes |

---

## 🔧 Structure des classes

- `Robot` (classe mère)
  - Attributs : nom, position, vitesse
  - Méthode : `move()`
- `CleaningRobot` (sous-classe)
  - Ajoute une méthode `clean_area()`
- `DeliveryRobot` (sous-classe)
  - Ajoute une méthode `deliver_package()`

---

## 🖼️ Diagramme UML

![Diagramme UML](../Images/robot_uml.png)

---

## ✅ Résultats attendus

- Création dynamique d’objets de chaque type
- Appel correct de la méthode `move()` redéfinie
- Bonne encapsulation avec getters/setters

---

## 📚 Ressources utiles

- [Python Classes](https://docs.python.org/3/tutorial/classes.html)
- [C++ OOP](https://cplusplus.com/doc/tutorial/classes/)

---

## 👥 Membres contributeurs

- **Nom A** – Programmation des classes
- **Nom B** – UML et documentation
