#include <WiFi.h>
#include <PicoMQTT.h>

const char *ssid = "FIOUNAMBOTS";
const char *password = "fiounambots2025";
IPAddress local_IP(192, 168, 5, 1);
IPAddress gateway(192, 168, 5, 1);
IPAddress subnet(255, 255, 255, 0);

PicoMQTT::Client mqtt(
    "192.168.5.99", // Broker
    1883,           // Port
    "ESP32CAM",     // Client ID
    "user1",        // Username
    "1234"          // Password
);

const int id_robot1 = 1;
const int id_robot2 = 2;
const int id_robot3 = 3;

void setup()
{
  Serial.begin(115200);

  WiFi.softAP(ssid, password); // Start Acces point mode
  WiFi.softAPConfig(local_IP, gateway, subnet);
  Serial.println("Access Point Started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());

  // Subscribe to a every topic
  mqtt.subscribe("#", [](const char *topic, const char *payload)
                 { Serial.printf("Received message in topic '%s': %s\n", topic, payload); });

  // Start the client
  mqtt.begin();
}

void loop()
{
  // This will automatically reconnect the client if needed.
  // Re-subscribing to topics is never required.
  mqtt.loop();

  // Publish a message for each robot
  mqtt.publish("robot/1/action", "Forward");
  mqtt.publish("robot/2/action", "Forward");
  mqtt.publish("robot/3/action", "Backward");
  delay(10000);
}
