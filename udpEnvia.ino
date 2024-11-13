#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "NOME DO WIFI";
const char* password = "SENHA";

WiFiUDP udp;
const char* udpAdress = " IP DO PC";  // IP DO NOTEBOOK
//abre o cmd >>>>> ipconfig
const int udpPORT = 1234;  //porta de envio

void setup() {
  Serial.begin(115200);
  Wifi.begin(ssid, password);

  //conectar na rede
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("\n Wifi conectado com sucesso!");
}

void loop() {
  const char* mensagem = "Olá da ESP8622";

  // envia a mensagem

  udp.beginPacket(udpAdress, udpPORT);
  udp.write(mensagem);
  udp.endPacket();

  delay(2000);  //pra poder enviar uma mensagem a cada 2 segundos
}
