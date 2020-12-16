/*
   Code reads the tag and prints its unique ID.
   RFID Library Name: MFRC522 by GitHub Community, Availale in Library Manger (Ctrl+shift+I).
   RFID    ESP32
   SDA     5
   SCK     18
   MOSI    23
   MISO    19
   IRQ     Not connected
   GND     GND
   RST     4               Any digital pin and change code accordingly
   3.3V    3.3V
*/

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN  4
#define SS_PIN   5

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void setup() {
  Serial.begin(9600);
  while (!Serial);
  rfidSetup(); // Setup and initiate rfid 
  Serial.println("Setup Done");
}

void loop() {
  String s = rfid(); //check for card if available return unique key else none.
  if (s != "None")Serial.println(s);
}
// No changes below this
void rfidSetup() {
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
}
String rfid() {
  if ( mfrc522.PICC_IsNewCardPresent()) {
    if ( mfrc522.PICC_ReadCardSerial()) {
      String s = "";
      for (int i = 0; i < 5; i++) {
        s = s + mfrc522.uid.uidByte[i];
      }
      return s;
    }
  }
  else return "None";
}
