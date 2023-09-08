// Author Og'abek Sattorov

#include <IRremote.hpp>

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(8);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  int val = IrReceiver.decodedIRData.command;
  if(IrReceiver.decode()){
    IrReceiver.resume();

// Color control with number buttons
    
    if(val == 69){
      Coloring(255, 0, 0);
    }
    else if(val == 70){
      Coloring(255, 127, 0);
    }
    else if(val == 71){
      Coloring(255, 255, 0);
    }
    else if(val == 68){
      Coloring(127, 255, 0);
    }
    else if(val == 64){
      Coloring(0, 255, 0);
    }
    else if(val == 67){
      Coloring(0, 255, 255);
    }
    else if(val == 7){
      Coloring(0, 0, 255);
    }
    else if(val == 21){
      Coloring(127, 0, 255);
    }
    else if(val == 9){
      Coloring(255, 0, 255);
    }
    else if(val == 25){
      Coloring(0, 0, 0);
    }
  }

// Police Flasher animation
  
  if(val == 22){
    for(int i=0; i<=2; i++){
      Coloring(255, 0, 0);
      delay(100);
      Coloring(0, 0, 0);
      delay(100);
    }
    
    for(int i=0; i<=2; i++){
      Coloring(0, 0, 255);
      delay(100);
      Coloring(0, 0, 0);
      delay(100);
    }
  }
}

void Coloring(int red, int green, int blue){
  analogWrite(6, red);
  analogWrite(9, green);
  analogWrite(10, blue);
}
