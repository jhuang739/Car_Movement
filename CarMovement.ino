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

  if(leftRead > 700 && middleRead > 800 && rightRead > 800) //stop
  {
    //check if all three analog reads are a high value
    digitalWrite(topLeftLight, HIGH);
    digitalWrite(topMiddleLight, LOW);
    digitalWrite(topRightLight, HIGH);
    
    while(true)
    {      
      analogWrite(rightMotor, 0);
      analogWrite(leftMotor, 0);
    }
  }
  else if (middleRead > 800) {
      digitalWrite(topLeftLight, LOW);
      digitalWrite(topMiddleLight, HIGH);
      digitalWrite(topRightLight, LOW);
      analogWrite(rightMotor, 240);
      analogWrite(leftMotor,240);
  }
  else if(leftRead > 550) //turn left
  {
    digitalWrite(topLeftLight, HIGH);
    digitalWrite(topMiddleLight, LOW);
    digitalWrite(topRightLight, LOW);

    if(middleRead > 650) //slight left
    {  
      analogWrite(rightMotor, 240);
      analogWrite(leftMotor, 100);
      //Serial.println("slight left");
    }
    else
    {
      analogWrite(rightMotor, 240);
      analogWrite(leftMotor, 0);
    }
  }
  else if(rightRead > 700) //turn right
  {
    digitalWrite(topLeftLight, LOW);
    digitalWrite(topMiddleLight, LOW);
    digitalWrite(topRightLight, HIGH);
    
    if(middleRead > 650) //slight right
    {  
      analogWrite(rightMotor, 100);
      analogWrite(leftMotor, 240);
      //Serial.println("slight right");
    }
    else
    {
      analogWrite(rightMotor, 0);
      analogWrite(leftMotor, 240);
    }
  }
  else //move straight
  {
    digitalWrite(topLeftLight, LOW);
    digitalWrite(topMiddleLight, HIGH);
    digitalWrite(topRightLight, LOW);
  
    analogWrite(rightMotor, 240);
    analogWrite(leftMotor, 240);
  }
}
