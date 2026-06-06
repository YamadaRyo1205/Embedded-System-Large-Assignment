#include <Arduino.h>

unsigned long lastTime = 0;
unsigned int a[4] = {2,4,5,18};
void setup() {
  for(int i = 0; i < 4; i++) {
    pinMode(a[i],OUTPUT);
  }
}
unsigned int i = 0;
void loop() {
  unsigned long nowTime = millis();
  if(nowTime - lastTime >= 1000) {
    digitalWrite(a[i],HIGH);
    delay(500);
    digitalWrite(a[i],LOW);
    i = (i + 1) % 4;
    lastTime = nowTime;
  }
}