/************************************************************************/
/* Driver for the Nokia Graphic LCD 84x48, v1.0.                        */
/* Based on library written by Sylvain Bissonnette and Louis Frigon:    */
/* http://www.microsyl.com/index.php/2010/03/24/nokia-lcd-library/      */
/*                                                                      */
/* This library is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU General Public License as published by */
/* the Free Software Foundation, either version 3 of the License, or    */
/* (at your option) any later version.                                  */
/*                                                                      */
/* This library is distributed in the hope that it will be useful, but  */
/* WITHOUT ANY WARRANTY; without even the implied warranty of           */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU     */
/* General Public License for more details.                             */
/*                                                                      */
/* You should have received a copy of the GNU General Public License    */
/* along with this library. If not, see <http://www.gnu.org/licenses/>. */
/*                                                                      */
/* Written by Thomas Mittet thomas@mittet.nu September 2011.            */
/************************************************************************/

#ifndef NokiaLCD_h
#define NokiaLCD_h

#include <inttypes.h>

#define LCD_WIDTH      84
#define LCD_HEIGHT     48
#define FONT_WIDTH      6
#define FONT_HEIGHT     8

#define MODE_COMMAND   LOW
#define MODE_DATA      HIGH
#define DATA_ENABLED   LOW
#define DATA_DISABLED  HIGH

#define CHIP_CMD_BASIC_H   B00100000
#define CHIP_CMD_BASIC_V   B00100010
#define CHIP_CMD_EXTENDED  B00100001

#define DISP_CONF_NORMAL   B00001100
#define DISP_CONF_INVERTED B00001101
#define DISP_CONF_BLANK    B00001000
#define DISP_CONF_BLACK    B00001001

#define RAM_ADDRESS_X      B10000000
#define RAM_ADDRESS_Y      B01000000

#define TEMP_COEFFICIENT_0 B00000100
#define TEMP_COEFFICIENT_1 B00000101
#define TEMP_COEFFICIENT_2 B00000110
#define TEMP_COEFFICIENT_3 B00000111

class NokiaLCD
{

public:
  NokiaLCD(uint8_t clockPin, uint8_t dataPin, uint8_t modeSelectPin, uint8_t dataSelectPin, uint8_t resetPin);
  void begin(void);
  void clear(void);
  void setCursor(uint8_t line = 1, uint8_t column = 1);
  void writeCharacter(uint8_t character);
  void writeLine(char *line, bool crLf = 1);
  
private:
  static const uint8_t FONT[96][5];
  uint8_t clockPin, dataPin, modeSelectPin, dataSelectPin, resetPin;
  void write(uint8_t data);

};

#endif