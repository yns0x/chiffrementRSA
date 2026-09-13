# Chiffrement RSA en C

Projet personnel pour mieux comprendre l'utilisation de C pour les commandes systèmes + le chiffrement RSA.

## Installation

Pour tester ce projet faites les commandes suivantes :
   ```powershell
   git clone https://github.com/yns0x/chiffrementRSA
   cd chiffrementRSA/cmake-build-release
   ./chiffrementRSA.exe --gen
   ```

## Utilisation

Le programme s'utilise en ligne de commande avec les arguments suivants :

| Option | Description | Exemple |
| :--- | :--- | :--- |
| `--gen` | Génère et affiche une paire de clés (privée et publique). | `chiffrementRSA.exe --gen` |
| `--encrypt` | Chiffre un message numérique avec une clé publique `(e,n)`. | `chiffrementRSA.exe --encrypt 42 "(5,3911)"` |
| `--decrypt` | Déchiffre un message avec une clé privée `(d,n)`. | `chiffrementRSA.exe --decrypt 1234 "(1285,3911)"` |

## Exemples d'utilisation

1. **Générer les clés :**
   ```powershell
   .\chiffrementRSA.exe --gen
   ```

2. **Chiffrer un message (ex: `42`) :**
   ```powershell
   .\chiffrementRSA.exe --encrypt 42 "(5,3911)"
   ```

3. **Déchiffrer un message :**
   ```powershell
   .\chiffrementRSA.exe --decrypt 1234 "(1285,3911)"
   ```

## Structure du projet

- **`main.c`** : Point d'entrée du programme et gestion des arguments de la ligne de commande.
- **`utils.c`** : Implémentation des fonctions mathématiques (tests de primalité, algorithme d'Euclide étendu, exponentiation modulaire) et du menu ASCII.
- **`utils.h`** : Définition des structures (`Secret`, `ClePublique`, `ClePrivee`) et prototypes des fonctions.