const int ledPin = 8;
const int ledPin2 = 9;
int incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
int x=1000;
while (millis()<x)
{
  if (Serial.available() > 0) {
  x=10000;
    incomingByte = Serial.read();
    if (incomingByte == '1') {
      digitalWrite(ledPin, HIGH);
    }
    if (incomingByte == 'Q') {
      digitalWrite(ledPin, LOW);
    }
    if (incomingByte == '2') {
      digitalWrite(ledPin2, HIGH);
    }
    if (incomingByte == 'Q') {
      digitalWrite(ledPin2, LOW);
    }
  }}
  digitalWrite(ledPin2, HIGH);
  delay(250);
  digitalWrite(ledPin2, LOW);
  delay(250);
  digitalWrite(ledPin2, HIGH);
  delay(250);
  digitalWrite(ledPin2, LOW);
  delay(250);
  digitalWrite(ledPin2, HIGH);
  delay(250);
  digitalWrite(ledPin2, LOW);
  delay(250);
  digitalWrite(ledPin2, HIGH);
  delay(250);
  digitalWrite(ledPin2, LOW);
  delay(250);
  digitalWrite(ledPin2, HIGH);
  delay(250);
  digitalWrite(ledPin2, LOW);
  delay(250);
  digitalWrite(ledPin2, HIGH);
  delay(250);
  digitalWrite(ledPin2, LOW);
  delay(250);
  
}