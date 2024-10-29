#define greenLED 3
#define yellowLED 4
#define whiteLED 5

int analog_threshold = 500;
int time_thre_low = 1000;
int time_thre_high = 3000;
int delay_time = 500;

int state = LOW;
int start_time = 0;

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
  
  if (analog > analog_threshold){
    if (state == LOW){
      // press begin!
      state = HIGH;
      start_time = millis();
    }
    if (millis() - start_time > time_thre_high){
      digitalWrite(whiteLED, LOW);
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, HIGH);
      delay(delay_time);
      digitalWrite(yellowLED, LOW);
      delay(delay_time);
    }
    else if (millis() - start_time > time_thre_low){
      digitalWrite(yellowLED, LOW);
      digitalWrite(whiteLED, LOW);
      digitalWrite(greenLED, HIGH);
    }
    else {
      digitalWrite(greenLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(whiteLED, HIGH);
    }
  }
  else{
    state = LOW;
    digitalWrite(greenLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(whiteLED, HIGH);
  }
}
