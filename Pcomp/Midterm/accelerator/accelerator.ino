#include <Arduino_LSM6DS3.h>  // 包含 LSM6DS3 库

void setup() {
  // 初始化串口通信
  Serial.begin(9600);
  while (!Serial);

  // 初始化 IMU
  if (!IMU.begin()) {
    Serial.println("无法初始化IMU传感器！");
    while (1);
    delay(10);
  }

  Serial.println("IMU初始化成功！");
}

void loop() {
  float x, y, z;

  // 读取加速度数据
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    // 输出三轴加速度数据到串口监视器
    Serial.print("加速度X: ");
    Serial.print(x);
    Serial.print(" m/s^2, Y: ");
    Serial.print(y);
    Serial.print(" m/s^2, Z: ");
    Serial.print(z);
    Serial.println(" m/s^2");
  }

  delay(100);  // 每0.5秒更新一次
}