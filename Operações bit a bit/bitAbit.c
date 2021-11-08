#include <stdio.h>
#include <stdbool.h>

#define INT_BYTE_SIZE (sizeof(int))
#define INT_BIT_SIZE (INT_BYTE_SIZE * 8)

//
//	Prints the integer in binary
//
void print_binary(int num)
{
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


//
//	Returns true if the bit in position is set false otherwise
//
bool get_bit(unsigned int val, int position)
{
	int mask = 1 << position;
	return mask & val;
}


//
//	Using bitwise operations returns true if val is negative, false
//	otherwise
//
bool is_negative(unsigned int val)
{
	/*
	int mask = 1 << (INT_BIT_SIZE - 1);
	return val & mask;
	*/
	
	return get_bit(val, INT_BIT_SIZE-1);
}


//
//	Sets the bit at position of val to 1
//
int set_bit(unsigned int val, int position)
{	
	int mask = 1 << position;
	
	return val | mask;
}

//
//	Sets the bit at position of val to 0
//
int clear_bit(unsigned int val, int position)
{
	int mask = 1 << position;
	mask = ~mask;
	return val & mask;
}

//
//	Toggles the bit at position of val. 
//
int toggle_bit(unsigned int val, int position)
{
	int mask = 1 << position;
	return val ^ mask;
}


//
//	Returns nrBits bits at position of val.
//
unsigned int get_value_at(unsigned int val, int nrBits, int position)
{
	int mask = (1 << nrBits) - 1;
	int maskInPosition = mask << position;
	int values = maskInPosition & val;
	
	return values >> position;
}


void test_is_negative();
void test_get_bit();
void test_set_bit();
void test_clear_bit();
void test_toggle_bit();
void test_get_value_at();

int main()
{
	
	test_get_value_at();
	printf("\n\n");
	
	
/*	
	
	test_is_negative();
	printf("\n\n");

	
	test_get_bit();
	printf("\n\n");


	test_set_bit();
	printf("\n\n");
	
	test_clear_bit();
	printf("\n\n");
	
	
	
	test_get_value_at();
	printf("\n\n");
	*/

	return 0;
}


void test_is_negative()
{
	printf("%d is negative? <%d>\n", -1, is_negative(-1));
	printf("%2d is negative? <%d>\n", 2, is_negative(2));
	
}

void test_get_bit()
{
	int val = 0xbeef;
	
	printf("%d 0x%x\n", val, val);
	print_binary(val);
	for(int i = 0; i < 8; ++i)
	{
		printf("bit<%d> - %s\n", i, get_bit(val,i)? "true" : "false");
	}
}

#define BYTE4_START_BIT (3*8)
#define BYTE3_START_BIT (2*8)
#define BYTE2_START_BIT (1*8)
#define BYTE1_START_BIT (0*8)
void test_set_bit()
{
	int val = 0xc0ffee;
	
	printf("%d 0x%x\n", val, val);
	print_binary(val);
	
	val = set_bit(val, BYTE4_START_BIT+1);
	val = set_bit(val, BYTE4_START_BIT+3);
	
	
	printf("%d 0x%x\n", val, val);
	print_binary(val);
}



void test_clear_bit()
{
	int val = 0xffdbf;
	
	printf("%d 0x%x\n", val, val);
	print_binary(val);
	
	val = clear_bit(val, BYTE3_START_BIT+1);
	
	val = clear_bit(val, BYTE2_START_BIT+4);
	val = clear_bit(val, BYTE2_START_BIT);
	
	val = clear_bit(val, BYTE1_START_BIT+4);	
	
	printf("\n\n%d 0x%x\n", val, val);
	print_binary(val);
}

void test_toggle_bit()
{
	int val = 0;
	
	val = 0x5;
	
	
	printf("%d 0x%x\n", val, val);
	print_binary(val);
	
	val = toggle_bit(val, 0);
	
	printf("%d 0x%x\n", val, val);
	print_binary(val);
	
	val = toggle_bit(val, 0);
	
	
	printf("%d 0x%x\n", val, val);
	print_binary(val);
	
	/*
	 * 
	printf("%d 0x%x\n", val, val);
	print_binary(val);
	
	for(int i = 0; i < sizeof(int) * 8; ++i)
	{
		val = toggle_bit(val, i);
	}
	
	
	printf("%d 0x%x\n", val, val);
	print_binary(val);
	*/
}

void test_get_value_at()
{
	int val = 0xabc195fc;
	printf("%u 0x%x\n", val, val);
	print_binary(val);
	
	val = get_value_at(val, 4, 1);
	
	printf("\n\n%d 0x%x\n", val, val);
	print_binary(val);
}
