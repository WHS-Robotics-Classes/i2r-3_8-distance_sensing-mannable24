#define echoPin 2
#define trigPin 3

long duration;
int distance;

int red = 10;
int green = 9;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}
  
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print(distance);
  Serial.println(" cm");
  if (distance >= 30){
  analogWrite(green, 255);
  analogWrite(red, 0);
  }
  else if (distance < 30 && distance >= 10){
  analogWrite(red, 255);
  analogWrite(green, 255);
  }
  else {
  analogWrite(red, 255);
  analogWrite(green, 0);
  }
}
