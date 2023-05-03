#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Set these to your desired credentials.
const char *ssid = "esp32-webserver";
const char *password = "password";

AsyncWebServer server(80);

void handle_root(AsyncWebServerRequest *request) {
  request->send(200, "text/plain", "Hello from ESP32!");
}

void not_found(AsyncWebServerRequest *request) {
  request->send(404, "text/plain", "Not found");
}

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  server.on("/", handle_root);
  server.onNotFound(not_found);

  server.begin();
  Serial.println("Server started");
}

void loop() {}
