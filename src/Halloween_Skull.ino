//Halloween_Skull.ino

//Switch to PWM, because of tone()

#define rightEye 5
#define leftEye 6
#define speaker 8
#define trigger 12 //3
#define echo 13 //4

//unsigned int sound = 1000; //frequency best for human ears: 2000-5000
//unsigned int direction = 1;
//unsigned int sounddirection = 10;
unsigned int i = 1;
unsigned int j = 254;
int distance = 0;
boolean is_on = false;

//long distance = 0;
//long timeT = 0;

void setup() {
	pinMode(rightEye, OUTPUT); 
	pinMode(leftEye, OUTPUT);
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
	digitalWrite(trigger, HIGH); //Signal abschalten
	Serial.begin(9600); 
	Serial.print("It's Halloween!\n");
	Serial.print("Here you see the distance in cm!\n");
}

void loop() {
	// analogWrite(rightEye, i);
	// analogWrite(leftEye, j);
	// tone(speaker, sound, 5);
	// i = i + direction;
	// j = 254 - i;
	// // sound = sound + sounddirection;
	// if(i == 1) direction = 1;
	// if(i == 254) direction = -1;
	// // if(sound == 4000) sounddirection = -10;
	// // if(sound == 2000) sounddirection = 10;
	
	delay(50);
	distance = getDistance();
	Serial.print("Distance: ");
	Serial.println(distance, DEC);
	if (distance < 75) {
		if (is_on == false) {
			flash();
		}
	}
	if (distance > 75) {
		if (is_on == true) {
		dimm();
		}
	}

}

// get distance via sensor in centimeters
int getDistance(){ 
	long distance = 0;
	long timeT = 0;
	digitalWrite(trigger, LOW); 
	delayMicroseconds(3);
	noInterrupts();
	digitalWrite(trigger, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigger, LOW); 
	timeT = pulseIn(echo, HIGH);
	interrupts();
	Serial.print("Time: ");
	Serial.println(timeT, DEC);
	distance = (timeT / 2) * 0.03432;
	return(distance);
}

// flash eyes from very dark to full quickly
void flash() {
	for(int i = 5; i < 256; i++) {
		analogWrite(rightEye, i);
		analogWrite(leftEye, i);
		delay(3);
	}
	is_on = true;
}

// dim eyes back to very dark
void dimm() {
	for(int i = 256; i > 5; i--) {
		analogWrite(rightEye, i);
		analogWrite(leftEye, i);
		delay(5);
	}
	is_on = false;
}