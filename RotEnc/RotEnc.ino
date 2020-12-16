#include "AiEsp32RotaryEncoder.h"
#include "Arduino.h"

#define ROTARY_ENCODER_A_PIN 21
#define ROTARY_ENCODER_B_PIN 22
#define ROTARY_ENCODER_BUTTON_PIN 23
#define ROTARY_ENCODER_VCC_PIN -1 /*put -1 of Rotary encoder Vcc is connected directly to 3,3V; else you can use declared output pin for powering rotary encoder */
int16_t Dim = 0;
AiEsp32RotaryEncoder rotaryEncoder = AiEsp32RotaryEncoder(ROTARY_ENCODER_A_PIN, ROTARY_ENCODER_B_PIN, ROTARY_ENCODER_BUTTON_PIN, ROTARY_ENCODER_VCC_PIN);

void setup() {
  Serial.begin(115200);
  rotaryEncoder.begin();
  rotaryEncoder.setup([] {rotaryEncoder.readEncoder_ISR();});
  rotaryEncoder.setBoundaries(0, 42, false ); //minValue, maxValue, cycle values (when max go to min and vice versa)
}

void loop() {
 Serial.println(rotaryEncoder.encoder);
}
