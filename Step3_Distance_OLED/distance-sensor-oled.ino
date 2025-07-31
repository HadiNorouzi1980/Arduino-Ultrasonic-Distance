#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET    -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

//HC-SR04 pins
const int trigPin = 9;
const int echoPin = 8;

//LED pins
const int greenLED = 3;
const int yellowLED = 4;
const int redLED = 5;


void setup() {
 Serial.begin(9600);

 pinMode(trigPin, OUTPUT);
 pinMode(echoPin , INPUT);

 pinMode(greenLED , OUTPUT);
 pinMode(yellowLED , OUTPUT);
 pinMode(redLED , OUTPUT);

 digitalWrite(greenLED , LOW);
 digitalWrite(yellowLED , LOW);
 digitalWrite(redLED , LOW);

 // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // 0x3C is default I2C address
    Serial.println(F("SSD1306 allocation failed"));
    while(true); // Loop forever
  }
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
  distance = duration * 0.034 / 2;
 
  if (distance > 50)
  {
    digitalWrite(greenLED , HIGH);
    digitalWrite(yellowLED , LOW);
    digitalWrite(redLED , LOW);
  }
  else if (distance <= 50 && distance > 20)
  {
    digitalWrite(yellowLED , HIGH);
    digitalWrite(greenLED , LOW);
    digitalWrite(redLED , LOW);
  }
  else if (distance <= 20)
  {
    digitalWrite(redLED , HIGH);
    digitalWrite(yellowLED , LOW);
    digitalWrite(greenLED , LOW);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Distance:");
  display.setTextSize(3);
  display.setCursor(0,30);
  display.print(distance ,1);
  display.setTextSize(2);
  display.print(" cm");
  display.display();

  delay(500);
    
}

