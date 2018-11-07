int enablePin = 11;
int inA = 10;
int inB = 9;
int speed = 150;
int direc = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(enablePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  direc = Serial.parseInt();
}
if(direc == 0){
  forward(speed);
  Serial.print("Forward Speed: ");
  Serial.println(speed);
}
else{
  reverse(speed);
  Serial.print("Reverse Speed: ");
  Serial.println(speed);
}
}
void forward(int speed){
  analogWrite(enablePin, speed);
  digitalWrite(inA, LOW);
  digitalWrite(inB,HIGH);
}
void reverse(int speed){
  analogWrite(enablePin, speed);
  digitalWrite(inA, HIGH);
  digitalWrite(inB,LOW);
}
