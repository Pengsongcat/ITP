#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11);  // TX, RX
DFRobotDFPlayerMini myDFPlayer;

void setup() {
  mySoftwareSerial.begin(9600);  // 设置软件串口的波特率
  Serial.begin(9600);            // 调试输出波特率

  if (!myDFPlayer.begin(mySoftwareSerial)) {  // 初始化 DFPlayer Mini
    Serial.println("DFPlayer Mini not detected.");
    while (true)
      ;  // 停止程序
  }

  Serial.println("DFPlayer Mini online.");
  myDFPlayer.volume(15);  // 设置音量 (范围：0-30)
}

void loop() {
  // 如果需要，可以在这里添加其他播放控制逻辑
  myDFPlayer.play(1);  // 播放第一个 MP3 文件
  delay(3000);
  myDFPlayer.next();
  delay(3000);
}
