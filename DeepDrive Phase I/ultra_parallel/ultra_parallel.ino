#define trigcen 4
#define trigleft 3
#define trigright 6


#define echoleft 2
#define echocen 5
#define echoright 7

      
void setup() {

 pinMode(trigcen,OUTPUT);
 pinMode(trigright,OUTPUT);
 pinMode(trigleft,OUTPUT);

 
 pinMode(echocen,INPUT);
 pinMode(echoright,INPUT);
 pinMode(echoleft,INPUT);

 
Serial.begin(9600);  

}

void loop()
{
  

  

digitalWrite(trigright, LOW);
digitalWrite(trigleft, LOW);
digitalWrite(trigcen, LOW);

delayMicroseconds(2);

digitalWrite(trigright, HIGH);
digitalWrite(trigleft, HIGH);
digitalWrite(trigcen, HIGH);

delayMicroseconds(10);
digitalWrite(trigright, LOW);
digitalWrite(trigright, LOW);
digitalWrite(trigcen, LOW);

int duration1 = pulseIn(echocen,HIGH);
int duration2 = pulseIn(echoleft,HIGH);
int duration3 = pulseIn(echoright,HIGH);

Serial.print(duration1);
Serial.print(",");
Serial.print(duration2);
Serial.print(",");
Serial.println(duration3);


}
