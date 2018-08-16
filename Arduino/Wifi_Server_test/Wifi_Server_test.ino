#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h> 
#include <WebServer.h>
#include <ESPmDNS.h>
#include <SPIFFS.h>

const char* path_root   = "/index.html";
const char* ssid        = "auhome_aaEGx5";
const char* password    = "h5cgebfa5ebhfcj";
#define BUFFER_SIZE 16384
uint8_t buf[BUFFER_SIZE];

WebServer server(80);

void handleRoot(){
  Serial.println("Access");
  server.send(200, "text/html", (char *)buf);
}

boolean readHTML(){
  File htmlFile = SPIFFS.open(path_root, "r");
  if (!htmlFile) {
    Serial.println("Failed to open index.html");
    return false;
  }
  size_t size = htmlFile.size();
  if(size >= BUFFER_SIZE){
    Serial.print("File Size Error:");
    Serial.println((int)size);
  }else{
    Serial.print("File Size OK:");
    Serial.println((int)size);
  }
  htmlFile.read(buf,size);
  htmlFile.close();
  return true;
}

void LedOn(){
  Serial.println("ON");
  digitalWrite(4,HIGH);
  server.send(200, "text/html","OK");
}

void LedOff(){
  Serial.println("OFF");
  digitalWrite(4,LOW);
  server.send(200, "text/html","OK");
}

void setup() {
  pinMode(4,OUTPUT);
  Serial.begin(115200);
  SPIFFS.begin(true);
  if(!readHTML()){
    Serial.println("Read HTML error!!");
  }
  WiFi.begin(ssid, password);
  WiFi.mode(WIFI_STA);
  Serial.println("Connecting to Access Point");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  if (MDNS.begin("wifi-tng")) {
    Serial.println("MDNS responder started");
  }
  server.on("/", handleRoot);
  server.on("/on/", LedOn);
  server.on("/off/", LedOff);
  server.begin();
  MDNS.addService("http", "tcp", 80);    
}

void loop() {
  server.handleClient();
}
