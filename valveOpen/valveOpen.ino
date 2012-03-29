int ValvePin = 4; //The solenoid is on pin 4

void setup()
{
  pinMode(ValvePin, OUTPUT);
  Serial.begin(9600);
}

void openValve()
{
  digitalWrite(ValvePin, HIGH);
  Serial.println("Valve Open!");
}

void closeValve()
{
  digitalWrite(ValvePin, LOW);
  Serial.println("Valve Closed!");
}

void loop()
{
  openValve();
  delay(10000);
  closeValve();
  delay(10000);
  
}
