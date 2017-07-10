/* @file HelloKeypad.pde
  || @version 1.0
  || @author Alexander Brevig
  || @contact alexanderbrevig@gmail.com
  ||
  || @description
  || | Demonstrates the simplest use of the matrix Keypad library.
  || #
*/
#include <Keypad.h>
#include <Wire.h>
#include "rgb_lcd.h"

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
byte rowPins[ROWS] = {5, 6, 7, 8};
byte colPins[COLS] = {2, 3, 4};
rgb_lcd lcd;
int flag = 0;
int num = 0;
int num2 = 0;
int res = 1;
int i = 0;

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  // Print a message to the LCD.

}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key != '*' && key != '#')
    {
      num = num * 10 + key - '0';
      lcd.print(num);
    }
    if (key == '*')
    {

      if (flag == 1)
      {
        lcd.print("*");
        num = res;
        num2 = num;
        num = 0;
      }
      else
      {
        res = res * num;
        num = 0;
        lcd.print("*");
      }
    }
    if (key == '#')
    {
      if (flag == 1)
      {
        res = num * num2;
        lcd.print("=");
        lcd.print(res);
        
      }
      else
      {
        res = res * num;
        lcd.print("=");
        lcd.print(res);
        flag = 1;
        num = 0;

      }
    }
  }
}
