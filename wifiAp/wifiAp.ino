#include <WiFi.h>
const char* ssid = "M 57"; // router name 
const char* password = "8376918157"; // password

const char* ssidAp = "Makers"; // hotspot
const char* passwordAp = "12345678"; //passowrd

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  WiFi.mode(WIFI_AP_STA); // //WIFI_AP WIFI_STA
  WiFi.begin(ssid, password);
  WiFi.softAP(ssidAp, passwordAp);
  Serial.print("Connecting");
  int tries = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    tries = tries + 1;
    if (tries > 20)
      break;
  }
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Failed to connect.");
  } else {
    Serial.println("Connected");
    Serial.println("STA IP Address : ");
    Serial.println(WiFi.localIP());
  }
  IPAddress myIP = WiFi.softAPIP(); // Gatway IP of router
  Serial.print("AP IP address: ");
  Serial.println(myIP);
}

void loop() {
  // put your main code here, to run repeatedly:

}
