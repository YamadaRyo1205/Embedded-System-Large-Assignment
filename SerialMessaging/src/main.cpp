#include <Arduino.h>

void setup() {
    Serial.begin(115200);
    pinMode(2,OUTPUT);
    pinMode(4,OUTPUT);
}

void loop() {
    if (Serial.available() > 0) {
        char receivedData = Serial.read();
        if(receivedData == '1') {
            digitalWrite(2, digitalRead(2) == LOW ? HIGH : LOW);
        } else if(receivedData == '2') {
            digitalWrite(4, digitalRead(4) == LOW ? HIGH : LOW);
        }
    }
}