/*
 * This code creates software serial port
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  // Open serial communication on hardware and wait for port to open:
  Serial.begin(115200);
  while (!Serial); // wait for serial port to connect. Needed for Native USB only
  Serial.println("Hardware Serial port Started");
  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);
  Serial.println("Software Serial port Started");
}

void loop() // run over and over
{
  if (mySerial.available()) {
    char c = mySerial.read();
    Serial.println(c);
  }
  if (Serial.available()) {
    char c = Serial.read();
    mySerial.print(c);
  }
}
