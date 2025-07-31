#include <Arduino.h>
// HC-SR04 pins
const int trigPin = 9;
const int echoPin = 8;

void setup() {
  Serial.begin(9600);         // Start Serial Monitor
  pinMode(trigPin, OUTPUT);   // Trig pin as output
  pinMode(echoPin, INPUT);    // Echo pin as input
}

void loop() {
  long duration;
  float distance;

  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the echoPin
  duration = pulseIn(echoPin, HIGH);

  // Calculate distance (in cm)
  distance = duration * 0.034 / 2;

  // Print result
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(500); // Wait half a second
}
