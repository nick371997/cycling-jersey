# cycling-jersey
A Wearable IoT Device (Jacket/Jersey) made for safety of Cyclist by a Cyclist.

Hello Everyone,

This is the code for a Wearable IoT Jacket/Jersey for Cyclists.
It is a simple device to build and all you need is an arduino or it's Atmel Chipset along with some accelerometers.
I have a custom PCB gerber file which was used on a flexible board somewhere. Hit me up if you need it as well.


Working: 

It works based on gestures and real time interrupts.
The idea is to have LED's on Left, Right and Center (preferably red).
When you give the turn signal using the left hand, the left LED's should blink and viceversa.
The Center LED's should be always ON or should light up when you brake.
Pretty simple!

P.S: Try to use accelerometers without built in gyroscope. If you do use them then don't connect the pins for gyroscope.

I also included a hard code in the adx folder that can be used if you are stuck using library or any issues with setting up interrupts, but that code is archaic.
