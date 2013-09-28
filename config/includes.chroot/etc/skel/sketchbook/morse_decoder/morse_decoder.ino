/*
 * Hardware:
 * a switch connected to pin 2 with a pulldown resistor
 */

#define BUTTON 2
#define LCD_PINS 12, 11, 10, 9, 8, 7
#define LCD_COLUMNS 16
#define LCD_ROWS 2

#define PULSE_THRESHOLD 200
#define LETTER_SEPARATION 500
#define WORD_SEPARATION 2000

void setup()
{
  pinMode(BUTTON, INPUT);

  initMorse(BUTTON, PULSE_THRESHOLD, LETTER_SEPARATION, WORD_SEPARATION);

  initLCD(LCD_COLUMNS, LCD_ROWS, LCD_PINS);
}

void loop()
{
  // used to skip the first space
  static boolean firstLoop = true;

  char c = getNextChar();

  if (firstLoop)
  {
    firstLoop = false;
    if (c == ' ')
      return;
  }

  LCDPrint(c);
}
