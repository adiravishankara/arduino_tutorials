

int sensorReading = 0;
int led = A3;
void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);

  pinMode(led, OUTPUT);
}

void loop()
{

  sensorReading = analogRead(A0);
  sensorReading = map(sensorReading,26,923,0,150);
  Serial.println(sensorReading);

  analogWrite(led, 255-sensorReading);
 //tone(9, 440 * pow(2.0, (constrain(int(map(sensorReading, 0, 1023, 36, 84)), 35, 127) - 57) / 12.0), 1000);
  delay(10); 
}
