/*
  Esp32 Servo: https://github.com/madhephaestus/ESP32Servo or available in the servo folder.
  This code rotates servo motor 0 to 180 and then back to 0 contnuously. 
 */
#include <ESP32Servo.h>

Servo myservo;  // create servo object to control a servo
int servoPin = 13;      // GPIO pin used to connect the servo control (digital out)

void setup()
{
  // Allow allocation of all timers
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);
  myservo.setPeriodHertz(50);// Standard 50hz servo
  myservo.attach(servoPin, 500, 2400);
  // "myservo.attach(servoPin);"
}

void loop() {
  for (int i = 0; i < 181; i++) {
    myservo.write(i);                  // set the servo position according to the scaled value
    delay(10);                          // wait for the servo to get there
  }
}
