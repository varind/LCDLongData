/*
   Long data on a 20x4 LCD by Ben Lipsey www.varind.com 2016. This code is public domain, enjoy!
   https://github.com/varind/LCDLongData
*/
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);

byte lcdRows = 4;
byte lcdCols = 20;
byte offset;
byte dataLength;
byte charNum;
char text[] = {"01234567890123456789 01234567890123456789 01234567890123456789 0123456789"};

void setup() {
  lcd.begin(lcdCols, lcdRows);
  lcd.clear();
}

void loop() {
  dataLength = strlen(text);
  charNum = 0;
  offset = 0;
  if (dataLength > lcdCols * lcdRows)dataLength = lcdCols * lcdRows;

  for (byte rowNum = 0; rowNum < lcdRows; rowNum++) {
    lcd.setCursor(0, rowNum);
    charNum = rowNum * lcdCols + offset;
    while (charNum < ((rowNum + 1) *lcdCols) + offset) {
      if (charNum - offset == rowNum * lcdCols && charNum < dataLength-offset && text[charNum] == ' ') {
        charNum++;
        offset++;
      }
      if (charNum - offset >= dataLength-offset) lcd.write(254);
      //if (charNum-offset >= dataLength-offset) lcd.print("x");
      else if (charNum - offset < dataLength-offset)lcd.print(text[charNum]);
      charNum++;
    }
  }


  delay(1000);
}

