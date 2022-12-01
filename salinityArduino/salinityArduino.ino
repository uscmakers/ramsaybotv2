
//https://www.instructables.com/Water-Salinity-meter/ heavy reference
#include <DallasTemperature.h>

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

void setup() {
  pinMode(leftProbe, OUTPUT);
  pinMode(rightProbe, OUTPUT);
  Serial.begin(9600);

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
  avg = tot/samples;
  Serial.print("Average resistance is: ");
  Serial.print(avg);
}
