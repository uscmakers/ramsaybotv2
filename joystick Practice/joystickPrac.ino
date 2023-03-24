#define joyX A0
#define joyY A1
 
void setup() {
  Serial.begin(9600);
}
int xValue,yValue;

 
void loop() {
  // put your main code here, to run repeatedly:
  xValue = analogRead(joyX);
  yValue = analogRead(joyY);
 
  //print the values with to plot or view
  // Serial.print(xValue);
  // Serial.print("\t");
  // Serial.println(yValue);
  
  //the joystick is in the center usually at 512,492 x,y coords
  if(xValue>500&&xValue<530){
    if(yValue>478&&yValue<507){
      Serial.println("stationary");
    }
  }//left:
  else if(xValue<=100){
      //upLeft
      if(yValue<=80){
        Serial.println("upLeft");
      }
      else if(yValue>=800){
        //downLeft
        Serial.println("downLeft");
      }
      else{
        Serial.println("LEFT");
      }
  }//right
  else if(xValue>=923){
      //upRight
      if(yValue<=80){
        Serial.println("upRight");
      }
      else if(yValue>=800){
        //downLeft
        Serial.println("downRight");
      }
      else{
        Serial.println("RIGHT");
      }
  }
  else{
    //look for up/down
    if(yValue<=80){
      Serial.println("UP");
    }
    else{
      Serial.println("DOWN");
    }
  }
}