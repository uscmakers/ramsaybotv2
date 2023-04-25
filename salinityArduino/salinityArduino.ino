#include <DallasTemperature.h>

#include "SoftwareSerial.h" // Speaker_Code
#include "DFRobotDFPlayerMini.h" // Speaker_Code
#include <Stepper.h>

// IMPORTANT: CHANGE PIN_MP3_TX and PIN_MP3_RX ACCORDING TO FINAL BREADBOARD
static const uint8_t PIN_MP3_TX = 2; // Speaker_Code
static const uint8_t PIN_MP3_RX = 3; // Speaker_Code

SoftwareSerial softwareSerial(PIN_MP3_RX, PIN_MP3_TX); // Speaker_Code

const int wirePin = 4; // Speaker_Code
const int endPin = 5;  // Speaker_Code
long rand_sound_choice;  // Speaker_Code
DFRobotDFPlayerMini player; // Speaker_Code

//pin setup
int analogPin = 0;
int raw = 0;
int leftProbe = 3;
int rightProbe = 5;
//voltage setup
int Vin = 3.3;
int Vout = 0;
//R1, R2 values
float R1 = 39;
float R2 = 0;
int samples = 15;
float delayTime = 0.5;
float avg = 0;
float buff = 0;
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;

Stepper motor(200, in1Pin, in2Pin, in3Pin, in4Pin);



void setup() {

  pinMode(leftProbe, OUTPUT);
  pinMode(rightProbe, OUTPUT);
  Serial.begin(9600);

  pinMode(wirePin, INPUT); // Speaker_Code
  pinMode(endPin, INPUT); // Speaker_Code
  // Init serial port for DFPlayer Mini
  softwareSerial.begin(9600); // Speaker_Code
  // Change if we have something plugged into Port 0
  randomSeed(analogRead(0)); // Speaker_Code

  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);

  motor.setSpeed(60)
}


void playSound(int sound){ // Speaker_Code
  
  if (player.begin(softwareSerial)) { // Speaker_Code
   Serial.println("OK"); // Speaker_Code
    player.volume(30); // Speaker_Code
    player.play(sound); // Speaker_Code
  } else { // Speaker_Code
    Serial.println("Connecting to DFPlayer Mini failed!"); // Speaker_Code
    playSound(sound); // Speaker_Code
    return; // Speaker_Code
  }
}


void loop() {
    float tot = 0;
    for(int i = 0; i < samples; i++){
      //generate PWM
      digitalWrite(leftProbe, LOW);
      digitalWrite(rightProbe, HIGH);
      delay(delayTime);
      digitalWrite(leftProbe, HIGH);
      digitalWrite(rightProbe, LOW);
      delay(delayTime);
      //read voltage on pin
      raw = analogRead(analogPin);
      if(raw){
        buff = raw * Vin;
        Vout = (buff)/1024.0;
        buff = (Vin/Vout) - 1;
        R2 = R1 * buff;
        tot = tot + R2;
      }
    }
    Serial.println("clockwise")
    myStepper.step(200);
    delay(500);
    
    avg = tot/samples;
    Serial.print("Average resistance is: ");
    Serial.print(avg);
    
    // Speaker_Code Below
    rand_sound_choice = rand()%4 + 4;
    if(avg > 80000){
      // Super Salty
      playSound(1);
    }
    else if(avg > 50000){
      // Good Salt
      playSound(2);
    }
    else if(avg > 40000){
      // A tiny bit too little
      playSound(3);
    }
    else if(avg > 1000){
      // Not Enough Salt
      playSound(rand_sound_choice);
    }
    else{
      // No Salt
      playSound(8);
    }

    Serial.println("counterclockwise")
    myStepper.step(-200);
    delay(500);
}
