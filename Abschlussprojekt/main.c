#include "resultmaker.h"

int main(int argc, char* argv[])
{
	sresult_t sresult = {.uirunsinlist = 0};
	sstatistics_t sstatistics = {0};
	sprogramdata_t sprogramdata = { .acinputfilename = "c:\\temp\\input.txt", .acoutputfilename = "c:\\temp\\output.txt",.eprgstate = init };
	char cChoice;
	int iReturnValue = 2;
	do 
	{
		system("cls");
		printprogramstate(sprogramdata);
		printmenue();
		scanf_s("%c",&cChoice,1);
		(void)getchar(); //remove enter character
		vChoice(cChoice, &iReturnValue, &sprogramdata, &sresult, &sstatistics);
	} while (iReturnValue == 2);
	return iReturnValue;
}

void vChoice(char cKey, int *piReturnValue, sprogramdata_t *psprogramdata, sresult_t *psresult, sstatistics_t *psstatistics)
{
	int iReturnFunction;
	switch (cKey)
	{
	case '1':
		printf("Reading file...");
		iReturnFunction = readresults(psprogramdata->acinputfilename, psresult);
		psprogramdata->eprgstate = readdone;
		if (iReturnFunction != 0)
		{
			printf("Read failure");
			*piReturnValue = EXIT_FAILURE;
		}
		break;
	case '2':
		printresults(*psresult);
		break;
	case '3':
		iReturnFunction = sort(psresult);
		psprogramdata->eprgstate = sortdone;
		if (iReturnFunction != 0)
		{
			printf("Write failure");
			*piReturnValue = EXIT_FAILURE;
		}
		break;
	case '4':
		if (psprogramdata->eprgstate == sortdone || psprogramdata->eprgstate == statdone)
		{
			iReturnFunction = calcstatistics(*psresult, psstatistics);
			psprogramdata->eprgstate = statdone;
			if (iReturnFunction != 0)
			{
				printf("Statistics failure");
				*piReturnValue = EXIT_FAILURE;
			}
		}
		else
		{
			printf("Please sort first.");
			printf("Press any key to continue.");
			(void)getchar(); //wait for a key
		}
		break;
	case '5':
		if (psprogramdata->eprgstate == statdone)
		{
			printstatistics(*psstatistics);
		}
		else
		{
			printf("Please calculate statistics first.");
			printf("Press any key to continue.");
			(void)getchar(); //wait for a key
		}
		break;
	case '6':
		iReturnFunction = saveresults(psprogramdata->acoutputfilename, *psresult);
		if (iReturnFunction != 0)
		{
			printf("Write failure");
			*piReturnValue = EXIT_FAILURE;
		}
		break;
	case '7':
		psprogramdata->eprgstate = init;
		enterfilename(psprogramdata->acinputfilename);
		break;
	case '8':
		enterfilename(psprogramdata->acoutputfilename);
		break;
	case '9':
		printf("Bye.");
		*piReturnValue = EXIT_SUCCESS;
		break;
	default:
		printf("Incorrect choice.");
		printf("Press any key to continue.");
		(void)getchar(); //wait for a key
		break;
	}
}