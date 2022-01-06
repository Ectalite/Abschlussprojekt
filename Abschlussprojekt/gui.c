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
	system("cls");
	printf("Lastname\t|\tName\t\t|\tRun time\n");
	printf("_________________________________________________________\n");
	for (unsigned int ui = 0; ui < sresult.uirunsinlist; ui++)
	{
		printf("%s", sresult.asresultlist[ui].aclastname); //Function is more complex because of the indentation
		if (strlen(sresult.asresultlist[ui].aclastname) < 8)
		{
			printf("\t");
		}
		printf("\t|\t%s", sresult.asresultlist[ui].acfirstname);
		if (strlen(sresult.asresultlist[ui].acfirstname) < 8)
		{
			printf("\t");
		}
		printf("\t|\t%lf\n", sresult.asresultlist[ui].dtime);
	}
	printf("Press any key to quit.");
	(void)getchar(); //wait for a key
}

void printstatistics(struct statistics sstatistics)
{
	printf("STATISTICS:\n");
	printf("Number of elements:\t\t%u\n", sstatistics.uielements);
	printf("Distance's Mean:\t\t%lf\n", sstatistics.darithmeticmean);
	printf("Median value:\t\t\t%lf\n", sstatistics.dmedianvalue);
	printf("Range of distances:\t\t%lf\n", sstatistics.drange);
	printf("Variance of distances:\t\t%lf\n",sstatistics.dvariance);
	printf("Standard deviation of distances:\t%lf\n",sstatistics.dstandarddeviation);
	printf("Press any key to quit.");
	(void)getchar(); //wait for a key
}

void enterfilename(char* psfilename)
{
	printf("Please give a path to the file:\n");
	scanf_s("%s", psfilename, MAXLENGTH_PATHFILE);
	(void)getchar(); //remove enter character
}