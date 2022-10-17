#include <string.h>
#include "functions/BluetoothReceiverClass.ino"

void setup()
{
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop()
{
  checkBluetoothHeader();

  delay(50);
}