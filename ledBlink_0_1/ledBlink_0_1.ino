//pinMode(13, OUTPUT);
//digitalWrite(13, HIGH);
//delay();
//digitalWrite(13, LOW);

int led = 13;

void setup(){
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}

