#include <Servo.h>

Servo myservo;   

int pos = 0;

// C++ code
//
int distanceThreshold = 0;

int cm = 0;

int inches = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  //pinMode(2, OUTPUT);
  myservo.attach(9); 

}

void loop()
{
  // set threshold distance to activate LEDs
  distanceThreshold = 10;
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 6);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(cm);
  Serial.print("cm, ");
  Serial.print(inches);
  Serial.println("in");
  // if (cm > distanceThreshold) {
  //   digitalWrite(2, HIGH);
  // }
  if (cm <= distanceThreshold) {
   // digitalWrite(2, HIGH);
    for (pos = 180; pos >= 90; pos -= 1) { 
    myservo.write(pos);
    delay(15);                                     
  }
   delay(100);
  delay(15);
   for (pos = 90; pos <= 180; pos += 1) { 
    myservo.write(pos);             
   delay(15);                       
  }
 

  
  }              
  
  
  // delay(100); // Wait for 100 millisecond(s)
  // digitalWrite(2, LOW);
}