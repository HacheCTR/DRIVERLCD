/*
 * lcd.c
 *
 *  Created on: Aug 26, 2020
 *      Author: HECTOR ZUÑIGA
 */
#include "stm32f4xx_hal.h"
#include "stm32f4xx.h"
#include "LCD.h"
#include "stdio.h"

uint8_t FunctionSet = 0x38;

void vClear_Display(void)
{
	RS_OFF;
	WR_OFF;
	D7_OFF;
	D6_OFF;
	D5_OFF;
	D4_OFF;
	D3_OFF;
	D2_OFF;
	D1_OFF;
	D0_ON;
	HAL_Delay(1);
}
void vReturn_Home(void)
{
	RS_OFF;
	WR_OFF;
	D7_OFF;
	D6_OFF;
	D5_OFF;
	D4_OFF;
	D3_OFF;
	D2_OFF;
	D1_ON;
	D0_OFF;
	HAL_Delay(1);
}
void vLcd_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;

	/* GPIO Ports Clock Enable */
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOH_CLK_ENABLE();

	GPIO_InitStruct.Pin 	 = RS_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(RS_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = WR_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(WR_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = E_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(E_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D0_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D0_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D1_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D1_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D2_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D2_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D3_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D3_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D4_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D4_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin    	 = D5_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D5_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D6_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D6_GPIO_PORT, &GPIO_InitStruct);

	GPIO_InitStruct.Pin 	 = D7_PIN;
	GPIO_InitStruct.Mode 	 = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull 	 = GPIO_NOPULL;
	GPIO_InitStruct.Speed    = GPIO_SPEED_FREQ_HIGH;
	HAL_GPIO_Init(D7_GPIO_PORT, &GPIO_InitStruct);

	HAL_Delay(15);
	D7_OFF; D6_OFF; D5_ON; D4_ON; D3_OFF; D2_OFF; D1_OFF; D0_OFF;
	E_OFF;
	//LCDRW_OFF;
	RS_OFF;
	//---------one------
	D7_OFF; D6_OFF; D5_ON; D4_ON; D3_OFF; D2_OFF; D1_OFF; D0_OFF;
	E_ON;
	//LCDRW_OFF;
	RS_OFF;
	HAL_Delay(10);
	E_OFF;
	HAL_Delay(10);
	//-----------two-----------
	D7_OFF; D6_OFF; D5_ON; D4_ON; D3_OFF; D2_OFF; D1_OFF; D0_OFF;
	E_ON;
	//LCDRW_OFF;
	RS_OFF;
	HAL_Delay(10);
	E_OFF;
	HAL_Delay(10);
	//-------three-------------
	D7_OFF; D6_OFF; D5_ON; D4_ON; D3_ON; D2_OFF; D1_OFF; D0_OFF;
	E_ON;
	//LCDRW_OFF;
	RS_OFF;
	HAL_Delay(10);
	E_OFF;
	HAL_Delay(10);
	//-----FUNCTION 8--------
	vFunctionEightBits();
	//-----DISPLAY ON--------
	vDisplay_On();
	//-----Clear display
	vClear_Display();
}
void vDisplay_On(void)
{
	RS_OFF;
	WR_OFF;
	D0_OFF;
	D1_OFF;
	D2_OFF;
	D3_OFF;
	D4_ON;
	D5_ON;
	D6_OFF;
	D7_OFF;
	HAL_Delay(5);
}
void vDisplayOff(void)
{
	RS_OFF;
	WR_OFF;
	D0_OFF;
	D1_OFF;
	D2_OFF;
	D3_OFF;
	D4_ON;
	D5_OFF;
	D6_OFF;
	D7_OFF;
	HAL_Delay(5);
}
void vFunctionEightBits(void)
{
	RS_OFF;
	WR_OFF;
	D0_OFF;
	D1_OFF;
	D2_ON;
	D3_ON;
	D4_OFF;
	D5_OFF;
	D6_OFF;
	D7_OFF;
	HAL_Delay(5);
}
void lcd_putc(unsigned char ch){		//Sends Char to LCD

	RS_ON;

	if ( ch & 0x10 ) {
		D4_ON;
	} else {
		D4_OFF;
	}
	if ( ch & 0x20 ) {
		D5_ON;
	} else {
		D5_OFF;
	}
	if ( ch & 0x40 ) {
		D6_ON;

	} else {
		D6_OFF;
	}
	if ( ch & 0x80 ) {
		D7_ON;
	} else {
		D7_OFF;
	}

	E_ON;
	HAL_Delay(5);//__delay_us(300);
	E_OFF;
	HAL_Delay(5);//__delay_us(300);

	if ( ch & 0x01 ) {
		D4_ON;
	} else {
		D4_OFF;
	}
	if ( ch & 0x02 ) {
		D5_ON;
	} else {
		D5_OFF;
	}
	if ( ch & 0x04 ) {
		D6_ON;
	} else {
		D6_OFF;
	}
	if ( ch & 0x08 ) {
		D7_ON;
	} else {
		D7_OFF;
	}

	E_ON;
	HAL_Delay(5);//__delay_us(300);
	E_OFF;
	HAL_Delay(5);//__delay_us(300);
}
void vlcd_command(unsigned char cmd){	//Sends Command to LCD

	RS_OFF;

	if ( cmd & 0x10 ) {
		D4_ON;
	} else {
		D4_OFF;
	}
	if ( cmd & 0x20 ) {
		D5_ON;
	} else {
		D5_OFF;
	}
	if ( cmd & 0x40 ) {
		D6_ON;
	} else {
		D6_OFF;
	}
	if ( cmd & 0x80 ) {
		D7_ON;
	} else {
		D7_OFF;
	}

	E_ON;
	HAL_Delay(5);//__delay_us(300);
	E_OFF;
	HAL_Delay(5);//__delay_us(300);

	if ( cmd & 0x01 ) {
		D4_ON;
	} else {
		D4_OFF;
	}
	if ( cmd & 0x02 ) {
		D5_ON;
	} else {
		D5_OFF;
	}
	if ( cmd & 0x04 ) {
		D6_ON;
	} else {
		D6_OFF;
	}
	if ( cmd & 0x08 ) {
		D7_ON;
	} else {
		D7_OFF;
	}

	E_ON;
	HAL_Delay(5);//__delay_us(300);
	E_OFF;
	HAL_Delay(5);//__delay_us(300);

}
void lcd_gotoxy(unsigned char x, unsigned char y){		//Cursor to X Y position
	register unsigned char DDRAMAddr;

	switch(y){		// remap lines into proper order
	case 1: DDRAMAddr = LCD_LINE0_DDRAMADDR+x-1; break;
	case 2: DDRAMAddr = LCD_LINE1_DDRAMADDR+x-1; break;
	case 3: DDRAMAddr = LCD_LINE2_DDRAMADDR+x-1; break;
	case 4: DDRAMAddr = LCD_LINE3_DDRAMADDR+x-1; break;
	default: DDRAMAddr =LCD_LINE0_DDRAMADDR+x-1;break;
	}
	vlcd_command(1<<LCD_DDRAM|DDRAMAddr);	// set data address
}
void lcd_definechar(unsigned char *car,unsigned char CGRAM_dir){
	unsigned char i=0,a=0;
	a=(CGRAM_dir<<3)|1<<LCD_CGRAM;		//	posiciona en la CGRAM address
	for(i=0;i<8;i++){
        vlcd_command(a++);			//	incrementa la direccion para la data
		lcd_putc(car[i]);			//	escribe caracter
	}
}
void vPrintInt(int number)
{
	char numStr[16];
	sprintf(numStr,"%d", number);
	LCD1602_print(numStr);
}
//Enable two lines
void LCD1602_TwoLines(void)
{
	FunctionSet |= (0x08);
	LCD1602_writeCommand(FunctionSet);
}
void LCD1602_print(char string[])
{
	for(uint8_t i=0;  i< 16 && string[i]!=NULL; i++)
	{
		LCD1602_writeData((uint8_t)string[i]);
	}
}
