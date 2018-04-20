
String inputString = "";         // a String to hold incoming data
boolean stringComplete = false;  // whether the string is complete

#include <Servo.h>


void setup() {
 
  // initialize serial:
  Serial.begin(9600);
  // reserve 200 bytes for the inputString:
  
  
  inputString.reserve(200);
}

void loop() {
   Servo S;
  S.attach(9);


  if (stringComplete) {
    int PPM=0;
    int tmp=0;
    int i=0; 
     

          Serial.println(inputString);

tmp=0;
  while(inputString[i]!='E'){
    PPM=PPM*10;
    tmp=0;
    tmp=inputString[i]-48;
    Serial.println("PPM");
        Serial.println(PPM);
        Serial.println("tmp");
        Serial.println(tmp);
        Serial.println("i");
        Serial.println(i);
    PPM=tmp+PPM;  
        i++;

  }

  if(PPM<1050){
    PPM=0;
  }

  if(PPM>2000){
    PPM=2000;
  }

  S.writeMicroseconds(PPM);
    
  
    
    Serial.println(PPM);
    // clear the string:
    inputString = "";
    i=0;
    PPM=0;
    tmp=0;
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag so the main loop can
    // do something about it:
    if (inChar == 'Z') {
      stringComplete = true;
    }
  }
}
