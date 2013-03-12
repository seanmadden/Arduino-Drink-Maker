/*
 **********************************************************************************************
 * The eventual goal of this is to be able to send a command from Bellatrix 
 * to my Arduino to open the valve and pour me a drink.
 **********************************************************************************************
*/

#include <Ethernet.h>
#include <SPI.h>
#include <EthernetUdp.h>

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
     
     udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
     Serial.println((char *)packetBuffer);
     String packet = String((char *)packetBuffer);
     if (packet == "OPEN")
     {
       OpenValve();
     } else {
       CloseValve();
     }
     packet = "";
     packetBuffer[0] = '\0';
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
