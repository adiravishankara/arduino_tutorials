#include <NewPing.h>
 

int mindist = 20;
int maxdist = 200;
int dist = 200;
int dist2 = 5;

#define TRIGGER_PIN  12
#define ECHO_PIN     11
#define MAX_DISTANCE 200
     
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
     
void setup() {

   Serial.begin(115200);
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
}
void twoLight(){
  Serial.println(12);
}
void threeLight(){
  Serial.println(123);
}
void fourLight(){
  Serial.println(1234);
}
void fiveLight(){
  Serial.println(12345);
}
void zero(){
  }

