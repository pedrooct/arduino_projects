
void setup() {
  pinMode(12, OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,INPUT);
  pinMode(8,OUTPUT);

  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long d = pulseIn(10,HIGH);
  Serial.println(d);
  if(d < 160)
  {
    digitalWrite(8,HIGH);
  }
   digitalWrite(8,LOW);
}
