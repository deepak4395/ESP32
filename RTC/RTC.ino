/*
 * This code reads the time from RTC and creates buffer in preference of user. Buffer can be converted to string.
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
  Serial.begin(115200);
  if (! rtc.begin()) { // begin the rtc communication with controller.
    Serial.println("Couldn't find RTC");
    while (1);
  }
  pinMode(2, OUTPUT);
}

void loop() {

  DateTime now = rtc.now();

  //buffer can be defined using following combinations:
  //hh - the hour with a leading zero (00 to 23)
  //mm - the minute with a leading zero (00 to 59)
  //ss - the whole second with a leading zero where applicable (00 to 59)
  //YYYY - the year as four digit number
  //YY - the year as two digit number (00-99)
  //MM - the month as number with a leading zero (01-12)
  //MMM - the abbreviated English month name ('Jan' to 'Dec')
  //DD - the day as number with a leading zero (01 to 31)
  //DDD - the abbreviated English day name ('Mon' to 'Sun')

  char buf1[] = "hh:mm";
  String s = now.toString(buf1);
  Serial.println(s);
  if (s == "18:27") {
    digitalWrite(2, HIGH);
  }
  else {
    digitalWrite(2, LOW);
  }

  char buf2[] = "YYMMDD-hh:mm:ss";
  Serial.println(now.toString(buf2));

  char buf3[] = "Today is DDD, MMM DD YYYY";
  Serial.println(now.toString(buf3));

  char buf4[] = "MM-DD-YYYY";
  s = now.toString(buf4);
  Serial.println(s);

  delay(1000);
}
