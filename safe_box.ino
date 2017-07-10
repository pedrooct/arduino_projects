int greenled = 13, redled = 12, blueLed = 11;
int num, num1;
int button = 44, buttonReset = 40;
int i = 0, j=0, k=0;
int flagR;
int find[4];
int key[4] = {1, 2, 3, 4};
int pot = 0; //potentiometer attatched
int pinArray[] =      {2, 3, 4, 5, 6 , 7, 8, 9};
int matrix [10][8] = {{0, 0, 0, 0, 0, 1, 1, 0},
  {1, 0, 0, 1, 1, 1, 1, 1},
  {0, 0, 1, 0, 0, 1, 0, 1},
  {0, 0, 0, 0, 1, 1, 0, 1},
  {0, 1, 1, 0, 0, 1, 0, 0},
  {1, 0, 1, 0, 1, 1, 0, 0},
  {0, 1, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 1, 0, 1, 0, 1},
  {1, 0, 1, 0, 1, 1, 1, 1},
  {0, 0, 0, 0, 0, 1, 1, 0}
};
void setup() {
  Serial.begin(9600);
  pinMode(greenled, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(pot, INPUT);
  pinMode(button,INPUT);
  pinMode(buttonReset,INPUT);

  for (i = 0; i < 9; i++)
  {
    pinMode(pinArray[i], OUTPUT);
  }
  j = 0;
}

void displayNumber(int num1)
{
  delay(500);
  for (j = 0; j <= 9; j++)
  {
    digitalWrite(pinArray[j], matrix[num1][j]);
  }
}

void loop() {

  num1 = analogRead(pot);

  num = map(num1, 0, 1015, 0, 9);
  Serial.println(num);
  displayNumber(num);
  if (digitalRead(button) == HIGH)
  {
    find[j] = num;
    j++;
    digitalWrite(blueLed, HIGH);
    delay(1000);
    digitalWrite(blueLed, LOW);
  }
  if (digitalRead(buttonReset) == HIGH)
  {
    flagR = 1;
    while (flagR == 1) {
      num1 = analogRead(pot);
      num = map(num1, 0, 1023, 0, 9);
      if (digitalRead(buttonReset) == LOW) {
        key[i] = num;
        i++;
      }
      digitalWrite(blueLed, HIGH);
      delay(1000);
      digitalWrite(blueLed, LOW);
      if(i==4)
      {
          i = 0;
          flagR = 0;
          break;
      }
    }
    
  }

  if (j == 4)
  {
    for (k = 0; k < 4; k++) {
      if (find[k] != key[k])
      {
        digitalWrite(redled, HIGH);
        delay(1000);
        digitalWrite(redled, LOW);
        break;
      }
    }
    if (k == 4)
    {
      digitalWrite(greenled, HIGH);
      delay(1000);
      digitalWrite(greenled, LOW);
      k = 0;
    }
    j = 0;
  }

}


