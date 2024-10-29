#include <DFRobotDFPlayerMini.h>

DFRobotDFPlayerMini myDFPlayer;
unsigned long timer = 0;

void setup() {
  Serial1.begin(9600);  // 初始化硬件串口1的波特率
  Serial.begin(9600);   // 初始化调试串口

  if (!myDFPlayer.begin(Serial1)) {  // 使用硬件串口1初始化 DFPlayer Mini
    Serial.println("DFPlayer Mini not detected.");
    while (true);  // 停止程序
  }

  myDFPlayer.volume(20);  // 设置音量 (范围：0-30)
}

void loop() {
  if (millis() - timer > 3000) {
    timer = millis();
    myDFPlayer.play(19);  // 每3秒播放下一个 MP3 文件
  }
  delay(100);
}