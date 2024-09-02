#include <QTRSensors.h>
int RF = 12;
int RB = 11;
int LF = 9;
int LB = 10;
int SR = 5;
int SL = 6;
int hs = 200;
int ms = 0;
int ls = 0;
int irValue1;
int irValue2;
QTRSensors qtr;

const uint8_t SensorCount = 6;
uint16_t sensorValues[SensorCount];

void setup() {
  //R= right L=LEFT F=front B=back S=speed
  pinMode(RF, OUTPUT);
  pinMode(RB, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(SR, OUTPUT);
  pinMode(SL, OUTPUT);
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){ A0, A1, A2, A3, A4, A5 }, SensorCount);
  qtr.setEmitterPin(2);
  Serial.begin(9600);
}

void loop() {
  qtr.read(sensorValues);


if (sensorValues[0] >= 1000) {
    do {
      qtr.read(sensorValues);
    analogWrite(SL, hs);
    analogWrite(SR, ms);
    digitalWrite(RF, HIGH);
    digitalWrite(RB, LOW);
    digitalWrite(LF, HIGH);
    digitalWrite(LB, LOW);} while( sensorValues[5] < 1000&&sensorValues[4] < 1000 && sensorValues[3] < 1000 );
  } else if (sensorValues[5] >= 1000) {
    do {
      qtr.read(sensorValues);
    analogWrite(SL, ms);
    analogWrite(SR, hs);
    digitalWrite(RF, HIGH);
    digitalWrite(RB, LOW);
    digitalWrite(LF, HIGH);
    digitalWrite(LB, LOW);} while(sensorValues[2] < 1000&&sensorValues[1] < 1000 && sensorValues[0] < 1000 );
  Serial.print("R=  ");
  Serial.print(sensorValues[0]);
  Serial.print("   ");

  Serial.print(sensorValues[1]);
  Serial.print("   ");
  Serial.print(sensorValues[2]);
  Serial.print("   ");
  Serial.print(sensorValues[3]);
  Serial.print("   ");
  Serial.print(sensorValues[4]);
  Serial.print("   ");
  Serial.println(sensorValues[5]);}
  delayMicroseconds(50);
}