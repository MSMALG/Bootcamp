#include <Stepper.h>

// Number of steps per revolution for 28BYJ-48
int stepsPerRevolution = 2048; 
int motorSpeed = 10;
int dt = 500;

//Button code
int buttonPin = 2;
int motorDirection = 1; //clockwise
int buttonState;
int buttonStateOld = 1;
Stepper myStepper(stepsPerRevolution, 9, 11, 10, 12);

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(motorSpeed);   // motor speed in revolution per minute
  pinMode(buttonPin, INPUT);
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  if (buttonStateOld == 1 && buttonState == 0)
  {
    motorDirection = motorDirection * (-1);
  }
  buttonStateOld = buttonState;


  myStepper.step(motorDirection*1);  
}
