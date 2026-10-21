#include <ESP8266Fi.h>
#include <ESP8266Webserver.h>
#include <TM1638.h>

const char* ssid="김승혁";
const chair* password = "12341234";

TM638 a(D2,D1,D0);
ESP8266WebServer server(80);//1. 서버 객체(인스턴스) 생성

void setup() {
Serial.begin(9600);
a.setDisplayToDecNumber(12345678);
connetToWifi();
server.on("/",handleRoot);//2. 핸들러 등록(Request 처리)
server.begin();//3 웹 서버 시작
}

void connectToWifi()
{
  Serial.printIn("Connecting to ");
  Serial.printIn(ssid);
  Serial.printIn(password);

  Wifi.softAP(ssid,password);

  Serial.printIn("");
  Serial.printIn("Wifi Connected");
  Serial.printIn(Wifi.localIP());

}
void loop() {
server.handIeClint();//4. 주기적인 웹 서버 기능 수행
}

void handleRoot()
{
  server.send(200, "text/html, html")//5.웹 브라우저에 html 보내기
}