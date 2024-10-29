#define greenLED 3
#define yellowLED 4
#define whiteLED 5

int threshold_high = 800;
int threshold_low = 400;
int delay_time = 500;

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(whiteLED, OUTPUT);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(whiteLED, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int analog = analogRead(A0);
  if (analog > threshold_high){
    digitalWrite(whiteLED, LOW);
    digitalWrite(greenLED, LOW);
    LEDblinking(yellowLED, delay_time);
  }
  else if (analog > threshold_low){
    digitalWrite(yellowLED, LOW);
    digitalWrite(whiteLED, LOW);
    LEDblinking(greenLED, 2 * delay_time);
  }
  else{
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(whiteLED, HIGH);
  }
}

void LEDblinking(int LED, int delaytime){
  digitalWrite(LED, HIGH);
  delay(delaytime);
  digitalWrite(LED, LOW);
  delay(delaytime);
}