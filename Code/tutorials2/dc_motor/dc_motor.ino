#include <Servo.h>

int pot = 0;

//Servo servo_A3;

void setup()
{
  pinMode(A1, INPUT);
  pinMode(A3,OUTPUT);
  //servo_A3.attach(A3);

}

void loop()
{
  pot = analogRead(A1);
  analogWrite(A3,map(pot, 0, 1023, 0, 4000));
  delay(10); // Delay a little bit to improve simulation performance
}
