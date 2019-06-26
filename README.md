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
- [ ] Route for /home
- [ ] Route for /roomSettings
- [ ] Route for /wifiSettings
- [ ] Route for /loraSettings
- [ ] Route for  /btSettings

## Usage

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License
[MIT](https://github.com/danboe90/ESP32RoomData/blob/master/LICENSE)