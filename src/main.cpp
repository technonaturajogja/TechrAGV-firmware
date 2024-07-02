#include <Arduino.h> 
#include <AFMotor.h>

// AF_DCMotor motor1(1);
// AF_DCMotor motor2(2);
AF_DCMotor motor3(3); 
AF_DCMotor motor4(4); 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Start Serial Communication
}

void loop() {
  // put your main code here, to run repeatedly:

  // Looping if there is serial data received
  while(Serial.available()>0){
    uint8_t data[10]; // declaring the data buffer
    Serial.readBytesUntil('/n',data,6); // reading data from serial

    // if the first and the last received data are synchrone with the real data
    if(data[0] == 's' && data[5] =='d'){
        // in this particular application, we use serial to send velocity values of each motor in arduino
        // since uint8_t only receive data from 0-255, which doesn't contain minus, hence we need an element
        // in the array data to specify if it's minus or plus
        if(data[1] == 0) 
          Serial.print("-");
        else
          Serial.print("");
        Serial.print(data[2]);
        Serial.print(",");
        if(data[3] == 0)
          Serial.print("-");
        else
          Serial.print("");
        Serial.println(data[4]);
        
      // Atur kecepatan motor berdasarkan input
      motor1.setSpeed(data[2]);
      motor2.setSpeed(data[4]);
      // motor3.setSpeed(data[6]);
      // motor4.setSpeed(data[8]);
      
      // // Gerakkan semua motor maju
      motor1.run(data[1]);
      motor2.run(data[3]);
      // motor3.run(data[5]);
      // motor4.run(data[7]);
      delay(100);
    
    }
  }

   
  
  }





