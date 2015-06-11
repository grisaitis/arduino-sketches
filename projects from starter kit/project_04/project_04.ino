int sensorValue = 0;
int value = 0;


void setup(){
  Serial.begin(9600);
  
  pinMode(9,OUTPUT);
}

void loop() {
  digitalWrite(9, HIGH);
  sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  value = sensorValue / 4;
  //Serial.println(value);
  analogWrite(9,value);
  delay(5);
}
