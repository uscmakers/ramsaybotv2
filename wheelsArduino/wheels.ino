/*

//source code: https://github.com/srebroa/Arduino/blob/master/ArduinoMega2560/Mecanum_wheel_robot/Mecanum_wheel_robot.ino

//Dual Motor Driver --> Arduino Setup
.----------------------.-----------------.--------------------.
|     TB6612FNG        | Type of Control | Arduino Connection |
:----------------------+-----------------+--------------------:
| RightFrontMotor_PWMA | PWM             |                  2 |
:----------------------+-----------------+--------------------:
| LeftFrontMotor_PWMB  | PWM             |                  3 |
:----------------------+-----------------+--------------------:
| RightRearMotor_PWMA  | PWM             |                  4 |
:----------------------+-----------------+--------------------:
| LeftRearMotor_PWMB   | PWM             |                  5 |
:----------------------+-----------------+--------------------:
| RightFrontMotor_AIN1 | Rotation        |                 22 |
:----------------------+-----------------+--------------------:
| RightFrontMotor_AIN2 | Rotation        |                 23 |
:----------------------+-----------------+--------------------:
| LeftFrontMotor_BIN1  | Rotation        |                 24 |
:----------------------+-----------------+--------------------:
| LeftFrontMotor_BIN2  | Rotation        |                 25 |
:----------------------+-----------------+--------------------:
| RightRearMotor_AIN1  | Rotation        |                 26 |
:----------------------+-----------------+--------------------:
| RightRearMotor_AIN2  | Rotation        |                 27 |
:----------------------+-----------------+--------------------:
| LeftRearMotor_BIN1   | Rotation        |                 28 |
:----------------------+-----------------+--------------------:
| LeftRearMotor_BIN2   | Rotation        |                 29 |
'----------------------'-----------------'--------------------'

//other definitons
.---------.------------.
| Symbols | Definition |
:---------+------------:
| STBY    | VCC        |
:---------+------------:
| VMOT    | Motor Volt |
:---------+------------:
| VCC     | Logic Volt |
:---------+------------:
| GND     | GND        |
'---------'------------'

//Dual Motor Driver --> DC Motor Setup
.------------------.-----------------.
|    TB6612FNG     |    DC Motors    |
:------------------+-----------------:
| MotorDriver1_A01 | RightFrontMotor |
:------------------+-----------------:
| MotorDriver1_A02 | RightFrontMotor |
:------------------+-----------------:
| MotorDriver1_B01 | LeftFrontMotor  |
:------------------+-----------------:
| MotorDriver1_B02 | LeftFrontMotor  |
:------------------+-----------------:
| MotorDriver2_A01 | RightRearMotor  |
:------------------+-----------------:
| MotorDriver2_A02 | RightRearMotor  |
:------------------+-----------------:
| MotorDriver2_B01 | LeftRearMotor   |
:------------------+-----------------:
| MotorDriver2_B02 | LeftRearMotor   |
'------------------'-----------------'


*/

#include <SoftwareSerial.h> //for HC-12 RF module

// Motor driver pins for motor 1
#define AIN1_1 2
#define AIN2_1 3
#define PWMA_1 9
#define BIN1_1 4
#define BIN2_1 5
#define PWMB_1 10

// Motor driver pins for motor 2
#define AIN1_2 6
#define AIN2_2 7
#define PWMA_2 11
#define BIN1_2 8
#define BIN2_2 12
#define PWMB_2 13

// HC-12 RF Module Pins
#define HC12_TX 10
#define HC12_RX 11

// PWM variables
long PWMA_VAL = 255;
long PWMB_VAL = 255;
byte pwmChannel = 0;
const char startNumDelim = "<";
const char endNumDelim = ">";

SoftwareSerial HC12(HC12_TX, HC12_RX); // HC-12 object

void setup(){
    // Motor Driver Setup
    pinMode(AIN1_1, OUTPUT);
    pinMode(AIN2_1, OUTPUT);
    pinMode(PWMA_1, OUTPUT);
    pinMode(BIN1_1, OUTPUT);
    pinMode(BIN2_1, OUTPUT);
    pinMode(PWMB_1, OUTPUT);

    pinMode(AIN1_2, OUTPUT);
    pinMode(AIN2_2, OUTPUT);
    pinMode(PWMA_2, OUTPUT);
    pinMode(BIN1_2, OUTPUT);
    pinMode(BIN2_2, OUTPUT);
    pinMode(PWMB_2, OUTPUT);

    // Init HC-12
    HC12.begin(9600);
    Serial.begin(9600);
    delay(100);

    // Init motor driver speed to 0
    analogWrite(PWMA_1, 0);
    analogWrite(PWMB_1, 0);
    analogWrite(PWMA_2, 0);
    analogWrite(PWMB_2, 0);

    // Init motors to stop
    digitalWrite(AIN1_1, LOW);
    digitalWrite(AIN2_1, LOW);
    digitalWrite(BIN1_1, LOW);
    digitalWrite(BIN2_1, LOW);
    digitalWrite(AIN1_2, LOW);
    digitalWrite(AIN2_2, LOW);
    digitalWrite(BIN1_2, LOW);
    digitalWrite(BIN2_2, LOW);
}

void loop(){
    // Read HC-12
    if(HC12.available()){
    }
}



