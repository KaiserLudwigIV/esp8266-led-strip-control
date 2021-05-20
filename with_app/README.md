# Led strip control with a android app

## Setup on esp8266

To have this sketch working in your network simply change the **ssid**, the **pwd** and the **udpPort** to your local network
**(wifi.cpp)**. To define the amount of led pixel and the data pin of your esp8266, change the values **NUM_LEDS** and
**FASTLED_DATA_PIN** **(Led_Cube.h)**. Upload the code to your microcontroller, connect your pins and start playing the modes.

## Setup the app

To setup the app you need to open the project in the MIT App Inventor (http://appinventor.mit.edu/) and build it.
When the app is started it asks for "microphone permission" this permission is used by the music analysis mode. If it wont open up automaticly you need to open the "IP & Port Settings" yourself and put in the IP and the Port of your esp8266 (they get printed in the console of your esp).
