#include "pitches.h"
 
const int threshold = 200;      // minimum reading of the sensors that generates a note
const int speakerPin = 8;      // pin number for the speaker
const int noteDuration = 20;   // play notes for 20 ms
 
// notes to play, corresponding to the 3 sensors:
int notes[] = {NOTE_A4, NOTE_B4, NOTE_D1};
int sensor[] = {A0, A1, A2};
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  for (int thisSensor = 0; thisSensor < 3; thisSensor++) {
    // get a sensor reading:
    int sensorReading = analogRead(sensor[thisSensor]);
    Serial.println(sensorReading); 
 
    // if the sensor is pressed hard enough:
    if (sensorReading > threshold) {
      // play the note corresponding to this sensor:
      tone(speakerPin, notes[thisSensor], noteDuration);
    }
  }
}