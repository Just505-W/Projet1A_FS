# Qu’est-ce qu’un _data logger bus CAN_ ?

Un **data logger bus CAN** est un **enregistreur de données** qui permet de :

> **lire, enregistrer, analyser et stocker les messages circulant sur un bus CAN.**

# Rappel rapide : qu’est-ce que le bus CAN ?

**CAN = Controller Area Network**

C’est un **bus de communication série industriel** très utilisé
👉 Il permet à **plusieurs calculateurs (ECU)** de communiquer entre eux sur **2 fils seulement**

- CAN_H
    
- CAN_L

# Qu’est-ce qu’un data logger ?

Un **data logger** est un appareil qui :

- **mesure**
    
- **enregistre**
    
- **stocke**
    

des données **dans le temps** pour :

- analyse
    
- diagnostic
    
- validation
    
- maintenance
# Choix du microcontrôleur

**caractéristiques :**
- 16 broches 
- contrôleur CAN
- interface SD

## Puissance de calcul suffisante

Typiquement :

- fréquence ≥ **48 MHz**
    
- architecture **32 bits**
    

Ex :

- ARM Cortex-M

## Interfaces disponibles

Indispensables :

✔ CAN  
✔ SPI (carte SD)  
✔ UART / USB  
✔ I²C (RTC, capteurs)

## D. Mémoire suffisante

- Flash ≥ **128 kB**
    
- RAM ≥ **32 kB**
    

Pour :

- buffers CAN
    
- stockage temporaire

# Recherche de Chip

On utilise le product selector de chez ST pour trier par boitier (dans lequel le nombre de broche est indiqué), puis on regarde si il est disponible chez les fournisseurs. "QFP16" à rechercher dans la catégorie package ou en tout cas "FP16".

On utilisera un STM32F042F6U6

# Liste de composant : 

- MCU : STM32F042F6P6
- Interface Bus CAN : Transceiver TJA1050T; Connecteur DB9 Femelle
- Alimentation : Régulateur MCP1700-3.3V, Connecteur JST PH 2 pins
- Stockage (carte SD) : Connecteur microSD Push-Push (JAE ST12)
### 3.1. Bloc Alimentation

- Placez le **connecteur batterie** (JST PH 2 pins)
    
- Placez la **diode Schottky** (protection anti-retour)
    
- Placez le **régulateur LDO 3.3V**
    
- Placez les **condensateurs** (10µF entrée, 10µF + 100nF sortie)
    
- **Nommez les nets** : `+BATT`, `+3V3`, `GND`
###  3.2. Bloc STM32F042F6P6 (TSSOP20)

- Placez le symbole du µC
    
- **Brochage critique à vérifier** :
    
    - `VDD` (pin 5) → `+3V3`
        
    - `VSS` (pin 4) → `GND`
        
    - `VDDA` (pin 1) → `+3V3` (via une inductance ou direct + condo 100nF vers GND)
        
    - `VSSA` (pin 20) → `GND`
        
    - `BOOT0` (pin 14) → `GND` via résistance 10kΩ (pull-down)
        
    - `NRST` (pin 3) → bouton + pull-up 10kΩ vers `+3V3`
        
- **Découplage** : Placez un condensateur **100nF** entre chaque pin VDD/VSS au plus près du µC. Ici, vous en avez besoin d'au moins 2.
### 3.3. Bloc Interface CAN

- Placez le **transceiver CAN** (ex: TJA1050)
    
    - Broche `VCC` → `+3V3`
        
    - Broche `GND` → `GND`
        
    - Broche `TXD` → broche GPIO du STM32 (ex: PA9 ou PA11 selon datasheet)
        
    - Broche `RXD` → broche GPIO du STM32 (ex: PA10 ou PA12)
        
    - Broche `CANH` → connecteur DB9 pin 7
        
    - Broche `CANL` → connecteur DB9 pin 2
        
- Placez le **connecteur DB9** (trouvez-le dans bibliothèque `Connector` : `DB9_Female`)
    
- Placez la **résistance 120Ω** entre `CANH` et `CANL` **avec un cavalier ou un strap** (sélectionnable)
    
- **Protection ESD** : Placez un composant de protection (bidirectionnel) entre `CANH`/`GND` et `CANL`/`GND`

### 3.4. Bloc Carte microSD

- Placez le **connecteur microSD Push-Push** (bibliothèque `Connector_SD` : `microSD_HC`)
    
- **Câblage SPI** :
    
    - `CS` → broche GPIO (ex: PA4)
        
    - `SCK` → broche GPIO (ex: PA5)
        
    - `MOSI` → broche GPIO (ex: PA7)
        
    - `MISO` → broche GPIO (ex: PA6)
        
- **CRITIQUE** : Placez des **résistances de pull-up 10kΩ** sur les lignes `CS`, `SCK`, `MOSI`, `CD` (Card Detect). La broche `MISO` est souvent en entrée, elle n'en a pas besoin.
    
- **Alimentation** : Reliez `VDD` du connecteur à `+3V3` avec un condo 100nF à côté
### 3.5. Bloc Programmation/Debug (SWD)

- Résultat positif : Plusieurs dépôts proposent des **symboles et footprints pour connecteurs SWD** [](https://git.cryptech.is/user/shatov/alpha_rev04/blame/KiCAD/footprints.pretty/PLS-6.kicad_mod?id=e08dc0de68ed2b159a06eca81da5c9b1450830b0)[](https://gist.github.com/glmoritz/Kicad-STM32)[](https://github.com/piit79/Kicad-STM32).
    
- Placez un **connecteur 4 pins** (ex: `PinHeader_1x04_P2.54mm`)
    
- **Câblage** :
    
    - Pin 1 : `+3V3`
        
    - Pin 2 : `SWDIO` (broche PA13 sur STM32F042)
        
    - Pin 3 : `SWCLK` (broche PA14)
        
    - Pin 4 : `GND`
        
- **Résistance de pull-up** : 10kΩ sur `SWDIO` (optionnelle mais recommandée)
    
- **Résistance de pull-down** : 10kΩ sur `SWCLK` (optionnelle)