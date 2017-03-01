#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2header.h"

//a function that reads from a binary input file and outputs to a text file
void bin2text( FILE * inFile, FILE * outFile)
{
unsigned char arrBuff[255];
unsigned char strLen;
unsigned int numB;
int flag = 0;

	//while loop that executes if whole length is 1 byte
	while( fread(&strLen, (size_t) 1, (size_t) 1, inFile) == 1)
	{
		if(flag != 0)
			fprintf(outFile,"\n"); 
		
		flag = 1;

	//then reads all of string into arrBuff w/ size of length of string
	fread(&arrBuff, strLen , (size_t)1, inFile);
	arrBuff[strLen] = '\0';

	//then reads rest of ints into numB
	fread(&numB, 1, (size_t)(sizeof(unsigned int)) , inFile);
	//takes string and integer and prints out to outfile using a tab inbetween.
	
	fprintf(outFile,"%s\t%u", arrBuff, numB); 


	}


return ;
	
}