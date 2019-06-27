










/**
 * ------------------------------------------------ INCLUDES ------------------------------------------------
 */
#include <FreeRTOS.h>             // RTOS
#include <WiFi.h>                 // STA and SoftAP
#include <WebServer.h>
#include <ESPAsyncWebServer.h>    // Asnychronous WebServer for WebUI
#include <ESPmDNS.h>              // DNS Service
#include <Update.h>               // OTA Service
#include <EEPROM.h>
#include <SPIFFS.h>               // Flash File System
#include <U8x8lib.h>              // Display
#include <Adafruit_CCS811.h>      // CO2 Sensor
#include <SparkFunBME280.h>       // BMP280 Sensor
#include <Wire.h>
#include <ArduinoJson.h>          // JSON Support

/**
 * ------------------------------------------------ GLOBALS ------------------------------------------------
 */

 const char *fmw_version = "0.0.1";
 const char *productCode = "HelTec ESP32-LoRa";

/**
 * ------------------------------------------------ PROTOTYPES ------------------------------------------------
 */
void hello_task     (void *pvParameter);
void serviceWifi    (void *pvParameter);
void serviceWebui   (void *pvParameter);
void serviceDisplay (void *pvParameter);
void serviceI2Sens  (void *pvParameter);

void write2Display(int row, int col, String text);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // Init the filesystem#
  if(!SPIFFS.begin(true)) {
    Serial.println("[SETUP] \t SPIFFS not initializied (closing)");
    return;
  }


  xTaskCreate(&hello_task,    "helloWorld", 2048, NULL, 8, NULL);
  xTaskCreate(&serviceWifi,   "wifi",       4096, NULL, 4, NULL);
  xTaskCreate(&serviceWebui,  "webui",      4096, NULL, 3, NULL);
  xTaskCreate(&serviceDisplay,"display",    2048, NULL, 5, NULL);
  xTaskCreate(&serviceI2Sens, "I2C",        2048, NULL, 6, NULL);

  Serial.println("[SETUP] \t complete");

}

void loop() {
  // put your main code here, to run repeatedly:

}
