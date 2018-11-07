#include "IRremote/IRremote.h"
#include <NewPing.h>

#define TRIGGER_PIN 4
#define ECHO_PIN 3
#define MAX_DISTANCE 200


int enablePin = 11;
int inA = 10;
int inB = 9;
int motor_speed = 150;
int direc = 0;
int Recv_pin = 6;
int us_dist = 200;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

IRrecv irrecv(Recv_pin);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("IR ENABLED");
  Serial.println("MOTOR READY");
}

void loop() {
  // put your main code here, to run repeatedly:
if (irrecv.decode(&results)){
    //Serial.println(results.value,HEX);
    remote_vals(&results);

if(direc == 0){
  forward(motor_speed);
  Serial.print("Forward Speed: ");
  Serial.println(motor_speed);
}
else{
  reverse(motor_speed);
  Serial.print("Reverse Speed: ");
  Serial.println(motor_speed);
}

  irrecv.resume();
  Serial.println("Waiting for next value");
  }
  delay(1000);
}
void forward(int motor_speed){
  analogWrite(enablePin, motor_speed);
  digitalWrite(inA, LOW);
  digitalWrite(inB,HIGH);
}
void reverse(int motor_speed){
  analogWrite(enablePin, motor_speed);
  digitalWrite(inA, HIGH);
  digitalWrite(inB,LOW);
}

