//  FARM DATA RELAY SYSTEM
//
//  ESP-NOW Sensor Example
//
//  Developed by Timm Bogner (timmbogner@gmail.com) for Sola Gratia Farm in Urbana, Illinois, USA.
//  An example of how to send data via ESP-NOW using FDRS.
//

#include <Arduino.h>
#include "fdrs_node_config.h"
#include <fdrs_node.h>

float data1;
float data2;
time_t timetoPrint = 0;

float readTemp() {
  return 22.069;
}

float readHum() {
  return random(0, 100);
}

void setup() {
  beginFDRS();
}
void loop() {
  loopFDRS();
  if(millis() - timetoPrint > 1000 * 30) {
    printTime();
    pingFDRS(400);

  float data1 = readHum();
  loadFDRS(data1, HUMIDITY_T);
  float data2 = readTemp();
  loadFDRS(data2, TEMP_T);
  if(sendFDRS()){
      DBG("Big Success!");
  } else {
      DBG("Nope, not so much.");
  }

    timetoPrint = millis();
  }
  // for(int i = 0; i < 10; i++) {
  //   data1 = readHum();
  //   loadFDRS(data1, HUMIDITY_T);
  //   data2 = readTemp();
  //   loadFDRS(data2, TEMP_T);
  //   if(sendFDRS()){
  //     DBG("Big Success!");
  //   } else {
  //     DBG("Nope, not so much.");
  //   }
  //   pingFDRS(200);
  // }
  // sleepFDRS(10);  //Sleep time in seconds
}
