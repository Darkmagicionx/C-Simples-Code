#include <stdio.h>

#define BUFFER_SIZE (2)
int main()
{
	// r - Opens to read
	FILE* fp = fopen("file.txt", "r");
	
	if(fp == NULL)
	{
		printf("Error opening the file\n");
		return 1;
	}
	
	char buffer[BUFFER_SIZE];
	int reads = 0;
	do
	{
		if(fgets(buffer, BUFFER_SIZE, fp) == NULL)
			break;
			
		reads++;
		
		printf("%s", buffer);
		
	}while(1);
		
	printf("reads: %d | EOF: %d\n", reads, EOF);
	fclose(fp);
	return 0;
}

