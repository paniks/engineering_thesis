//#include "Timer.h"
#include "include/ANFIS.h"
#include "third_party/due_timer/due_timer.h"

ANFIS left = ANFIS();
ANFIS right = ANFIS();

bool ISRflag = false;

void setup() 
{
  Timer1.attachInterrupt(setTimer1Flag).setFrequency(1000).start();

  // put your setup code here, to run once:
  analogReadResolution(12);
  Serial.begin(115200);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  if (ISRflag == true)
  {
    float pinA0 = analogRead(A0);
    Serial.print(pinA0);
    Serial.print(" ");
    float pinA1 = analogRead(A1);
    Serial.print(pinA1);
    Serial.print(" ");
    float pinA2 = analogRead(A2);
    Serial.print(pinA2);
    Serial.print(" ");
    float pinA3 = analogRead(A3);
//    Serial.print(pinA3);
//    Serial.print(" ");
    float pinA4 = analogRead(A4);
//    Serial.print(pinA4);
//    Serial.print(" ");
    float pinA5 = analogRead(A5);
//    Serial.print(pinA5);
//    Serial.print(" ");
//    Serial.println();
   
   
    ISRflag = false;

    float result_left = left.classify(pinA0, pinA1, pinA2);
//    Serial.print(400 * result_left);
    Serial.print(" ");
//    float result_right = right.classify(pinA3, pinA4, pinA5);
//    Serial.print(400*result_right);
//    Serial.print(" ");
    Serial.println();  
  }
}

void setTimer1Flag()
{
  ISRflag = true;
}


