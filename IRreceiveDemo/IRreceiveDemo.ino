#include <IRremote.h>
int IR_RECEIVE_PIN = 4;

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN, DISABLE_LED_FEEDBACK);
}

void loop() {
  if (IrReceiver.decode()) {
    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_WAS_OVERFLOW) {
      IrReceiver.decodedIRData.flags = false; // yes we have recognized the flag :-)
      // no need to call resume, this is already done by decode()
      Serial.println(F("Overflow detected"));
    } else {
      // Print a short summary of received data
      //IrReceiver.printIRResultShort(&Serial);
      if (IrReceiver.decodedIRData.protocol == UNKNOWN) {
        // We have an unknown protocol, print more info
        //IrReceiver.printIRResultRawFormatted(&Serial, true);
      }
    }
    //Serial.println();
    IrReceiver.resume(); // Enable receiving of the next value
    unsigned long b=IrReceiver.decodedIRData.decodedRawData;
    //char c=IrReceiver.decodedIRData.command;
    //Serial.println(c); 
    Serial.println(b);
  }
}
