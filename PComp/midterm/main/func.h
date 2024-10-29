#ifndef FUNC_H 
#define FUNC_H

#include <Arduino_LSM6DS3.h>
#include <DFRobotDFPlayerMini.h>
#include "config.h"

extern DFRobotDFPlayerMini myDFPlayer;
extern unsigned long Timer;

extern int event;
extern unsigned long eventStartTime;
extern int timeLeft;

unsigned long Timer = 0;
bool ledState = HIGH;
int lastButtonState = LOW;
int pressCount = 0;


void fail(){ 
  delay(100);
  Serial.println("Event:fail");
  myDFPlayer.play(Laugh);   // Do the action of the fail event
  delay(4000);
  
  digitalWrite(MaryEye, LOW);
  digitalWrite(TomEye, LOW);
  
  ledState = HIGH;
  lastButtonState = LOW;
  pressCount = 0;

  event = 0;
  timeLeft = WaitTime;
  eventStartTime = millis();
  Timer = eventStartTime;
}

void Switch(){ 
  delay(100);
  Serial.println("Event:switch");
  digitalWrite(MaryEye, HIGH);
  digitalWrite(TomEye, HIGH);
  delay(4000);

  ledState = HIGH;
  lastButtonState = LOW;
  pressCount = 0;

  event += 1;
  timeLeft = WaitTime;
  eventStartTime = millis();
  Timer = eventStartTime;
}

void final(){
  delay(100);
  Serial.println("Event:final");
  myDFPlayer.play(Last);  // Do the action of the final event
  delay(10000);

  digitalWrite(MaryEye, LOW);
  digitalWrite(TomEye, LOW);

  ledState = HIGH;
  lastButtonState = LOW;
  pressCount = 0;

  event = 0;
  timeLeft = WaitTime;
  eventStartTime = millis();
  Timer = eventStartTime;
}

void EventStart(){
  // 显示规则，摇摇篮
  float x, y, z;
  if (IMU.accelerationAvailable()) { // read accelerator
    IMU.readAcceleration(x, y, z);
    // Serial.print("X: ");
    // Serial.print(x);
    // Serial.print(" m/s^2, Y: ");
    // Serial.print(y);
    // Serial.print(" m/s^2, Z: ");
    // Serial.print(z);
    // Serial.println(" m/s^2");
  }
  if (y >= 0.15 || y <= -0.15){    // if satisfy requirement of the start event
    myDFPlayer.play(Laugh);
    Switch();
  }
}

void Event1(){
  // mary尖叫(ScreamMary)，握住mary的手（MaryHand）
  if (millis() - Timer > 6000 || Timer == eventStartTime) {
    Timer = millis();
    myDFPlayer.play(ScreamMary);
  }
  
  int sensorValue = analogRead(MaryHand);
  if (sensorValue > 500){ // if satisfy requirement of event 1 
    Switch();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

void Event2(){  
  // tom尖叫(ScreamTom)），捂住Tom的口鼻（TomNose）
  if (millis() - Timer > 6000 || Timer == eventStartTime) {
    Timer = millis();
    myDFPlayer.play(ScreamTom);
  }

  int sensorValue = analogRead(TomNose);
  if (sensorValue < 60){  // if satisfy requirement of event 2
    Switch();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

void Event3(){
  // mary眼睛闪烁（MaryEye）， 按压Mary心脏5次（MaryHeart)
  if (millis() - Timer >= 500) {
    Timer = millis();
    ledState = !ledState;
    digitalWrite(MaryEye, ledState);
  }

  int buttonState = digitalRead(MaryHeart);
  if (buttonState == HIGH && lastButtonState == LOW) {
    pressCount++; 
    delay(20); 
  }
  lastButtonState = buttonState; 

  if (pressCount >= 5){
    Switch();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

void Event4(){  
  //tom眼睛闪烁(TomEye)，抓住tom的手（TomHand）
  if (millis() - Timer >= 500) {
    Timer = millis();
    ledState = !ledState;
    digitalWrite(TomEye, ledState);
  }

  int sensorValue = analogRead(TomHand);
  if (sensorValue > 500){ // if satisfy requirement of event 1 
    Switch();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

void Event5(){
  // mary打喷嚏(SneezeMary），捏住Mary的鼻子(MaryNose）
  if (millis() - Timer > 2800 || Timer == eventStartTime) {
    Timer = millis();
    myDFPlayer.play(SneezeMary);
  }

  int sensorValue = analogRead(MaryNose);
  if (sensorValue < 60){  // if satisfy requirement of event 2
    Switch();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

void Event6(){
  // tom窒息（ChokingTom），按压Tom心脏5次（TomHeart)
  if (millis() - Timer > 15000 || Timer == eventStartTime) {
    Timer = millis();
    myDFPlayer.play(ChokingTom);
  }

  int buttonState = digitalRead(TomHeart);
  if (buttonState == HIGH && lastButtonState == LOW) {
    pressCount++; 
    delay(20); 
  }
  lastButtonState = buttonState; 

  if (pressCount >= 5){
    Switch();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

void Event7(){
  // mary鼻子堵了（SleepMary）, 抓mary的脚 (MaryFoot）   
  if (millis() - Timer > 8000 || Timer == eventStartTime) {
    Timer = millis();
    myDFPlayer.play(SleepMary);
  }

  int sensorValue = analogRead(MaryFoot);
  if (sensorValue > 500){ // if satisfy requirement of event 1 
    Switch();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

void Event8(){
  // tom打喷嚏(SneezeTom），抓住tom的脚 (TomFoot）
  if (millis() - Timer > 2800 || Timer == eventStartTime) {
    Timer = millis();
    myDFPlayer.play(SneezeTom);
  }

  int sensorValue = analogRead(TomFoot);
  if (sensorValue > 500){ // if satisfy requirement of event 1 
    Switch();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

void EventLast(){
  // 一起哭，摇摇篮
  if (millis() - Timer > 12000 || Timer == eventStartTime) {
    Timer = millis();
    myDFPlayer.play(Cry);
  }

  float x, y, z;
  if (IMU.accelerationAvailable()) { // read accelerator
    IMU.readAcceleration(x, y, z);
    // Serial.print("X: ");
    // Serial.print(x);
    // Serial.print(" m/s^2, Y: ");
    // Serial.print(y);
    // Serial.print(" m/s^2, Z: ");
    // Serial.print(z);
    // Serial.println(" m/s^2");
  }
  if (y >= 0.15 || y <= -0.15){    // if satisfy requirement of the last event
    final();
  }
  else if (timeLeft < 0){  // if time out
    fail();
  }
}

#endif