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

byte remoteIp[4];
unsigned int remotePort;
byte packetBuffer[UDP_TX_PACKET_MAX_SIZE];
char replyBuffer[] = "ack";

EthernetUDP udp;

void setup()
{
  Ethernet.begin(mac, ip);
  udp.begin(PORT);
  
  Serial.begin(9600);
  
  //Starts listening for clients on port 23
  
}

void loop()
{
   int packetSize = udp.parsePacket();
   
   if (packetSize)
   {
     packetSize = packetSize - 8; //header
     
     udp.read(packetBuffer, UDP_TX_PACKET_MAX_SIZE);
     Serial.println((char *)packetBuffer);
   }     
   delay(10);
}

