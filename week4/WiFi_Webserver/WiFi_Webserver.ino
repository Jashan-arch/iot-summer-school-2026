/*
-------------------------------------------------------
Project: Wi-Fi Temperature Monitor (ESP32)
Author: Shubh Jashan Singh
Date: 06-07-2026
-------------------------------------------------------
*/

#include <WiFi.h>
#include <WebServer.h>
#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT22
#define LED_PIN 2

DHT dht(DHTPIN, DHTTYPE);
WebServer server(80);

const char* ssid = "Wokwi-GUEST";
const char* password = "";

bool ledState = false;

String formatUptime() {
  unsigned long ms = millis();
  unsigned long secs = ms / 1000;
  unsigned long mins = secs / 60;
  unsigned long hrs = mins / 60;
  secs %= 60;
  mins %= 60;
  char buf[32];
  sprintf(buf, "%02lu:%02lu:%02lu", hrs, mins, secs);
  return String(buf);
}

String buildPage() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  String tempStr = isnan(t) ? "Error" : String(t, 1) + " &deg;C";
  String humStr  = isnan(h) ? "Error" : String(h, 1) + " %";

  String page = "<!DOCTYPE html><html><head>";
  page += "<meta http-equiv='refresh' content='10'>";
  page += "<title>ESP32 Weather Monitor</title>";
  page += "<style>";
  page += "body{font-family:Arial;text-align:center;background:#f0f4f8;margin-top:40px;}";
  page += ".card{background:white;display:inline-block;padding:30px 50px;border-radius:12px;box-shadow:0 4px 10px rgba(0,0,0,0.15);}";
  page += "h1{color:#333;} p{font-size:22px;color:#555;}";
  page += ".btn{padding:12px 24px;font-size:18px;border:none;border-radius:8px;background:";
  page += ledState ? "#e74c3c" : "#2ecc71";
  page += ";color:white;cursor:pointer;margin-top:15px;}";
  page += "</style></head><body>";
  page += "<div class='card'>";
  page += "<h1>ESP32 Temperature Monitor</h1>";
  page += "<p><b>Temperature:</b> " + tempStr + "</p>";
  page += "<p><b>Humidity:</b> " + humStr + "</p>";
  page += "<p><b>LED State:</b> " + String(ledState ? "ON" : "OFF") + "</p>";
  page += "<p><b>Uptime:</b> " + formatUptime() + "</p>";
  page += "<form action='/toggle' method='GET'>";
  page += "<button class='btn' type='submit'>Toggle LED</button>";
  page += "</form>";
  page += "<p style='font-size:14px;color:#999;'>Auto-refreshes every 10s</p>";
  page += "</div></body></html>";

  return page;
}

void handleRoot() {
  server.send(200, "text/html", buildPage());
}

void handleToggle() {
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState ? HIGH : LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
