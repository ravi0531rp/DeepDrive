#define lm1 8
#define lm2 9
#define rm1 11
#define rm2 10
int count=0;
void setup() {
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
   
Serial.begin(9600);  
Serial1.begin(9600);
}

void loop()
{
  
  if(Serial1.available()){
  char a = Serial1.read();
  
 
  
  if(a=='S'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
   if(a=='F'){
    analogWrite(lm1,250);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    
  }
  if(a=='B'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,250);       analogWrite(rm2,250);
  }
  if(a=='R'){
    analogWrite(lm1,250);  analogWrite(rm1,0);
    analogWrite(lm2,0);       analogWrite(rm2,0);
    Serial.println(a);
    count+=1;
    Serial.println(count);
    Serial.println("-------------------------");
  }
  if(a=='L'){
    analogWrite(lm1,0);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
  if(a=='G'){
    analogWrite(lm1,100);  analogWrite(rm1,250);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
  if(a=='I'){
    analogWrite(lm1,250);  analogWrite(rm1,100);
    analogWrite(lm2,0);       analogWrite(rm2,0);
  }
  if(a=='H'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,100);       analogWrite(rm2,250);
  }
 if(a=='J'){
    analogWrite(lm1,0);  analogWrite(rm1,0);
    analogWrite(lm2,250);       analogWrite(rm2,100);
  }
}
}
