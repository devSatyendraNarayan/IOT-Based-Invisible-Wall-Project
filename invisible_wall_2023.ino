#include <Servo.h>
Servo s;

const int trigPin = 10;
const int echoPin = 9;
#define buzzer 13
long duration;
int distance;
// Road Motor A connections
int in1 = 8;
int in2 = 7;
int c=0,m=0;

void setup() {
  //ultrasonic sensor
  Serial.begin(9600);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //buzzer
  pinMode(buzzer, OUTPUT); 
digitalWrite(buzzer, LOW);
// Set all the motor control pins to outputs
pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  digitalWrite(in1, HIGH); // Door Open 
digitalWrite(in2, LOW);// Door Close 
delay(2000); // Waiting for a while
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  s.attach(12);
}
void loop() {
 
 // Write a pulse to the HC-SR04 Trigger Pin
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
   digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  distance= duration*(0.034/2);

  if (distance >= 12 || distance < 2) 
  {
    Serial.println("Out of range");
     s.write(50);
      digitalWrite(buzzer,LOW);
      
      if(c<2)
      {
      do{
     
       digitalWrite(in2, HIGH); // Door Open 
 digitalWrite(in1, LOW);// Door Close
      }while(c<0);
      }c++;
      delay(1000);
 digitalWrite(in1, LOW);// Door Close
 digitalWrite(in2, LOW); // Door Open 
 
  }
  
  else if(distance<12 && distance>2)
  {
    Serial.print("Distance = ");
    Serial.print(distance);
    Serial.println(" cm");
    s.write(180);
    digitalWrite(buzzer,HIGH);
    digitalWrite(in1, HIGH); // Door Open 
digitalWrite(in2, LOW);// Door Close 
delay(4000); // Waiting for a while
digitalWrite(in1, LOW); // Door Open 
digitalWrite(in2, LOW); // Door Close
c=0;
    } 
   
delay(500);
   }
   
 
 
