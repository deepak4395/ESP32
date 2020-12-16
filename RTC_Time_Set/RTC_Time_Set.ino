/*
   This code sets time in RTC module. Need to be uplaoded once or when time is incorrect in rtc.
   RTC Library : RTCLib by Adafruit, Availale in Library Manger (Ctrl+shift+I)
   RTC    ESP32
   VCC    Vin
   GND    GND
   SCL    22
   SDA    21
*/
#include <Wire.h>
#include <RTClib.h>
RTC_DS1307 rtc;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
  // following line sets the RTC to the date & time this sketch was compiled
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // This line sets the RTC with an explicit date & time, for example to set
  // January 21, 2014 at 3am you would call:
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0)); // year, month, day, hour, minute, seconds
  Serial.println("RTC Setup Done");
  DateTime now = rtc.now();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:

}
