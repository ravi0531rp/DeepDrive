#define lm1 8 
#define lm2 9
#define rm1 11
#define rm2 10

#define trigcen 4
#define trigleft 3
#define trigright 6

char a;
String hari="";
#define echoleft 2
#define echocen 5
#define echoright 7

#include <SD.h>
#include <SPI.h>
String comma=",";
File myFile;
int pinCS = 53; 

unsigned long startMillis;
unsigned long currentMillis;
const unsigned long period = 10000;  //the value is a number of milliseconds between changes of brightness

void setup() {
pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT);
 
 pinMode(trigcen,OUTPUT);
 pinMode(trigright,OUTPUT);
 pinMode(trigleft,OUTPUT);

 
 pinMode(echocen,INPUT);
 pinMode(echoright,INPUT);
 pinMode(echoleft,INPUT);

 
Serial.begin(9600);  
SD.begin();
}

void loop() {
  
  currentMillis = millis();  //get the current time
  
    
    
  

  digitalWrite(trigcen, LOW);
  delayMicroseconds(2);
  digitalWrite(trigcen, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigcen, LOW);
  int duration1 = pulseIn(echocen, HIGH);
  Serial.println(duration1);
 

if(Serial.available())
{
  a = Serial.read();
  hari+=String(duration1)+comma+String(a);

  if (currentMillis - startMillis >= period)  //test whether the period has elapsed
  {
    myFile = SD.open("cmpb.txt", FILE_WRITE);
    startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED brightness

  if (myFile)
  { 
     
    myFile.println(hari);
   Serial.println(hari);
   hari="";
       myFile.close(); // close the file  
    
  }
  else{
    Serial.println("SHIT");
  }
 
}
}
}
