#include "func.h"
#include "config.h"
#include <Arduino_LSM6DS3.h>
#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;

int event = 0; 
int event_list[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

unsigned long eventStartTime = 0;
int timeLeft;

unsigned long SerialTimer = 0;

void setup() {
  initialize();
  randomSeed(analogRead(0)); 
  shuffleEvent();
}
 
void loop() {
  timeLeft = WaitTime - (millis() - eventStartTime);

  if (millis() - SerialTimer >= 200) {
    Serial.print("Timeleft:");
    Serial.println(timeLeft/1000);
    Serial.print("Event:");
    Serial.println(event);
    SerialTimer = millis(); 
  }

  if (event_list[event] == 0) EventStart();
  if (event_list[event] == 1) Event1();
  if (event_list[event] == 2) Event2();
  if (event_list[event] == 3) Event3();
  if (event_list[event] == 4) Event4();
  if (event_list[event] == 5) Event5();
  if (event_list[event] == 6) Event6();
  if (event_list[event] == 7) Event7();
  if (event_list[event] == 8) Event8();
  if (event_list[event] == 9) EventLast();

  delay(10);  // for stablity
}
