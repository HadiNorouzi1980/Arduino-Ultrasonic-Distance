#include <Arduino.h>

//HC-SR04 pins
const int trigPin = 9;
const int echoPin = 8;

//LED pins
const int greenLED = 3;
const int yellowLED = 4;
const int redLED = 5;


void setup() {
    
  pinMode(trigPin , OUTPUT);
  pinMode(echoPin , INPUT);

  pinMode(greenLED , OUTPUT);
  pinMode(yellowLED , OUTPUT);
  pinMode(redLED , OUTPUT);
  digitalWrite(greenLED , LOW);
  digitalWrite(yellowLED , LOW);
  digitalWrite(redLED , LOW);

}

void loop() {

  long duration;
  float distance;

  digitalWrite(trigPin , LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin , HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin , LOW);

  duration = pulseIn(echoPin , HIGH);

  distance = duration * 0.034 / 2; //cm

 
  if (distance > 100)
  {
    digitalWrite(greenLED , HIGH);
    digitalWrite(yellowLED , LOW);
    digitalWrite(redLED , LOW);
  }
  else if (distance <= 100 && distance > 20)
  {
    digitalWrite(yellowLED , HIGH);
    digitalWrite(greenLED , LOW);
    digitalWrite(redLED , LOW);
  }
  else if (distance <= 20)
  {
    digitalWrite(redLED , HIGH);
    digitalWrite(greenLED , LOW);
    digitalWrite(yellowLED , LOW);
  }
  
  delay(20);
  
}
