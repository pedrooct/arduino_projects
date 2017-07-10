int i, j, k;
int pinArray[] =      {13, 12, 11, 10, 9, 14, 15};
int matrix [3][7] =  {{1, 0, 0, 1, 1, 1, 1},
                      {0, 0, 1, 0, 0, 1, 0},
                      {0, 0, 0, 0, 1, 1, 0},};
int elevatornum = 1, currentLevel = 1;

int redLed = 4, greenLed = 18;
int bt1 = 5, bt2 = 6, bt3 = 7;
int eleBt1 = 1, eleBt2 = 2, eleBt3 = 3;

int north=16,south=17;
int enable=3;

void setup() {

  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(bt1, INPUT);
  pinMode(bt2, INPUT);
  pinMode(bt3, INPUT);
  pinMode(north,OUTPUT);
  pinMode(south,OUTPUT);
  pinMode(enable,OUTPUT);

  for (i = 0; i < 7; i++)
  {
    pinMode(pinArray[i], OUTPUT);
  }
}

void displayNumber(int num)
{
  delay(1000);
  for (k = 0; k <= 6; k++)
  {
    digitalWrite(pinArray[k], matrix[num - 1][k]);
  }
}

void loop() {

  digitalWrite(greenLed, HIGH);
  elevatornum = currentLevel;
  digitalWrite(redLed, LOW);
  digitalWrite(bt1, HIGH);
  digitalWrite(bt2, HIGH);
  digitalWrite(bt3, HIGH);
  displayNumber(elevatornum);
  digitalWrite(north,LOW);
  digitalWrite(south,LOW);
  digitalWrite(enable,LOW);
  if (digitalRead(bt1) == LOW)
  {
    currentLevel = 1;
    if (elevatornum - currentLevel > 0)
      j = -1;
    else
      j = 1;
  }
  if (digitalRead(bt2) == LOW)
  {
    currentLevel = 2;
    if (elevatornum - currentLevel > 0)
      j = -1;
    else
      j = 1;
  }
  if (digitalRead(bt3) == LOW)
  {
    currentLevel = 3;
    if (elevatornum - currentLevel > 0)
      j = -1;
    else
      j = 1;
  }
  if (j < 0)
  {
    for (i = elevatornum; i > currentLevel; i = i + j)
    {
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      displayNumber(i);
      digitalWrite(north,HIGH);
      digitalWrite(south,LOW);
      analogWrite(enable,100);
      delay(1000);
    }
  }
  else {
    for (i = elevatornum; i < currentLevel; i = i + j)
    {
      digitalWrite(greenLed, LOW);
      digitalWrite(redLed, HIGH);
      displayNumber(i);
      digitalWrite(north,LOW);
      digitalWrite(south,HIGH);
      analogWrite(enable,100);
      delay(1000);
    }
  }
}
