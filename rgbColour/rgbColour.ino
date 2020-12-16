/*
  This code creates different colours on RGB Led of anode type connected to Pin 19,18,21.
*/
void setup() {
  // put your setup code here, to run once:
  ledcSetup(0, 5000, 8); //red
  ledcSetup(1, 5000, 8); //blue
  ledcSetup(2, 5000, 8); //green
  ledcAttachPin(19, 0);
  ledcAttachPin(18, 1);
  ledcAttachPin(21, 2);
  // Set all to High. That is RGB Led is white.
  ledcWrite(0, 0);
  ledcWrite(1, 0);
  ledcWrite(2, 0);
  delay(3000);
  // Set all to Low. That is RGB Led is off.
  ledcWrite(0, 255);
  ledcWrite(1, 255);
  ledcWrite(2, 255);
  delay(3000);
}
int i;
void loop() {
  //Red Dimming
  i = 0;
  while (i < 256) {
    ledcWrite(0, i);
    i = i + 1;
    delay(10);
  }
  //blue Dimming
  i = 0;
  while (i < 256) {
    ledcWrite(1, i);
    i = i + 1;
    delay(10);
  }
  //green Dimming
  i = 0;
  while (i < 256) {
    ledcWrite(2, i);
    i = i + 1;
    delay(10);
  }
  //Green and blue Dimming
  i = 0;
  while (i < 256) {
    ledcWrite(2, i);
    ledcWrite(1, i);
    i = i + 1;
    delay(10);
  }
  //Red and blue Dimming
  i = 0;
  while (i < 256) {
    ledcWrite(0, i);
    ledcWrite(1, i);
    i = i + 1;
    delay(10);
  }
  //Red and Green Dimming
  i = 0;
  while (i < 256) {
    ledcWrite(0, i);
    ledcWrite(2, i);
    i = i + 1;
    delay(10);
  }
  //White Dimming
  i = 0;
  while (i < 256) {
    ledcWrite(0, i);
    ledcWrite(1, i);
    ledcWrite(2, i);
    i = i + 1;
    delay(10);
  }
}
