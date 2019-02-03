#define lm1 8 
#define lm2 9
#define rm1 11
#define rm2 10

#include <SD.h>
#include <SPI.h>

#define trigcen 4
#define trigleft 3
#define trigright 6

String hari;

#define echoleft 2
#define echocen 5
#define echoright 7


int dx=0;
int dy=0;
int yspeed=0.9;
int xspeed=0.3;
int lateralSpeed=0.63;
int angSpeed=0.96;

File myFile;
int pinCS = 53; 



void myfunc(String x){
  SD.begin();
  myFile = SD.open("cb.txt", FILE_WRITE);
   
  if (myFile) {
    
    myFile.println(x);
   
       myFile.close(); // close the file  
    
  }
}
    
  



      
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

 
pinMode(pinCS, OUTPUT);
Serial.begin(9600);  
//Serial1.begin(9600);

}

void loop()
{
  

  
digitalWrite(trigcen, LOW);
delayMicroseconds(2);
digitalWrite(trigcen, HIGH);
delayMicroseconds(10);
digitalWrite(trigcen, LOW);
int duration1 = pulseIn(echocen, HIGH);

digitalWrite(trigright, LOW);
delayMicroseconds(2);
digitalWrite(trigright, HIGH);
delayMicroseconds(10);
digitalWrite(trigright, LOW);
int duration2 = pulseIn(echoright, HIGH);

digitalWrite(trigleft, LOW);
delayMicroseconds(2);
digitalWrite(trigleft, HIGH);
delayMicroseconds(10);
digitalWrite(trigright, LOW);
int duration3 = pulseIn(echoleft, HIGH);

  
  String comma = ",";
 
  //check whether arduino is receiving signal or not 
  if(Serial.available())
  {
  char a = Serial.read();
  
  if(a=='S'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    
    
  }
 else if(a=='F'){
    analogWrite(lm1,250);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    dy+=yspeed;
    hari+= String(duration1)+comma+String(duration2)+comma+String(duration3)+comma+String(dx)+comma+String(dy)+comma+String(a);
  }
 else if(a=='B'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,250);       analogWrite(rm2,250);
    dy-=yspeed;
  hari+= String(duration1)+comma+String(duration2)+comma+String(duration3)+comma+String(dx)+comma+String(dy)+comma+String(a);
  }
 else if(a=='R'){
    analogWrite(lm1,250);  analogWrite(rm1,0);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    dx+=xspeed;
    hari+= String(duration1)+comma+String(duration2)+comma+String(duration3)+comma+String(dx)+comma+String(dy)+comma+String(a);
  }
else if(a=='L'){
    analogWrite(lm1,0);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
     dx-=xspeed;
hari+= String(duration1)+comma+String(duration2)+comma+String(duration3)+comma+String(dx)+comma+String(dy)+comma+String(a);
  }
 else if(a=='G'){
    analogWrite(lm1,100);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    dy+=lateralSpeed;
    dx-=lateralSpeed;
    hari+= String(duration1)+comma+String(duration2)+comma+String(duration3)+comma+String(dx)+comma+String(dy)+comma+String(a);
  }
 else if(a=='I'){
    analogWrite(lm1,250);  analogWrite(rm1,100);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    dy-=lateralSpeed;
    dx+=lateralSpeed;
    hari+= String(duration1)+comma+String(duration2)+comma+String(duration3)+comma+String(dx)+comma+String(dy)+comma+String(a);
  }
 else if(a=='H'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,100);       analogWrite(rm2,250);
    dy-=lateralSpeed;
    dx-=lateralSpeed;
    hari+= String(duration1)+comma+String(duration2)+comma+String(duration3)+comma+String(dx)+comma+String(dy)+comma+String(a);
  }
else if(a=='J'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,250);       analogWrite(rm2,100);
    dy-=lateralSpeed;
    dx+=lateralSpeed;
    hari+= String(duration1)+comma+String(duration2)+comma+String(duration3)+comma+String(dx)+comma+String(dy)+comma+String(a);
  }
   
if(a=='U'){
  Serial1.println(a);
    Serial1.println(hari);

  myfunc(hari);
  hari="";

}
  
}
}
