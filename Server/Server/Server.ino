/*
 **********************************************************************************************
 * The eventual goal of this is to be able to send a command from Bellatrix 
 * to my Arduino to open the valve and pour me a drink.
 **********************************************************************************************
*/

#include <Ethernet.h>
#include <SPI.h>
#include <EthernetUdp.h>
#include <aJSON.h>

//mac address for my Arduino
byte mac[] = { 0x00, 0xAA, 0xBA, 0xC4, 0xFF, 0x21 };
IPAddress ip(10, 0, 0, 66);
int PORT = 8771;

//Received packet stuff
byte remoteIp[4];
unsigned int remotePort;
byte packetBuffer[UDP_TX_PACKET_MAX_SIZE];
char replyBuffer[] = "ack";

EthernetUDP udp;
aJsonStream ethStream(&udp);

//Pin for the valve
unsigned int valvePin = 4;

void setup()
{
  Ethernet.begin(mac, ip);
  udp.begin(PORT);
  pinMode(valvePin, OUTPUT);
  
  Serial.begin(9600);
  
  //Starts listening for clients on port 23
  
}

void loop()
{
   int packetSize = udp.parsePacket();
   
   if (packetSize)
   {
     Serial.print("Received packet of size ");
     Serial.println(packetSize);
     
     aJsonObject* jsonObject = aJson.parse(&ethStream);
     
     //JSON I'm current sending: {'ing0': 'rum', 'ing1': 'cola'}
     aJsonObject *name = aJson.getObjectItem(jsonObject, "ing0");
     aJsonObject *name2 = aJson.getObjectItem(jsonObject, "ing1");
     
     //Sooo, you need to print out the name->valueint, not valuestring (which parses it as a string... duh)
     Serial.println(name->valuestring);
     Serial.println(name2->valuestring);
   }     
   delay(10);
}

void OpenValve()
{
  digitalWrite(valvePin, HIGH);
  Serial.println("Valve Open!");
}

void CloseValve()
{
  digitalWrite(valvePin, LOW);
  Serial.println("Valve Closed!");
}
