



U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);



void serviceDisplay(void *pvParameter) {
  Serial.println("[DISPLAY] \t starting");
  
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  u8x8.drawString(0, 20, "Room-Data-Collector");

  while(1) {
    vTaskDelay(2000/portTICK_RATE_MS);
  }
}



void write2Display(int row, int col, String text) {
  //u8x8.drawString(row, col, text);
}
