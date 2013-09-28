// note that some comments assume 16x2 LCD, but the code should mostly work for
// another size

#include <LiquidCrystal.h>

LiquidCrystal *lcd;
int columns = 0;
int rows = 0;

void initLCD(short lcolumns, short lrows, short pin1, short pin2, short pin3, short pin4, short pin5, short pin6)
{
  // this pointer is global, so we don't need a delete strategy
  lcd = new LiquidCrystal(pin1, pin2, pin3, pin4, pin5, pin6);

  columns = lcolumns;
  rows = lrows;

  lcd->begin(columns, rows);
  lcd->cursor();
}

void LCDPrint(char c)
{
  // only need 33 (16 x 2 plus a null terminator), but we'll allocate one extra
  // to be safe.
  static int bufferSize = columns * rows + 2;
  // again, this pointer will never die, so we won't bother trying to free it
  // use calloc so that the buffer is zeroed out

  static char *buffer = (char *) calloc(bufferSize, sizeof(char));

  static int currentIndex = 0;

  // shift left if we need room (we only accept 31 characters so that the cursor
  // can be at the end)
  if (currentIndex >= columns * rows - 1)
  {
    shiftBufferLeft(buffer);
    currentIndex = columns * rows - 2;
  }

  buffer[currentIndex] = c;
  buffer[currentIndex + 1] = '\0';

  printBuffer(buffer);

  currentIndex++;

  lcd->setCursor(currentIndex % columns, currentIndex / columns);
}

void printBuffer(char *buffer)
{
  // TODO this is not general on rows
  lcd->setCursor(0, 0);
  lcd->print(buffer);
  lcd->setCursor(0, 1);
  lcd->print(buffer + columns);
 }

void shiftBufferLeft(char *buffer)
{
  for (int i = 0; buffer[i] != '\0'; i++)
    buffer[i] = buffer[i + 1];
}
