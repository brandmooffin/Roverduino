const int trigPin = 11;
const int echoPin = 10;
const int in1 = 9;
const int in2 = 8;
const int in3 = 4;
const int in4 = 3;

long duration, distance;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
}
  
void loop()
{
  // Reset pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(12);
  digitalWrite(trigPin, LOW);

  // Check for distance
  duration = pulseIn(echoPin, HIGH);
  distance = duration/58.2;
  if(distance < 30)
  {
    // Obstacle found
    // Rotate rover
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  }
  else
  {
    // Move forward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  }

  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  delay(90);
}
