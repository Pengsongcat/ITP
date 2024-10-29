#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino_LSM6DS3.h>
#include <DFRobotDFPlayerMini.h>

#define VOLUME 15

#define WaitTime 10999

#define SleepMary 1
#define ChokingTom 2
#define SneezeMary 3
#define SneezeTom 4
#define ScreamMary 5
#define ScreamTom 6
#define Laugh 7
#define Cry 8
#define Last 9


#define MaryHand A1
#define TomHand A2
#define MaryFoot A7
#define TomFoot A6
#define MaryNose A0
#define TomNose A3
#define MaryEye 4
#define TomEye 3
#define MaryHeart 2
#define TomHeart 6

extern DFRobotDFPlayerMini myDFPlayer;

void initialize(){
  // initialize serial communications
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port
  }
  Serial.println("Serial Begin!");

  // start imu
  if (!IMU.begin()) {
    Serial.println("Fail to initialize IMU!");
    while (1);
    delay(10);
  }
  Serial.println("IMU initialized!");

  // initialize dfplayer
  Serial1.begin(9600);
  if (!myDFPlayer.begin(Serial1)) {  // initialize DFPlayer Mini with Serial1
    Serial.println("DFPlayer Mini not detected.");
    while (true);  // halt program
  }
  myDFPlayer.volume(VOLUME);  // st volume (0-30)
  Serial.println("DFPlayer initialized!");

  // set pin mode
  pinMode(MaryEye, OUTPUT);
  pinMode(TomEye, OUTPUT);
  pinMode(MaryHeart, INPUT);
  pinMode(TomHeart, INPUT);

  // print Arduino ready
  Serial.println("Arduino Ready"); 
}

#endif