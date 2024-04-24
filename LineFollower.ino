
#include <QTRSensors.h>
int RF = 5;
int RB = 4;
int LF = 8;
int LB = 9;
int SR = 10;
int SL =6 ;
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
  qtr.setSensorPins((const uint8_t[]){A0, A2, A3, A4, A5, A7}, SensorCount);
  qtr.setEmitterPin(2);

  Serial.begin(9600);
}

void loop() {
qtr.read(sensorValues);
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();


    analogWrite(SL, 255);
    analogWrite(SR, 255);
    digitalWrite(RF, HIGH);
    digitalWrite(RB, LOW);
    digitalWrite(LF, LOW);
    digitalWrite(LB, LOW);
  
  delay(50);
}
