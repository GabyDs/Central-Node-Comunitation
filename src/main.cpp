#include <WiFi.h>

const char* ssid     = "FIOUNAMBOTS";
const char* password = "fiounambots2025";

IPAddress local_IP(192,168,5,1);
IPAddress gateway(192,168,5,1);
IPAddress subnet(255,255,255,0);

void setup() {
  Serial.begin(115200);

  WiFi.softAP(ssid, password); //Start Acces point mode
  WiFi.softAPConfig(local_IP, gateway, subnet);
  Serial.println("Access Point Started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  
}

void loop() {
  // put your main code here, to run repeatedly:
}
