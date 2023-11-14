# ESP8266-Remote

A remote designed with two buttons for controlling a PowerPoint presentation. Designed by using an ESP8266 to connect to WiFi and interface with a PC running VICREO-Listener to send TCP packets of keyboard commands.

## Required Software

- [Arduino IDE](https://www.arduino.cc/en/software)
- [VICREO-Listener](https://www.vicreo-listener.com/)

## Required Components

- 1x ESP8266 (Preferably a WEMOS D1 Mini)
- 1x TP4056 USB-C Charging Board
- 2x 12mm x 12mm momentary switches
- 1x 804040 LiPo 3.7v battery
- 1x on/off switch
- 2x 1N5817 Diodes

## Setup

1. Open ESP8266-Remote.ino in Arduino IDE and fill out the following:
	- "ssid" - The name of your WiFi network.
	- "password" - The password to your WiFi network.
	- "serverAddress" - The IP of the computer running PowerPoint/VICREO-Listener
	- "tcpPass" - The MD5 hash of the password you set in VICREO-Listener.
		- You can hash your password [here.](https://www.md5hashgenerator.com/)
2. Connect your ESP8266 to the computer and upload the script to your device.
3. 3D print the included STL files.
4. Solder all the components together using the included diagram (Schematic.png).
5. Assemble and switch on!
