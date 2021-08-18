#include <PA12.h>
#define ID_NUM 0

PA12 myServo(&Serial,         2,        1 );
//          (&Serial ,enable_pin,  Tx Level)
int alarm;

const int ledPin =  LED_BUILTIN;
const int potPin = 0;

unsigned long previousMillis;

const long interval = 200;

int alarmLevel = 1;

void setup() {
//  Serial.begin(9600);    
  myServo.begin(32);  
//  while (! Serial);  
//  Serial.print("*Alarm LED Setting : ");
//  Serial.println(myServo.alarmLed(ID_NUM));
//  Serial.print("*Alarm LED Setting : ");
  myServo.ledOn(ID_NUM, BLUE);
  alarmLevel = 1;
}

void loop() {         
  unsigned long currentMillis = millis();

  if (myServo.presentTemperature(ID_NUM) != 0) {
    digitalWrite(ledPin, HIGH);
  }

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    alarmLevel = alarmLevel + 1;
    alarmLevel = alarmLevel % 4;

    // set the LED with the ledState of the variable:
    switch (alarmLevel) {
      case 0:
        myServo.ledOn(ID_NUM, RED);
        break;
      case 1:
        myServo.ledOn(ID_NUM, BLUE);
        break;
      case 2:
        myServo.ledOn(ID_NUM, GREEN);
        break;
      case 3:
        myServo.ledOn(ID_NUM, off);
        break;
    }
  }
}
