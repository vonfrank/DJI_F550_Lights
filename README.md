# DJI F550 lights

This is a small C++ program to use on Arduino boards. The main purpose is to control lights, with a switch on your RC transmitter. Arduino Nano has been used for lightning controller, FrSky Taranis X9D+ transmitter, HKPilot32 with Arducopter, and FrSky X8R reciever as other pheripials.

## Dependencies
Keyes Wearable 2812 full color 5050 RGB LED modules has been used as lightsource. The WS2812 control board, requires Adafruit Neopixel library, which is places inside the package. Move this to your library folder, and you are ready to go.

## In- and output pins
* **PIN02** - has been used as the PWM input channel, connected to an output channel on your reciever
* **PIN07** - is a LED output channel
* **PIN08** - is a LED output channel
* **PIN09** - is a LED output channel

## Functions
For now 3 modes have been implemented, which has been assigned to a 3-pos switch on the Taranis.
* **Off** - is a mode where all LEDs are turned off
* **PosHold** - is a mode for the Arducopter PosHold mode, which makes the front LEDs on the F550 green, the middle as a white strobe/beacon, and the back as a red tail light
* **RTL** - another mode for the Arducopter, but when the drone is returning to launch. All LEDs is red strobes/beacon lights, to alert the drone is in autoland mode

More functions to be implemented.