#include<Arduino.h>

// 定义LED引脚
const int ledPins[] = {18, 19, 21, 22};
// LED数量
const int ledCount = sizeof(ledPins) / sizeof(ledPins[0]);
// 延时毫秒数，控制流水速度
const int delayTime = 300;

void setup() {
  // 逐个设置引脚为输出模式
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW); // 初始熄灭
  }
}

void loop() {
  // 正向流水灯
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }

  // 反向流水灯（可选，注释掉则只单向流动）
  for (int i = ledCount - 2; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
    digitalWrite(ledPins[i], LOW);
  }
}