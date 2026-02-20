#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor
 * @author manish_kumar
 * @date 2026-01-23
 *
 * @details
 * Measures distance using HC-SR04 ultrasonic sensor
 * and displays structured output via Serial Monitor.
 */

int trigPin = 9;


 // Define TRIG pin (Use pin 9)

int echoPin = 10;
 // Define ECHO pin (Use pin 10)
long duration =0;

 // Create variable to store duration

float distance =0;
 // Create variable to store calculated distance

void setup() {

 Serial.begin(9600);
    // Initialize Serial communication (9600 baud rate)

 pinMode(trigPin, OUTPUT);
    // Configure TRIG as OUTPUT

 pinMode(echoPin, INPUT);
    // Configure ECHO as INPUT

 Serial.println("HC-SR04 Ultrasonic Distance Measurement");
    // Print system initialization message
}

void loop() {

    digitalWrite(trigPin, LOW);

    delayMicroseconds(2);



    digitalWrite(trigPin, HIGH);

    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

     duration = pulseIn(echoPin, HIGH);

     distance = duration * 0.034 / 2;

    Serial.print("Distance: ");

    Serial.print(distance);

    Serial.println(" cm");

    delay(500);
}
