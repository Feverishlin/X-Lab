#include <Arduino.h>
#include <LiquidCrystal.h>

// 按照您的接线顺序初始化 LCD 对象：(RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(2, 23, 18, 19, 21, 22); 

void setup() {
  // 初始化串口通信，用于接收电脑端输入的字符
  Serial.begin(115200); 
  
  // 设置 LCD 为 16列 2行
  lcd.begin(16, 2); 
  
  // 提示用户开始输入
  lcd.print("Enter text:");
  Serial.println("Please enter text to display on LCD:");
}

void loop() {
  // 检查串口是否有数据输入
  if (Serial.available() > 0) {
    // 读取串口输入的一整行字符串
    String inputText = Serial.readStringUntil('\n'); 
    
    // 清除屏幕旧内容
    lcd.clear(); 
    
    // 将光标移动到第一行第一列并打印文字
    lcd.setCursor(0, 0); 
    lcd.print(inputText); 
    
    // 将接收到的文字回显到串口监视器
    Serial.print("Displaying: "); 
    Serial.println(inputText);
  }
}
