#include <REGX52.H>
#include "LCD1602.h"
#include "DS18B20.h"
#include "Delay.h"
#include "Nixie.h"
#include "Timer0.h"
#include "OneWire.h"
float T;
int s=22,s1=0,i,z=0,x=0,y=0,i;
unsigned int cnt1=0;
unsigned int T0Count,a;

void main()
{
	DS18B20_ConvertT();
	Delay(1000);			
	Timer0Init();
	LCD_Init();
	LCD_ShowString(1,1,"NOW T:");
	while(1)
	{
		DS18B20_ConvertT();	
		T=DS18B20_ReadT();	//温度读取T
		if(T<0)				
		{
			LCD_ShowChar(1,8,'-');	
			T=-T;									//正负号与温度分开显示
		}
		else				
		{
			LCD_ShowChar(1,8,'+');	
                                             
		}
		LCD_ShowNum(1,9,T,3);		//LCD显示18B20返回的温度值T
		LCD_ShowChar(1,12,'.');		
		LCD_ShowNum(1,13,(unsigned long)(T*10000)%10000,4);//在LCD显示T，小数精度四位		
			LCD_ShowString(2,1,"Set:");
		if(s<0)				//设定温度个位显示为s
		{
			LCD_ShowChar(2,8,'-');	//若s小于0显示负号
			T=-T;			//T随之取反
		}
		else				
		{
			LCD_ShowChar(2,8,'+');	//与上面相反
		}
			LCD_ShowNum(2,9,s,3);
			LCD_ShowChar(2,12,'.');
			LCD_ShowNum(2,13,s1,1);//设定温度小数部分s1
		LCD_ShowNum(2,14,0,3);//单精度调节，小数后三位显示0，与实际温度NOW T对齐
			if(P3_6==0)
	{
		Delay(20);//消抖
		while(P3_6==0);//按键判定
		Delay(20);
		s1++;//若按下P3_6口对应按键，则s1示数+1
	}
		if(P3_5==0)
	{
		Delay(20);
		while(P3_5==0);//同前
		Delay(20);
		s1--;
	}
		if(s1<0)
	{
		s1=9;
		s--;//小于零消一
	}
	if(s1>9)
	{
		s1=0;
		s++;//十进一操作
	}
	if(T>(s+0.1*s1)+0.5)//设定温度大于T0.5度时执行操作
	{
		P3_0=0;//P3口绿灯亮起表示TEC工作
		P2_0=0;//P2口接继电器，TEC开始工作
		TL0 = 0x18;		//取低位
		TH0 = 0xFC;		//取高位
		T0Count++;	//用定时器计数
	if(T0Count>=100)
	{
		T0Count=0;
	}
	Nixie(1,T0Count/10);//数码管第一位显示数字每秒+1
	Delay(28);
	
	}
	else
	{
		P3_0=1;
		P2_0=1;
		T0Count=0;
	}
		if(T<(s+0.1*s1)-0.5)//同上
	{
		P3_1=0;
		
	}
	else
	{
		P3_1=1;
	}
}
	}
void Int1_ISR() interrupt 1 //外部中断,按键控制单片机运行与暂停查询;
	{
   
		while(!P3_3);

}
