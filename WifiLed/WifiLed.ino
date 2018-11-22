#include <WiFiEsp.h>
#include <WiFiEspServer.h>
#include <WiFiEspClient.h>
#include <WiFiEspUdp.h>

/* Node MCU ESP8266 IOT wifi dev. Board wifi connectivity test   code by Ashraf Minhaj.
  Tutorial on blog  www.youtube.com/c/fusebatti
  for any quory mail at ashraf_minhaj@yahoo.com
  Consider subscribing my youTube channel  www.youtube.com/c/fusebatti    */
//declare ESP8266 library
const char* ssid = "shiwan"; //Put your wifi network name here
const char* password = "shiwan11";   //Put your wifi password here
void setup() {
  Serial.begin(115200);      //initial Serial communication for serial monitor  Note:115200 depends on your board
  Serial.println();
  Serial.print("Wifi connecting to ");
  Serial.println( ssid );  WiFi.begin(ssid, password);    Serial.println();  Serial.print("Connecting");  while ( WiFi.status() != WL_CONNECTED ) 
  //while loop runs repeatedly unless condition is false 
  {                                    
      delay(500);      Serial.print(".");          }  Serial.println();  Serial.println("Wifi Connected Success!");
    Serial.print("NodeMCU IP Address : ");   //Shows the IP (Internet Protocol) number of your NodeMcu
  Serial.println(WiFi.localIP() );         //Gets the IP address of your Board  
  }
  
void loop(){ 
    }
 

