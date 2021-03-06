#include <NewPing.h>
 
int led1 = 1;
int led2 = 2;
int led3 = 3;
int led4 = 4;
int led5 = 5;

int mindist = 20;
int maxdist = 200;
int dist = 200;
int dist2 = 5;

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
     
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
     
void setup() {
   pinMode(led1,OUTPUT);
   pinMode(led2,OUTPUT);
   pinMode(led3,OUTPUT);
   pinMode(led4,OUTPUT);
   pinMode(led5,OUTPUT);
   Serial.begin(9600);
   zero();
}
     
void loop() {
    delay(50);
    zero();
    dist = sonar.convert_cm(sonar.ping_median());
    if (dist == 0){dist2 = 0;}
    else{
    dist2 = map(dist,1,200,1,5);
    switch (dist2) {
      case 1:
        fiveLight();
      break;
      case 2:
        fourLight();
      break;
      case 3:
        threeLight();
      break;
      case 4:
        twoLight();
      break;
      case 5:
        oneLight();
      break;
      default:
        zero();
    }
    }
}


void oneLight(){
  Serial.println(1);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
}
void twoLight(){
  Serial.println(12);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);

}
void threeLight(){
  Serial.println(123);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
}
void fourLight(){
  Serial.println(1234);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,LOW);
}
void fiveLight(){
  Serial.println(12345);
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
  digitalWrite(led4,HIGH);
  digitalWrite(led5,HIGH);
}
void zero(){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  }

