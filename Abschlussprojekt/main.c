#include "resultmaker.h"

int main(int argc, char* argv[])
{
	sresult_t sresult = {.uirunsinlist = 0};
	sstatistics_t sstatistics;
	sprogramdata_t sprogramdata = { .acinputfilename = "c:\\temp\\input.txt", .acoutputfilename = "c:\\temp\\output.txt",.eprgstate = init };
	char cChoice;
	int iReturnValue = 2;
	int iReturnFunction;
	do 
	{
		printprogramstate(sprogramdata);
		printmenue();
		scanf_s("%c",&cChoice,1);
		while (getchar() != '\n'); //Clean buffer for the next time
		switch (cChoice)
		{
		case '1':
			iReturnFunction = readresults(sprogramdata.acinputfilename, &sresult);
			if (iReturnFunction != 0)
			{
				printf("Read failure");
				iReturnValue = EXIT_FAILURE;
			}
			break;
		case '2':
			iReturnFunction = saveresults(sprogramdata.acoutputfilename, sresult);
			if (iReturnFunction != 0)
			{
				printf("Write failure");
				iReturnValue = EXIT_FAILURE;
			}
			break;
		case '3':

			break;
		case '4':

			break;
		case '5':

			break;
		case '6':

			break;
		case '7':

			break;
		case '8':

			break;
		case '9':
			printf("Bye.");
			iReturnValue = EXIT_SUCCESS;
			break;
		default:
			printf("Incorrect choice.");
			break;
		}
	} while (iReturnValue == 2);
	return iReturnValue;
}