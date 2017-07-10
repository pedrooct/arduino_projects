
#include <Servo.h>
int MEASURES = 20;
int ledv = 12;
int  leda = 11;
int ired = A2;
int sonar = 9;
Servo motor;
long d;
long i;
float s;
unsigned int p;

void setup() {

  pinMode(ledv, OUTPUT);
  pinMode(leda, OUTPUT);
  pinMode(ired, INPUT);
  pinMode(8, OUTPUT);
  pinMode(sonar, INPUT);
  motor.attach(5);
  motor.write(90);
  Serial.begin(9600);

}

void loop() {

  float sumSonar = 0.0; // recolha de amostras para fazer média
  for (int i = 0; i < MEASURES; i++ )
    sumSonar += pulseIn(sonar, HIGH);
  sumSonar /= MEASURES;

  i = analogRead(ired);
  s = (sumSonar / 147) * 2.54; // converte para distancia em cm
  if (s < 30 ) // se o valor de distancia do sonar for menor que 30 cm entra no if e inicia o ciclo while à espera do sonar
  {
    digitalWrite(leda, HIGH);
    motor.write(0); // servo motor para 0
    while (analogRead(ired) <= 266 ) // enquanto não ativar o sensor o infravermelhos fica em ciclo á espera
    {
    }
    digitalWrite(ledv, HIGH);
    motor.write(90); // fecha porta;
    p--; //saiu uma pessoa
  }
  if (i >= 266 ) //// se o valor de distancia no infravermelhos for menor que 30 cm entra no if e inicia o ciclo while à espera do sonar
  {
    digitalWrite(ledv, HIGH);
    motor.write(180);
    sumSonar = 0.0;
    while (s > 30 ) // á espera que detete um obstaculo
    {
      for (int i = 0; i < MEASURES; i++ ) // vai atualizando o valor enquanto não deteta
        sumSonar += pulseIn(sonar, HIGH);
      sumSonar /= MEASURES;
      s = (sumSonar / 147) * 2.54;

    }
    digitalWrite(leda, HIGH);
    motor.write(90); //fecha a porta
    p++; // uma pessoa entrou
  }
  else
  {
    digitalWrite(ledv, LOW);
    digitalWrite(leda, LOW);
    motor.write(90);
  }
  Serial.println(p); // imprime
  delay(1000);
}
