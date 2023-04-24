#include <SoftwareSerial.h>

const char stationary='0';
const char upRight='2';
const char right='3';
const char downRight='4';
const char down='5';
const char downLeft='6';
const char left='7';
const char upLeft='8';
const char up='1';

SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin

const int leftFrontMotor1  = 2;  // Pin 14 of L293
const int leftFrontMotor2  = 3;  // Pin 10 of L293
const int leftFrontMotorEn  = 4;  // Pin 10 of L293

const int rightFrontMotor1  = 25;  // Pin 14 of L293
const int rightFrontMotor2  = 26;  // Pin 10 of L293
const int rightFrontMotorEn  = 3;

//the other 2 motors will require one more l293

const int leftBackMotor1  = 27;  // Pin 14 of L293
const int leftBackMotor2  = 28;  // Pin 10 of L293
const int leftBackMotorEn  = 4;

const int rightBackMotor1  = 29;  // Pin 14 of L293
const int rightBackMotor2  = 30;  // Pin 10 of L293
const int rightBackMotorEn  = 5;

const int HIGHSPEED=100;
const int LOWSPEED=0;

void setup() {
  //setting up the serial for receiving stuff
  Serial.begin(4800);
  HC12.begin(9600);

  pinMode(leftFrontMotorEn,OUTPUT);
  pinMode(leftFrontMotor1,OUTPUT);
  pinMode(leftFrontMotor2,OUTPUT);

  pinMode(rightFrontMotorEn,OUTPUT);
  pinMode(rightFrontMotor1,OUTPUT);
  pinMode(rightFrontMotor2,OUTPUT);
  
  pinMode(leftBackMotorEn,OUTPUT);
  pinMode(leftBackMotor1,OUTPUT);
  pinMode(leftBackMotor2,OUTPUT);
  
  pinMode(rightBackMotorEn,OUTPUT);
  pinMode(rightBackMotor1,OUTPUT);
  pinMode(rightBackMotor2,OUTPUT);
}

void moveForward(){
    // delay(1000);
    //leftFrontMotor
    //analogWrite(leftFrontMotorEn, HIGHSPEED);
    digitalWrite(leftFrontMotor1, HIGH);
    digitalWrite(leftFrontMotor2, LOW);

    //rightFrontMotor
    //analogWrite(rightFrontMotorEn, HIGHSPEED);
    digitalWrite(rightFrontMotor1, HIGH);
    digitalWrite(rightFrontMotor2, LOW);

    //rightBackMotor
    //analogWrite(rightBackMotorEn, HIGHSPEED);
    digitalWrite(rightBackMotor1, HIGH);
    digitalWrite(rightBackMotor2, LOW);

    //leftBackMotor
    //analogWrite(leftBackMotorEn, HIGHSPEED);
    digitalWrite(leftBackMotor1, HIGH);
    digitalWrite(leftBackMotor2, LOW);
    // delay(1000);
}

void moveForwardLeft(){
    //leftFrontMotor
    //analogWrite(leftFrontMotor1, LOWSPEED);
    //analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    //analogWrite(rightFrontMotor1, HIGHSPEED);
    //analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    //analogWrite(rightBackMotor1, LOWSPEED);
    //analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    //analogWrite(leftBackMotor1, HIGHSPEED);
    //analogWrite(leftBackMotor2, LOWSPEED);
}

void moveForwardRight(){
    //leftFrontMotor
    //analogWrite(leftFrontMotor1, HIGHSPEED);
    //analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    //analogWrite(rightFrontMotor1, LOWSPEED);
    //analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    //analogWrite(rightBackMotor1, HIGHSPEED);
    //analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    //analogWrite(leftBackMotor1, LOWSPEED);
    //analogWrite(leftBackMotor2, LOWSPEED);
}

void moveLeft(){
    //leftFrontMotor
    //analogWrite(leftFrontMotor1, LOWSPEED);
    //analogWrite(leftFrontMotor2, HIGHSPEED);

    //rightFrontMotor
    //analogWrite(rightFrontMotor1, HIGHSPEED);
    //analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    //analogWrite(rightBackMotor1, LOWSPEED);
    //analogWrite(rightBackMotor2, HIGHSPEED);

    //leftBackMotor
    //analogWrite(leftBackMotor1, HIGHSPEED);
    //analogWrite(leftBackMotor2, LOWSPEED);
}

void moveRight(){
    //leftFrontMotor
    //analogWrite(leftFrontMotor1, HIGHSPEED);
    //analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    //analogWrite(rightFrontMotor1, LOWSPEED);
    //analogWrite(rightFrontMotor2, HIGHSPEED);

    //rightBackMotor
    //analogWrite(rightBackMotor1, HIGHSPEED);
    //analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    //analogWrite(leftBackMotor1, LOWSPEED);
    //analogWrite(leftBackMotor2, HIGHSPEED);
}

void moveStationary(){
    //leftBackMotor
    analogWrite(leftFrontMotorEn, LOWSPEED);
    digitalWrite(leftFrontMotor1,LOW);
    digitalWrite(leftFrontMotor2,LOW);

    //leftBackMotor
    analogWrite(rightFrontMotorEn, LOWSPEED);
    digitalWrite(rightFrontMotor1,LOW);
    digitalWrite(rightFrontMotor2,LOW);

    //leftBackMotor
    analogWrite(rightBackMotorEn, LOWSPEED);
    digitalWrite(rightBackMotor1,LOW);
    digitalWrite(rightBackMotor2,LOW);

    //leftBackMotor
    analogWrite(leftBackMotorEn, LOWSPEED);
    digitalWrite(leftBackMotor1,LOW);
    digitalWrite(leftBackMotor2,LOW);
}


