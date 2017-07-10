static const struct {
  const char letter, *code;
} MorseMap[] =
{
  { 'A', ".-" },
  { 'B', "-..." },
  { 'C', "-.-." },
  { 'D', "-.." },
  { 'E', "." },
  { 'F', "..-." },
  { 'G', "--." },
  { 'H', "...." },
  { 'I', ".." },
  { 'J', ".---" },
  { 'K', ".-.-" },
  { 'L', ".-.." },
  { 'M', "--" },
  { 'N', "-." },
  { 'O', "---" },
  { 'P', ".--." },
  { 'Q', "--.-" },
  { 'R', ".-." },
  { 'S', "..." },
  { 'T', "-" },
  { 'U', "..-" },
  { 'V', "...-" },
  { 'W', ".--" },
  { 'X', "-..-" },
  { 'Y', "-.--" },
  { 'Z', "--.." },
  { ' ', "     " },
};
String buff;
int flag = 0;
int i = 0, j = 0, k = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (flag == 0)
  {
    Serial.println("Write a message: ");
    flag = 1;
  }
  if (Serial.available() > 0)
  {
    buff = Serial.readString();
    Serial.println(buff);
    for (i = 0; buff[i] != '\0'; i++)
    {
      for (j = 0; j <= 26; j++)
      {
        if (buff[i] == MorseMap[j].letter)
        {
          for (k = 0; MorseMap[j].code[k] != '\0'; k++)
          {
            delay(500);
            if (MorseMap[j].code[k] == '.')
            {
              Serial.println("1s");
              digitalWrite(12, HIGH);
              delay(1000);
              digitalWrite(12, LOW);
            }
            delay(500);
            if (MorseMap[j].code[k] == '-')
            {
              Serial.println("3s");
              digitalWrite(12, HIGH);
              delay(3000);
              digitalWrite(12, LOW);
            }
            delay(500);
          }
        }
      }
    }
    flag = 0;
  }

}

