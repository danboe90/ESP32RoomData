
const char *ssid = "Your-SSID";
const char *pass = "Your-Password";



void serviceWifi(void *pvParameter) {

  Serial.println("[WIFI] \t\t attempt connecting");
  WiFi.begin(ssid, pass);

  
  while(WiFi.status() != WL_CONNECTED) {
    vTaskDelay(10000/portTICK_RATE_MS);
  }

  Serial.print("[WIFI] \t\t connected with IP: ");
  Serial.println(WiFi.localIP());

  while(1) {
    if(WiFi.status() != WL_CONNECTED) {
      Serial.println("[WIFI] \t\t reconnect");
      WiFi.disconnect();
      WiFi.mode(WIFI_OFF);
      WiFi.mode(WIFI_STA);
      WiFi.begin(ssid, pass);
    }
    vTaskDelay(20000/portTICK_RATE_MS);
  }
}
