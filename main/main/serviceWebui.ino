
/**
 * ------------------------------------------------ LOCAL GLOBALS ------------------------------------------------
 */
const char *host = "esp32";




/**
 * ------------------------------------------------ PROTOTYPES ------------------------------------------------
 */
void startPage(AsyncWebServerRequest *request);





/**
 * ------------------------------------------------ HELPER FUNCTIONS ------------------------------------------------
 */



/**
 *  @brief    This function transmitts index.html stored in the SPIFFS to the requesting client
 *  @param    request - the request obtained from the client
 */
void startPage(AsyncWebServerRequest *request) {
  request->send(SPIFFS, "/index.html", "text/html");
}


/**
 * ------------------------------------------------ WEBUI TASK ------------------------------------------------
 */

/**
 *  @brief    This function represents the task in charge of offerening the webui to the clients.
 *  @param    pvParameter - not in use
 */
void serviceWebui(void *pvParameter) {

  AsyncWebServer webui(80);
  Serial.println("[WEBUI] \t starting DNS");
  MDNS.begin(host);


  /*
   * Routes for the webserver
   */
  webui.on("/", HTTP_GET, [](AsyncWebServerRequest *request){ 
    startPage(request);
  });

  webui.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request){ 
    request->send(SPIFFS, "/style.css", "text/css");
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

  webui.on("/i2cSettings", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", "text/html");                      // TODO: Edit index.html and send other data to client
  });

  webui.onNotFound([](AsyncWebServerRequest *request){
    request->send(404);
  });

  Serial.println("[WEBUI] \t starting");
  webui.begin();

  while(1) {
    vTaskDelay(200/portTICK_RATE_MS);
  }
}
