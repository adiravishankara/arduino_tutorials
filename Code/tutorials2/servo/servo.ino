#include <Servo.h>

int pot = 0;

Servo servo_A3;

void setup()
{
  pinMode(A1, INPUT);
  servo_A3.attach(A3);

}

void loop()
{
  pot = analogRead(A1);
  servo_A3.write(map(pot, 0, 1023, 0, 360));
  delay(10); // Delay a little bit to improve simulation performance
}
