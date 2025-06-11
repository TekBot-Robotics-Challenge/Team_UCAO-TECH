# Test 1 – CAO Niveau Débutant (SolidWorks)

---

## Objectif

Ce test évalue nos compétences de base en **Conception Assistée par Ordinateur (CAO)** à travers l’usage de SolidWorks. Il s’agit de créer, à partir de croquis cotés, un ensemble de pièces 3D fonctionnelles, respectant les contraintes de matériau, de masse et de géométrie, puis de réaliser un **assemblage mécanique fonctionnel** avec calcul du centre de gravité.

---

## Pièces modélisées

Nous avons conçu quatre pièces individuelles à partir de croquis 2D, en utilisant les outils de base du logiciel.

### Méthodologie utilisée

- **Croquis 2D** : Rectangles, cercles, polygones, lignes construites.
- **Fonctions 3D** : 
  - Bossage/base extrudée
  - Enlèvement de matière
  - Congés (rayons)
  - Symétrie
- **Contraintes de croquis** : Horizontale, verticale, tangente, coïncidente, symétrie.
- **Système d’unité** : MMGS (mm, gramme, seconde)
- **Décimales** : 2 chiffres après la virgule
- **Trous** : Tous débouchants sauf mention contraire

### Détails des pièces

| Pièce   | Matériau                 | Densité (g/mm³) | Masse obtenue | Masse attendue | Écart |
|---------|--------------------------|------------------|----------------|------------------|--------|
| Pièce 1 | Acier AISI 1020          | 0.0079           | —             | —               | —     |
| Pièce 2 | Aluminium 1060           | 0.0027           | —             | —               | —     |
| Pièce 3 | Acier AISI 1020          | 0.0079           | —             | —               | —     |
| Pièce 4 | Aluminium 1060           | 0.0027           | —             | —               | —     |

> Les masses ont été vérifiées avec l'outil de calcul intégré à SolidWorks, avec une tolérance cible de ±5 %.

---

## Assemblage Mécanique

Nous avons assemblé les quatre pièces pour former une **pince mécanique**, conformément aux spécifications techniques.

### Contraintes d’assemblage appliquées

- Alignement axial entre pièces mobiles
- Coincidence entre surfaces de fixation
- Blocage ou dégagement selon la position du vérin

### Centre de Gravité

Le centre de masse du système a été déterminé dans deux configurations :
- **Position minimale du vérin**
- **Position maximale du vérin**

Les coordonnées ont été extraites via l’outil `Propriétés du centre de masse` de SolidWorks. Les variations ont été analysées pour évaluer la stabilité du système.

---

## Problèmes rencontrés & solutions

- **Tolérance de masse difficile à respecter** → Ajustement précis des cotes + vérification des matériaux attribués
- **Contraintes d’assemblage conflictuelles** → Utilisation de l’outil de diagnostic pour identifier les erreurs
- **Détermination du centre de gravité ambiguë** → Manipulation des outils de masse + documentation officielle SolidWorks

---

## Outils et ressources

- **Logiciel** : SolidWorks 2021 ou version ultérieure
- **Fonctions utilisées** : Croquis 2D, extrusion, symétrie, assemblage
- **Mesures** : Masse, centre de gravité, propriétés physiques
- **Tutoriels** : Manuels SolidWorks, ressources vidéos

---

## Conclusion

Ce test a permis de valider notre capacité à :
- Modéliser des pièces mécaniques précises
- Appliquer des matériaux et contraintes fonctionnelles
- Réaliser un assemblage réaliste sous contraintes
- Évaluer des propriétés comme la masse et le centre de gravité

Ce projet constitue une base solide pour des conceptions mécaniques plus complexes dans le cadre du TRC2K25.

---
