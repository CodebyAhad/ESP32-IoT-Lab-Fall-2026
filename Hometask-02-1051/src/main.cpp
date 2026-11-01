#include <Arduino.h>

const int LED1_PIN = 18;
const int LED2_PIN = 19;

const int LED1_CHANNEL = 0;
const int LED2_CHANNEL = 1;


const int LED1_FREQ = 10000;  
const int LED2_FREQ = 5000;   


const int PWM_RESOLUTION = 8;
const int MAX_DUTY = 255;


int duty1 = 0;
int duty2 = 0;

int direction1 = 1;
int direction2 = 1;


unsigned long lastFade1 = 0;
unsigned long lastFade2 = 0;

const unsigned long FADE_INTERVAL_1 = 12;
const unsigned long FADE_INTERVAL_2 = 20;

void updateFade(int &duty, int &direction, int channel) {
    duty += direction;

    if (duty >= MAX_DUTY) {
        duty = MAX_DUTY;
        direction = -1;
    }
    else if (duty <= 0) {
        duty = 0;
        direction = 1;
    }

    ledcWrite(channel, duty);
}

void setup() {
    Serial.begin(115200);

    
    ledcSetup(LED1_CHANNEL, LED1_FREQ, PWM_RESOLUTION);
    ledcAttachPin(LED1_PIN, LED1_CHANNEL);

    ledcSetup(LED2_CHANNEL, LED2_FREQ, PWM_RESOLUTION);
    ledcAttachPin(LED2_PIN, LED2_CHANNEL);

    ledcWrite(LED1_CHANNEL, 0);
    ledcWrite(LED2_CHANNEL, 0);

    Serial.println("Task 1: Dual LED PWM started");
    Serial.println("LED 1: GPIO 18, Frequency: 10000 Hz");
    Serial.println("LED 2: GPIO 19, Frequency: 5000 Hz");
    Serial.println("Resolution: 8-bit");
}

void loop() {
    unsigned long now = millis();

    if (now - lastFade1 >= FADE_INTERVAL_1) {
        lastFade1 = now;
        updateFade(duty1, direction1, LED1_CHANNEL);
    }

    if (now - lastFade2 >= FADE_INTERVAL_2) {
        lastFade2 = now;
        updateFade(duty2, direction2, LED2_CHANNEL);
    }
}