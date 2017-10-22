//Halloween_Skull.ino

#define rightEye 5
#define leftEye 6
#define speaker 8
#define trigger 12
#define echo 13

unsigned int i = 1;
unsigned int j = 254;
int distance = 0;
boolean is_on = false;

void setup() {
	pinMode(rightEye, OUTPUT); 
	pinMode(leftEye, OUTPUT);
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
	digitalWrite(trigger, HIGH);
	Serial.begin(9600); 
	Serial.print("It's Halloween!\n");
	Serial.print("Here you see the distance in cm!\n");
}

void loop() {

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
	// Serial.print("Time: ");
	// Serial.println(timeT, DEC);
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