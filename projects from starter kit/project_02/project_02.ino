// stores status of the switch on the circuit
// the switch is manually changeable
int switchState = 0; 


// setup() and void() must be defined in any sketch, it seems. 
void setup() {
  pinMode(2,INPUT); // this is the switch pin
  
  pinMode(3,OUTPUT); // for green LED
  pinMode(4,OUTPUT); // for red LED
  pinMode(5,OUTPUT); // for another red LED
}

void loop(){
  // this checks the voltage on pin 2
  switchState = digitalRead(2); 
  // if voltage exists, then digitalRead returns 1 or the value 'HIGH'
  // otherwise, it returns 0 or 'LOW'
  if (switchState == LOW) {
    // the button is not pressed
    // send 5V of voltage out through pin 3
    digitalWrite(3,HIGH); // green LED
    // send zero volts out pins 4 and 5
    digitalWrite(4,LOW); // red LED
    digitalWrite(5,LOW); // red LED
  }
  else {
    // the button is pressed
    // turn off the 
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    delay(250);
    // toggle the LEDs
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    delay(250);
  }
}
