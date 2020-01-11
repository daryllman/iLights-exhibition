// INSTRUCTIONS:
// For schematics of the LDR --follow the pic in this folder.
// Connect LDR to Analog pin A1
// Connect LED to Digital PWM Pin 3 (Note this is optional - just to show the intensity of the ldr to output to LED)


const int ldrPin = A1;
const int ledPin = 3; // Use pins 3,5,6,9,10,11 only for digital pwm analog o/p


void setup() {

Serial.begin(9600);

pinMode(ldrPin, INPUT);
pinMode(ledPin, OUTPUT);

}

void loop() {

int rawLdrVal = analogRead(ldrPin);

int ldrVal = map(rawLdrVal, 50, 550, 0, 1000); //Tested Values are ---     most min (lowest it can get): abt 50-65,      min(covered with finger to top): abt 120,       max (with phone flash direct on it): abt 550-600

int outputLedVal = map(ldrVal, 0, 1000, 0, 255); // Re-map back to show intensity on LED

analogWrite(ledPin, outputLedVal);

Serial.print("rawLDR: ");
Serial.print(rawLdrVal);
Serial.print("____________");
Serial.print("LDR: ");
Serial.print(ldrVal);
Serial.print("____________");
Serial.print("LED: ");
Serial.println(outputLedVal);



}
