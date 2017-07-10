#include<Servo.h>

int buzz = 11;
int ledverde = 12;
int ledred = 3;
int i = 0;
int num1, num2, res;
int user;
int count = 0;
int answer = 1;
int sign;
Servo motor;

void setup() {
  motor.attach(7);
  pinMode(ledverde, OUTPUT);
  pinMode(ledred, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
  motor.write(0);
}
void loop() {


  if (answer == 1)
  {
    sign = random(0, 4);
    if (sign == 0)
    {
      num1 = random(1, 11);
      num2 = random(1, 11);
      res = num1 + num2;
      Serial.print(num1);
      Serial.print("+");
      Serial.println(num2);
      answer = 0;
    }
    else if (sign == 1)
    {
      num1 = random(1, 11);
      num2 = random(1, 11);
      res = num1 - num2;
      Serial.print(num1);
      Serial.print("-");
      Serial.println(num2);
      answer = 0;
    }
    else if (sign == 2)
    {
      num1 = random(1, 11);
      num2 = random(1, 11);
      res = num1 * num2;
      Serial.print(num1);
      Serial.print("*");
      Serial.println(num2);
      answer = 0;
    }
    else if (sign == 3)
    {
      num1 = random(1, 11);
      num2 = random(1, 11);
      res = num1 / num2;
      Serial.print(num1);
      Serial.print("/");
      Serial.println(num2);
      answer = 0;
    }
  }
  if (Serial.available() > 0)
  {
    user = Serial.parseInt();
    Serial.println(user);
    answer = 1;
    if (user == res)
    {
      digitalWrite(ledverde, HIGH);
      delay(1000);
      digitalWrite(ledverde, LOW);
      i = i + 20;
      count++;
      if (count <= 8)
      {
        motor.write(i);
      }
    }
    else if (user != res)
    {
      i = 0;
      digitalWrite(ledred, HIGH);
      delay(1000);
      digitalWrite(ledred, LOW);
      motor.write(i);
      count = 0;
    }
  }
  if (count == 8)
  {
    motor.write(180);
    analogWrite(buzz, 200);
    delay(500);
    analogWrite(buzz, 0);
    delay(500);
    count++;
  }
}
