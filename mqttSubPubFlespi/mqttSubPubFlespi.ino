/*
 * Mqtt Library : PubSubClient by Nick O'Leary, Availale in Library Manger (Ctrl+shift+I)
 * Mqtt Dash: https://play.google.com/store/apps/details?id=net.routix.mqttdash
 * Update the code with your MQTT Broker details to avoid interfacing of other users to control your system.
 * Set your own broker at flespi.io
 * 
 * This code controls inbuilt led from mqtt dash app and send/publish random to same app.
 */
#include <WiFi.h>
#include <PubSubClient.h>
// Wifi Credentials
char ssid[] = "M 57"; //Put your wifi name.
char password[] = "8376918157"; //Put your wifi password.

// MQTT Broker Credentials flespi.io
const char server[] = "mqtt.flespi.io";
char mqttUserName[] = "hXMU1DZsH9kjIZQkUm69e36qVT3OtoUAbuj1V6hs5rBEffOXrLWvCTKoAD2URMkR";
char mqttPass[] = "";
const char clientID[] = "9899845428"; // change according to your no. must be unique in the world.
// Topics to subscibe and publish
const char topicSub[] = "LED2";
String topicPub = "RFID";
//Messages to sent
bool rfidFlag = true;

WiFiClient client;
PubSubClient mqttClient(client);

void mqttSub() {
  mqttClient.subscribe(topicSub);
}
void callback_fun(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived from [");
  Serial.print(topic);
  Serial.print("]");
  String s = "";
  for (int i = 0; i < length; i++) {
    s = s + (char)payload[i];
  }
  Serial.println(s);
  if (topic = "LED2") {
    if (s.indexOf("1") >= 0) {
      digitalWrite(2, HIGH);
    }
    else digitalWrite(2, LOW);
  }
}

void setup() {
  Serial.begin(9600);
  //Wifi Setup
  WiFi.mode(WIFI_AP_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  int tries = 0;
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    tries = tries + 1;
    if (tries > 20) {
      Serial.println("Failed to connect.");
      break;
    }
  }
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected");
    Serial.println("IP Address : ");
    Serial.println(WiFi.localIP());
  }
  //mqtt setup
  mqttClient.setServer(server, 1883);
  mqttClient.setCallback(callback_fun);
  //pin setup
  pinMode(2, OUTPUT);
  Serial.println("Setup Done");
}

void loop() {
  mqttLoop();
 // mqttPublish(topicPub, String(rfidFlag)); //topic and message
}
// No changes below this
long mqttRetry = millis();
void mqttLoop() {
  if (!mqttClient.connected() && ((millis() - mqttRetry) > 5000))
  {
    Serial.print("Attempting MQTT connection...");
    if (mqttClient.connect(clientID, mqttUserName, mqttPass)) {
      mqttSub();
      Serial.println("connected and subscribed");
    }
    else {
      Serial.print("failed, Reason =");
      Serial.print(mqttClient.state());
      Serial.println(" will try again in 5 seconds");
      mqttRetry = millis();
    }
  }
  mqttClient.loop();
}

void mqttPublish(String t, String m) {
  if (mqttClient.publish( t.c_str(), m.c_str())) Serial.println("Message published");
}
