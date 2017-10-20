//Halloween_Skull.ino

//Switch to PWM, because of tone()

//#include <SoftPWM.h>
unsigned int LED1 = 5;
unsigned int LED2 = 6;
unsigned int speaker = 8;
unsigned int sound = 1000; //frequency for human ears: 2000-5000
unsigned int direction = 1;
unsigned int sounddirection = 10;
unsigned int i = 1;
//unsigned int j = 100;
unsigned int j = 254;

void setup() {
//	SoftPWMBegin();
	pinMode(LED1, OUTPUT); 
	pinMode(LED2, OUTPUT);
}

void loop() {
//	SoftPWMSetPercent(LED1, i);
//	SoftPWMSetPercent(LED2, j);
	analogWrite(LED1, i);
	analogWrite(LED2, j);
	tone(speaker, sound, 5);
	i = i + direction;
//	j = 100 - i;
	j = 254 - i;
	sound = sound + sounddirection;
	if(i == 1) direction = 1;
//	if(i == 100) direction = -1;
	if(i == 254) direction = -1;
	if(sound == 4000) sounddirection = -10;
	if(sound == 2000) sounddirection = 10;
	delay(10);
}


