/*
 * Car Movement source code
 */

//digital
int topRightLight = 11;
int topMiddleLight = 10;
int topLeftLight = 9;

int rightMotor = 6;
int leftMotor = 5;

// analog
int rightSensor = 0;
int rightRead = 0;

int middleSensor = 1;
int middleRead = 0;

int leftSensor = 2;
int leftRead = 0;

// the setup routine runs once when you press reset:
void setup() {
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  
  pinMode(topRightLight, OUTPUT);
  pinMode(topMiddleLight, OUTPUT);
  pinMode(topLeftLight, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  rightRead = analogRead(rightSensor);
  middleRead = analogRead(middleSensor);
  leftRead = analogRead(leftSensor);

  Serial.print(leftRead);
  Serial.print(" ");
  Serial.print(middleRead);
  Serial.print(" ");
  Serial.println(rightRead);

  if(leftRead > 700 && rightRead > 700 && middleRead > 700)
  {
    //check if all three analog reads are a high value
    digitalWrite(topLeftLight, LOW);
    digitalWrite(topMiddleLight, LOW);
    digitalWrite(topRightLight, LOW);
    
    while(true)
    {
      analogWrite(rightMotor, 0);
      analogWrite(leftMotor, 0);
    }
  }
  else if(leftRead > 700) //turn left
  {
    digitalWrite(topLeftLight, HIGH);
    digitalWrite(topMiddleLight, LOW);
    digitalWrite(topRightLight, LOW);
  
    analogWrite(rightMotor, 240);
    analogWrite(leftMotor, 0);
  }
  else if(rightRead > 700) //turn right
  {
    digitalWrite(topLeftLight, LOW);
    digitalWrite(topMiddleLight, LOW);
    digitalWrite(topRightLight, HIGH);
  
    analogWrite(rightMotor, 0);
    analogWrite(leftMotor, 240);
  }
  else //move straight
  {
    digitalWrite(topLeftLight, LOW);
    digitalWrite(topMiddleLight, HIGH);
    digitalWrite(topRightLight, LOW);
  
    analogWrite(rightMotor, 150);
    analogWrite(leftMotor, 150);
  }
}
