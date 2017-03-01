#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "p2header.h"

//a function that reads input from a binary file and outputs to a normal printout.
void myStats(FILE *inFile)
{

unsigned char arrBuff[255];
unsigned char strLen;
unsigned int numB;
unsigned char longest, smallest, min, max;
int flag = 0;



	//while loop that executes if whole length is 1 byte
while( fread(&strLen, (size_t) 1, (size_t) 1, inFile) == 1)
{
	//then reads all of string into arrBuff w/ size of length of string
	fread(&arrBuff, strLen , (size_t)1, inFile);

	//then reads rest of ints into numB
	fread(&numB, (size_t)(sizeof(unsigned int)) , (size_t)1, inFile);

	//if flag is 0 assign strLen (char read in) to longest AND smallest for comparison 
	//and assign min and max to numB (integer read in) for comparison as well.
	if( flag == 0)
		{
			longest = strLen;
			smallest = strLen;
			min = numB;
			max = numB;
			flag = 1;

		}
			//because I set flag to 1 it will do a selection swap
			// which compares longest and shortest to char input then stores the value
			// then compares max and min to integer input and stores the value
		else
			{
			
				if (strLen > longest)
				{
					longest = strLen;
				}
				if (strLen < smallest)
				{
					smallest = strLen;
				}
					
					if (numB > max)
					{
						max = numB;
					}
					
					if(numB < min)
					{
						min = numB;
					}	

			}
	
}
	//print statements for output
	printf("The length of the shortest in the input file is: %u \n", smallest);
	printf("The length of the longest in the input file is: %u \n", longest);
	printf("The value of the largest integer in the input file is: %u \n", max);
	printf("The value of the smallest integer in the input file is: %u \n", min);
	


return ;

}