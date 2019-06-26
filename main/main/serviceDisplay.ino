







/**
 *  @brief    This function represents the task beeing executed and in charge of 
 *            writing data to the built in Display of the HelTec ESP32-LoRa
 *  @param    pcParameter - not used
 */
void serviceDisplay(void *pvParameter) {
  
  U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ 15, /* data=*/ 4, /* reset=*/ 16);
  
  Serial.println("[DISPLAY] \t starting");
  
  u8x8.begin();
  u8x8.setFont(u8x8_font_chroma48medium8_r);

  u8x8.drawString(0, 20, "Room-Data-Collector");

  while(1) {
    vTaskDelay(2000/portTICK_RATE_MS);
  }
}


/**
 *  @brief  Wrapper Function for writing to the display
 *  @param  row - where to start writing
 *  @param  col - where to start writing
 *  @param  text - to be written
 */
void write2Display(int row, int col, String text) {
  //u8x8.drawString(col, row, text);
}
