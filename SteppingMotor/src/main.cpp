#include <Arduino.h>

const int DelayTime = 5;          
const int Pin1 = 2;
const int Pin2 = 4;
const int Pin3 = 5;
const int Pin4 = 18;
const long STEPS_PER_REV = 4096;  
int CurrentStep = 0;              

void setup() {
  pinMode(Pin1, OUTPUT);
  pinMode(Pin2, OUTPUT);
  pinMode(Pin3, OUTPUT);
  pinMode(Pin4, OUTPUT);
  Serial.begin(115200);
  Serial.println("步进电机控制初始化完成");
}

void StepMotor(int step) {
  switch(step) {
    case 0:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, HIGH);
      break;
    case 1:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, HIGH);
      break;
    case 2:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, HIGH);
      break;
    case 3:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, LOW);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, HIGH);
      break;
    case 4:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, HIGH);
      break;
    case 5:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, LOW);
      digitalWrite(Pin4, LOW);
      break;
    case 6:
      digitalWrite(Pin1, HIGH);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, LOW);
      break;
    case 7:
      digitalWrite(Pin1, LOW);
      digitalWrite(Pin2, HIGH);
      digitalWrite(Pin3, HIGH);
      digitalWrite(Pin4, LOW);
      break;
  }
}

void loop() {
  if (Serial.available() > 0) {
    int angle = Serial.parseInt();           
    long steps = (long)angle * STEPS_PER_REV / 360;

    if (steps > 0) {
      for (long i = 0; i < steps; i++) {
        StepMotor(CurrentStep);
        delay(DelayTime);
        CurrentStep = (CurrentStep + 1) % 8; 
      }
    } else if (steps < 0) {
      steps = -steps;
      for (long i = 0; i < steps; i++) {
        StepMotor(CurrentStep);
        delay(DelayTime);
        CurrentStep = (CurrentStep - 1+8) % 8; 
      }
    }
  }
}