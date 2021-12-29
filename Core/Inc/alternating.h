#ifndef __ALTER_H
#define __ALTER_H

#include "lcd_init.h"
#include "lcd.h"
#include "lcd_front.h"
#include "delay.h"
#include "main.h"

unsigned char T,H,P_C,P_S,receivesystem,R,S;
unsigned char F1,F2,F3,F4,F5,F6,F7,F8,F9,F10,F11,F12,F13,F14,F15;

#define LCD_Forward()  HAL_GPIO_ReadPin(forward_GPIO_Port,forward_Pin)
#define LCD_Backward()  HAL_GPIO_ReadPin(backward_GPIO_Port,backward_Pin)
#define LCD_Select()  HAL_GPIO_ReadPin(select_GPIO_Port,select_Pin)

union receivedata
{
	short d;
	unsigned char data[2];

}data_x,data_D_F,data_D_B,data_D_L,data_D_R,data_C_S;

void SYS_LCD(void);
void SYS_DEFEND(unsigned char* buf);
void SYS_WI(void);
void SYS_WO(void);
void DATA_ERROR(void);
void Ptotect(void);


#endif
