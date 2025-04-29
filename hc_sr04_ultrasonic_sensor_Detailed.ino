const int trigPin = 9; //Trig pin
const int echoPin = 10; //Echo Pin

float duration = 0; //Represents the duration it takes to send a sound signal and receive it.
float distance = 0; //Reprents the distance measured by the sensor after it is calculated.

void setup() {
  pinMode(trigPin, OUTPUT); //Set up Trig pin
  pinMode(echoPin, INPUT); //Set up Echo Pin
  Serial.begin(9600); // Setup serial communication for monitoring
}

void loop() {
  digitalWrite(trigPin, LOW); //Make sure Trig is LOW.
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // Set the Trig HIGH to send out the sound signal.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // Set the Trig back to LOW.

  duration = pulseIn(echoPin, HIGH); // The time it takes to send and receive sound signal.
  distance = (duration*.0343)/2; // Equation to calculate the distance (centimeters) based on the time it took to send and receive a sound signal.
  Serial.println(distance); //Distance in centimeters.
  delay(100); //delay between the time each measurement is taken.
}
