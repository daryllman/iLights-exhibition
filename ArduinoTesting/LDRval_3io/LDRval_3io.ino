// THIS IS TO CHECK WORKINGNESS OF 3 LDRs: LDR1, LDR2, LDR3

// INSTRUCTIONS:
// For schematics of the LDR --follow the pic in this folder.


// Connect LDR to Analog pins:  LDR1 TO A1, LDR2 TO A2, LDR3 TO A3.
// Connect LED to Digital PWM Pins(Note this is optional - just to show the intensity of the ldr to output to LED): LED1 TO 9, LED2 TO 10, LED3 TO 11

// Calibrate the LDR values.
// find the min and max ranges and update accordingly
//_______________________________________________

// LDR PINS
const int ldr1Pin = A1;
const int ldr2Pin = A2;
const int ldr3Pin = A3;


// LED PINS
// Use pins 3,5,6,9,10,11 only for digital pwm analog o/p
const int led1Pin = 9;
const int led2Pin = 10;
const int led3Pin = 11;

//CALIBRATION
//Tested Values are ---     most min (lowest it can get): abt 5-20,      min(covered with finger to top): abt 20,       max (with phone flash direct on it): abt 450-500
int minLdr1 = 15; 
int maxLdr1 = 450;

 //Tested Values are ---     most min (lowest it can get): abt 45-80,      min(covered with finger to top): abt 95-105,       max (with phone flash direct on it): abt 500-600
int minLdr2 = 80;
int maxLdr2 = 500;

//Tested Values are ---     most min (lowest it can get): abt 50-80,      min(covered with finger to top): abt 100-120,       max (with phone flash direct on it): abt 550-650
int minLdr3 = 80;
int maxLdr3 = 550;




//_______________________________________________




void setup() {

Serial.begin(9600);

pinMode(ldr1Pin, INPUT);
pinMode(ldr2Pin, INPUT);
pinMode(ldr3Pin, INPUT);

pinMode(led1Pin, OUTPUT);
pinMode(led2Pin, OUTPUT);
pinMode(led3Pin, OUTPUT);

}

void loop() {

int rawLdr1Val = analogRead(ldr1Pin);
int rawLdr2Val = analogRead(ldr2Pin);
int rawLdr3Val = analogRead(ldr3Pin);

// Normalise to be postitive (sometimes values will be below threshold for some reason - cant allow this to happen)
if (rawLdr1Val < minLdr1) { rawLdr1Val = minLdr1; }
if (rawLdr2Val < minLdr2) { rawLdr2Val = minLdr2; }
if (rawLdr3Val < minLdr3) { rawLdr3Val = minLdr3; }

int ldr1Val = map(rawLdr1Val, minLdr1, maxLdr1, 0, 1000); 
int ldr2Val = map(rawLdr2Val, minLdr2, maxLdr2, 0, 1000); 
int ldr3Val = map(rawLdr3Val, minLdr3, maxLdr3, 0, 1000); 

int outputLed1Val = map(ldr1Val, 0, 1000, 0, 255); // Re-map back to show intensity on LED
int outputLed2Val = map(ldr2Val, 0, 1000, 0, 255); // Re-map back to show intensity on LED
int outputLed3Val = map(ldr3Val, 0, 1000, 0, 255); // Re-map back to show intensity on LED

// Show Intensity on LED
analogWrite(led1Pin, outputLed1Val);
analogWrite(led2Pin, outputLed2Val);
analogWrite(led3Pin, outputLed3Val);

Serial.print("rawLDR1: ");
Serial.print(rawLdr1Val); 
Serial.print(" | ");
Serial.print("LDR1: ");
Serial.print(ldr1Val);
Serial.print(" | ");
Serial.print("LED1: ");
Serial.print(outputLed1Val);
Serial.print("____________");

Serial.print("rawLDR2: ");
Serial.print(rawLdr2Val); 
Serial.print(" | ");
Serial.print("LDR2: ");
Serial.print(ldr2Val);
Serial.print(" | ");
Serial.print("LED2: ");
Serial.print(outputLed2Val);
Serial.print("____________");

Serial.print("rawLDR3: ");
Serial.print(rawLdr3Val); 
Serial.print(" | ");
Serial.print("LDR3: ");
Serial.print(ldr3Val);
Serial.print(" | ");
Serial.print("LED3: ");
Serial.print(outputLed3Val);
Serial.println("____________");



}
