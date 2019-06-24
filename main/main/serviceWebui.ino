const char *host = "esp32";

void startPage(AsyncWebServerRequest *request);



void startPage(AsyncWebServerRequest *request) {
  request->send(SPIFFS, "/index.html", "text/html");
}


void serviceWebui(void *pvParameter) {

  AsyncWebServer webui(80);
  Serial.println("[WEBUI] \t starting DNS");
  MDNS.begin(host);

  webui.on("/", HTTP_GET, [](AsyncWebServerRequest *request){ 
    startPage(request);
  });

  webui.on("/home", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/home.html", "text/html");
  });

  webui.on("/roomSettings", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");                      // TODO: Edit index.html and send other data to client
  });

  webui.on("/wifiSettings", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");                      // TODO: Edit index.html and send other data to client
  });

  webui.on("/loraSettings", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/lora.html", "text/html");
  });

  webui.on("/btSettings", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");                      // TODO: Edit index.html and send other data to client
  });

  Serial.println("[WEBUI] \t starting");
  webui.begin();

  while(1) {
    vTaskDelay(200/portTICK_RATE_MS);
  }
}
