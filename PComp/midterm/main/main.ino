#include "func.h"
#include "config.h"
#include <Arduino_LSM6DS3.h>
#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;

int event = 0;   // 0 for the start
unsigned long eventStartTime = 0;
int timeLeft;

unsigned long SerialTimer = 0;

void setup() {
  initialize();
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

  if (event == 0) EventStart();
  if (event == 1) Event1();
  if (event == 2) Event2();
  if (event == 3) Event3();
  if (event == 4) Event4();
  if (event == 5) Event5();
  if (event == 6) Event6();
  if (event == 7) Event7();
  if (event == 8) Event8();
  if (event == 9) EventLast();

  delay(10);  // for stablity
}