void moveBackward(){
    //leftFrontMotor
    analogWrite(leftFrontMotorEn, HIGHSPEED);
    digitalWrite(leftFrontMotor2, HIGH);
    analogWrite(leftFrontMotor1, LOW);

    //rightFrontMotor
    analogWrite(rightFrontMotorEn, HIGHSPEED);
    digitalWrite(rightFrontMotor2, HIGH);
    analogWrite(rightFrontMotor1, LOW);

    //rightBackMotor
    analogWrite(rightBackMotorEn, HIGHSPEED);
    digitalWrite(rightBackMotor2, HIGH);
    analogWrite(rightBackMotor1, LOW);

    //leftBackMotor
    analogWrite(leftBackMotorEn, HIGHSPEED);
    digitalWrite(leftBackMotor2, HIGH);
    analogWrite(leftBackMotor1, LOW);
}

void moveBackwardRight(){
    //leftFrontMotor
    //analogWrite(leftFrontMotor1, LOWSPEED);
    //analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    //analogWrite(rightFrontMotor2, HIGHSPEED);
    //analogWrite(rightFrontMotor1, LOWSPEED);

    //rightBackMotor
    //analogWrite(rightBackMotor2, LOWSPEED);
    //analogWrite(rightBackMotor1, LOWSPEED);

    //leftBackMotor
    //analogWrite(leftBackMotor2, HIGHSPEED);
    //analogWrite(leftBackMotor1, LOWSPEED);

}

void moveBackwardLeft(){
    //leftFrontMotor
    //analogWrite(leftFrontMotor1, LOWSPEED);
    //analogWrite(leftFrontMotor2, HIGHSPEED);

    //rightFrontMotor
    //analogWrite(rightFrontMotor2, LOWSPEED);
    //analogWrite(rightFrontMotor1, LOWSPEED);

    //rightBackMotor
    //analogWrite(rightBackMotor2, HIGHSPEED);
    //analogWrite(rightBackMotor1, LOWSPEED);

    //leftBackMotor
    //analogWrite(leftBackMotor2, LOWSPEED);
    //analogWrite(leftBackMotor1, LOWSPEED);

}

void moveAntiClockWise(){
    //leftFrontMotor
    //analogWrite(leftFrontMotor1, LOWSPEED);
    //analogWrite(leftFrontMotor2, HIGHSPEED);

    //rightFrontMotor
    //analogWrite(rightFrontMotor1, HIGHSPEED);
    //analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    //analogWrite(rightBackMotor1, HIGHSPEED);
    //analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    //analogWrite(leftBackMotor2, HIGHSPEED);
    //analogWrite(leftBackMotor1, LOWSPEED);

}

void moveClockwise(){
    //leftFrontMotor
    //analogWrite(leftFrontMotor1, HIGHSPEED);
    //analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    //analogWrite(rightFrontMotor2, HIGHSPEED);
    //analogWrite(rightFrontMotor1, LOWSPEED);

    //rightBackMotor
    //analogWrite(rightBackMotor2, HIGHSPEED);
    //analogWrite(rightBackMotor1, LOWSPEED);

    //leftBackMotor
    //analogWrite(leftBackMotor1, HIGHSPEED);
    //analogWrite(leftBackMotor2, LOWSPEED);

}


void loop() {
  // moveBackward();
  // moveForward();
  // Serial.write("here\n");
  while (HC12.available()) {        // If HC-12 has data
    // Serial.write("here2\n");
    int joyStickDirection=HC12.read();      // Send the data to Serial monitor
//     Serial.println(joyStickDirection);
//  Serial.write("here2\n");
    // Serial.print(HC12.readString());
    // Serial.write(HC12.read());
    // Serial.println(HC12.read());

    if(joyStickDirection==stationary){
      Serial.println("stationary");
      moveStationary();
    }
    if(joyStickDirection==up){
     Serial.println("movingForward");
      moveForward();
    }
    if(joyStickDirection==upLeft){
     Serial.println("moveForwardLeft");
      moveForwardLeft();
    }
    if(joyStickDirection==upRight){
     // Serial.println("moveForwardRight");
      moveForwardRight();
    }
    // if(joyStickDirection.equals("left")){
    // //  Serial.println("moveLeft");
    //   moveLeft();
    // }
    // if(joyStickDirection.equals("right")){
    //   moveRight();
    // }
    if(joyStickDirection==down){
      Serial.println("moveBackward");
      moveBackward();
    }
    // if(joyStickDirection.equals("downLeft")){
    //   moveBackwardLeft();
    // }
    // if(joyStickDirection.equals("downRight")){
    //   moveBackwardRight();
    // }
    // if(joyStickDirection.equals("clockwise")){
    //   moveClockwise();
    // }
    // if(joyStickDirection.equals("antiClockwise")){
    //   moveAntiClockWise();
    // }
    //  Serial.write("here3\n");
  }

}
