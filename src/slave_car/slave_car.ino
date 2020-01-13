#include <SoftwareSerial.h>
// Pinii motor 1
#define mpin00 5
#define mpin01 6
// Pinii motor 2
#define mpin10 3
#define mpin11 11


#define SPEED 50

SoftwareSerial blue_serial(2,12); // RX, TX

void setup() {
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
  pinMode (mpin00, OUTPUT);
  pinMode (mpin01, OUTPUT);
  pinMode (mpin10, OUTPUT);
  pinMode (mpin11, OUTPUT);
  // pin LED
  pinMode(13, OUTPUT);
  blue_serial.begin(38400);
  //Serial.begin(9600);
  //Serial1.begin(9600);

   for (int i = 0; i < 10; i++)
  {
    digitalWrite(13, 1);
    delay(200);
    digitalWrite(13, 0);
    delay(200);
  }
  // Blink rapid. Scoateți cablul USB!!!!
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(13, 1);
    delay(100);
    digitalWrite(13, 0);
    delay(100);
  }
  digitalWrite(13, 1);
}

void loop() {
  int command = blue_serial.read();
  if (command != -1) {
    switch (command) {
      case 'F': forward(); break;
      case 'B': back(); break;
      case 'L': left(); break;
      case 'R': right(); break;
      case 'S': stoped(); break;
    //  default: break;
    }
    delay(10);
  }
  
}

void forward() {
  stoped();
   analogWrite(mpin00, SPEED);
  analogWrite(mpin10, SPEED);
 
}

void back() {
  stoped();
 

   analogWrite(mpin01, SPEED);
  analogWrite(mpin11, SPEED);
  
}

void left() {
  stoped();
 analogWrite(mpin10, SPEED);
  analogWrite(mpin01, SPEED);
  
}

void right() {
  stoped();
  

   analogWrite(mpin11, SPEED);
  analogWrite(mpin00, SPEED);
}

void stoped() {
  analogWrite(mpin00, 0);
  analogWrite(mpin01, 0);
  analogWrite(mpin10, 0);
  analogWrite(mpin11, 0);
}
