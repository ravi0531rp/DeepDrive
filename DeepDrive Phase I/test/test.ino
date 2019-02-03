#define lm1 8 
#define lm2 9
#define rm1 11
#define rm2 10

#include <SD.h>
#include <SPI.h>

#define trigcen 4
#define trigleft 3
#define trigright 6
//#define trigR 25
//#define trigL 22


#define echoleft 2
#define echocen 5
#define echoright 7
//#define echoR 23
//#define echoL 24

int dx=0;
int dy=0;
int yspeed=0.9;
int xspeed=0.3;
int lateralSpeed=0.63;
int angSpeed=0.96;

File myFile;
int pinCS = 53; // Pin 10 on Arduino Uno

int ultra(int trigPin,int echoPin)
{                                                    // ---- Ultrasonic function starts.
int duration;
int distance;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);


return duration;

}   
      
void setup() {
 pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT);
 
 pinMode(trigcen,OUTPUT);
 pinMode(trigright,OUTPUT);
 pinMode(trigleft,OUTPUT);
// pinMode(trigR,OUTPUT);
// pinMode(trigL,OUTPUT);
 
 pinMode(echocen,INPUT);
 pinMode(echoright,INPUT);
 pinMode(echoleft,INPUT);
// pinMode(echoL,INPUT);
// pinMode(echoR,INPUT);
 
pinMode(pinCS, OUTPUT);
Serial.begin(9600);  
Serial1.begin(9600);
}

void loop()
{
  SD.begin();
  int val1 = ultra(trigleft,echoleft);
  int val2 = ultra(trigcen,echocen);
  int val3 = ultra(trigright,echoright);
  myFile = SD.open("be.txt", FILE_WRITE);
  String comma = ",";
 
  //check whether arduino is reciving signal or not 
  if(Serial1.available())
  {
  char a = Serial1.read();
  
  if(a=='S'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
   if(a=='F'){
    analogWrite(lm1,250);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    dy+=yspeed;
    
  }
  if(a=='B'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,250);       analogWrite(rm2,250);
    dy-=yspeed;
  
  }
  if(a=='R'){
    analogWrite(lm1,250);  analogWrite(rm1,0);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    dx+=xspeed;
  }
  if(a=='L'){
    analogWrite(lm1,0);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
     dx-=xspeed;

  }
  if(a=='G'){
    analogWrite(lm1,100);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    dy+=lateralSpeed;
    dx-=lateralSpeed;
  }
  if(a=='I'){
    analogWrite(lm1,250);  analogWrite(rm1,100);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    dy-=lateralSpeed;
    dx+=lateralSpeed;
  }
  if(a=='H'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,100);       analogWrite(rm2,250);
    dy-=lateralSpeed;
    dx-=lateralSpeed;
  }
 if(a=='J'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,250);       analogWrite(rm2,100);
    dy-=lateralSpeed;
    dx+=lateralSpeed;
  }
  // String fin = String(val1) + comma + String(val2)+ comma+ String(val3)+comma+ String(val4)+comma+ String(val5)+comma+String(dx)+comma+String(dy)+comma+String(a);
  String fin = String(val1) + comma + String(val2)+ comma+ String(val3)+comma+String(dx)+comma+String(dy)+comma+String(a);
   if (myFile) {
    
    myFile.println(fin);
   
       myFile.close(); // close the file
    
    
  }

  Serial.println(fin);
  
}
}
