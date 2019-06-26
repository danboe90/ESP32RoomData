



/**
 *  @brief  This function represents the task in charge of reading all available I2C Sensors
 *  @param  pvParameter - not in use
 */
void serviceI2Sens(void *pvParameter) {

  Adafruit_CCS811 ccs;
  BME280 bmp;

  Serial.println("[I2C-Sensor] \t starting");

  if(!ccs.begin()) { Serial.println("[I2C-Sensor] \t not able to start CO2"); }
  else {
    while(!ccs.available());    
    float temp_cal = ccs.calculateTemperature();
    ccs.setTempOffset(temp_cal - 25.0);
  }

  Wire.begin();
  bmp.setI2CAddress(0x76);
  if(!bmp.begin()) { Serial.println("[I2C-Sensor] \t not able to start BMP280"); }
  
  while(1) {
    if(ccs.readData() == 0) {
      int eCO2 = ccs.geteCO2();
      int tvoc = ccs.getTVOC();
      float temp = ccs.calculateTemperature();
      Serial.print("[I2C-Sensor] \t CO2: ");
      Serial.print(eCO2);
      Serial.print(" ppm \t ");
  
      Serial.print("TVOC: ");
      Serial.print(tvoc);
      Serial.print(" ppb \t ");
  
      Serial.print("Temperature: ");
      Serial.print((temp-32)/(1.8));
      Serial.println(" °C");
      
    }
    
    float bmpTemp = bmp.readTempC();   
    float humi = bmp.readFloatHumidity();

    Serial.print("[I2C-Sensor] \t TempBMP280: ");
    Serial.print(bmpTemp);
    Serial.print(" °C \t ");

    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.println(" %");
    
    Serial.println("------------------------------------------------");
    vTaskDelay(20000/portTICK_RATE_MS);
  }
}
