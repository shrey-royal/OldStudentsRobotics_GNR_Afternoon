#include <SoftwareSerial.h>

// Choose two Arduino pins to use for software serial
int RXPin = 4;
int TXPin = 3;

//Default baud of NEO-6M is 9600
int GPSBaud = 9600;

// Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(4, 3);

void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
}

void loop()
{
  // Displays information when new sentence is available.
    // Serial.println(gpsSerial.read());
    Serial.println(gpsSerial.available());
}