//Function for controlling motors/values
void motorControl(String motorStr, int dir, int speed){
    int IN1 = 0; //input 1
    int IN2 = 0; //input 2
    int motorPWM = 0; //motor PWM

    //check which motor to control
    if(motorStr == "rf"){  // right front
        IN1 = AIN1_1;
        IN2 = AIN2_1;
        motorPWM = PWMA_1;
    }
    else if(motorStr == "lf"){ // left front
        IN1 = BIN1_1;
        IN2 = BIN2_1;
        motorPWM = PWMB_1;
    }
    else if(motorStr == "rr"){ // right rear
        IN1 = AIN1_2;
        IN2 = AIN2_2;
        motorPWM = PWMA_2;
    }
    else if(motorStr == "lr"){ // left rear
        IN1 = BIN1_2;
        IN2 = BIN2_2;
        motorPWM = PWMB_2;
    }

    //check direction
    if(dir == 1){ //forward
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
    }
    else if(dir == -1){ //backward
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
    }
    else if(dir == 0){ //stop
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, LOW);
    }

    analogWrite(motorPWM, speed);
}

void SetPWM(const long pwm, byte pwm_ch){
    if(pwm_ch == 1){ // drive motor
        analogWrite(PWMA_1, pwm);
        PWMA_VAL = pwm;
    }
    else if(pwm_ch == 2){ // steer motor
        analogWrite(PWMB_1, pwm);
        PWMB_VAL = pwm;
    }
}

void goForward(int mspeed){
    motorControl("rf", 1, mspeed);
    motorControl("lf", 1, mspeed);
    motorControl("rr", 1, mspeed);
    motorControl("lr", 1, mspeed);
}

void goBackward(int mspeed){
    motorControl("rf", -1, mspeed);
    motorControl("lf", -1, mspeed);
    motorControl("rr", -1, mspeed);
    motorControl("lr", -1, mspeed);
}

void moveRight(int mspeed){
    motorControl("rf", -1, mspeed);
    motorControl("lf", 1, mspeed);
    motorControl("rr", 1, mspeed);
    motorControl("lr", -1, mspeed);
}

void moveLeft(int mspeed){
    motorControl("rf", 1, mspeed);
    motorControl("lf", -1, mspeed);
    motorControl("rr", -1, mspeed);
    motorControl("lr", 1, mspeed);
}

void moveRightForward(int mspeed){
    motorControl("rf", 1, 0);
    motorControl("lf", 1, mspeed);
    motorControl("rr", 1, mspeed);
    motorControl("lr", 1, 0);
}

void moveRightBackward(int mspeed){
    motorControl("rf", -1, mspeed);
    motorControl("lf", 1, 0);
    motorControl("rr", 1, 0);
    motorControl("lr", -1, mspeed);
}

void moveLeftForward(int mspeed){
    motorControl("rf", 1, mspeed);
    motorControl("lf", 1, 0);
    motorControl("rr", 1, 0);
    motorControl("lr", 1, mspeed);
}

void moveLeftBackward(int mspeed){
    motorControl("rf", 1, 0);
    motorControl("lf", -1, mspeed);
    motorControl("rr", -1, mspeed);
    motorControl("lr", 1, 0);
}

void turnRight(int mspeed){
    motorControl("rf", -1, mspeed);
    motorControl("lf", 1, mspeed);
    motorControl("rr", -1, mspeed);
    motorControl("lr", 1, mspeed);
}

void turnLeft(int mspeed){
    motorControl("rf", 1, mspeed);
    motorControl("lf", -1, mspeed);
    motorControl("rr", 1, mspeed);
    motorControl("lr", -1, mspeed);
}

void stopRobot(int delay_ms){
    analogWrite(PWMA_1, 0);
    analogWrite(PWMB_1, 0);
    analogWrite(PWMA_2, 0);
    analogWrite(PWMB_2, 0);
    delay(delay_ms);
}


//Function for controlling motors/values
void processInput() {
    static long receivedValue = 0;
    static bool sign = false;
    byte c = Serial.read();

    switch (c){
        case endOfDelim: //reached end of delimiter
            if (sign){ // if sign is positive, make value negative
                SetPWM(-receivedValue, pwmChannel);
            }
            else{ // if sign is negative, leave it as is
                SetPWM(receivedValue, pwmChannel);
            }
        
        // fall through to start of delimiter
        case startOfDelim: 
            receivedValue = 0;
            sign = false;
            pwmChannel = 0;
            break;

        case 'f': // forward
            goForward(255);
            break;
        
        case 'b': // backward
            goBackward(255);
            break;
        
        case 'r': // right
            moveRight(255);
            break;
        
        case 'l': // left
            moveLeft(255);
            break;
        
        case 'tR': // turn right
            turnRight(255);
            break;
        
        case 'tL': // turn left
            turnLeft(255);
            break;
        
        case 'RF': // right forward
            moveRightForward(255);
            break;
        
        case 'RB': // right backward
            moveRightBackward(255);
            break;
        
        case 'LF': // left forward
            moveLeftForward(255);
            break;
        
        case 'LB': // left backward
            moveLeftBackward(255);
            break;
        
        case 's': // stop
            stopRobot(0);
            break;
        
        case 'x': // RightFrontMotor_PWM
            pwmChannel = 1; 
            break;
        
        case 'y': // LeftFrontMotor_PWM
            pwmChannel = 2; 
            break;

        case '0'...'9': // numbers
            receivedValue = receivedValue * 10 + (c - '0');
            break;
        
        case '-':
            sign = true;
            break;
    }

}
