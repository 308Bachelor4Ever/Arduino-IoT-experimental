void setup() {
  // Use GPIO Pin 13 as output.
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  delay(1000);

 // Turn off built in LED and then 1000 ms.
 digitalWrite(13, LOW);
 delay(1000); 
}
