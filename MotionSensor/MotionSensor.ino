/*
Always give time for PIR to warm up. A time of atleaset 50 seconds is sufficient.
In this code inbuilt led is on for fixed pirDelay if there is a motion else off.
Refer the Pirpinout picture in reference folder for pinout.
PIR Connection
PIR    ESP32
VCC    Vin
GND    GND
DOUT   26 (Any digital pin and change code accordingly)
*/
int pirPin = 26;
long timePir = millis();
bool pirFlag = false;
const int pirDelay = 5000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(pirPin, INPUT);
  Serial.println("Warm up delay of 40 seconds");
  delay(40000);
}
void loop() {
  MotionSensor();
  digitalWrite(2, pirFlag);
}

void MotionSensor() {
  if ( !pirFlag || (millis() - timePir) > pirDelay) {
    if (digitalRead(pirPin)) {
      Serial.println("Motion Detected");
      pirFlag = true;
      timePir = millis();
    }
    else {
      pirFlag = false;
    }
  }
}
