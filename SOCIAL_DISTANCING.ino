#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(6, 7);  // Trig Pin to 6 & Echo Pin to 7
int distance;
int buzzer = 2;                                 // Connect Buzzer to Pin 2
int greenPin = 3;                               // Connect Green Leg of RGB LED to Pin 3 
int redPin = 4;                                 // Connect Red Leg of RGB LED to Pin 4
int bluePin = 5;                                // Connect Blue Leg of RGB LED to Pin 5
int minDistance = 100;                          // Define minimum distnace in cm to turn ON the buzzer and RED LED


void setup() {
  Serial.begin(9600);
  pinMode (buzzer, OUTPUT);
  pinMode (greenPin, OUTPUT);
  pinMode (redPin, OUTPUT);
  pinMode (bluePin, OUTPUT);
}

void loop() {

  distance = (distanceSensor.measureDistanceCm());      //Measure distance from Ultrasonic sensor and assign distance value to int "distance"
  Serial.println (distance);                            //Print Distance to Serial Monitor
  delay (100);

  if (distance > minDistance) {                         // If distance is more than minimum distance, Light = Green & Buzzer = OFF
    digitalWrite(buzzer, LOW);
    digitalWrite (redPin, LOW);
    digitalWrite (greenPin, HIGH);
    digitalWrite (bluePin, LOW);
  }

  if (distance <= minDistance) {                        // If distance is less than minimum distance, Light = Red & Buzzer = ON
    digitalWrite(buzzer, HIGH);
    digitalWrite (redPin, HIGH);
    digitalWrite (greenPin, LOW);
    digitalWrite (bluePin, LOW);
  }

  else {
  }

}
