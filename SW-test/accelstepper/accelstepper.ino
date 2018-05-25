/*
Runs two 28BYJ-48 stepper motors with AccelStepper Library.
Motors accelerate and decelerate simultaneously in opposite rotations
NOTE: May need separate +5 power supply to power motors
*/

#include <AccelStepper.h>

#define FULLSTEP 4
#define HALFSTEP 8

#define motorPin1  2    // Blue   - 28BYJ48 pin 1
#define motorPin2  1     // Pink   - 28BYJ48 pin 2
#define motorPin3  0     // Yellow - 28BYJ48 pin 3
#define motorPin4  3     // Orange - 28BYJ48 pin 4
                        // Red    - 28BYJ48 pin 5 (VCC)
                        

// NOTE: The sequence 1-3-2-4 is required for proper sequencing of 28BYJ48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);


void setup()
{
  stepper1.setMaxSpeed(2000.0);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(50);
  stepper1.moveTo(305);  // 1 revolution 
  

}


void loop()
{
  //Change direction at the limits
  if (stepper1.distanceToGo() == 0) 
    stepper1.moveTo(-stepper1.currentPosition());

  
  stepper1.run();

}
