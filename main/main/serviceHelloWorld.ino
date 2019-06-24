





/**
 *  @brief  This function represents the task of a heartbeat, offering the user to 
 *          view over Serial Monitor if the HelTec ESP32-LoRa is in operation.
 *  @param  pvParameter - not in sue
 */
void hello_task(void *pvParameter) {


  while(1) {
    Serial.println("[Hello] \t Alive!");
    vTaskDelay(20000/portTICK_RATE_MS);
  }
}
