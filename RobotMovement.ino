#include <Wire.h>

#include <Adafruit_MotorShield.h>


Adafruit_MotorShield AFMS= Adafruit_MotorShield(0x62);
Adafruit_DCMotor *motor;
Adafruit_DCMotor *motor2;
Adafruit_DCMotor *motor3;
Adafruit_DCMotor *motor4;

char inChar;

void setup() {
  // put your setup code here, to run once:
  
  motor=AFMS.getMotor(1);
  motor2=AFMS.getMotor(2);
  motor3=AFMS.getMotor(3);
  motor4=AFMS.getMotor(4);
  AFMS.begin();
  Serial.begin(9600);

  //guide
  Serial.println("Power On");
  Serial.println("f = forward");
  Serial.println("b = backwards");
  Serial.println("l = left");
  Serial.println("r = right");
  Serial.println("L = left diagonal");
  Serial.println("R = right diagonal");
  Serial.println("s = spin counter");
  Serial.println("S = spin clockwise");
  Serial.println("d = right diagonal back");
  Serial.println("D = left diagonal back");
  
}

void loop() {
  // put your main code here, to run repeatedly:
   
    //take in character from user and move
    inChar = Serial.read();
    switch (inChar){
      case 'f': 
        Serial.println("go forward");
        forward();
        delay(1000);
        stop();
        break;
      case 'b':
        Serial.println("go backwards");
        backward();
        delay(1000);
        stop();
        break; 
      case 'l':
        Serial.println("go left");
        left();
        delay(1000);
        stop();
        break;
      case 'r':
        Serial.println("go right");
        right();
        delay(1000);
        stop();
        break;
      case 'L':
        Serial.println("go left diagonal");
        diagonalLeft();
        delay(1000);
        stop();
        break;
      case 'R':
        Serial.println("go right diagonal");
        diagonalRight();
        delay(1000);
        stop();
        break;
      case 's':
        Serial.println("spin counterclockwise");
        spinCounter();
        delay(1000);
        stop();
        break;
      case 'S':
        Serial.println("spin clockwise");
        spinClockwise();
        delay(1000);
        stop();
        break;
      case 'd':
        Serial.println("go right diagonal backwards");
        diagonalRightBack();
        delay(1000);
        stop();
        break;
     case 'D':
        Serial.println("go left diagonal backwards");
        diagonalLeftBack();
        delay(1000);
        stop();
        break;
    }
      
}

void forward()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);

 motor->run(BACKWARD);
  motor2->run(BACKWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);
}

void backward()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);

  motor->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(BACKWARD);
  motor4->run(BACKWARD); 

  
}

void left()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);


  motor->run(FORWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
  motor4->run(FORWARD);
}
void right()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);


  motor->run(BACKWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(BACKWARD);
}

void diagonalRight()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);


  motor->run(BACKWARD);
  motor3->run(FORWARD); 
  motor2 ->setSpeed(0);
  motor4 ->setSpeed(0);
}

void diagonalLeftBack()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);


  motor->run(FORWARD);
  motor3->run(BACKWARD); 
  motor2 ->setSpeed(0);
  motor4 ->setSpeed(0);
}

void diagonalLeft()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);


  motor4->run(FORWARD);
  motor2->run(BACKWARD);
  motor->setSpeed(0);
  motor3 ->setSpeed(0);
}

void diagonalRightBack()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);


  motor4->run(BACKWARD);
  motor2->run(FORWARD);
  motor->setSpeed(0);
  motor3 ->setSpeed(0);
}

void spinCounter()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);


  motor->run(FORWARD);
  motor2->run(FORWARD);
  motor3->run(FORWARD);
  motor4->run(FORWARD);  
}

void spinClockwise()
{
  motor-> setSpeed(255);
  motor2->setSpeed(255);
  motor3->setSpeed(255);
  motor4->setSpeed(255);


  motor->run(BACKWARD);
  motor2->run(BACKWARD);
  motor3->run(BACKWARD);
  motor4->run(BACKWARD);  
}

void stop()
{
  motor-> setSpeed(0);
  motor2->setSpeed(0);
  motor3->setSpeed(0);
  motor4->setSpeed(0);
}

