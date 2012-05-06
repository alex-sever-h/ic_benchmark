#ifndef LCD_H
#define LCD_H

#define MAX_CHAR_IN_ONE_LINE 16

enum ROW_NUMBERS
{
  LINE1,
  LINE2	
};

void lcd_init_pins(void);
void lcd_init(void);
void lcd_clear(void);

int  lcd_putstring( int line, int col, char *string );
void lcd_putchar(int c);
int  lcd_gotoxy( int x,  int y);

#endif
