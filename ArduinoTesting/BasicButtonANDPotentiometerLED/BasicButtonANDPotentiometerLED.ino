// There are 2 simple setups
// 1) Push-button (i/p: 2) to light up LED (o/p: 13)
// 2) Potentiometer (i/p: A0) to light up LED (o/p: 9)
//_______________________________________________________________________________

// For Button-LED
const int buttonPin = 2;//the push-button pin
const int ledButtonPin = 13;
int inputButtonVal = 0; //variable to store the value from button
int correctButtonVal = 0;//variable to store the CORRECT value from button - 0 means not pressed, 1 means pressed


// For Potentiometer-LED
const int analogPotentiometerPin = 0;//the analog input pin of potentiometer
const int ledPotPin = 9;
int inputPotVal = 0;//variable to store the analog value coming from potentiometer
int outputLedPotVal = 0;//variable to store the output value (after being mapped to 0-255)
int outputToMax = 0;//variable to store the output value to max - mapped from outputLedPotVal from 0-1000

//_______________________________________________________________________________

void setup()
{

  Serial.begin(9600);//set the serial communication baudrate as 9600

  // For Button-LED
  //configure buttonPin(pin2) as an input and enable the internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledButtonPin, OUTPUT);

}

//_______________________________________________________________________________

void loop()
{
  //__________For Button-LED__________
  inputButtonVal = digitalRead(buttonPin);
  correctButtonVal = !inputButtonVal; // button pressed = 1, not pressed = 0 
  Serial.print("Button: ");
  Serial.println(correctButtonVal);
  // Keep in mind the pull-up means the pushbutton's logic is inverted. It goes
  // HIGH when it's open, and LOW when it's pressed. Turn on pin 13 when the
  // button's pressed, and off when it's not:
  if (inputButtonVal == HIGH) {
    digitalWrite(ledButtonPin, LOW);
  } else {
    digitalWrite(ledButtonPin, HIGH);
    Serial.println("Button pressed");
  }


  //__________For Potentiometer-LED__________
  inputPotVal = analogRead(analogPotentiometerPin);//read the value from the potentiometer
  Serial.print("Input from Potentiometer: ");
  Serial.println(inputPotVal);
  
  //outputLedPotVal = map(inputPotVal, 0, 1023, 0, 255); // Convert from 0-1023 proportional to the number of a number of from 0 to 255
  outputLedPotVal = map(inputPotVal, 0, 656, 0, 255); // Calibrated to 656 - tested max analog reading of potentiometer
  outputToMax = map(outputLedPotVal, 0, 255, 0, 1000); // mapped from 0 to 1000 to be received by max via serial comms

  Serial.print("Output to LED: ");
  Serial.println(outputLedPotVal);
  
  Serial.print("Output to MAX: ");
  Serial.println(outputToMax);
  
  analogWrite(ledPotPin, outputLedPotVal); //tune the brightness of LED according to the potentiometer value



  Serial.println("_________________________"); //print "Output"


  //delay(1000); 
}

//_______________________________________________________________________________
