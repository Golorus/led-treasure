/**
   BasicHTTPClient.ino

    Created on: 24.05.2015

*/
#include <ESP8266WiFi.h>
#include <WebSocketClient.h>

#define activate_Pin D6

const char* ssid     = "FiWi-Desktop";
const char* password = "e8749Q)6";
char path[] = "/";
char host[] = "192.168.137.62";
string output  
WebSocketClient webSocketsClient;

// Use WiFiClient class to create TCP connections
WiFiClient client;

void setup() {
  pinMode(activate_Pin,INPUT_PULLUP);
  Serial.begin(115200);
  delay(10);
StaticJsonDocument<32> doc;

doc["setVars"]["isBuzzerHit"] = true;

serializeJson(doc, output);
  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(5000);
  

  // Connect to the websocket server
  if (client.connect(host, 81)) {
    Serial.println("Connected");
  } else {
    Serial.println("Connection failed.");
    while(1) {
      // Hang on failure
    }
  }

  // Handshake with the server
  webSocketsClient.path = path;
  webSocketsClient.host = host;
  if (webSocketsClient.handshake(client)) {
    Serial.println("Handshake successful");
  } else {
    Serial.println("Handshake failed.");
    while(1) {
      // Hang on failure
    }  
  }

}


void loop() {
  String data;

  if (client.connected()) {
    
       // capture the value of analog 1, send it along
    if (digitalRead(activate_Pin)) {
    webSocketsClient.sendData(output);
    }
  } else {
    Serial.println("Client disconnected.");
    while (1) {
      // Hang on disconnect.
    }
  }
  
  // wait to fully let the client disconnect
  delay(3000);
  
}