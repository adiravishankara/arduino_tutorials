#include <NewPing.h>
uint32_t ledPins[] = {1,2,3,4,5};  

int mindist = 20;
int maxdist = 200;
int dist = 201;
int dist2 = 6;
#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
     
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
     
void setup() {
   Serial.begin(115200);
}
     
void loop() {
    delay(50);
    dist = sonar.convert_cm(sonar.ping_median());
    dist2 = map(dist,0,200,5,0);
    dispLights(dist2);
}

void dispLights(int a){
  if(a == 0){digitalWrite(ledPins[1,2,3,4,5],LOW);}
  else{
    digitalWrite(ledPins[1,2,3,4,5],LOW);
    for(int i = 1; i = dist2; i++){
      digitalWrite(ledPins[i],HIGH);
    }
  }
}

