// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley (mikem@open.com.au)
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $

#include <bcm2835.h>

int pinArray[]={4,18,23,24,8,10,9,11,17};
int count =0;
int timer=400;
int i = 0;

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
//    bcm2835_set_debug(1);

    if (!bcm2835_init())
	return 1;

    // Set the pin to be an output
	for (count=0;count<9;count++) {    
	bcm2835_gpio_fsel(pinArray[count], BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_write(pinArray[count], LOW);
	}
    // Blink
	while (1)
	{
		for (count = 0; count < 9; count++) {
			// Turn it on
			bcm2835_gpio_write(pinArray[count], HIGH);

			// wait a bit
			delay(timer);

			// turn it off
			bcm2835_gpio_write(pinArray[count], LOW);

			// wait a bit
			delay(timer);
		}
		for (count = 0; count < 9; count++) {
			bcm2835_gpio_write(pinArray[count], HIGH);
		}
		for (count = 0; count < 9; count++) {
			// Turn it off
			bcm2835_gpio_write(pinArray[count], LOW);

			// wait a bit
			delay(timer);

			// turn it on
			bcm2835_gpio_write(pinArray[count], HIGH);

			// wait a bit
			delay(timer);
		}
		for (i = 0; i < 10; i++) {
			for (count = 0; count < 9; count++) {
				bcm2835_gpio_write(pinArray[count], LOW);
			}
			delay(timer);
			for (count = 0; count < 9; count++) {
				bcm2835_gpio_write(pinArray[count], HIGH);
			}
			delay(timer);
		}
	}
    return 0;
}

