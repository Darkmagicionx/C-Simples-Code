
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include "separadorString.h"



void separatorUnify( char str[] ){
	
	int size = 0;
	int idx = 0;
	int position = 0;
	int counter = 0;
	int nbytes = 0;
	
	// Este ciclo identifica se existe algum carater a substituir no 
	// no final da string
	for(int j = sizeString(str)-1; j != 0; j-- ){
		size = sizeString(str)-1;
		
		if(isParam(str[size])){
			str[size] = '\0';
		}
		else{
			break;
		}
	}	

	// Este ciclo identifica se existe algum carater a substituir no 
	// no inicio da string e se existir remove o carater e desloca a 
	// a string para a posição 0 do array
	for(int j = 0; j <= sizeString(str); j++ ){
		
		size = sizeString(str);		
		if(isParam(str[0])){	
			for(int i = 0; i < size; i++){
				str[i] = str[i+1];							
			}
		}
	}	

	// Este ciclo identifica se existe algum carater a substituir no 
	// no meio da string e se existir remove-os substituindo por um ' '	
	while (str[idx] != '\0'){
		
		if(isParam(str[idx])){
			while (isParam(str[idx])) {
				counter++;
				idx++;
			}
			
			position = idx - counter;
			str[position] = ' ';
			
			for(int i = (position + 1); i < sizeString(str); i++){
				str[i] = str[i+counter-1];
			}			
		}	
		counter = 0;
		idx++;
	}

	size = sizeString(str);
	for(int i = 0; i < size; ){
		nbytes = utf8Length( str, i );
		if(nbytes <= 1){
			printf("%c", str[i]);
			i++;
		}
		else{
			printBytes(str,i,nbytes);
			i+=nbytes;
		}
	}
	printf("\n");
}

// Função recebe uma string e devolve o seu tamanho
int sizeString (char str[]){
	size_t size = strlen(str);
	return size;
}

// Função recebe uma string devolve true se for um carater a substituir
// ou false caso seja um carater válido
bool isParam (char c){
	if((c == ' ') || (c == '\t') || (c == '\n'))
		return true;
	return false;
}