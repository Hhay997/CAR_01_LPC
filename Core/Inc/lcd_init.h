#ifndef __LCD_INIT_H
#define __LCD_INIT_H
#include "main.h"
#include "sys.h"

#define USE_HORIZONTAL 0


#if USE_HORIZONTAL==0||USE_HORIZONTAL==1
#define LCD_W 240
#define LCD_H 320

#else
#define LCD_W 320
#define LCD_H 240
#endif





#define LCD_SCLK_Clr() HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_SCLK_Pin,0)//SCL=SCLK
#define LCD_SCLK_Set() HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_SCLK_Pin,1)

#define LCD_MOSI_Clr() HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_MOSI_Pin,0)//SDA=MOSI
#define LCD_MOSI_Set() HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_MOSI_Pin,1)

#define LCD_RES_Clr()  HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_RES_Pin,0)//RES
#define LCD_RES_Set()  HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_RES_Pin,1)

#define LCD_DC_Clr()   HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_DC_Pin,0)//DC
#define LCD_DC_Set()   HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_DC_Pin,1)

#define LCD_BLK_Clr()  HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_BLK_Pin,0)//BLK
#define LCD_BLK_Set()  HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_BLK_Pin,1)

#define ZK_MISO        HAL_GPIO_ReadPin(LCD_SCLK_GPIO_Port,ZK_MOSI_Pin)//MISO  ��ȡ�ֿ���������

#define LCD_CS_Clr()   HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_CS_Pin,0)//CS1
#define LCD_CS_Set()   HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,LCD_CS_Pin,0)

#define ZK_CS_Clr()    HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,ZK_CS_Pin,0)//CS2 �ֿ�Ƭѡ
#define ZK_CS_Set()    HAL_GPIO_WritePin(LCD_SCLK_GPIO_Port,ZK_CS_Pin,0)



void LCD_GPIO_Init(void);//初始化GPIO
void LCD_Writ_Bus(u8 dat);//模拟SPI时序
void LCD_WR_DATA8(u8 dat);//写入一个字节
void LCD_WR_DATA(u16 dat);//写入两个字节
void LCD_WR_REG(u8 dat);//写入一个指令
void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2);//设置坐标函数
void LCD_Init(void);//LCD初始化

#endif
