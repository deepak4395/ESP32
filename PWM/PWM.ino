/*
   Pwm Pulse width Modulation
   Chanel number 0-15
   Frequency 5000
   Bit 8bit =2^8=256 0-255 0-3.3v
   Bit 10bit= 2^10=1024 0-1023 0-3.3v

   This code control the brightness of in built led on pin 2.
*/
void setup() {
  ledcSetup(0, 5000, 8); // channel number, frequency, Bit
  ledcAttachPin(2, 0); // Pin number , channel number
}
int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  while (i < 256) {
    ledcWrite(0, i);
    i = i + 1;
    delay(10);
  }
  while (i > 0) {
    ledcWrite(0, i);
    i = i - 1;
    delay(10);
  }
}
