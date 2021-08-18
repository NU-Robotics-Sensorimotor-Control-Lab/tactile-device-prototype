#include <PA12.h>
#define ID_NUM 0

PA12 myServo(&Serial1,         2,        1 );

const int ledPin =  LED_BUILTIN;
int posPot = 2;
int forcePot = 3;

int targetPos = 0;

int pos, foc;

int targetForce = 5;
int tForce;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.begin(32);
  myServo.ledOn(ID_NUM, GREEN);
  myServo.forceLimit(ID_NUM, targetForce);
}

void loop() {
  // put your main code here, to run repeatedly:
  pos = analogRead(posPot);
  foc = analogRead(forcePot);

  tForce = map(foc, 0, 1023, 1, 1023);
  targetPos = map(pos, 0, 1023, 0, 4095);

  myServo.goalPosition(ID_NUM, targetPos);

  Serial.print("Force: ");
  Serial.print(tForce);
  Serial.print(" Position: ");
  Serial.println(targetPos);

  if (tForce != targetForce) {
    targetForce = tForce;
    myServo.forceLimit(ID_NUM, targetForce);
  }
  
}
