#include <stdio.h>
/*int main(void)
{
	int a=0x66;
	int* p;
	p = &a;
	printf("%x\n", p);
	printf("%x\n", *p);
}
*/
int arr[] = { 1,2,3,3,4,5,8,4,1 };
int findmax(int* arry,int a)
{
	int count = arr[0], i;
	for (i = 0; i < a; i++)
	{
		if (arry[i] > count)
		{
			count = arry[i];
		}
	}
	return count;
}
int main(void)
{
	int len = sizeof (arr)/sizeof(arr[0]);
	int max = findmax(arr,len);
	printf("max is %d", max);
}