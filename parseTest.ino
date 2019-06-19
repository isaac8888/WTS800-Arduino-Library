/* strtok example */
#include <stdio.h>
#include <string.h>

struct WTS {
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

struct WTS weather_data;

void parseTest(void)
{
  char str[512];
  memset(str, 0, 512);
  char * pch;

  // Send R0 command and dump response into str
  Serial1.print("0R0\r\n");
  Serial1.readBytesUntil("\n", str, 512);


  // Parse string into tokens using a comma as the delimeter
  pch = strtok(str, ",");
  while (pch != NULL)
  {
    char *p;
    p = strchr (pch, '=');
    if (p != NULL)
    {
      Serial.println(pch);
      if (decimal point)
      {
        stringtofloat (put the result into the structure up top)
      }

      else if (no decimal point)
      {
        string to long (put the result into the structure up top)
      }

    }

    pch = strtok (NULL, " ,");
  }

}

void setup()
{
  Serial.begin(19200);
  Serial1.begin(19200);
  delay(2000);
  parseTest();
}

void loop()
{

}
