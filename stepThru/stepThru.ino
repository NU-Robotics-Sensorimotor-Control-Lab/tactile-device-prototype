#include <PA12.h>
#define ID_NUM 0

PA12 myServo(&Serial1,         2,         1);
//        (&Serial ,enable_pin,  Tx Level)

int i = 0;

void setup() {
  // Initialize the PA12 bus:
  // Baudrate -> 128: 9600, 32: 57600, 16: 115200 
  myServo.begin(32);
  Serial.begin(9600);
}

void loop() {
  myServo.goalPosition(ID_NUM, i++); 
  delay(10);
  Serial.print(myServo.presentPosition(ID_NUM));
  Serial.print(" ");
  Serial.print(i);
  Serial.print(" ");
  Serial.println(myServo.presentPosition(ID_NUM) - i);
}
