#include <SD.h>
#include <SPI.h>
#define trigcen 4
#define trigleft 3
#define trigright 6
#define echoleft 2
#define echocen 5
#define echoright 7
#define lm1 8
#define lm2 9
#define rm1 11
#define rm2 10
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
SD.begin();
  
  // Create/Open file 
  myFile = SD.open("cha.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.println("Writing to file...");
    // Write to file
    myFile.print(ultra(trigcen,echocen));
    myFile.print(",");
       myFile.close(); // close the file
    
    Serial.println("Done.");
  }

    myFile = SD.open("cha.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.println("Writing to file...");
    // Write to file
    myFile.print(ultra(trigleft,echoleft));
    myFile.print(",");
       myFile.close(); // close the file
    
    Serial.println("Done.");
  }


    myFile = SD.open("cha.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.println("Writing to file...");
    // Write to file
    myFile.print(ultra(trigright,echoright));
    myFile.print(",");
       myFile.close(); // close the file
    
    Serial.println("Done.");
  }

  
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening file");
  }





















  
//  // Reading the file
//  myFile = SD.open("chachachu.csv");
//  if (myFile) {
//    Serial.println("Read:");
//    // Reading the whole file
//    while (myFile.available()) {
//      Serial.write(myFile.read());
//   }
//    myFile.close();
//  }
//  else {
//    Serial.println("error opening test.txt");
//  }
}
