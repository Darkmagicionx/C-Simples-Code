#include <stdio.h>

#define INT_BYTE_SIZE (sizeof(int))
#define INT_BIT_SIZE (INT_BYTE_SIZE * 8)

void print_binary(int num)
{
	//int lastBit = num>>INT_BIT_SIZE-1;
	for(unsigned int mask = 1 << (INT_BIT_SIZE - 1) ; mask ; mask >>= 1)
	{
		if(mask & num)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
	
	printf("\n");
}	

int main()
{
	int num;
	
	while(1)
	{
		if(scanf("%d", &num) != 1) 
			return 0;
			
		print_binary(num);	
	}
	
	return 0;
}
	
