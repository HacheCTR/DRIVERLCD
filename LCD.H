/*
 * LCD.h
 *
 *  Created on: 26 ago. 2020
 *      Author: HECTOR ZUÑIGA
 */

#ifndef LCD_H_
#define LCD_H_

#include "stm32f4xx_hal.h"

#define RS_PIN           GPIO_PIN_1
#define RS_GPIO_PORT     GPIOB

#define WR_PIN           GPIO_PIN_2
#define WR_GPIO_PORT     GPIOB

#define E_PIN            GPIO_PIN_3
#define E_GPIO_PORT      GPIOB

#define D0_PIN           GPIO_PIN_4
#define D0_GPIO_PORT     GPIOB

#define D1_PIN           GPIO_PIN_5
#define D1_GPIO_PORT     GPIOB

#define D2_PIN           GPIO_PIN_6
#define D2_GPIO_PORT     GPIOB

#define D3_PIN           GPIO_PIN_7
#define D3_GPIO_PORT     GPIOB

#define D4_PIN           GPIO_PIN_8
#define D4_GPIO_PORT     GPIOB

#define D5_PIN           GPIO_PIN_9
#define D5_GPIO_PORT     GPIOB

#define D6_PIN           GPIO_PIN_10
#define D6_GPIO_PORT     GPIOB

#define D7_PIN           GPIO_PIN_0
#define D7_GPIO_PORT     GPIOB
//PINS STATE OFF
#define  RS_OFF			 HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, 	GPIO_PIN_RESET)
#define  WR_OFF			 HAL_GPIO_WritePin(WR_GPIO_PORT, WR_PIN, 	GPIO_PIN_RESET)
#define  E_OFF           HAL_GPIO_WritePin(E_GPIO_PORT , E_PIN, 	GPIO_PIN_RESET)
#define  D0_OFF      	 HAL_GPIO_WritePin(D0_GPIO_PORT, D0_PIN,  	GPIO_PIN_RESET)
#define  D1_OFF      	 HAL_GPIO_WritePin(D1_GPIO_PORT, D1_PIN, 	GPIO_PIN_RESET)
#define  D2_OFF     	 HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN,  	GPIO_PIN_RESET)
#define  D3_OFF      	 HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN,  	GPIO_PIN_RESET)
#define  D4_OFF      	 HAL_GPIO_WritePin(D4_GPIO_PORT, D4_PIN,  	GPIO_PIN_RESET)
#define  D5_OFF      	 HAL_GPIO_WritePin(D5_GPIO_PORT, D5_PIN, 	GPIO_PIN_RESET)
#define  D6_OFF     	 HAL_GPIO_WritePin(D6_GPIO_PORT, D6_PIN,  	GPIO_PIN_RESET)
#define  D7_OFF      	 HAL_GPIO_WritePin(D7_GPIO_PORT, D7_PIN,  	GPIO_PIN_RESET)
//PINS STATE ON
#define  RS_ON			 HAL_GPIO_WritePin(RS_GPIO_PORT, RS_PIN, 	GPIO_PIN_SET)
#define  WR_ON			 HAL_GPIO_WritePin(WR_GPIO_PORT, WR_PIN, 	GPIO_PIN_SET)
#define  E_ON            HAL_GPIO_WritePin(E_GPIO_PORT , E_PIN, 	GPIO_PIN_SET)
#define  D0_ON      	 HAL_GPIO_WritePin(D0_GPIO_PORT, D0_PIN,  	GPIO_PIN_SET)
#define  D1_ON      	 HAL_GPIO_WritePin(D1_GPIO_PORT, D1_PIN, 	GPIO_PIN_SET)
#define  D2_ON     	     HAL_GPIO_WritePin(D2_GPIO_PORT, D2_PIN,  	GPIO_PIN_SET)
#define  D3_ON      	 HAL_GPIO_WritePin(D3_GPIO_PORT, D3_PIN,  	GPIO_PIN_SET)
#define  D4_ON      	 HAL_GPIO_WritePin(D4_GPIO_PORT, D4_PIN,  	GPIO_PIN_SET)
#define  D5_ON      	 HAL_GPIO_WritePin(D5_GPIO_PORT, D5_PIN, 	GPIO_PIN_SET)
#define  D6_ON     	     HAL_GPIO_WritePin(D6_GPIO_PORT, D6_PIN,  	GPIO_PIN_SET)
#define  D7_ON      	 HAL_GPIO_WritePin(D7_GPIO_PORT, D7_PIN,  	GPIO_PIN_SET)
//DEFINE INSTRUCTIONS CODES OF THE LCD
#define LCD_FUNCTIONSET  0b00100000
#define	CLEAR_DISPLAY    0b00000001
#define RETURN_HOME      0b00000010
//ENTRY MODE SET DIFFERENTS CODES
#define MOVESRIGHT       0b00000110
#define MOVESLEFT        0b00000100
#define SHIFTRIGHT       0b00000101
#define SHIFTLEFT        0b00000111
//LCD ON OR OFF  DIFFERENTS CODES
#define DISPLAYON        0b00001100
#define DISPLAYOFF       0b00001000
#define CURSORON         0b00001010
#define CURSOROFF        0b00001000
#define BLINKON          0b00001001
#define BLINKOFF         0b00001000
//LCD CURSOR OR DISPLAY SHIFT CODES
#define CURSORLEFT       0b00010000
#define CURSORRIFHT      0b00010100
#define DISPLAYRIGHT     0b00011100
#define DISPLAYLEFT      0b00011000
//LCD FUNCTION SET
#define EIGHTBITS        0b00110000
#define FOURBITS         0b00100000
#define TWOLINES         0b00010100
#define ONELINE          0b00010000
#define FXEDOTS          0b00010010
#define FXENDOTS         0b00010000
//DDRAM
#define LCD_LINE0_DDRAMADDR		0x00
#define LCD_LINE1_DDRAMADDR		0x40
#define LCD_LINE2_DDRAMADDR		0x14
#define LCD_LINE3_DDRAMADDR		0x54
//FUNCTIONS
void vLcd_init(void);
void vClear_Display(void);
void vlcd_putc(unsigned char);
void vDisplay_On(void);
void vFunctionEightBits(void);
void vlcd_gotoxy(unsigned char x, unsigned char y);
void vlcd_command(unsigned char cmd);
void lcd_definechar(unsigned char *car,unsigned char CGRAM_dir);
void vPrintInt(int number);
void LCD1602_TwoLines(void);
void LCD1602_print(char string[]);
//SET ADDRESS
#define LCD_CGRAM           6	//DB6: set CG RAM address
#define LCD_DDRAM           7	//DB7: set DD RAM address



#endif /* LCD_H_ */
