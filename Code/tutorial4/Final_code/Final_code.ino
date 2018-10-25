#include "IRremote.h"

int Recv_pin = 11;
int motor_pin = 5;
int motor_speed = 255;


IRrecv irrecv(Recv_pin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("IR ENABLED");
  pinMode(motor_pin,OUTPUT);
  //analogWrite(motor_pin,motor_speed);
  Serial.println("MOTOR READY");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)){
    //Serial.println(results.value,HEX);
    motor_control(&results);
    irrecv.resume();
    Serial.println("Waiting for next value");
  }
  delay(1000);
}
void motor_control(decode_results *results){
  if(results->value == 0xFF629D){
    Serial.print("VOL + PRESSED, motor speed: ");
    motor_speed += 20;
    motor_speed = constrain(motor_speed,100,255);
    Serial.println(motor_speed);
    motor(motor_speed);
  }
  else if (results->value == 0xFFA857){
    Serial.print("VOL - PRESSED, motor speed: ");
    motor_speed -= 20;
    motor_speed = constrain(motor_speed,100,255);
    Serial.println(motor_speed);
    motor(motor_speed);
  }
  else{
    Serial.print("WRONG INPUT, motor speed: ");
    Serial.println(motor_speed);
  }
}
void motor(int motor_speed){
  analogWrite(motor_pin,motor_speed);
  //Serial.print("Analog Read Value: ");
  //Serial.println(analogRead(motor_pin));  
}


