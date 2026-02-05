#include <REGX52.H>
#include "Delay.h"

void Nixie(unsigned char locate,num)
{
	unsigned char table[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F,0x40};

	switch(locate)
	{
		case 8:P0_2=1;P0_3=1;P0_4=1;break;
		case 7:P0_2=0;P0_3=1;P0_4=1;break;
		case 6:P0_2=1;P0_3=0;P0_4=1;break;
		case 5:P0_2=0;P0_3=0;P0_4=1;break;
		case 4:P0_2=1;P0_3=1;P0_4=0;break;
		case 3:P0_2=0;P0_3=1;P0_4=0;break;
		case 2:P0_2=1;P0_3=0;P0_4=0;break;
		case 1:P0_2=0;P0_3=0;P0_4=0;break;
	}
	P1=table[num];
	Delay(1);
	P1=0x00;
}
