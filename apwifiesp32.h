#include <Arduino.h>
#include <EEPROM.h>
#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

#define MAX_SSID_SIZE 32
#define MAX_PASSWORD_SIZE 64

#define EEPROM_SSID_ADDRESS 0
#define EEPROM_PASSWORD_ADDRESS (EEPROM_SSID_ADDRESS + MAX_SSID_SIZE)

void handleRoot() {
  String html = "<html><body>";
  html += "<form method='POST' action='/wifi'>";
  html += "Red Wi-Fi: <input type='text' name='ssid'><br>";
  html += "Contraseña: <input type='password' name='password'><br>";
  html += "<input type='submit' value='Conectar'>";
  html += "</form></body></html>";
  server.send(200, "text/html", html);
}

void handleWifi() {
  String ssid = server.arg("ssid");
  String password = server.arg("password");

  Serial.print("Conectando a la red Wi-Fi ");
  Serial.println(ssid);
  Serial.print("Clave Wi-Fi ");
  Serial.println(password);
  Serial.print("...");

  WiFi.disconnect();
  WiFi.begin(ssid.c_str(), password.c_str(), 6);
  int cnt = 0;
  while (WiFi.status() != WL_CONNECTED && cnt < 30) {
    delay(1000);
    Serial.print(".");
    cnt++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    EEPROM.writeString(EEPROM_SSID_ADDRESS, ssid);
    EEPROM.writeString(EEPROM_PASSWORD_ADDRESS, password);
    EEPROM.commit();

    Serial.println("Conexión establecida");
    server.send(200, "text/plain", "Conexión establecida");
  } else {
    Serial.println("Conexión no establecida");
    server.send(200, "text/plain", "Conexión no establecida");
  }
}

void initAP(const char *apSsid, const char *apPassword) {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(apSsid, apPassword);

  server.on("/", handleRoot);
  server.on("/wifi", handleWifi);

  server.begin();
}

void loopAP() {
  server.handleClient();
}