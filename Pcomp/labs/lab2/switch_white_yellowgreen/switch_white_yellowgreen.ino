int peakValue = 0;
int threshold = 500;   //set your own value based on your sensors
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  //read sensor on pin A0:
  int sensorValue = analogRead(A0);
  // check if it's higher than the current peak:
  if (sensorValue > peakValue) {
    peakValue = sensorValue;
  }
  if (sensorValue <= threshold) {  // calculate when go back below threshold
    if (peakValue > threshold) {
      // you have a peak value:
      Serial.println(peakValue);
      // reset the peak variable:
      peakValue = 0;
    }
  }
}