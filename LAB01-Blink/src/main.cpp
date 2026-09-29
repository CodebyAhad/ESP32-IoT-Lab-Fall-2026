// Week2-Lecture1-2
// Blink
// Embedded IoT System Fall-2026

// Name: Abdul Ahad                Reg#: 1051

#include <Arduino.h>

#define LED_PIN 2

void setup() {
    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(500);

    digitalWrite(LED_PIN, LOW);
    delay(500);
}