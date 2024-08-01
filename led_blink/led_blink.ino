// C++ code
//
void setup()
{
  pinMode(8, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  digitalWrite(8, HIGH);
  digitalWrite(4, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(8, LOW);
  digitalWrite(4, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
}