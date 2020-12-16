#include <WiFi.h>
const char* ss = "M 57"; // update it with yours
const char* p = "837691815"; // update it with yours

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  WiFi.mode(WIFI_AP_STA); // //WIFI_AP WIFI_STA
  WiFi.begin(ss,p);
  Serial.print("Connecting");
  int tries = 0;
  
  while (WiFi.status() != WL_CONNECTED) { // macro
    Serial.println(WiFi.status());
    Serial.print(".");
    delay(500);
    tries = tries + 1;
    if (tries > 20)
      break;
  }
  if (WiFi.status() != WL_CONNECTED ) {
    Serial.println("Failed to connect.");
  } else {
    Serial.println("Connected");
    Serial.println("STA IP Address : ");
    Serial.println(WiFi.localIP());
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
