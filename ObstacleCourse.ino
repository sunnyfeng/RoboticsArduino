#include <Adafruit_MotorShield.h>
#include <Wire.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);
Adafruit_DCMotor *motor1;
Adafruit_DCMotor *motor2;

void setup() {
  // put your setup code here, to run once:
  motor1= AFMS.getMotor(1);
  motor2= AFMS.getMotor(2);
  AFMS.begin();

  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  motor1->setSpeed(0);
  motor2->setSpeed(200); //full speed = 255

  motor1 ->run(BACKWARD);
  motor2 ->run(FORWARD);

  delay(1000);
  
  motor1->setSpeed(200);
  motor2->setSpeed(200); //full speed = 255

  motor1 ->run(BACKWARD);
  motor2 ->run(FORWARD);

  delay(2500);

  motor1->setSpeed(200);
  motor2->setSpeed(0); //full speed = 255

  motor1 ->run(BACKWARD);
  motor2 ->run(FORWARD);

  delay(1500);

  motor1->setSpeed(200);
  motor2->setSpeed(200); //full speed = 255

  motor1 ->run(BACKWARD);
  motor2 ->run(FORWARD);

  delay(4600);

  motor1->setSpeed(10);
  motor2->setSpeed(100); //full speed = 255

  motor1 ->run(BACKWARD);
  motor2 ->run(FORWARD);

  delay(1500);

  motor1->setSpeed(200);
  motor2->setSpeed(200); //full speed = 255

  motor1 ->run(BACKWARD);
  motor2 ->run(FORWARD);

  delay(2000);

  
  motor1->setSpeed(100);
  motor2->setSpeed(200); //full speed = 255

  motor1 ->run(BACKWARD);
  motor2 ->run(FORWARD);

  delay(6000);


  motor1->setSpeed(0);
  motor2->setSpeed(0); //full speed = 255

  motor1 ->run(BACKWARD);
  motor2 ->run(FORWARD);

  delay(30000);


}
