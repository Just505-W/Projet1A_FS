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

Le plus utilisé est le 0805 **de plus** d'après le TD Projet ce sont celles qu'on a utilisée
    
On prend donc : **Capacitor_SMD:C_0603** 
    
- Mountingholes : on utilise les même qu'en TD
    
- Resistances et LED : tout en 0603 HandSolder comme vu en TD
    
- STM : Originellement on avait 
    
STM32C092FCP6 : SOP65P640X120-20N
    
Pour trouver l'affectation on a va p.120 (Ordering information) de la DataSheet pour regarder : STM32C092**FCP**6

![image1](https://github.com/Just505-W/Projet1A_FS/blob/main/Image/image1.png)

On peut donc mettre comme affectation : Package_SO:TSSOP-20_4.4x6.5mm_P0.65mm

- Bouton poussoir : ChatGPT

## 12 Février 2026

- **NOICI Amélie** :

Finalisation du schéma kikad, rajout d'un deuxième régulateur de tension car problème de tension d'entrée:
![image1](https://github.com/Just505-W/Projet1A_FS/blob/main/Image/Datalogger_kikad_sch.png)

## 19 Février
- **Avancement global**

<ins> Datalogger</ins> : Le PCB est agencé, on doit encore vérifier certaines empreintes, on a trouvé les boutons au labo (on les a réservés), le routage est en cours. Les empreintes en commun avec le groupes d'Alain on été choisies (Le groupe d'Alain s'adaptera au notre)  
Seule note d'Alain : choisir JST qui empêchent la deconnexion (JST AM - il me semble)




