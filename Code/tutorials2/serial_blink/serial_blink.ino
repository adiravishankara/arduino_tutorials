const int led = 5;
int delay_time = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("How quick do you want it to blink(100 to 3000)?");
  if(Serial.available()){delay_time = Serial.parseInt();}
  digitalWrite(led,HIGH);
  delay(delay_time);
  digitalWrite(led,LOW);
  delay(delay_time);
}
