# Suivi de Projet
Le but de cette section est de résumer les avancées du projet jour par jour.\
Voici un exemple de présentation : 
## Date 
 - **NOM Prénom** : 

 modification/recherche apportée

## 05 Février 2026
- **WOELFFEL Justine** :

Notes de début de séance : https://docs.google.com/document/d/1G-7Qv987tz_3XtQDTyCQzI4an9IfghzEJT-DvZPg25M/edit?usp=sharing

## 11 Février 2026
- **WOELFFEL Justine** :

Affectation des composants : 
    - Condensateur : d'après la datasheet on doit prendre les condensateur en céramique, c'est à dire non-polarisé (- ChatGPT). Ces condensateurs sont les plus classiques donc on ne prend pas trop de risque 
    ChatGPT donne une liste de composant : Capacitor_SMD:C_0603, Capacitor_SMD:C_0805 et Capacitor_SMD:C_1206
    Le plus utile est le 0805 **de plus** d'après le TD Projet ce sont celles qu'on a utilisée
    On prend donc : **Capacitor_SMD:C_0603** 
    - Mountingholes : on utilise les même qu'en TD
    - Resistences et LED : tout en 0603 HandSolder comme vu en TD
    - STM : Originellement on avait 
    STM32C092FCP6 : SOP65P640X120-20N
    Pour trouver l'affectation on a va p.120 (Ordering information) de la DataSheet pour regarder : STM32C092**FCP**6
    - Bouton poussoir : ChatGPT


!(image1)[C:\Users\justi\OneDrive\Belgeler\Dossier_GIT\Projet1A_FS\Image]



pour le reste j'ai tout mis en 0805 car apparement c'est les trucs de débutants 

on avait : STM32C092FCP6 : SOP65P640X120-20N j'ai donc remplacé le SOP65P640X120-20N par le Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm
pour ça on regarde 7 Ordering information p.120 et on lit les lettres STM32C092FCP6




