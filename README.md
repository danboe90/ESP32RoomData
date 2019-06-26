# Room Data Collector based on HelTec ESP32-LoRa

The project consists of an ESP32 microcontroller platform manufactured by HelTec Automation
and includes a LoRa-tranceiver module.

## Motivation and Goals

During my Masterthesis I found first evaluations of LoRa in the sector of home- and building-automation.
Therefore, my Motivation is build on top of the fact, that even, if LoRa is not designed especifically for 
building-automation, it would be fun to have an LoRa-based smart-home system.

## Features
The entire Project provides the following functionality:
- [x] task for WiFi connectivity 
- [x] task for providing webui
- [x] task for display handling
- [x] task for i2c connectivity
- [x] task for heartbeat (HelloWorld)

Additional functionality Webui:
- [x] Route for /home
- [x] Route for /roomSettings
- [x] Route for /wifiSettings
- [x] Route for /loraSettings
- [x] Route for /btSettings
- [x] Route for /i2cSettings

Responses of Webui:
- [x] Response for /home
- [ ] Response for /roomSettings
- [ ] Response for /wifiSettings
- [x] Response for /loraSettings
- [ ] Response for /btSettings
- [ ] Response for /i2cSettings
- [x] Response for /style.css


## Usage
Download the entire project to your hard-drive and flash the sketch to your HelTec ESP32-LoRa.
Do not forget to upload the data-directory to your SPIFFS.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://github.com/danboe90/ESP32RoomData/blob/master/LICENSE)