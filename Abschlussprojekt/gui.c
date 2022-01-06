#include "resultmaker.h"

void printmenue(void)
{
	printf("MENUE:\n");
	printf("-1- Read results from input file\n");
	printf("-2- Output results\n");
	printf("-3- Sort results\n");
	printf("-4- Calculate statistics\n");
	printf("-5- Output statistics\n");
	printf("-6- Save results to output file\n");
	printf("-7- Enter input file name\n");
	printf("-8- Enter output file name\n");
	printf("-9- Quit program\n\n");
	printf("Choose a function/number:\n");
}

void printprogramstate(struct programdata sprgdata)
{
	printf("PROGRAM STATE:\n");
	printf("Current input file name: %s\n", sprgdata.acinputfilename);
	printf("Current output file name: %s\n", sprgdata.acoutputfilename);
	switch (sprgdata.eprgstate)
	{
	case init:
		printf("Current program state: init\n\n");
		break;
	case readdone:
		printf("Current program state: readdone\n\n");
		break;
	case sortdone:
		printf("Current program state: sortdone\n\n");
		break;
	case statdone:
		printf("Current program state: statdone\n\n");
		break;
	default:
		break;
	}
}

void printresults(struct result sresult)
{

}

void printstatistics(struct statistics sstatistics)
{

}

void enterfilename(char* psfilename)
{

}