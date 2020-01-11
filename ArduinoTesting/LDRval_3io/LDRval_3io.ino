// THIS IS TO CHECK WORKINGNESS OF 3 LDRs: LDR1, LDR2, LDR3

// INSTRUCTIONS:
// For schematics of the LDR --follow the pic in this folder.


// Connect LDR to Analog pins:  LDR1 TO A1, LDR2 TO A2, LDR3 TO A3.
// Connect LED to Digital PWM Pins(Note this is optional - just to show the intensity of the ldr to output to LED): LED1 TO 9, LED2 TO 10, LED3 TO 11
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

int ldr1Val = map(rawLdr1Val, 50, 550, 0, 1000); //Tested Values are ---     most min (lowest it can get): abt 50-65,      min(covered with finger to top): abt 120,       max (with phone flash direct on it): abt 550-600
int ldr2Val = map(rawLdr2Val, 50, 550, 0, 1000); //Tested Values are ---     most min (lowest it can get): abt 50-65,      min(covered with finger to top): abt 120,       max (with phone flash direct on it): abt 550-600
int ldr3Val = map(rawLdr3Val, 50, 550, 0, 1000); //Tested Values are ---     most min (lowest it can get): abt 50-65,      min(covered with finger to top): abt 120,       max (with phone flash direct on it): abt 550-600

int outputLed1Val = map(ldr1Val, 0, 1000, 0, 255); // Re-map back to show intensity on LED
int outputLed2Val = map(ldr2Val, 0, 1000, 0, 255); // Re-map back to show intensity on LED
int outputLed3Val = map(ldr3Val, 0, 1000, 0, 255); // Re-map back to show intensity on LED

// Show Intensity on LED
analogWrite(led1Pin, outputLed1Val);
analogWrite(led2Pin, outputLed2Val);
analogWrite(led3Pin, outputLed3Val);

Serial.print("rawLDR: ");
Serial.print(rawLdrVal);
Serial.print("____________");
Serial.print("LDR: ");
Serial.print(ldrVal);
Serial.print("____________");
Serial.print("LED: ");
Serial.println(outputLedVal);



}
