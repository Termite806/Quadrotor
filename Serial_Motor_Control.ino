#include <Servo.h>

#define FIRST_MOTOR_PIN 9  //Back Right         //define the pins the motors are on 
#define SECOUND_MOTOR_PIN 10 //Front Right
#define THIRD_MOTOR_PIN 11  //Back Left
#define FOURTH_MOTOR_PIN 6  //Front Left

Servo motorFL;   //say there are 4 motors
Servo motorFR;
Servo motorBL;
Servo motorBR;
int input = 0;      //variables for speed and serial input
int spd = 1200;     //defualt speed to start the program

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                   //start serial
  motorBR.attach(FIRST_MOTOR_PIN);       //attach the motors to the pins
  motorFR.attach(SECOUND_MOTOR_PIN);
  motorBL.attach(THIRD_MOTOR_PIN);
  motorFL.attach(FOURTH_MOTOR_PIN);
  Serial.println("Program Starting");
  Serial.println("1 = -10 | 2 = -5 | 3 = -1 | 4 = +1 | 5 = +5 | 6 = +10 | k = kill process");      //input usage prompt
}

void loop() {
  if(input == 0)
  {
  motorFL.writeMicroseconds(spd);    //start the motors at spd
  motorFR.writeMicroseconds(spd);
  motorBL.writeMicroseconds(spd);
  motorBR.writeMicroseconds(spd);
  }
  
  if(Serial.available() > 0)      //read from serial
  {
    input = Serial.read();      //store the serial input into input
    Serial.print("input = ");   //display the value read
    Serial.print(input);
    Serial.println("");
  }
  if(input == 49)       //the value of 1
  {
    spd = spd - 10;
  }
  else if(input == 50)        //the value of 2
  {
    spd = spd - 5;
  }
  else if(input == 51)        //the value of 3
  {
    spd = spd - 1;
  }
  else if(input == 52)      //the value of 4
  {
    spd = spd + 1;
  }
  else if(input == 53)      //the value of 5
  {
    spd = spd + 5;
  }
  else if (input == 54)     //the value of 6
  {
    spd = spd + 10;
  }
  else if(input == 'k')     //if k is sent
  {
     Serial.println("");
     Serial.print("process killed");
     motorFL.writeMicroseconds(1000);      //slow the motors down
     motorFR.writeMicroseconds(1000);
     motorBL.writeMicroseconds(1000);
     motorBR.writeMicroseconds(1000);
     delay(1000);                           //wait for the motor to slow down
     motorFL.detach();                 //detach the motors to stop from turing on again
     motorFR.detach();
     motorBL.detach();
     motorBR.detach();
  }
  if(input != 0)      //if input was given
  {
    if(input != 'k')    //if the input was not kill
    {
      Serial.print("Speed = ");       //display the speed
      Serial.println(spd);
      Serial.println("");
    }
    input = 0;                          //re initalize the input
  }
  
}
