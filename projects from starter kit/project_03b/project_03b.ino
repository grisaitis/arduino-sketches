const int sensorPin = A0;
float baselineTemperature = 20.0;
float sensorSuppliedVoltage = 5.0;

void turnOffLEDs(){
  for(int pin=2; pin<5; pin++){
    digitalWrite(pin, LOW);
  }
}

void setup(){
  // opens a serial port, so we can read input in the IDE
  Serial.begin(9600);
  for(int pin=2; pin<5; pin++){
    pinMode(pin, OUTPUT);
  }
  turnOffLEDs();
}

float getVoltageFromSensor(int pin){
  return (analogRead(sensorPin) / 1024.0) * sensorSuppliedVoltage;
}

float getTemperatureFromSensor(int pin){
  return (getVoltageFromSensor(pin) - 0.5) * 100;
}

void printSensorValue(int sensorValue){
  Serial.print("value: ");
  Serial.print(sensorValue);
}

void printVoltage(float voltage){
  Serial.print("; voltage: ");
  Serial.print(voltage);
}

void printTemperature(float temperature){
  Serial.print("; temperature (C): ");
  Serial.print(temperature);
}

void setLEDs(float temperature, float baselineTemperature){
  if(temperature > baselineTemperature + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } 
  else if(temperature > baselineTemperature + 2) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } 
  else if(temperature > baselineTemperature + 0) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } 
  else turnOffLEDs();
}

void loop(){
  printSensorValue(analogRead(sensorPin));
  printVoltage(getVoltageFromSensor(sensorPin));
  printTemperature(getTemperatureFromSensor(sensorPin));
  Serial.println();
  setLEDs(getTemperatureFromSensor(sensorPin),baselineTemperature);
  delay(1);
}


