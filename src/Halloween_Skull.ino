//Halloween_Skull.ino

#include <SoftPWM.h>
unsigned int LED1 = 2;
unsigned int LED2 = 3;
unsigned int direction = 1;
unsigned int i = 1;
unsigned int j = 100;

void setup() {
	SoftPWMBegin();
}

void loop() {
	SoftPWMSetPercent(LED1, i);
	SoftPWMSetPercent(LED2, j);
	i = i + direction;
	j = 100 - i;
	if(i == 1) direction = 1;
	if(i == 100) direction = -1;
	delay(10);
}


