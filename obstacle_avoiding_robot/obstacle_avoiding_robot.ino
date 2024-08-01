#include <Servo.h> 
Servo servo_motor;
#define trigPin 9           // Trig Pin Of HC-SR04
#define echoPin 8        // Echo Pin Of HC-SR04
#define MLa 4                   //left motor 1st pin
#define MLb 5                  //left motor 2nd pin
#define MRa 6               //right motor 1st pin
#define MRb 7               //right motor 2nd pin
#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

void setup() {
  Serial.begin(9600);
  pinMode(MLa, OUTPUT);     // Set Motor Pins As O/P
  pinMode(MLb, OUTPUT);
  pinMode(MRa, OUTPUT);
  pinMode(MRb, OUTPUT);
  pinMode(trigPin, OUTPUT);       // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);        //Set Echo Pin As I/P To Receive Reflected Waves
  servo_motor.attach(10);
  servo_motor.write(90);
  delay(2000);
  distance = readPing();
  delay(100);
}



void loop() 
{
 int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);


  if (distance <= 20){
    moveStop();
    delay(300);
    moveBackward();
    delay(300);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else {
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(0);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
}

int lookLeft(){
  servo_motor.write(180);
  delay(500);
  int distance = readPing();
  delay(100);
  servo_motor.write(90);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);       // Transmit Waves For 10us
  delayMicroseconds(10);
  int cm = pulseIn(echoPin, HIGH);        // Receive Reflected Waves
  //cm = cm / 58.2;                       // Get Distance    // Receive Reflected Waves

  if (cm==0){
    cm=250;
  } else {
     cm=cm / 58.2; 
  }
  Serial.println(cm);  
  return cm;
}

void moveStop(){
  
  digitalWrite(MRb, LOW);        //Stop                
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, LOW);                                
    digitalWrite(MLa, LOW);  
}

void moveForward(){

  if(!goesForward){

    goesForward=true;

    digitalWrite(MRb, HIGH);       // Move Forward
    digitalWrite(MRa, LOW);
    digitalWrite(MLb, HIGH);                                
    digitalWrite(MLa, LOW);     
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(MLa, HIGH);
  digitalWrite(MRa, HIGH);
  
  digitalWrite(MLb, LOW);
  digitalWrite(MRb, LOW);
  
}

void turnRight(){

  digitalWrite(MLb, HIGH);
  digitalWrite(MRa, HIGH);
  
  digitalWrite(MLa, LOW);
  digitalWrite(MRb, LOW);
  
  delay(500);
  
  digitalWrite(MLb, HIGH);
  digitalWrite(MRb, HIGH);
  
  digitalWrite(MLa, LOW);
  digitalWrite(MRa, LOW);
 
  
  
}

void turnLeft(){

  digitalWrite(MLa, HIGH);
  digitalWrite(MRb, HIGH);
  
  digitalWrite(MLb, LOW);
  digitalWrite(MRa, LOW);

  delay(500);
  
  digitalWrite(MLb, HIGH);
  digitalWrite(MRb, HIGH);
  
  digitalWrite(MLa, LOW);
  digitalWrite(MRa, LOW);
}

