
#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                            // Declare right servo signal

int PIEZOPIN = 5;                            // Declare pin that the piezo is connected to.
// DECLARE LED PINS HERE

// One octave of notes between A4 and A5, for Piezo Greeting
int note_A4 = 440;
int note_As4 = 466; int note_Bb4 = note_As4;
int note_B4 = 494;
int note_C5 = 523;
int note_Cs5 = 554; int note_Db5 = note_Cs5;
int note_D5 = 587;
int note_Ds5 = 622; int note_Eb5 = note_Ds5;
int note_E5 = 659;
int note_F5 = 698;
int note_Fs5 = 740; int note_Gb5 = note_Fs5;
int note_G5 = 784;
int note_Gs5 = 830; int note_Ab5 = note_Gs5;

void setup()
{
  pinMode(PIEZOPIN, OUTPUT);                 // Attach piezo to pin 5.
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12
  servoLeft.writeMicroseconds(1490);        // Calibrate left servo
  servoRight.writeMicroseconds(1490);       // Calibrate right servo
  // Attach LED pins here.
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);

}

void loop()
{
  // Code for testing servos.
  // Tinker with the numbers to see how they work!
  // For help, visit https://learn.parallax.com/tutorials/robot/shield-bot/robotics-board-education-shield-arduino/chapter-2-shield-lights-servo-4.
  int speedOfCar = 200;
  int seconds = 2;
//  forward(seconds,speedOfCar);
//  delay(1000);
//  backward(seconds,speedOfCar);
//  delay(1000);
  turnRight();
  turnLeft();
  delay(6000);
}

void forward(int seconds, int speedOfCar){
  int leftSpeed = 1490+speedOfCar;
  int rightSpeed = 1490-speedOfCar;
  servoLeft.writeMicroseconds(leftSpeed);
  servoRight.writeMicroseconds(rightSpeed);
  delay(seconds*1000);
  servoLeft.writeMicroseconds(1490); // Stop
  servoRight.writeMicroseconds(1490);
}

void backward(int seconds, int speedOfCar){
  forward(seconds,0-speedOfCar);
}

void turn(int speedOfCar){
  int leftSpeed = 1490+speedOfCar;
  int rightSpeed = 1490+speedOfCar;
  servoLeft.writeMicroseconds(leftSpeed);
  servoRight.writeMicroseconds(rightSpeed);
  delay(1000);
  servoLeft.writeMicroseconds(1490); // Stop
  servoRight.writeMicroseconds(1490);
}

void turnRight(){
  blinkRight(3, .5);
  turn(60);
}

void turnLeft(){
  blinkLeft(3, .5);
  turn(-58);
}

void blinkRight(int times, float blinkSpeed){
  blink(times,blinkSpeed,2);
}

void blinkLeft(int times, float blinkSpeed){
  blink(times,blinkSpeed,3);
}

void blink(int times, float blinkSpeed, int pin){
  for (int i = 0; i < times; i++){
    digitalWrite(pin, HIGH);       // sets the digital pin 13 on
    delay(blinkSpeed*1000);                  // waits for a second
    digitalWrite(pin, LOW);        // sets the digital pin 13 off
    delay(blinkSpeed*1000);                  // waits for a second
  }
}
