#include <Wire.h>
String incoming="Pravi;";
void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
  Wire.begin();
}

void loop() {
Wire.beginTransmission(9);
int c =0;


while(c<incoming.length()){
  
    Wire.write(incoming[c]);
    c++;
    Serial.println(incoming[c]);
  }
  Wire.endTransmission();  
}
