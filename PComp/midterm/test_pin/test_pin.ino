#define MaryHand A1
#define TomHand A2
#define MaryFoot A7
#define TomFoot A6
#define MaryMouth A0
#define TomMouth A3
#define MaryEye 4
#define TomEye 3
#define MaryHeart 2
#define TomHeart 6

void setup() {
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port
  }
  Serial.println("Serial Begin!");
}

void loop() {
  int sensorValue = analogRead(TomMouth);
  Serial.println(sensorValue);
}
