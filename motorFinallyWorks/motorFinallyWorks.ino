
const int leftFrontMotor1  = 9;  // Pin 14 of L293
const int leftFrontMotor2  = 10;  // Pin 10 of L293

const int rightFrontMotor1  = 11;  // Pin 14 of L293
const int rightFrontMotor2  = 12;  // Pin 10 of L293

//the other 2 motors will require one more l293

const int leftBackMotor1  = 13;  // Pin 14 of L293
const int leftBackMotor2  = 14;  // Pin 10 of L293


const int rightBackMotor1  = 15;  // Pin 14 of L293
const int rightBackMotor2  = 16;  // Pin 10 of L293

const int HIGHSPEED=255;
const int LOWSPEED=0;

void setup() {
  pinMode(leftFrontMotor1,OUTPUT);
  pinMode(leftFrontMotor2,OUTPUT);
  pinMode(rightFrontMotor1,OUTPUT);
  pinMode(rightFrontMotor2,OUTPUT);
  pinMode(leftBackMotor1,OUTPUT);
  pinMode(leftBackMotor2,OUTPUT);
  pinMode(rightBackMotor1,OUTPUT);
  pinMode(rightBackMotor2,OUTPUT);
}

void moveForward(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, HIGHSPEED);
    analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor1, HIGHSPEED);
    analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor1, HIGHSPEED);
    analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor1, HIGHSPEED);
    analogWrite(leftBackMotor2, LOWSPEED);
}

void moveForwardLeft(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, LOWSPEED);
    analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor1, HIGHSPEED);
    analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor1, LOWSPEED);
    analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor1, HIGHSPEED);
    analogWrite(leftBackMotor2, LOWSPEED);
}

void moveForwardRight(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, HIGHSPEED);
    analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor1, LOWSPEED);
    analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor1, HIGHSPEED);
    analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor1, LOWSPEED);
    analogWrite(leftBackMotor2, LOWSPEED);
}

void moveLeft(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, LOWSPEED);
    analogWrite(leftFrontMotor2, HIGHSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor1, HIGHSPEED);
    analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor1, LOWSPEED);
    analogWrite(rightBackMotor2, HIGHSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor1, HIGHSPEED);
    analogWrite(leftBackMotor2, LOWSPEED);
}

void moveRight(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, HIGHSPEED);
    analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor1, LOWSPEED);
    analogWrite(rightFrontMotor2, HIGHSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor1, HIGHSPEED);
    analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor1, LOWSPEED);
    analogWrite(leftBackMotor2, HIGHSPEED);
}

void stationary(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, LOWSPEED);
    analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor1, LOWSPEED);
    analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor1, LOWSPEED);
    analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor1, LOWSPEED);
    analogWrite(leftBackMotor2, LOWSPEED);
}

void moveBackward(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, LOWSPEED);
    analogWrite(leftFrontMotor2, HIGHSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor2, HIGHSPEED);
    analogWrite(rightFrontMotor1, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor2, HIGHSPEED);
    analogWrite(rightBackMotor1, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor2, HIGHSPEED);
    analogWrite(leftBackMotor1, LOWSPEED);

}

void moveBackwardRight(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, LOWSPEED);
    analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor2, HIGHSPEED);
    analogWrite(rightFrontMotor1, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor2, LOWSPEED);
    analogWrite(rightBackMotor1, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor2, HIGHSPEED);
    analogWrite(leftBackMotor1, LOWSPEED);

}

void moveBackwardLeft(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, LOWSPEED);
    analogWrite(leftFrontMotor2, HIGHSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor2, LOWSPEED);
    analogWrite(rightFrontMotor1, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor2, HIGHSPEED);
    analogWrite(rightBackMotor1, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor2, LOWSPEED);
    analogWrite(leftBackMotor1, LOWSPEED);

}

void moveAntiClockWise(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, LOWSPEED);
    analogWrite(leftFrontMotor2, HIGHSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor1, HIGHSPEED);
    analogWrite(rightFrontMotor2, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor1, HIGHSPEED);
    analogWrite(rightBackMotor2, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor2, HIGHSPEED);
    analogWrite(leftBackMotor1, LOWSPEED);

}

void moveBackward(){
    //leftFrontMotor
    analogWrite(leftFrontMotor1, HIGHSPEED);
    analogWrite(leftFrontMotor2, LOWSPEED);

    //rightFrontMotor
    analogWrite(rightFrontMotor2, HIGHSPEED);
    analogWrite(rightFrontMotor1, LOWSPEED);

    //rightBackMotor
    analogWrite(rightBackMotor2, HIGHSPEED);
    analogWrite(rightBackMotor1, LOWSPEED);

    //leftBackMotor
    analogWrite(leftBackMotor1, HIGHSPEED);
    analogWrite(leftBackMotor2, LOWSPEED);

}


void loop() {
  // put your main code here, to run repeatedly:
  moveForward();
  delay(2000);
  stationary();
  delay(2000);
  moveBackward();
  delay(2000);
  stationary();
  delay(2000);

}
