#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2header.h"


//a function that reads input from a text file and outputs to a binary file
void text2bin(FILE * inFile, FILE * outFile)
{
unsigned char arrBuff[256];
unsigned char strLen;
unsigned int numB;


	//while loop that executes if whole length is 1 byte
	while( fscanf(inFile, "%s\t%u", &arrBuff, &numB) != EOF)
	{
	strLen = strlen(arrBuff); 	
	
	fwrite(&strLen, (size_t)(sizeof(char)), 1, outFile);

	fwrite(arrBuff, (size_t)(sizeof(char)), (size_t)( strLen), outFile); //(size_t)1 OK?
	
	fwrite(&numB, (size_t)( sizeof(int) ), (size_t)1, outFile);

	
	}




	return;

}
