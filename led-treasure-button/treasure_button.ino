/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ArduinoJson.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

ESP8266WiFiMulti WiFiMulti;

void setup() {
  pinMode(D6, INPUT_PULLUP);
  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("FiWi-WLAN", "!Affenzirkus?");

}

void loop() {
  
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    String pattern;
    WiFiClient client;
    
    if(digitalRead(D6) == LOW) {
      //pattern = getActualPattern();
        setButtonHit();
      
    };

  }
}
String getActualPattern() {
return "";
}

void setButtonHit() {
  HTTPClient http;
  StaticJsonDocument<96> doc;

doc["command"]["setVars"]["isBuzzerHit"] = true;
doc["ids"][0] = 13434724;
String json;
serializeJson(doc, json);
      Serial.print("[HTTP] begin...\n");
    if (http.begin("http://192.168.178.119:80/command")) {  // HTTP
        http.addHeader("Content-Type","application/json");

      Serial.print("[HTTP] POST...\n");
      // start connection and send HTTP header
//Serial.print(json);
      int httpCode = http.POST(json);

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void setOrangePattern() {
  HTTPClient http;
  StaticJsonDocument<96> doc;
doc["command"]["programName"] = "prophet-orange";
doc["ids"][0] = 14934563;
String json;
serializeJson(doc, json);
      Serial.print("[HTTP] begin...\n");
    if (http.begin("http://192.168.178.119:80/command")) {  // HTTP
        http.addHeader("Content-Type","application/json");

      Serial.print("[HTTP] POST...\n");
      // start connection and send HTTP header
//Serial.print(json);
      int httpCode = http.POST(json);

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTP] POST... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = http.getString();
          Serial.println(payload);
        }
      } else {
        Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
      }

      http.end();
    } else {
      Serial.printf("[HTTP} Unable to connect\n");
    }
}

void setBluePattern() {