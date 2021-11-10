
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#include "separadorString.h"
#include "CharReadOnes.h"
#include "utf8Len.h"


#define BUFFERWORD (100) //Dimensão máxima da linha a ler

int main(){
	
	char word[BUFFERWORD];
	
	
	// r - Opens to read
	FILE* fp = fopen("file.txt", "r"); // abre o ficheiro para leitura
	
	if(fp == NULL)
	{
		printf("Error opening the file\n");
		return 1;
	}
	
	do
	{
		if(fgets(word, BUFFERWORD, fp) == NULL)
			break;
			
			separatorUnify( word );

	}while(1);
	
	fclose(fp);
	return 0;

}