#include<Arduino.h>
// 定义LED引脚（ESP32开发板）
const int LED1_PIN = 18;    // ESP32板载LED（GPIO2）
const int LED2_PIN = 19;   // 外接LED的GPIO12
void toggleLED(int pin, String name);
void setup() {
  // 初始化串口通信
  Serial.begin(115200);
  
  // 设置LED引脚为输出模式
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  
  // 初始状态：两个LED都熄灭
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  
  // 打印启动信息
  Serial.println("Arduino/ESP32已启动，请输入指令：");
  Serial.println("'1' 切换LED1状态");
  Serial.println("'2' 切换LED2状态");
}

void loop() {
  // 检查串口是否有数据可读
  if (Serial.available() > 0) {
    // 读取一行字符串（直到换行符），注意串口助手需勾选“发送新行”
    String command = Serial.readStringUntil('\n');
    
    // 去除字符串两端的空白字符（如回车、空格等）
    command.trim();
    
    // 根据指令执行操作
    if (command == "1") {
      toggleLED(LED1_PIN, "LED1");
    } 
    else if (command == "2") {
      toggleLED(LED2_PIN, "LED2");
    }
    else {
      // 无效指令，不执行任何动作（可选：打印提示）
      // Serial.println("无效指令，请发送'1'或'2'");
    }
  }
}

/**
 * 切换指定LED的状态，并通过串口发送反馈
 * @param pin      LED引脚号
 * @param name     LED名称（用于反馈信息）
 */
void toggleLED(int pin, String name) {
  // 读取当前状态并取反
  int currentState = digitalRead(pin);
  int newState = !currentState;
  digitalWrite(pin, newState);
  
  // 根据新状态生成反馈信息
  String feedback;
  if (newState == HIGH) {
    feedback = name + "亮";
  } else {
    feedback = name + "灭";
  }
  
  // 通过串口发送反馈（自带换行）
  Serial.println(feedback);
}