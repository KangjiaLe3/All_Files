#include <REGX52.H>
#include "Nixie.h"
#include "Delay.h"
#include "OneWire.h"
#include "DS18B20.h"
void  main()
{
	int j,k;
	while(1)
	{
			if(T>(s+0.1*s1)+0.5)
			{
			Delay(1000);
			k++;
		if(k>9)
		{
			k=0;
			j++;
		}
		Nixie(1,j);
		Nixie(2,k);
	}
}
	}