#define PPM_MAX 2000
#define PPM_MIN 1050
#include<Servo.h>


  Servo S;

void setup() {
pinMode(A0,INPUT);
pinMode(10,OUTPUT);
  S.attach(9);

Serial.begin(9600);

}

void loop() {

  int PPM=0;
  PPM=analogRead(A0);
  PPM=map(PPM,0,1023,0,2000);
  Serial.print(PPM);
  S.writeMicroseconds(PPM);
  Serial.println();
  
  

}
