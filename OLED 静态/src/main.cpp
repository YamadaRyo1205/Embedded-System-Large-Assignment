#include <Arduino.h>
#include <U8g2lib.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLED(U8G2_R0);

void setup() {
  OLED.begin();
  OLED.enableUTF8Print();
  OLED.setFont(u8g2_font_wqy12_t_gb2312);
}

void loop() {
 
  OLED.clearBuffer();
  OLED.setCursor(0, 10);
  OLED.print("Hello, world!");
  OLED.setCursor(0, 30);
  OLED.print("你好,世界!");
  OLED.sendBuffer();
  delay(1000);
}
