// MultiStepper.pde
// -*- mode: C++ -*-
// Use MultiStepper class to manage multiple steppers and make them all move to 
// the same position at the same time for linear 2d (or 3d) motion.

#include <AccelStepper.h>
#include <MultiStepper.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// EG X-Y position bed driven by 2 steppers
AccelStepper stepper1(1,9,8);
AccelStepper stepper2(1,2,3);
AccelStepper stepper3(1,7,6);
AccelStepper stepper4(1,5,4);

// Position Marking
long positionsStepper[4]; // Array of desired stepper positions
long pos = 0;
String printChar;
long realPosition[4];


//buffer Serial
const int bSize = 20; 
char Buffer[bSize];  // Serial buffer
char Command[10];    // Arbitrary Value for command size
char Data[15];       // ditto for data size
int ByteCount;
char rep[70];

// Up to 10 steppers can be handled as a group by MultiStepper
MultiStepper steppers;

//setup code
void setup() {
  Serial.begin(9600);

  Serial.println("Robot Arm Demo Alpha Version 1.0");
  
  // Configure each stepper
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
  stepper3.setMaxSpeed(1000);
  stepper4.setMaxSpeed(1000);

  // Then give them to MultiStepper to manage
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
  steppers.addStepper(stepper3);
  steppers.addStepper(stepper4);

  //start position
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
  stepper3.setCurrentPosition(0);
  stepper4.setCurrentPosition(0);
  realPosition[0] = 0;
  realPosition[1] = 0;
  realPosition[2] = 0;
  realPosition[3] = 0;
}

void loop() {
 
  SerialParser();
         if (ByteCount  > 0) {
          process();
          //Serial.print("Command     : ");
          //Serial.println(Command);
          //Serial.print("Data        : ");
          //Serial.println(Data);
          
         }  
}
