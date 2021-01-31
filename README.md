# LED Treasure Hunt

*In LED Treasure Hunt you are searching for the long lost treasure of the pirates.*

But you have to be prepared with the following tools, to go on this journey:

- an ESP8266 controller
- a mechanical input device, in my case an emergency stop button
- a led controller for addressable leds. ideal with a direct web socket server like in my case, I used the PixelBlaze V2, designed and sold by Ben Hencke. [Ben Henckes Site](https://www.bhencke.com/pixelblaze)

But be patient. After you picked up your tools, you will need a bit of study to start the hunt:

- first go to the file /treasure-led-button/ and insert your personal information of the controller and your wlan.

```c++
#define IP_LED "YOUR-LED-CONTROLLER-IP-HERE"
#define PORT_LED "YOUR-LED-CONTROLLER-WEBSOCKET-PORT-HERE"
#define ssid "YOUR-WLAN-ID"
#define wlan-password "YOUR-WLAN-PW"
```
After that, transfer this file to your ESP8266 with your choice of IDE. For example you can use the Arduino IDE or like me, the VS Code IDE with several plugins.

-second please import the pattern file from /tresure-led-pixelblaze/led-treasure-game.epe to your pixelblaze controller

And now, after you configured all of your tools, you can start!

after powering everything with any kind of power source, the game will start by starting the led, hunting for the treasure. With a hit on the button, you will search on the special spot for the treasure. 

If you found it, you will get pleasured with the complete stripe blinking and starting a new game after a few seconds.

If you not hitted the right spot, you will get an indication, how far you are from the real treasure spot. The more LEDs are lightning up, the further you are away from the tresure. but be aware, with every far away search, your led searcher gots unpatiened and will speed up. Then you should search just for near by spots, because it will raise up your chance of hitting and also slows down the searcher again.

Have fun. I hope you enjoy it, even you need a bit of hardware to play. :-)