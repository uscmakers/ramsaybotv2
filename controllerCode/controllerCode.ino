#include <SoftwareSerial.h>

//these are the analog input pins on the arduino
#define joyX A0
#define joyY A1
#define tasteButton 7

const char stationary='0';
const char upRight='2';
const char right='3';
const char downRight='4';
const char down='5';
const char downLeft='6';
const char left='7';
const char upLeft='8';
const char up='1';
const char taste='t';

//setting up the tx and rx pins for the arduino
SoftwareSerial HC12(10, 11); // HC-12 TX Pin, HC-12 RX Pin
 
char prevMessage=stationary;
void setup() {
  Serial.begin(4800);
  HC12.begin(9600);
  pinMode(tasteButton,INPUT);
}

//the location of the joystick rn
int xValue,yValue;

 
void loop() {
  //for taste button
  if(digitalRead(tasteButton)==HIGH){
    HC12.write(taste);
  }


//joystick code

  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
  // Serial.println(xValue);
  // Serial.print(yValue);
  Serial.println(prevMessage);
 
  //the joystick is in the center usually at 512,492 x,y coords
  if(xValue>500&&xValue<530){
    if(yValue>478&&yValue<507){
      //code for up
      if(prevMessage!=stationary){
        Serial.println(prevMessage);
        HC12.write(stationary);
        prevMessage=stationary;
      }
      
    }
  }//left:
  else if(xValue<=100){
      //upLeft
      if(yValue<=80){
        if(prevMessage!=upLeft){
          HC12.write(upLeft);
          prevMessage=upLeft;
        }
      }
      else if(yValue>=800){
        //downLeft
        if(prevMessage!=downLeft){
          HC12.write(downLeft);
          prevMessage=downLeft;
        }
      }
      else{
        if(prevMessage!=left){
          HC12.write(left);
          prevMessage=left;
        }
      }
  }//right
  else if(xValue>=923){
      //upRight
      if(yValue<=80){
        //code for upRight
        if(prevMessage!=upRight){
          HC12.write(upRight);
          prevMessage=upRight;
        }
      }
      else if(yValue>=800){
        //downRight
        if(prevMessage!=downRight){
          HC12.write(downRight);
          prevMessage=downRight;
        }
      }
      else{
        if(prevMessage!=right){
          HC12.write(right);
          prevMessage=right;
        }
      }
  }
  else{
    //look for up/down
    if(yValue<=80){
        if(prevMessage!=up){
          HC12.write(up);
          prevMessage=up;
        }
    }
    else{
        if(prevMessage!=down){
          HC12.write(down);
          prevMessage=down;
        }
    }
  }
}