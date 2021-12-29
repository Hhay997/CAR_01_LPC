#include "alternating.h"
#include "usart.h"
short D_F=0;
short D_B=0;
short D_L=0;
short D_R=0;
short C_S=0;

int page=0;
int page_1=1;
int line=0;
int line_1=1;
int mode=0;
int mode_1=0;
int warning=0;
int warning_1=0;

void SYS_DEFEND(unsigned char* buf)
{
	/*unsigned char USART_Receiver              = 0;          //接收数据
	static short k=1;
	short x=0;
	USART_Receiver=HAL_UART_Receive(&huart1,buf,1,0xff);

		if(USART_Receiver=0x55)
			{
				while(k<=35)
				{
					if(k<=32)
					{
						x=x+buf[k];
					}
					buf[k]=HAL_UART_Receive(&huart1,buf,1,0xff);
					k++;
				}


			}
		data_x.data[0]=buf[33];//提取校验和
		data_x.data[1]=buf[32];
		if(data_x.d==x)//判断检验和
		{
			receivesystem=buf[1];
			if(receivesystem==0x88)//系统初始化成功
			{
				//提取火焰传感器
				F1=buf[2];
				F2=buf[3];
				F3=buf[4];
				F4=buf[5];
				F5=buf[6];
				F6=buf[7];
				F7=buf[8];
				F8=buf[9];
				F9=buf[10];
				F10=buf[11];
				F11=buf[12];
				F12=buf[13];
				F13=buf[14];
				F14=buf[15];
				F15=buf[16];
				//提取并赋值人体存在感应器
				R=buf[17];
				//提取烟雾传感器
				S=buf[18];
				//提取并赋值温湿度数据
				T=buf[19];
				H=buf[20];
				//提取并赋值超声波数据
				data_D_F.data[0]=buf[21];
				data_D_F.data[1]=buf[22];
				D_F=data_D_F.d;

				data_D_B.data[0]=buf[23];
				data_D_B.data[1]=buf[24];
				D_B=data_D_B.d;

				data_D_L.data[0]=buf[25];
				data_D_L.data[1]=buf[26];
				D_L=data_D_L.d;

				data_D_R.data[0]=buf[27];
				data_D_R.data[1]=buf[28];
				D_R=data_D_R.d;
				//提取并赋值车速数据
				data_C_S.data[0]=buf[29];
				data_C_S.data[0]=buf[30];
				C_S=data_C_S.d;
				//提取并赋值电压数据
				P_C=buf[31];
				P_S=buf[32];
				SYS_LCD();


			}*/

				 SYS_WI();

			//DATA_ERROR();



	}


void SYS_LCD(void)
{
		LCD_Init();//LCD初始化
		LCD_Fill(0,0,LCD_W,LCD_H,BLUE);
	  	  	LCD_ShowString(70,0,"Syetem work!",RED,YELLOW,16,0);

	  	  	LCD_ShowString(0,40,"T/H:",BRRED,BLUE,16,0);
	  		LCD_ShowIntNum(48,40,T,2,GREEN,BLUE,16);
	  		LCD_ShowString(64,40,"degree/",YELLOW,BLUE,16,0);
	  		LCD_ShowIntNum(128,40,H,2,GREEN,BLUE,16);
	  		LCD_ShowString(160,40,"percentage",YELLOW,BLUE,16,0);

	  		LCD_ShowString(0,80,"Distance front:",BRRED,BLUE,16,0);
	  		LCD_ShowIntNum(128,80,D_F,2,GREEN,BLUE,16);
	  		LCD_ShowString(160,80,"cm",YELLOW,BLUE,16,0);

	  		LCD_ShowString(0,120,"Distance behind:",BRRED,BLUE,16,0);
	  		LCD_ShowIntNum(130,120,D_B,2,GREEN,BLUE,16);
	  		LCD_ShowString(165,120,"cm",YELLOW,BLUE,16,0);

	  		LCD_ShowString(0,160,"Distance left:",BRRED,BLUE,16,0);
	  	    LCD_ShowIntNum(115,160,D_L,2,GREEN,BLUE,16);
	  	   LCD_ShowString(150,160,"cm",YELLOW,BLUE,16,0);

	  	    LCD_ShowString(0,200,"Distance right:",BRRED,BLUE,16,0);
	  		LCD_ShowIntNum(115,200,D_R,2,GREEN,BLUE,16);
	  		LCD_ShowString(150,200,"cm",YELLOW,BLUE,16,0);

	  		LCD_ShowString(0,240,"Car Speed:",BRRED,BLUE,16,0);
	  		LCD_ShowIntNum(80,240,C_S,2,GREEN,BLUE,16);
	  		LCD_ShowString(115,240,"cm/s",YELLOW,BLUE,16,0);

	  		delay_ms(5000);
	  	LCD_Fill(0,0,LCD_W,LCD_H,BRRED);
	        LCD_ShowString(70,0,"Syetem Power",RED,GRAY,16,0);

			LCD_ShowString(0,40,"Car Power:",BLUE,BRRED,16,0);
	  		LCD_ShowIntNum(80,40,P_C,2,CYAN,BRRED,16);
	  		LCD_ShowString(115,40,"percentage",YELLOW,BRRED,16,0);

	  		LCD_ShowString(0,240,"Pi Power:",BLUE,BRRED,16,0);
	  		LCD_ShowIntNum(80,240,P_S,2,CYAN,BRRED,16);
	  		LCD_ShowString(115,240,"percentage",YELLOW,BRRED,16,0);

	  		delay_ms(3000);
}


