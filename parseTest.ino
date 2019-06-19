#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define strtof(A, B) strtod(A, B)

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
    //checking if
    char *p;
    p = strchr (pch, '=');
    if (p != NULL)
    {
      Serial.println(pch);

      //if there's a decimal point, use string to float
      char *pch, *stopstring;
      float f;
      f = strtof (pch, &stopstring);

      Serial.println(f);
      //Serial.println(pch);
      //Serial.println(stopstring);
    }



    //string to long (put the result into the structure up top)



    //if decimal point use string to float
    //else if (decimal point)
    //{
    // string to double (put the result into the structure up top)
    //char *ptr;
    //double ret;
    //if (ret != NULL)

    //ret = strtod(str, &ptr);
    //Serial.println(pch);
    //}

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
