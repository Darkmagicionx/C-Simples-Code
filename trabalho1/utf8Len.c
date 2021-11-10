#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#incluide "utf8Len.h"
#include "CharReadOnes.h"

int utf8Length( char a[], int i ){

	int numberBytes = charLeadingOnes( a[i] );	

	return numberBytes;
}