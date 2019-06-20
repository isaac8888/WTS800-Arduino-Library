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
    float La;
    float Lo;
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

  Serial.print("Dx: ");
  Serial.println(weather_packet.Dx);
  
  Serial.print("Sn: ");
  Serial.println(weather_packet.Sn);
  
  Serial.print("Sm: ");
  Serial.println(weather_packet.Sm);

  Serial.print("Sx: ");
  Serial.println(weather_packet.Sx);

  Serial.print("Ta: ");
  Serial.println(weather_packet.Ta);
  
  Serial.print("Ua: ");
  Serial.println(weather_packet.Ua);

  Serial.print("Pa: ");
  Serial.println(weather_packet.Pa);

  Serial.print("Rc: ");
  Serial.println(weather_packet.Rc);
  
  Serial.print("Sr: ");
  Serial.println(weather_packet.Sr);

  Serial.print("Lux: ");
  Serial.println(weather_packet.Lux);

  Serial.print("T: ");
  Serial.println(weather_packet.T);
  
  Serial.print("La: ");
  Serial.println(weather_packet.La);

  Serial.print("Lo: ");
  Serial.println(weather_packet.Lo);

}


void parseTest(void)
{
    char str[512];
    memset(str, 0, 512);

    // Send R0 command and dump response into str
    Serial1.print("0R0\r\n");
    Serial1.readBytesUntil("\n", str, 512);

    Serial.println(str);
    

    sscanf(str,"0R0,Dn=%dD,Dm=%dD,Dx=%dD,Sn=%fM,Sm=%fM,Sx=%fM,Ta=%fC,Ua=%fP,Pa=%fH,Rc=%fM,Sr=%fW,Lux=%dL,T=%d,La=%f,N,Lo=%f,E", 
      &weather_packet.Dn, &weather_packet.Dm, &weather_packet.Dx, 
      &weather_packet.Sn, &weather_packet.Sm, &weather_packet.Sx, 
      &weather_packet.Ta, &weather_packet.Ua, &weather_packet.Pa, 
      &weather_packet.Rc, &weather_packet.Sr, &weather_packet.Lux,
      &weather_packet.T, &weather_packet.La, &weather_packet.Lo);

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
