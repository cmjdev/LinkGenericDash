#include <Arduino.h>
#include <CAN.h>
#include <./frames.h>

void sendData(const char *data)
{
  Serial.print(data);
}

void buildData(const byte frameIndex, const byte index, const short data)
{
  const struct s_frame s = frame[frameIndex][index];
  const float actual = data * s.mult + s.add;
  const int nextion = actual * pow(10, s.prec);
  // Nextion display only works with integer numbers. To get around this
  // we send an integer that includes digits of precision and set the
  // component precision value to place the decimal correctly
  char buffer[50];
  // set precision vvs1
  sprintf(buffer, "%s.vvs1=%iÿÿÿ", s.id, s.prec);
  sendData(buffer);
  sprintf(buffer, "%s.val=%iÿÿÿ", s.id, nextion);
  sendData(buffer)
}

void onReceive(const int packetSize)
{
  // read frame ID (byte[0] = 0-12+ DEC. byte[1] = 0 )
  byte frame[2];
  CAN.readBytes(frame, 2);

  for (short i = 0; i < 3; i++)
  {
    byte buffer[2];
    CAN.readBytes(buffer, 2);
    const short data = buffer[0] | buffer[1] << 8;
    buildData(frame[0], i, data);
  }
}

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3))
  {
    while (1)
      ;
  }

  CAN.filter(0x1AE); // 420 blazeit
  CAN.onReceive(onReceive);
}

void loop()
{
}
