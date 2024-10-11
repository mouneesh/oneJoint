#define outputA 10
#define outputB 11
#define indexPin 9
#define hallSensorPin 13

int counter = 0;
int aState;
int aLastState;
int indexState;
int hallSensorState;

void setup() {
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  pinMode(indexPin, INPUT);
  pinMode(hallSensorPin, INPUT);
  Serial.begin(9600); // Ensure baud rate matches that in the Serial Plotter
  aLastState = digitalRead(outputA);
}

void loop() {
  aState = digitalRead(outputA); // Read the current state of outputA
  if (aState != aLastState) {     
    if (digitalRead(outputB) != aState) { 
      counter++; // Increment on one direction
    } else {
      counter--; // Decrement on the other
    }
  }
  aLastState = aState;

  indexState = digitalRead(indexPin);
  hallSensorState = digitalRead(hallSensorPin);

  // Output the values in a comma-separated line
  Serial.print(counter);
  Serial.print(",");
  Serial.print(aState);
  Serial.print(",");
  Serial.print(digitalRead(outputB));
  Serial.print(",Index - ");
  Serial.print(indexState);
  Serial.print(", Hall Sensor - ");
  Serial.println(hallSensorState);

  // Delay slightly for readability
  delay(10);
}
