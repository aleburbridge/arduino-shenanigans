int ledPin = 13;
int temperaturePin = A0;
int temperatureThresholdC = 30;

void setup()
{
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float analogReading = (analogRead(temperaturePin));
  float voltageReading = analogReading * (5.0 / 1023.0);
  float tempC = (voltageReading - 0.5) * 100.0;

  if (tempC > temperatureThresholdC) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
  Serial.println(tempC);
  delay(1000);
}