# Projet1A_FS
Bienvenu sur le dépot GitHub d'un des groupes de Projet de première année de l'ENSEA. \
Participants du projet : \
BALLARD Athénaïs&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;NOICI Amélie\
EL GAAMOUCH Aïssa&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;VENTURA Arthur\
ELICE Bastien&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;WOELFFEL Justine\
GERVAIS Joseph

Professeur encadrant : M.TAUVEL

## Dossiers utiles :
Régulateur de tension datasheet : https://www.alldatasheet.com/datasheet-pdf/view/807123/TI1/LM1117DT-3.3.html

Comment éditer un fichier GitHub : https://docs.github.com/fr/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax

Tutoriel de conception de PCB : https://jak-services.github.io/fr/tutorial_kicad_9_build_your_first_pcb.html

:warning: ***Remplir le fichier Suivi de projet.md à la fin de chaque séance !***

## Description du projet: 

Ce projet a pour objectif de réaliser des composants utiles au bon fonctionnement d'une monoplace dans le cadre du concours **FORMULA STUDENT**. Un de ces composants est lui tiré du concours **PERSEUS**. 
 
Le projet se concentre sur la conception et la fabrication de 3 PCB:
 
- Un capteur d'**Odométrie** : il calcule la vitesse de rotation des roues de la voitures et la transmet au bus CAN. 

- Un capteur **ToF** (Time of flight) : il calcule les distances par rapport aux objets environnants et doit pouvoir assurer un arrêt de sécurité. 

- Un **Datalogger**:  il récupère les données du bus CAN en temps réel et les stock dans un carte SD, qui servira de "boîte noire" en cas de destruction de l'appareil. Il sera également doté d'une application codée en Java (référence à notre super cours de **programmation orientée objet**) afin d'avoir une interface graphique utile à la conduite.

## Rôles

| Chef de projet | Odométrie | Datalogger | Software | 
| :---: | :---: | :---: | :---: |
| Justine | Athénaïs \ Arthur | Aïssa \ Joseph | Amélie \ Bastien |

## Odométrie Spécifications : 

### Composants nécessaires + Datasheet : 

* Microcontrôleur: STM32C092FCP6 (code : 4676916 - Farnell)

* Régulateur de tension : (code : 197-7195P - RS)

* Connecteur USB : 

* 4 connecteurs d'entrée/sortie :

* 2 boutons poussoir : Interrupteur tactile traversant (code : 682-1254 - RS)

* 2 LED (LED de fonctionnement et de test) : (code : 466-3863 - RS)

## Datalogger Spécifications : 

### Composants nécessaires + Datasheet : 

* Microcontrôleur : STM32F042F6P6 (code : 2469549 - Farnell)

* 2 Régulateur de tension : Regulateur 3.3V (code : 197-7195P - RS) Régulateur 5.0V (code : 2534281 - Farnell)

* 4 connecteurs d'entrée/sortie : 

* 3 boutons poussoir : Interrupteur tactile traversant (code : 682-1254 - RS)

* 2 LED (LED de fonctionnement et de test) : LED CMS  (code : 466-3863 - RS)