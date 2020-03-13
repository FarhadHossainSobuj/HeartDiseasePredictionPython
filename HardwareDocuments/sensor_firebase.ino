#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <FirebaseArduino.h>
#include <ArduinoJson.h>
 #include <ESP8266HTTPClient.h>
 
// Set these to run example.https://heartrate-62a9c.firebaseio.com/
#define FIREBASE_HOST "heartrate-62a9c.firebaseio.com" 
#define FIREBASE_AUTH "QpeLfCfgMDUsPRUzM9cDNnIsHzYHU9uHEHGvdoTg" 
#define WIFI_SSID "risky_virus"
#define WIFI_PASSWORD "sobuj683"
 
String myString;
int vr = A0; // variable resistor connected 
int sdata = 0; // The variable resistor value will be stored in sdata.
 
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(vr ,INPUT);
  // connect to wifi.
  pinMode(D0,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
      {
    Serial.print(".");
    delay(500);
      }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setString("welcomeMessage","Welcome to Heart Disease Prediction");
  Firebase.setString("groupMemberName","Farhad, Nibir");
}
 
void loop()
{
 
sdata = analogRead(vr);
if(sdata < 550){
  
} else {
  myString = String(sdata/8); 
  Serial.println(myString); 
  Firebase.setString("Your_Heart_Rate",myString);
}

delay(1000);            
}
