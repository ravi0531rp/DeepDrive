#define lm1 8
#define lm2 9
#define rm1 11
#define rm2 10

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
  //check whether arduino is reciving signal or not 
  if(Serial1.available())
  {
   
  if (Serial1.read() == 'S')
  {
    digitalWrite(lm1,LOW);  digitalWrite(rm1,LOW);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
  }

  /*********For Forward motion*********/
  
  if (Serial1.read() == 'F')
  {
    digitalWrite(lm1,HIGH);  digitalWrite(rm1,HIGH);
    digitalWrite(lm2,LOW);       digitalWrite(rm2,LOW);
  }


 
    /*********For Backward Motion*********/
  else if(Serial1.read() == 'B')
  {
      digitalWrite(lm2,HIGH);  digitalWrite(rm2,HIGH);
    digitalWrite(lm1,LOW);       digitalWrite(rm1,LOW);
  
  }
   /*********Right*********/
  else if(Serial1.read() == 'R')
  {
    digitalWrite(lm1,HIGH);  digitalWrite(rm2,HIGH);
    digitalWrite(lm2,LOW);       digitalWrite(rm1,LOW);
  }
   /*********Left*********/
  else if(Serial1.read() == 'L')
  {
     digitalWrite(lm2,HIGH);  digitalWrite(rm1,HIGH);
    digitalWrite(lm1,LOW);       digitalWrite(rm2,LOW);
  
  }
   
  
}
}
