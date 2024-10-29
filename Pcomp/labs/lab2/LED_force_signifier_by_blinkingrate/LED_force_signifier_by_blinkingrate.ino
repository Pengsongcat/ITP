#define LEDpin 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LEDpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potValue =  analogRead(A0);
  Serial.println(potValue);
  
  digitalWrite(LEDpin, HIGH);
  delayMicroseconds(1023-potValue);
  digitalWrite(LEDpin, LOW);
  delayMicroseconds(1023-potValue);
  
  // delay(50);
}
