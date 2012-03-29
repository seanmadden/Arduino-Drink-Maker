/*
 **********************************************************************************************
 * The eventual goal of this is to be able to send a command from Bellatrix 
 * to my Arduino to open the valve and pour me a drink.
 **********************************************************************************************
*/

#include <Ethernet.h>
#include <SPI.h>

//mac address for my Arduino
byte mac[] = { 0x00, 0xAA, 0xBA, 0xC4, 0xFF, 0x21 };
IPAddress ip(192, 168, 0, 222);

EthernetServer server = EthernetServer(23);

void setup()
{
  Ethernet.begin(mac, ip);
  
  Serial.begin(9600);
  
  //Starts listening for clients on port 23
  server.begin();
}

void loop()
{
  EthernetClient client = server.available();
  if (client == true) {
    //command size limited to 12 right now
    char command[13];
    for (int i=0; i < 13; ++i)
    {
      command[i] = client.read(); 
    }
    command[12] = 0;
    Serial.println(command[0]);
  }  
}
