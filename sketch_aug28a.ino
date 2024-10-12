#include <AccelStepper.h>

#define dirPin 4    // Direction pin
#define stepPin 3   // Pulse/Step pin
#define enPin 5     // Enable pin (optional)

// Define steps per revolution
const int stepsPerRevolution = 1600;

// Create an instance of AccelStepper using DRIVER mode
AccelStepper stepper(AccelStepper::DRIVER, stepPin, dirPin, enPin);

void setup() 
{
  // Set the maximum speed and acceleration
  stepper.setMaxSpeed(stepsPerRevolution);     // Max speed in steps per second
  stepper.setAcceleration(stepsPerRevolution);  // Acceleration in steps per second^2

  // Enable the motor (if required by your driver)
  pinMode(enPin, OUTPUT);
  digitalWrite(enPin, HIGH);  // LOW to enable the motor

  // Move to the initial position
  stepper.moveTo(3200);  // Move one full revolution (1600 steps)
}

void loop() 
{
  // Move the stepper motor to a target position
  if (stepper.distanceToGo() == 0) 
  {
    stepper.moveTo(-stepper.currentPosition());  // Move to the opposite position
    enablePin = 0;
  }
  stepper.run();  // This will move the motor towards the target position
  
}
