// Author Og'abek Sattorov

#include <IRremote.hpp>

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(8);
}

void loop() {
  int val = IrReceiver.decodedIRData.command;
  if(IrReceiver.decode()){
    IrReceiver.resume();
    Serial.println(val);
  }
}
