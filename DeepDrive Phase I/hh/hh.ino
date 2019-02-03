#define lm1 8 
#define lm2 9
#define rm1 11
#define rm2 10

#include <SD.h>
#include <SPI.h>

#define trigcen 4
String hari;

#define echocen 5

File myFile;
int pinCS = 53; 
     
void setup() {
 pinMode(lm1,OUTPUT);
 pinMode(lm2,OUTPUT);
 pinMode(rm1,OUTPUT);
 pinMode(rm2,OUTPUT);
 
 pinMode(trigcen,OUTPUT);
 pinMode(echocen,INPUT);
pinMode(pinCS, OUTPUT);
Serial.begin(9600);
}

void loop()
{ 


 String comma = ",";
 
  if(Serial.available())
  {


  char a = Serial.read();
 if(a=='S'){
  // do nothing
 }  
  digitalWrite(trigcen, LOW);
  delayMicroseconds(2);
  digitalWrite(trigcen, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigcen, LOW);
  int duration1 = pulseIn(echocen, HIGH);
  Serial.println(duration1);
  Serial.println(a);
    
  
  if(a=='F'){
    analogWrite(lm1,250);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);

  }
 else if(a=='B'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,250);       analogWrite(rm2,250);
  }

 else if(a=='R'){
    analogWrite(lm1,250);  analogWrite(rm1,0);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
else if(a=='L'){
    analogWrite(lm1,0);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
else  if(a=='G'){
    analogWrite(lm1,100);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
    
else  if(a=='I'){
    analogWrite(lm1,250);  analogWrite(rm1,100);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
 else if(a=='H'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,100);       analogWrite(rm2,250);
  }
else if(a=='J'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,250);       analogWrite(rm2,100);
  }
}
}
}
