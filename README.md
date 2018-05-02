# LivoloPi
Control Livolo switches from Raspberry Pi

This is based [LivoloTx](https://github.com/bitlinker/LivoloTx) with modification for using the wiringPi library.

# Remote IDs

Remote ID calculation:
remoteID = 1 + N*3;

Where N is any integer number you choose starting from 0 to 21884 (should not exceed 65535)
Examples: 1,4,7,10,13,...,6400,6403,6406....
Typically remote IDs are 16 bit unsigned value but not all of them are valid.

Keycodes for full size remote:
#1: 0, #2: 96, #3: 120, #4: 24, #5: 80, #6: 48, #7: 108, #8: 12, #9: 72; #10: 40, #OFF: 106
#SCENE1: 90, #SCENE2: 114, #SCENE3: 10, #SCENE4: 18

Keycodes for mini remote:
#A: 8, #B: 16, #C: 56, #OFF (a.k.a #D): 42
