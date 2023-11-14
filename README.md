# ESP8266-Remote

A remote designed with two buttons for controlling a PowerPoint presentation. Designed by using an ESP8266 to connect to WiFi and interface with a PC running VICREO-Listener to send TCP packets of keyboard commands.

## Required Software

- [Arduino IDE](https://www.arduino.cc/en/software)
- [VICREO-Listener](https://www.vicreo-listener.com/)

## Required Components

- 1x ESP8266 (Preferably a WEMOS D1 Mini) [[1-pc](https://amzn.to/47qK93u)] [[3-pc](https://amzn.to/3QB1Bvx)] [[10-pc](https://amzn.to/3QFJfJE)]
- 1x TP4056 USB-C Charging Board [[1-pc](https://amzn.to/3QFRtSa)] [[3-pc](https://amzn.to/3FZfgYq)] [[10-pc](https://amzn.to/3FVEl6w)]
- 2x 12mm x 12mm momentary switches [[10-pc](https://amzn.to/46sZ7W9)] [[Assorted 250-pc](https://amzn.to/472IL7z)]
- 1x 804040 LiPo 3.7v battery [[1-pc](https://amzn.to/49tzffv)] [[4-pc 1](https://amzn.to/46iOVPz)] [[4-pc 2](https://amzn.to/3syTmrU)]
- 1x on/off switch [[Exact Size](https://amzn.to/47eD1rA)]
- 2x 1N5817 Diodes [[100-pc exact](https://amzn.to/3MDqs0D)] [[Assorted 200-pc](https://amzn.to/47coa0z)]

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
