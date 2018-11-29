#include "IRremote.h"

int ENA
int ENB
int IN1
int IN2
int IN3
int IN4
int direc = 0;
int RECV_PIN

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // put your setup code here, to run once:
  
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  irrecv.enableIRIn();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(irrecv.decode(&results)){
    direc = direc_decide(
  
  switch(direc){
    case 1: forward();
    break;
    case 2: backward();
    break;
    case 3: right();
    break;
    case 4: left();
    break;
    case 0: brake();
    break;
    default: brake();
    break;
  }
  irrecv.resume();
  Serial.println("Waiting for next value");  
}
}
void forward(){
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(5000);
  brake();
}
void backward(){
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(5000);
  brake();
}
void right(){
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  delay(5000);
  brake();
}
void left(){
  digitalWrite(ENA,HIGH);
  digitalWrite(ENB,HIGH);
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
  delay(5000);
  brake();
}
void brake(){
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}
int direc_decide(decode_results *results){
  int p1
  if(results->value == 0xFF629D){
    p1 = 1;
  }
  else if(results->value == 0xFF629D){
    p1 = 2;
  }
  else if(results->value == 0xFF629D){
    p1 = 3;
  }
  else if(results->value == 0xFF629D){
    p1 = 4;
  }
  else if(results->value == 0xFF629D){
    p1 = 0;
  }
}
