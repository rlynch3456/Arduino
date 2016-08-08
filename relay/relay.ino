void setup() {
  // put your setup code here, to run once:
  
  // Set up pins 12 and 13 for digital output
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  // toggle pins 12 and 13
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  
  delay(5000);
  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  
  delay(5000);
}