void SYS_WI(void)
{

		//LCD_Init();//LCD初始化
		//LCD_Fill(0,0,LCD_W,LCD_H,BLACK );

	//判断是否有险情

		unsigned char date[9]={0};
		warning=0;
		for(int i=0;i<6;i++)
		{
			if(date[i]==1)
			{
				warning=warning+i*i*i;
			}
		}
		if(warning_1!=warning){page=page_1=4;  line_1=line;  mode_1=mode;}//防止在险情时第一次扫描进入正常页面
	    //限制页数
		if(page>4){page=0;}
		if(page<0){page=4;}

			//翻页，选择按钮判断，低电平有效
		if(LCD_Forward()==0)
		{
			line++;
			if(page==0){if(line>8){line=0;}}
			if(page!=0){if(line>2){line=0;}}
		}
		if(LCD_Backward()==0)
		{
			line--;
			if(page==0){if(line<0){line=8;}}
			if(page!=0){if(line<0){line=2;}}
		}
		if(LCD_Select()==0)
		{
			if(page==0){if(line==1){mode=1;}}
			if(page==0){if(line==2){mode=2;}}
			if(page==0){if(line==6||line==5||line==4||line==3){page=line-2;line=0;}}
			if(page==0){if(line==7){page=4;line=0;}}
			if(page==0){if(line==8){page=page+1;line=0;}}
			if(page!=0){if(line==1){page=page-1;line=0;}}
			if(page==3||page==2||page==1){if(line==2){page=page+1;line=0;}}
			if(page==4){if(line==2){page=0;line=0;}}


		}

        //判断是否有新的数据变化，从而判断重新变化页面
		if(page!=page_1||line!=line_1||mode!=mode_1||warning!=warning_1)
		{
			line_1=line;

			//选择页面
       switch(page)
       {
        case 0:LCD_MainOrder(page,&page_1,line,mode,&mode_1);  break;
        case 1:LCD_BasicInformation (page,&page_1,line,mode,date);  break;
        case 2:LCD_TheSenor(page,&page_1,line,mode,date);  break;
        case 3:LCD_UltrasonicDistance(page,&page_1,line,mode,date);  break;
        case 4:LCD_Warning(date,warning,&warning_1,line,mode,page,&page_1); break;
       }
      /* //如果为自动模式，一段时间后自动进行页面切换
       if(mode==2)
       {
    	   page++;
    	   delay_ms(1000);
       }*/
       }


		//LCD_ShowString(50,120,"System Waiting.......",YELLOW ,RED ,16,0);




}


void DATA_ERROR(void)
{

		LCD_Init();//LCD初始化
		LCD_Fill(0,0,LCD_W,LCD_H,BLUE);
		LCD_ShowString(145,120,"Data Error!!!",RED,YELLOW,16,0);



}

void SYS_WO(void)
{
	LCD_Init();//LCD初始化
	LCD_Fill(0,0,LCD_W,LCD_H,BLUE);
    LCD_ShowString(135,120,"System init finished!!!",RED,YELLOW,16,0);


}

void Ptotect(void)
{
	if(S==0X10)
	{
		LCD_Fill(0,0,LCD_W,LCD_H,BLUE);
		    LCD_ShowString(135,120,"Attention Find Smok!!!",RED,YELLOW,16,0);
		    delay_ms(5000);
	}
	if(F1==0x01||F2==0x02||F3==0x03||F4==0x04||F5==0x05||F6==0x06||F7==0x07||F8==0x08||F9==0x09||F10==0x0a||F11==0x0b||F12==0x0c||F13==0x0d||F14==0x0e||F15==0x0f)
	{
		LCD_Fill(0,0,LCD_W,LCD_H,BLUE);
		 	 LCD_ShowString(135,120,"Attention Find Flame!!!",RED,YELLOW,16,0);
		 	delay_ms(5000);
	}

}
