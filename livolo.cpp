#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <wiringPi.h>
#include "LivoloTx.h"


/* defaults */
#define LIVOLO_REMOTE_ID 6400
#define LIVOLO_BTN 0
/* WiritngPi pin */
#define TX_PIN 0


void usage()
{
	printf("Arguments:\n");
	printf("  -p <PIN>        - GPIO pin\n");
	printf("  -r <REMOTE>     - Livolo remote id\n");
	printf("  -b <BUTTON>     - Livolo button id\n");
}

int main(int argc, char **argv)
{
	int c;
	int pin = TX_PIN;
	int remote = LIVOLO_REMOTE_ID;
	int btn = LIVOLO_BTN;

	while ((c = getopt(argc, argv, "p:r:b:h")) != -1) {
		switch (c) {
			case 'p':
				pin = atoi(optarg);
				break;
			case 'r':
				remote = atoi(optarg);
				break;
			case 'b':
				btn = atoi(optarg);
				break;
			case 'h':
				usage();
				return 1;
		}
	}

  	if (wiringPiSetup() == -1) {
		perror("wiringPiSetup failed");
		return 1;
	}

	pinMode(pin, OUTPUT);
	LivoloTx gLivolo(pin);

	printf("remote %d button %d\n", remote, btn);
	gLivolo.sendButton(remote, btn);
	return 0;
}
