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
}
