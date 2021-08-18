#include <PA12.h>
#define ID_NUM 0

PA12 myServo(&Serial,         2,        1 );

void setup() {
  // put your setup code here, to run once:
  myServo.begin(32);
  myServo.goalPosition(ID_NUM, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.goalPosition(ID_NUM, 0);

}
