int ledPin = 13;
int buttonPin = 2;
int buttonState = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // 读取按钮状态
  buttonState = digitalRead(buttonPin);
  
  // 将按钮状态通过串口发送到 p5.js
  if (buttonState == HIGH) {
    Serial.println("1");
  } else {
    Serial.println("0");
  }

  // 如果从 p5.js 接收到 "on"，点亮 LED；接收到 "off"，关闭 LED
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    if (command == "on") {
      digitalWrite(ledPin, HIGH);
    } else if (command == "off") {
      digitalWrite(ledPin, LOW);
    }
  }
}