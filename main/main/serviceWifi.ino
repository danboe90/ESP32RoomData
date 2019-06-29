
const char *ssid = "CCTVNetwork";
const char *pass = "raspberry";



/**
 *  @brief    This function represents the task of handling WiFi connectivity
 */
void serviceWifi(void *pvParameter) {

  Serial.println("[WIFI] \t\t attempt connecting");
  WiFi.setHostname("ESPRoomData");
  WiFi.begin(ssid, pass);

  
  while(WiFi.status() != WL_CONNECTED) {
    vTaskDelay(10000/portTICK_RATE_MS);
  }

  Serial.print("[WIFI] \t\t connected with IP: ");
  Serial.println(WiFi.localIP());

  while(1) {
    if(WiFi.status() == WL_DISCONNECTED) {
      Serial.println("[WIFI] \t\t reconnect");
      WiFi.disconnect();
      WiFi.mode(WIFI_OFF);
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, pass);
    }
    vTaskDelay(20000/portTICK_RATE_MS);
  }
}
