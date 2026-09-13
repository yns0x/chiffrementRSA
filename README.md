   ```powershell
;lc  'l; ...clllllllllllllllllllc,:l;'. .........',;:ccllllllllllllllllc..'cllllll,c.  .,cl,.               .
      ..',;' .,. ;cllllllllllllllllllllllc,..                 ........',;;::cc..,cllllllc,c   .:lc;..
      .     .  .,clllllllllllllllllllllc;.            .                         ...,:::cc,;  .'llccc;'.
      ..','....  .;llllllllllllllllllc;........'',;:::;,,::::cccccccccccc::..;;;,'.... ....  .,clllllc:.
      ...cclllc:'. ':lllllllllllllllc,,,;;;;;;;,;:;;,',;;;,,;;::ccclllllc,.;cllllllllcc;..    ';cccllll.
       ..,cccccccc:..':lllllllllllllcccc:cc:;''',;:c;'..',,,;;,,,,''''...,clcllllllllllc'.   'cclllllcl. .
       .'..';::cc:::..,,clllllllllllllllc:;:clc::;:cc,.,;clllllllllll;;;::;;;;:ccllllll:,    clllllllll. .c
       .,. .clllllllc',;;:lllllllllllll:;cllll::;::;..';::::::;:;;:::ccclllllccc:ccclll;'   ;lllllllll: .;c',.
       ',...',,.',;:::'.,,,clllllllllllclllllc:;:c:: .,,,;;;;;;;;;:::cccllccclllllllllc;.  ;lllllllllc'..c'clc.
       .'..'','........ ...:lllllllllllllllll::clc;.          ............. .''''',;::;:  'llllllllllc .,,:lllc.
.     .',lO0OOkOOxcc::.  'cllllllllllllllllcclc;'.. .cdkkkxxxddoo;'.....'coloooodkkx:'' .cllllllllll'..,:lllll;' .
.     '...0KKKKKd',;;,,'..clc::cllllllllllllllcc;.,c0KKKKKKKKKKKd.,;;;;;;'xKKKK0Oxl;;; ':llllllllll:  .;lllllll,  '.
.    .   '0KKKKO,';;;,.....',:cllllllllll::cllll;clo:;codxxxxkkO'';;;;;,..lkxoc'..';c..cllllllllllc.  ;llllllllc.  .
.   :ooooc. .. ..,;;'....,:clllllllcc::,;;;:cc:.....      .   .     .....,::c:..cllllllllllc.  ;llllllllll;
.     .''............ .;;;...   . .',;:::cclllllcc:::clcc:;::;:;..'''''',;;;;;:cclc,.,cllllllllllc.  :llllllllllc.
.,.,'''..   .. ......          ..  .  .....':cllllllllllllccccccllllllllllc;..clllllllllllc. .:lllllllllc...   .
.  .,.''.. ....',.,,....          ..... ..       ..',;;::clllllllllllllllllllc'.'clllllllllll:. .:llllllllc'    . ...
. .:.':.  ..,;cllllllllc,,      ......                     ...',,:lllllllllll;.:lllllllllllc,. ,clllllllc,.   .:c. ..
.',','  .,cllllllllllllllc;          ......'',,,,'............':clllllllllllcclllllllllll:..'clllllllll:.   .'cllc.
. .'..'..:lllllllllllllllllll:' ....,;cllllcllllllllllllcllllclllllllllllllllllllllllllllc',';lllllllll;.   .'lllll
   ```
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