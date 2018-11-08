#include <IRremote.h>
//#include <NewPing.h>

//#define TRIGGER_PIN 4
//#define ECHO_PIN 5
//#define MAX_DISTANCE 200

int enablePin = 11;
int inA = 10;
int inB = 9;
int motor_speed = 255;
int direc = 0;
int Recv_pin = 6;

String bp;

IRrecv irrecv(Recv_pin);
decode_results results;
//NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  pinMode(inA, OUTPUT);
  pinMode(inB,OUTPUT);
  pinMode(enablePin,OUTPUT);

  Serial.begin(9600);
  Serial.println("MOTORS READY");

  irrecv.enableIRIn();
  Serial.println("IR READY");

  //Serial.println("ULTRASOUND READY");
  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (irrecv.decode(&results)) {
    bp = button(&results);
    motor_control(bp,direc,motor_speed);
    Serial.println(bp);
    Serial.print(" Motor Speed : ");
    Serial.print(motor_speed);
    Serial.print(" ,Motor Direction: ");
    if (direc == 0)Serial.println("Forward");
    else Serial.println("Reverse");
    irrecv.resume();
  }
  //delay(100);
  
    
  }


