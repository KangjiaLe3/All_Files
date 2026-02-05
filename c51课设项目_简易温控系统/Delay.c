#include <REGX52.H>
void Delay(unsigned int xms)
{
	unsigned char i, j;
	while(xms--)
	{
		i = 2;
		j = 239;//根据晶体管频率12MHZ计算出内外循环次数
		do
		{
			while (--j);
		} while (--i);//while内外循环延迟函数
	}
}

