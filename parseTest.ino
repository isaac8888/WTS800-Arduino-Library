/* strtok example */
#include <stdio.h>
#include <string.h>

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
    Serial.println(pch);
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
