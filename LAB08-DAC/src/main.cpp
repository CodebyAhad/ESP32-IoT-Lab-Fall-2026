#include <Arduino.h>

#define DAC_PIN   25
#define PWM_PIN   2

#define PWM_CHANNEL 0
#define PWM_FREQ    5000  
#define PWM_RES     8 

void setup()
{
  Serial.begin(115200);

  
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);

  
  ledcAttachPin(PWM_PIN, PWM_CHANNEL);
}

void loop()
{
  
  dacWrite(DAC_PIN, 128);

  
  ledcWrite(PWM_CHANNEL, 128);

  Serial.println("DAC=128 | PWM duty=128");
  delay(1000);
}