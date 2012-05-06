#include <lpc213x.h>                       /* LPC214x definitions */
#include "lcd.h"


#define MAX_CHAR_IN_ONE_LINE 16

#define LCD_CTRL_DIR	   IO1DIR
#define LCD_CTRL_SET       IO1SET
#define LCD_CTRL_CLR       IO1CLR

#define LCD_DATA_DIR       IO1DIR
#define LCD_DATA_SET       IO1SET
#define LCD_DATA_CLR       IO1CLR

#define LCDRS	           (1 << 16)
#define LCDEN	           (1 << 18)
#define LCDRW              (1 << 17)


#define FIRST_LCD_PIN  19

#define LCD_DATA_MASK ( 0xF << FIRST_LCD_PIN )





/**
 ********************************************************************************************
  Function Name :       lcd_data_write()

  Description   :

  Input         :

  Output        :       Void

  Note          :
 ********************************************************************************************
 */
void lcd_data_write( unsigned char data )
{
  unsigned char temp=0;
  unsigned int temp1=0;
  unsigned int i;

  temp=data;
  temp=(temp>>4)&0x0F;
  temp1=(temp<<FIRST_LCD_PIN)&LCD_DATA_MASK;

  LCD_CTRL_SET = LCDRS;
  for(i=0;i<50;i++);
  LCD_CTRL_SET = LCDEN;
  LCD_DATA_CLR = LCD_DATA_MASK;
  LCD_DATA_SET = temp1;
  for(i=0;i<150;i++);
  LCD_CTRL_CLR = LCDEN;

  temp=data;
  temp&=0x0F;
  temp1=(temp<<FIRST_LCD_PIN)&LCD_DATA_MASK;

  LCD_CTRL_SET = LCDRS;
  for(i=0;i<50;i++);
  LCD_CTRL_SET = LCDEN;
  LCD_DATA_CLR = LCD_DATA_MASK;
  LCD_DATA_SET = temp1;
  for(i=0;i<150;i++);
  LCD_CTRL_CLR = LCDEN;

  for(i=0;i<3000;i++);
}





/**
 ********************************************************************************************
  Function Name :	lcd_command_write()

  Description   :	

  Input         :	

  Output        :	Void

  Note          :
 ********************************************************************************************
 */
void lcd_command_write( unsigned char command )
{
  unsigned char temp=0;
  unsigned int temp1=0;
  unsigned int i;

  temp=command;
  temp=(temp>>4)&0x0F;
  temp1=(temp<<FIRST_LCD_PIN)&LCD_DATA_MASK;

  LCD_CTRL_CLR = LCDRS;
  for(i=0;i<50;i++);
  LCD_CTRL_SET = LCDEN;
  LCD_DATA_CLR = LCD_DATA_MASK;
  LCD_DATA_SET = temp1;
  for(i=0;i<150;i++);
  LCD_CTRL_CLR = LCDEN;

  temp=command;
  temp&=0x0F;
  temp1=(temp<<FIRST_LCD_PIN)&LCD_DATA_MASK;

  LCD_CTRL_CLR = LCDRS;
  for(i=0;i<50;i++);
  LCD_CTRL_SET = LCDEN;
  LCD_DATA_CLR = LCD_DATA_MASK;
  LCD_DATA_SET = temp1;
  for(i=0;i<150;i++);
  LCD_CTRL_CLR = LCDEN;


  for(i=0;i<3000;i++);
}


/**
 ********************************************************************************************
  Function Name :	set_lcd_port_output()

  Description   :	

  Input         :	

  Output        :	Void

  Note          :
 ********************************************************************************************
 */
void lcd_init_pins( void )
{
  LCD_CTRL_DIR |= ( LCDEN | LCDRS | LCDRW );
  LCD_DATA_DIR |= LCD_DATA_MASK;


  LCD_CTRL_CLR  = ( LCDEN | LCDRS | LCDRW );
  LCD_DATA_CLR  = LCD_DATA_MASK;
}
/* *
 ********************************************************************************************
  Function Name :	lcd_clear()

  Description   :	

  Input         :	

  Output        :	Void

  Note          :
 ********************************************************************************************
 */
void lcd_clear( void)
{
  lcd_command_write( 0x01 );
}
/**
 ********************************************************************************************
  Function Name :	lcd_gotoxy()

  Description   :	

  Input         :	

  Output        :	Void

  Note          :
 ********************************************************************************************
 */
int lcd_gotoxy( int x, int y)
{

  if( (x < 0) || (x > 1) || (y > 15) || (y < 0) ) // out of bounds
    {
      return -1;
    }
  else
    {
      if( x == 0 )
        {
          lcd_command_write( 0x80 + y );        // first line
        }
      else
        {
          lcd_command_write( 0xC0 + y );        // second line
        }
    }
  return 0;
}

/**
 ********************************************************************************************
  Function Name :	lcd_putchar()

  Description   :	

  Input         :	

  Output        :	Void

  Note          :
 ********************************************************************************************
 */
void lcd_putchar( int c )
{
  lcd_data_write( c );
}

/**
 ********************************************************************************************
  Function Name :	lcd_putstring()

  Description   :	

  Input         :	

  Output        :	Void

  Note          :
 ********************************************************************************************
 */
int lcd_putstring( int line, int col, char *string )
{
  int i;
  int  retval = 0;

  retval = lcd_gotoxy( line, col );
  if(retval != 0)
    return -1;
  if(string == 0x0)
    return -2;

  i = MAX_CHAR_IN_ONE_LINE - col;

  while(*string != '\0' && i > 0)
    {
      lcd_data_write( *string );
      string++;
      i--;
    }

  return 0;
}

/**
 ********************************************************************************************
  Function Name :	init_lcd()

  Description   :	

  Input         :	

  Output        :	Void

  Note          :
 ********************************************************************************************
 */
void lcd_init( void )
{
  int i;

  for(i = 0; i < 50000; ++i);
  lcd_init_pins();

  for(i = 0; i < 50000; ++i);

  lcd_command_write(0x22);
  lcd_command_write(0x28);     /*   4-bit interface, two line, 5X7 dots.        */
  lcd_command_write(0x01);     /*   clrscr                                 */
  lcd_command_write(0x02);     /*   cursor home                                 */
  lcd_command_write(0x06);     /*   Entry mode                       */
  lcd_command_write(0x0F) ;    /*   display on cursor blinking    */  


}

/**
 ********************************************************************************************
  Function Name :	test_cmd()

  Description   :	

  Input         :	

  Output        :	Void

  Note          :
 ********************************************************************************************
 */
void lcd_test(void)
{
  lcd_command_write(0x08);   //Display off,cursor off
  lcd_command_write(0x0C);   //Display on cursor off
  lcd_command_write(0x10);   //Move cursor left by 1 char
  lcd_command_write(0x14);   //Move cursor right by 1 char
  lcd_command_write(0x01);   //Clear display
}

