/*  Author: Waciuma Wanjohi
    This code provides simple functions for driving the BoEbot forward, backward
    and turning left and right. When turning, the bot will blink a turn signal
    first. Slight calibration may be needed for the stop value. (The value
    should be 1500, but may be slightly higher or lower on any given servo)
*/


#include <Servo.h>                           // Include servo library

Servo servoLeft;                             // Declare left servo signal
Servo servoRight;                            // Declare right servo signal
int STOP = 1490                              // Value at which servos do not turn.

void setup()
{
  servoLeft.attach(13);                      // Attach left signal to pin 13
  servoRight.attach(12);                     // Attach right signal to pin 12

  // Attach LED pins here.
  pinMode(2, OUTPUT);                        // Attach right blinker to pin #2
  pinMode(3, OUTPUT);                        // Attach left blinker to pin #3

}

void loop()
{
  // Drive the car in an unusual loop. Test out functions below.
  int speedOfCar = 200;
  int seconds = 2;
  forward(seconds,speedOfCar);
  turnRight();
  backward(seconds,speedOfCar);
  turnRight();
  forward(seconds,speedOfCar);
  turnLeft();
  forward(seconds,speedOfCar);
  turnLeft();
}

void forward(int seconds, int speedOfCar){
  int leftSpeed = STOP+speedOfCar;             // Servos are facing opposite directions, so when one
  int rightSpeed = STOP-speedOfCar;            // turns clockwise, the other should turn counter clockwise
  servoLeft.writeMicroseconds(leftSpeed);
  servoRight.writeMicroseconds(rightSpeed);
  delay(seconds*1000);
  servoLeft.writeMicroseconds(STOP); // Stop
  servoRight.writeMicroseconds(STOP);
}

void backward(int seconds, int speedOfCar){
  forward(seconds,0-speedOfCar);
}

void turn(int speedOfCar){
  int leftSpeed = STOP+speedOfCar;
  int rightSpeed = STOP+speedOfCar;
  servoLeft.writeMicroseconds(leftSpeed);
  servoRight.writeMicroseconds(rightSpeed);
  delay(1000);
  servoLeft.writeMicroseconds(STOP); // Stop
  servoRight.writeMicroseconds(STOP);
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
