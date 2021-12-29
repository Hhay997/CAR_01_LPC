#ifndef _SPI01_H
#define _SPI01_H
#include "stdint.h"


/*SPI commands for nRF24L01*/
#define R_REGISTER         0x00
#define W_REGISTER         0x20
#define R_RX_PAYLOAD       0x61
#define W_TX_PAYLOAD       0xA0
#define FLUSH_TX           0xE1
#define FLUSH_RX           0xE2
#define REUSE_TX_PL        0xE3
#define R_RX_PL_WID        0x60
#define W_ACK_PAYLOAD      0xA8
#define W_TX_PAYLOAD_NOACK 0xB0
#define L01_NOP            0xFF

/*Internal register address map and its bits definations*/
#define L01REG_CONFIG    0x00 /*Configuration Register*/
    //reserved: bit7, only '0' allowed
    #define MASK_RX_DR   6 //RW, Mask interrupt caused by RX_DR
    #define MASK_TX_DS   5 //RW, Mask interrupt caused by TX_DS
    #define MASK_MAX_RT  4 //RW, Mask interrupt caused by MAX_RT
    #define EN_CRC       3 //RW, Enable CRC.
    #define CRCO         2 //RW, CRC encoding scheme, 0: 1 byte, 1: 2 bytes
    #define PWR_UP       1 //RW, Power up, 1: power up, 0: power down
    #define PRIM_RX      0 //RW, RX/TX control, 1: PRX, 0: PTX
#define L01REG_EN_AA     0x01 /*Enable'Auto Acknowledgement function'*/
    //reserved: bit7-bit6:only '00' allowed
    #define ENAA_P5      5 //RW, Enable auto acknowledgement data pipe 5
    #define ENAA_P4      4 //RW, Enable auto acknowledgement data pipe 4
    #define ENAA_P3      3 //RW, Enable auto acknowledgement data pipe 3
    #define ENAA_P2      2 //RW, Enable auto acknowledgement data pipe 2
    #define ENAA_P1      1 //RW, Enable auto acknowledgement data pipe 1
    #define ENAA_P0      0 //RW, Enable auto acknowledgement data pipe 0
#define L01REG_EN_RXADDR 0x02 /*Enable RX Addresses*/
    //reserved: bit7-bit6:only '00' allowed
    #define ERX_P5       5 //RW, Enable data pipe 5
    #define ERX_P4       4 //RW, Enable data pipe 4
    #define ERX_P3       3 //RW, Enable data pipe 3
    #define ERX_P2       2 //RW, Enable data pipe 2
    #define ERX_P1       1 //RW, Enable data pipe 1
    #define ERX_P0       0 //RW, Enable data pipe 0
#define L01REG_SETUP_AW  0x03 /*Setup of address widths(Common for all pipes)*/
    // reserved: bit7-bit2, only '000000' allowed
    #define AW_RERSERVED 0x0
    #define AW_3BYTES    0x1
    #define AW_4BYTES    0x2
    #define AW_5BYTES    0x3
#define L01REG_RETR      0x04 /*Setup of Automatic Retransmission*/
    //for bit7-bit4, Auto transmission delay
    #define ARD_250US    (0x00<<4)
    #define ARD_500US    (0x01<<4)
    #define ARD_750US    (0x02<<4)
    #define ARD_1000US   (0x03<<4)
    #define ARD_2000US   (0x07<<4)
    //......
    #define ARD_4000US   (0x0F<<4)
    //for bit3-bit0, Auto retransmission Count
    #define ARC_DISABLE   0x00
    //......
    #define ARC_15        0x0F
#define L01REG_RF_CH      0x05 /*Set the RF channel*/
    //reserved bit7, only '0' allowed
    //bit6-bit0, Sets the frequency channel nRF24L01+ operates on
#define L01REG_RF_SETUP   0x06 /*RF setup register*/
    #define CONT_WAVE     7 //RW, Enables continuous carrier transmit when high
    //reserved bit6, only '0' allowed
    #define RF_DR_LOW     5 //RW, Set RF Data Rate to 250kbps
    #define PLL_LOCK      4 //RW, Force PLL lock signal, Only used in test
    #define RF_DR_HIGH    3 //RW, Low-High:00,1Mbps,01,2Mbps,10,250kbps,11,reserved
    //bit2-bit1:
        #define PWR_18DB  (0x00<<1)
        #define PWR_12DB  (0x01<<1)
        #define PWR_6DB   (0x02<<1)
        #define PWR_0DB   (0x03<<1)
    //reserved, bit0, Do not care
