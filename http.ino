#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
 
const char* ssid = "snapoffice_01"; //modem de wifi
const char* password = "SnapAguascalientes"; //contraseña de tu modem
 
void setup () {
  
Serial.begin(115200); //comunicacion con el usuario
WiFi.begin(ssid, password);
Serial.println("Conectando a WiFi");

while (WiFi.status() != WL_CONNECTED) 
{
delay(1000); 
Serial.print("Conectando...");
}

Serial.println();
Serial.println("WiFi conectado");
Serial.print("Direccion IP:");
Serial.println(WiFi.localIP()); 
}

void loop() {
 
if (WiFi.status() == WL_CONNECTED) { //Checa el status de conexion del WiFi 
 
HTTPClient http;  //Declara el objeto a clase HTTPClient
Serial.println("[HTTP] Iniciando...");
 
http.begin("http://www.arduino.cc/asciilogo.txt");  //Destino del requerimiento especifico  
Serial.println("[HTTP] GET...");
int httpCode = http.GET();                         //Envia el requerimiento
 
if (httpCode > 0) { //Checa de regreso el codigo
 
String payload = http.getString();   //Tener la respuesta del requerimiento payload
Serial.println(payload);                     //Imprimir la respuesta
 
}
 
http.end();   //Cerrar conexion
 
}
 
delay(10000);    //Repetir el proceso cada 30 segundos
 
}
