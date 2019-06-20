#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*********************************************************
  Global variables + Defines
**********************************************************/

typedef struct {
    int Dn;
    int Dm;
    int Dx;
    float Sn;
    float Sm;
    float Sx;
    float Ta;
    float Ua;
    float Pa;
    float Rc;
    float Sr;
    int Lux;
    int T;
    int La;
    int Lo;
} wts;

wts weather_packet;

/*********************************************************
  Functions
**********************************************************/

void printWTSvalues(void)
{
  Serial.print("Dn: ");
  Serial.println(weather_packet.Dn);
  
  Serial.print("Dm: ");
  Serial.println(weather_packet.Dm);
}

void parseTest(void)
{
    char str[512];
    memset(str, 0, 512);

    // Send R0 command and dump response into str
    Serial1.print("0R0\r\n");
    Serial1.readBytesUntil("\n", str, 512);
    
    sscanf(str, const char * format, 
      weather_packet.Dn, weather_packet.Dm, weather_packet.Dx, 
      weather_packet.Sn, weather_packet.Sm, weather_packet.Sx, 
      weather_packet.Ta, weather_packet.Ua, weather_packet.Pa, 
      weather_packet.Rc, weather_packet.Sr, weather_packet.Lux,
      weather_packet.T, weather_packet.La, weather_packet.Lo);
      
  printWTSvalues();
}

/*********************************************************
  Init
**********************************************************/

void setup()
{
    Serial.begin(19200);
    Serial1.begin(19200);
    delay(2000);
    parseTest();
}

/*********************************************************
  Loop
**********************************************************/

void loop()
{
}
