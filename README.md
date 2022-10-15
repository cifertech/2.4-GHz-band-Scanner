<div align="center">

  <img src="https://user-images.githubusercontent.com/62047147/195847997-97553030-3b79-4643-9f2c-1f04bba6b989.png" alt="logo" width="100" height="auto" />
  <h1>2.4GHz band Scanner</h1>
  
  <p>
    Scan 2.4Ghz Band with nRF24
  </p>
  
  
<!-- Badges -->

<a href="https://github.com/cifertech/2.4-GHz-band-Scanner" title="Go to GitHub repo"><img src="https://img.shields.io/static/v1?label=cifertech&message=2.4-GHz-band-Scanner&color=white&logo=github" alt="cifertech - 2.4-GHz-band-Scanner"></a>
<a href="https://github.com/cifertech/2.4-GHz-band-Scanner"><img src="https://img.shields.io/github/stars/cifertech/2.4-GHz-band-Scanner?style=social" alt="stars - 2.4-GHz-band-Scanner"></a>
<a href="https://github.com/cifertech/2.4-GHz-band-Scanner"><img src="https://img.shields.io/github/forks/cifertech/2.4-GHz-band-Scanner?style=social" alt="forks - 2.4-GHz-band-Scanner"></a>
   
<h4>
    <a href="https://twitter.com/cifertech1">TWITTER</a>
  <span> · </span>
    <a href="https://www.instagram.com/cifertech/">INSTAGRAM</a>
  <span> · </span>
    <a href="https://www.youtube.com/c/cifertech">YOUTUBE</a>
  <span> · </span>
    <a href="https://cifertech.net/">WEBSITE</a>
  </h4>
</div>

<br />

<!-- Table of Contents -->
# :notebook_with_decorative_cover: Table of Contents

- [About the Project](#star2-about-the-project)
  * [Pictures](#camera-Pictures)
  * [Features](#dart-features)
- [Getting Started](#toolbox-getting-started)
  * [Schematic](#electric_plug-Schematic)
  * [Installation](#gear-installation)
- [Usage](#eyes-usage)
- [Contributing](#wave-contributing)
- [License](#warning-license)
- [Contact](#handshake-contact)

  

<!-- About the Project -->
## :star2: About the Project
In this project, we will build a 2.4GHz Wlan scanner using the nRF24L01 radio board. In this project, the output delivers all the interference and information in the scanned area in the form of ASCII codes. In the project of making  this scanner, we will use Arduino Nano as a processor. In the second part of this project, we will add an OLED display and display the scanned values in graphs and graphs. With the nRF24 module, we can scan and view the entire 2.4GHz network. This helps us to check the status of the signals in the network.


<!-- Pictures -->
### :camera: Pictures

<div align="center"> 
  <img src="https://user-images.githubusercontent.com/62047147/195984607-278ada2a-f733-4e01-8042-c0e8ac711ee9.jpg" alt="screenshot" />
</div>


<!-- Features -->
### :dart: Features

- Scan 2.4Ghz band
- Show all the Data in Graphs

<!-- Getting Started -->
## 	:toolbox: Getting Started

We will use Arduino Nano as a processor. and we will add an OLED display to show scanned values in graphs. With the nRF24 module, we can scan and view the entire 2.4GHz network.

- Arduino Nano
- nRF24
- Oled 0.96 SSD1306

<!-- Schematic -->
### :electric_plug: Schematic
Make the connections according to the table and schematic below.

* Arduino and nRF24.

| Arduino| nRF24|  
| ----   | -----|
| 9  | CE   |
| 13 | SCK  |
| 12 | MISO |
| 10 | CSN  |
| 11 | MOSI |
| 3V3 | Vcc |
| GND | GND |


* Arduino and OLED display.

| Arduino| Oled 0.96|
| ----   | -----|
| A5  | SCK |
| A4 | SDA  |
| Vin | VDD |
| GND | GND |

 
* Complete Schematic

<img src="https://user-images.githubusercontent.com/62047147/195948711-5e1dd386-0181-4160-b4cd-54e5fbc42589.jpg" alt="screenshot" width="800" height="auto" />


<!-- Installation -->
### :gear: Installation

Before uploading the code you need to install the required library in Arduino IDE. Follow these steps:

- Follow this path Sketch> Include Library> Manage Libraries
- Search for Adafruit SSD1306
- Install the library

-Then search for the “GFX” and install it also.
   
<!-- Usage -->
## :eyes: Usage

After uploading the code, the network scanner starts working automatically and Show the Scanned Data in Graph.


<!-- Contributing -->
## :wave: Contributing

<a href="https://github.com/cifertech/2.4-GHz-band-Scanner/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=cifertech/2.4-GHz-band-Scanner" />
</a>


<!-- License -->
## :warning: License

Distributed under the MIT License. See LICENSE.txt for more information.


<!-- Contact -->
## :handshake: Contact

CiferTech - [@twitter](https://twitter.com/cifertech1) - CiferTech@gmali.com

Project Link: [https://github.com/cifertech/2.4-GHz-band-Scanner](https://github.com/cifertech/2.4-GHz-band-Scanner)


