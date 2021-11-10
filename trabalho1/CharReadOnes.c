#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#include "CharReadOnes.h"
#include "utf8Len.h"


int charLeadingOnes( char value ){

	int i = 0;
	
	while (get_bit(value , (CHAR_BIT - i)-1)){
		i++;
	}
	return i;
}

bool get_bit(char val, int position)
{
	char mask = 1 << position;
	return mask & val;
}

void printBytes( char x[], int i, int n ){
	char aux [n];
	int aux2 = i;
	
	for(int b=0 ; b < n; b++){
		aux[b] = x[aux2];
		aux2++;
	}
	aux[n] = '\0';
	printf("%s",aux);

	for(int a = i; a < (i + n) ; a++){

	
		if(a == i)
				printf("{");

		printf("%x",(unsigned char) x[a]);
		
		
		if(a == (i + n)-1)
				printf("}");
	}
}