#define L01REG_STATUS     0x07 /*Status register for nRF24L01*/
    //reserved, bit7, only '0' allowed
    #define RX_DR         6 //RW, Data ready RX FIFO interrupt
    #define TX_DS         5 //RW, Data sent TX FIFO interrupt
    #define MAX_RT        4 //RW, Maximum number of TX retransmits interrupt
    //for bit3-bit1, R, Data pipe number for the payload available for reading from
    //RX_FIFO, 000-101, Data pipe number, 110, not used, 111, RX FIFO empty
    #define TX_FULL_0     0 //R, TX FIFO full flag
#define L01REG_OBSERVE_TX 0x08 /*R, Transmit observe register*/
    //bit7-bit4, Count lost packets
    //bit3-bit0, Count retransmitted packets
#define L01REG_RPD        0x09 /**/
    //bit7-bit1, reserved
    #define RPD           0 //Received power detector
#define L01REG_RX_ADDR_P0 0x0A /*RW, Receive address data pipe 0*/
#define L01REG_RX_ADDR_P1 0x0B /*RW, Receive address data pipe 1*/
#define L01REG_RX_ADDR_P2 0x0C /*RW, Receive address data pipe 2*/
#define L01REG_RX_ADDR_P3 0x0D /*RW, Receive address data pipe 3*/
#define L01REG_RX_ADDR_P4 0x0E /*RW, Receive address data pipe 4*/
#define L01REG_RX_ADDR_P5 0x0F /*RW, Receive address data pipe 5*/
#define L01REG_TX_ADDR    0x10 /*RW, Transmit address, used for PTX only*/

#define L01REG_RX_PW_P0   0x11 /*RW, Number of bytes in RX payloadin data pipe 0*/
    //bit7-bi6, reserved, only '00' allowed
    //bit5-bit0, number, 0-32bytes
#define L01REG_RX_PW_P1   0x12 /*RW, Number of bytes in RX payloadin data pipe 1*/
    //bit7-bi6, reserved, only '00' allowed
    //bit5-bit0, number, 0-32bytes
#define L01REG_RX_PW_P2   0x13 /*RW, Number of bytes in RX payloadin data pipe 2*/
    //bit7-bi6, reserved, only '00' allowed
    //bit5-bit0, number, 0-32bytes
#define L01REG_RX_PW_P3   0x14 /*RW, Number of bytes in RX payloadin data pipe 3*/
    //bit7-bi6, reserved, only '00' allowed
    //bit5-bit0, number, 0-32bytes
#define L01REG_RX_PW_P4   0x15 /*RW, Number of bytes in RX payloadin data pipe 4*/
    //bit7-bi6, reserved, only '00' allowed
    //bit5-bit0, number, 0-32bytes
#define L01REG_RX_PW_P5   0x16 /*RW, Number of bytes in RX payloadin data pipe 5*/
    //bit7-bi6, reserved, only '00' allowed
    //bit5-bit0, number, 0-32bytes

#define L01REG_FIFO_STATUS 0x17 /*FIFO status register*/
    //bit7, reserved, only '0' allowed
    #define TX_REUSE      6 //R,
    #define TX_FULL_1     5 //R, TX FIFO full flag
    #define TX_EMPTY      4 //R, TX FIFO empty flag
    //bit3-bit2, reserved, only '00'
    #define RX_FULL       1 //R, RX FIFO full flag
    #define RX_EMPTY      0 //R, RX FIFO empty flag
#define L01REG_DYNPD      0x1C /**/
    //reserved, bit7-bit6, only '00' allowed
    #define DPL_P5        5 //RW, Enable dynamic payload length data pipe 5
    #define DPL_P4        4 //RW, Enable dynamic payload length data pipe 4
    #define DPL_P3        3 //RW, Enable dynamic payload length data pipe 3
    #define DPL_P2        2 //RW, Enable dynamic payload length data pipe 2
    #define DPL_P1        1 //RW, Enable dynamic payload length data pipe 1
    #define DPL_P0        0 //RW, Enable dynamic payload length data pipe 0
