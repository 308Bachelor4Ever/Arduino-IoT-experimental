/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  WARNING!
    It's very tricky to get it working. Please read this article:
    http://help.blynk.cc/hardware-and-libraries/arduino/esp8266-with-at-firmware

  Blynk using a LED widget on your phone!

  App project setup:
    LED widget on V1
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <WiFiEspServer.h>
#include <WiFiEspUdp.h>
#include <WiFiEspClient.h>
#include <WiFiEsp.h>
#include <SoftwareSerial.h>
#include <ESP8266_Lib.h>
#include <BlynkSimpleShieldEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "b60f347dc3744b63b0b95b3e0a025fb5";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "shiwan";
char pass[] = "shiwan11";

// Declare and intialise variable for radio status
int status = WL_IDLE_STATUS;

// or Software Serial on Uno, Nano...
SoftwareSerial Serial1(6, 7); // RX, TX

ESP8266 wifi(&Serial1);

WidgetLED led1(V1);

BlynkTimer timer;

// V1 LED Widget is blinking
void blinkLedWidget()
{
  if (led1.getValue()) {
    led1.off();
    Serial.println("LED on V1: off");
  } else {
    led1.on();
    Serial.println("LED on V1: on");
  }
}

void setup()
{
   pinMode(13, OUTPUT);

  // Initialize serial for debugging
  Serial.begin (115200);

  // Intialize serial for ESP module
  Serial1.begin(9600);

  // Initialize ESP module
WiFi.init(&Serial1);

//Check for the presences of the shield
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");

                   // Don't continue
                   while (true);
                 }

                   // Attempt to connect to WiFi netwok
                   while (status != WL_CONNECTED) {
                   Serial.print("Attempting to connect to SSID: ");
                   Serial.println(ssid);

                   //Connect to WPA/WPA2 network
                   status = WiFi.begin(ssid, pass);
                 }

                   Serial.println("You're connected to the network");
printWifiStatus();

  Blynk.begin(auth, wifi, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, wifi, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, wifi, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, blinkLedWidget);
}

void loop()
{
  Blynk.run();
  timer.run();
}

void printWifiStatus() {
// Print the SSID of the network
Serial.print("SSID: ");
Serial.println(WiFi.SSID());

// Print the IP address
IPAddress ip = WiFi.localIP();
Serial.print("IP Address: ");
Serial.println(ip);
}

