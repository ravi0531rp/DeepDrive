#include <SD.h>
#include <SPI.h>
#define trigcen 4
#define trigleft 3
#define trigright 6
#define echoleft 2
#define echocen 5
#define echoright 7
File myFile;
int pinCS = 53; // Pin 10 on Arduino Uno

int ultra(int trigPin,int echoPin){                                                    // ---- Ultrasonic function starts.
int duration;
int distance;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;
return distance;

}         
void setup() {
    pinMode(trigcen,OUTPUT);
 pinMode(trigright,OUTPUT);
 pinMode(trigleft,OUTPUT);
 pinMode(echocen,INPUT);
 pinMode(echoright,INPUT);
 pinMode(echoleft,INPUT);
  Serial.begin(9600);
  pinMode(pinCS, OUTPUT);
  
 
}
void loop() {
  int val1 = ultra(trigleft,echoleft);
  int val2 = ultra(trigcen,echocen);
  int val3 = ultra(trigright,echoright);
  String comma = ",";
  String fin = String(val1) + comma + String(val2)+ comma+ String(val3);
  Serial.println(fin);
  delay(500);

}