#define L01REG_FEATRUE    0x1D
    //reserved, bit7-bit3, only '0000' allowed
    #define EN_DPL        2 //RW, Enables Dynamic payloard length
    #define EN_ACK_PAY    1 //RW, Enable Payload with ACK
    #define EN_DYN_ACK    0 //RW, Enables the W_TX_PAYLOAD_NOACK command
/*===========================================================================
* 网址 ：http://yhmcu.taobao.com/   http://www.cdebyte.com/                 *
* 作者 ：李勇  原 亿和电子工作室  现 亿佰特电子科技有限公司                 *
* 邮件 ：yihe_liyong@126.com                                                *
* 电话 ：18615799380                                                        *
============================================================================*/

#define REPEAT_CNT      15  // 0-15, repeat transmit count
#define INIT_ADDR       1, 2, 3, 4, 5

// nRF24L01P相关控制引脚定义， CSN(PB4), IRQ(PA3), CE(PA2)


#define L01_CSN_LOW()    HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port,SPI1_NSS_Pin,0);
#define L01_CSN_HIGH()   HAL_GPIO_WritePin(SPI1_NSS_GPIO_Port,SPI1_NSS_Pin,1);

#define L01_CE_LOW()     HAL_GPIO_WritePin(SPI1_CE_GPIO_Port,SPI1_CE_Pin,0);
#define L01_CE_HIGH()    HAL_GPIO_WritePin(SPI1_CE_GPIO_Port,SPI1_CE_Pin,0);

#define L01_IRQ_READ()   HAL_GPIO_ReadPin(SPI1_IRQ_GPIO_Port,SPI1_IRQ_Pin,0);


int SPI_ExchangeByte(uint8_t  date);
// nRF24L01P相关函数接口
// 初始化L01
void L01_Init(void);

// 复位TX FIFO指针
void L01_FlushTX(void);

// 复位RX FIFO指针
void L01_FlushRX(void);

// 读取中断
int L01_ReadIRQSource(void);

// 清除中断
#define IRQ_ALL  ((1<<RX_DR) | (1<<TX_DS) | (1<<MAX_RT))
void L01_ClearIRQ(int IRQ_Source);

// 读取FIFO数据宽度
int L01_ReadTopFIFOWidth(void);

// 读取接收到的数据
int L01_ReadRXPayload(int *pBuff);

// 设置L01模式
typedef enum{ TX_MODE, RX_MODE } L01MD;
void L01_SetTRMode(L01MD mode);

// 设置L01空速
typedef enum{ SPD_250K, SPD_1M, SPD_2M } L01SPD;
void L01_SetSpeed(L01SPD speed);

// 设置L01功率
typedef enum{ P_F18DBM, P_F12DBM, P_F6DBM, P_0DBM } L01PWR;
void L01_SetPower(L01PWR power);

// 设置L01频率
void L01_WriteHoppingPoint(int FreqPoint);

int L01_ReadStatusReg(void);

// 写数据到一个寄存器
void L01_WriteSingleReg(int Addr, int Value);

// 读取一个寄存器的值
int L01_ReadSingleReg(int Addr);

// 读取多个寄存器的值
void L01_ReadMultiReg(int StartAddr, int nBytes, int *pBuff);

// 写数据到多个寄存器
void L01_WriteMultiReg(int StartAddr, int *pBuff, int Length);

// 写数据到TXFIFO(带ACK返回)
void L01_WriteTXPayload_Ack(int *pBuff, int nBytes);

// 写数据到TXFIFO(不带ACK返回)
void L01_WriteTXPayload_NoAck(int *Data, int Data_Length);

// 设置发送物理地址
void L01_SetTXAddr(int *pAddr, int Addr_Length);

// 设置接收物理地址
void L01_SetRXAddr(int PipeNum, int *pAddr, int Addr_Length);



/*===========================================================================
-----------------------------------文件结束----------------------------------
===========================================================================*/




#endif
