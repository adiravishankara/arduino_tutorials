#include <NewPing.h>
 
int led1 = ;
int led2 = ;
int led3 = ;
int led4 = ;
int led5 = ;

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
     
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Setup the led's as outputs here.
  //It would look something like 
  pinMode(led1,OUTPUT);
  //copy this for the rest of the led's

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

//The code below are called functions
//They provide steps for the program to follow and makes organization easier
//This particular code tells the code how many LED's should be on
//The first one turns only one led on, the second turns two leds on and so on
//Write the rest of the functions
void oneLight(){

  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
}
void twoLight(){

  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);

}
void threeLight(){

}
void fourLight(){

}
void fiveLight(){

}
void zero(){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  }

