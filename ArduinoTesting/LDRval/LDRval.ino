
const int ldrPin = A1;

void setup() {

Serial.begin(9600);

pinMode(ldrPin, INPUT);

}

void loop() {

int ldrVal = analogRead(ldrPin);
Serial.println(ldrVal);


}
