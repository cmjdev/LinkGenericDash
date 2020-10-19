#include <Arduino.h>
#include <CAN.h>
#include <./frames.h>

// return the number of digits a byte would contain in ascii
// byte countDigits(int i)
// {
//   i = abs(i);
//   return i > 0 ? (int)log10((float)i) + 1 : 1;
// }

void sendData(const char *data)
{
  Serial.print(data);
  Serial.write(0xFF);
  Serial.write(0xFF);
  Serial.write(0xFF);
}

void buildData(const byte frameIndex, const byte index, const short data)
{
  const struct s_frame s = frame[frameIndex][index];
  const float actual = data * s.mult + s.add;
  const int nextion = actual * pow(10, s.prec);
  // Nextion display only works with integer numbers. To get around this
  // we send an integer that includes digits of precision and set the
  // component precision and mantissa values to place the decimal correctly
  char buffer[50];
  // set precision vvs0
  sprintf(buffer, "%s.vvs0=%i", s.id, s.prec);
  sendData(buffer);
  // set mantissa vvs1 not needed
  // sprintf(buffer, "%svvs1=%i", s.id, countDigits(nextion) - s.prec);
  // sendData(buffer);
  // send value
  sprintf(buffer, "%s.val=%i", s.id, nextion);
}

void onReceive(const int packetSize)
{
  // read frame ID (byte[0] = 0-12 DEC. byte[1] = 0 )
  byte frame[2];
  CAN.readBytes(frame, 2);

  for (short i = 0; i < 3; i++)
  {
    byte buffer[2];
    CAN.readBytes(buffer, 2);
    const short data = buffer[0] << 8 | buffer[1];
    buildData(frame[0], i, data);
  }
}

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  Serial.println("CAN Receiver");

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3))
  {
    Serial.println("Starting CAN failed!");
    while (1)
      ;
  }

  CAN.filter(0x1AE); // 420 blazeit
  CAN.onReceive(onReceive);
}

void loop()
{
  // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize)
  {

    // Serial.print("packet with id 0x");
    // Serial.print(CAN.packetId(), HEX);

    if (!CAN.packetRtr())
    {
      while (CAN.available())
      {
        Serial.print((char)CAN.read());
      }
      Serial.println();
    }
  }
}
