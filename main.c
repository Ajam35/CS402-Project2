#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p2header.h"

int main(int argc, char* argv[])
{

char * flag = argv[1];

FILE *fpIn = fopen(argv[2], "r");  

//ERROR CHECKS
if (fpIn == NULL)
{
fprintf(stderr, "input error\n");
	return (0);
}
//END ERROR CHECKS


//Check for flags here:

//if text is the -t,-b or -s that gets read in
// else error

//pass input argument into text2bin
if (strcmp(flag, "-t") == 0)
{
	//ERROR CHECKS
	if(argv[3] == NULL)
	{
		fprintf(stderr, "command-line error\n");
		exit(1);
	}

	if(argc != 4){
		fprintf(stderr, "argument count error\n");
		exit(1);
	}
	//END ERROR CHECKS
	
	FILE *fpOut = fopen(argv[3], "wb"); 
	
	//function call
	text2bin(fpIn, fpOut);

	fclose(fpIn);
	fclose(fpOut);
	return 0;
}
//pass input argument into bin2text
if (strcmp(flag, "-b") == 0)
{
	//ERROR CHECKS
	if (argv[3] == NULL)
	{
		fprintf(stderr, "command-line error\n");
	}

	if (argc != 4){
		fprintf(stderr, "argument count error\n");
		exit(1);
	}
	//END ERROR CHECKS
	FILE *fpOut = fopen(argv[3], "w");
	
	//function call
	bin2text(fpIn, fpOut);

	fclose(fpIn);
	fclose(fpOut);
	return 0;
}
//pass argument into myStats.
if (strcmp(flag, "-s") == 0)
{
	//ERROR CHECKS
	if (argc != 3){
		fprintf(stderr, "argument count error\n");
		exit(1);
	}
	printf("-s check\n"); // @@@@@@@@@@@@@@@@@@
	//END ERRORCHECKS
	
	//function call
	myStats(fpIn);
	
	fclose(fpIn);
	return 0;
}
if ( strcmp(flag, "-s") != 0 && strcmp(flag, "-t") != 0 && strcmp(flag,"-b") != 0 )
	{
	fprintf(stderr,"flag error, please enter -t, -b, -s");
	}






return 0;
}