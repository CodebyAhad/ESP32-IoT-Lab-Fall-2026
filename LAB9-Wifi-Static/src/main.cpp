
#include <WiFi.h>

const char* ssid = "carpe diem";
const char* password = "12345678";

// Static IP configuration
IPAddress local_IP(192, 168, 43, 100);
IPAddress gateway(192, 168, 43, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress primaryDNS(8, 8, 8, 8);
IPAddress secondaryDNS(8, 8, 4, 4);

void setup() {
  Serial.begin(115200);
  delay(1000);

  WiFi.mode(WIFI_STA);

  // Configure static IP before connecting
  if (!WiFi.config(local_IP, gateway, subnet,
                   primaryDNS, secondaryDNS)) {
    Serial.println("Static IP configuration failed!");
  }

  Serial.println("Connecting to hotspot...");
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\nWiFi Connected!");

  Serial.print("Static IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
}

void loop() {
}
