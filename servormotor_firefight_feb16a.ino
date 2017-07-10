
#include <Servo.h>

Servo motorX;
Servo motorY;
int potpinX = 1;
int potpinY = 0;
int val;
int INA = 5;
int INB = 6;
int state=LOW;


void setup() {
  // put your setup code here, to run once:
  motorY.attach(8);
  motorX.attach(7);
  pinMode(2, INPUT);
  Serial.begin(9600);
  pinMode(INA, OUTPUT);
  pinMode(INB, OUTPUT);
}

void loop() {

  val = analogRead(potpinX);
  val = map(val, 0, 1023, 0, 180);
  motorX.write(val);
  val = analogRead(potpinY);
  val = map(val, 0, 1023, 0, 180);
  motorY.write(val);
  delay(150);

  
  if (digitalRead(2) == LOW)
  {
    state=!state;
  }
      
      
  if(state)    {
      digitalWrite(INA, LOW);
      digitalWrite(INB, HIGH);

  } else {
    
      digitalWrite(INA, LOW);
      digitalWrite(INB, LOW);

    }
}
