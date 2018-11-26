//digital

int led = 7;
int rightMotor = 6;

int topRightLight = 11;
int topMiddleLight = 10;
int topLeftLight = 9;

//analog
int pTransistor = 3;
int pRead = 0;

int counter = 0;
int past = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(rightMotor, OUTPUT);

  pinMode(topRightLight, OUTPUT);
  pinMode(topMiddleLight, OUTPUT);
  pinMode(topLeftLight, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  pRead = analogRead(A3);
  digitalWrite(led, HIGH);
  analogWrite(rightMotor, 150);

  Serial.println(pRead);

  int current = pRead;

  if(abs(current-past) < 20)
  {
    counter++;
  }
  else
  {
    counter = 0;
  }
  
  if(counter >= 100)
  {
    digitalWrite(topLeftLight, HIGH);
    digitalWrite(topMiddleLight, HIGH);
    digitalWrite(topRightLight, HIGH);

    delay(500);

    digitalWrite(topLeftLight, LOW);
    digitalWrite(topMiddleLight, LOW);
    digitalWrite(topRightLight, LOW);

    delay(500);
    
    analogWrite(rightMotor, 240);
  }
  past = current;
}
