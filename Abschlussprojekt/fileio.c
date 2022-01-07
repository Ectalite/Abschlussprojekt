#include "resultmaker.h"

int readresults(char* pcfilename, struct result* psresult)
{
	errno_t iErrorCode;
	char* pcReadStrReturn;
	char acLine[255] = { 0 };
	FILE* pFile = NULL;
	char* pcStartOfToken = (char*)malloc(sizeof(char) * 255);
	char* pcToken = NULL;
	char* pcTokenNext = pcStartOfToken;
	strncpy_s(pcTokenNext, 255, "", 254);
	iErrorCode = fopen_s(&pFile, pcfilename, "r");
	int iReturnValue = 0;
	if (iErrorCode == 0)
	{
		do
		{
			pcReadStrReturn = fgets(acLine, 255, pFile);
			if (pcReadStrReturn != NULL)
			{
				pcToken = strtok_s(acLine, ";", &pcTokenNext);
				if (pcToken != NULL && pcTokenNext != NULL)
				{
					printf("%s\n", pcToken);
					strncpy_s(psresult->asresultlist[psresult->uirunsinlist].aclastname, MAXLENGTH_NAMES, pcToken, MAXLENGTH_NAMES - 1);
					if (strcmp(psresult->asresultlist[psresult->uirunsinlist].aclastname, "") == 0)
					{
						printf("Nachname Token ist leer.");
						iReturnValue = -1;
					}
					pcToken = strtok_s(NULL, ";", &pcTokenNext);
					if (pcToken != NULL && pcTokenNext != NULL)
					{
						printf("%s\n", pcToken);
						strncpy_s(psresult->asresultlist[psresult->uirunsinlist].acfirstname, MAXLENGTH_NAMES, pcToken, MAXLENGTH_NAMES - 1);
						if (strcmp(psresult->asresultlist[psresult->uirunsinlist].acfirstname, "") == 0)
						{
							printf("Vorname Token ist leer.");
							iReturnValue = -1;
						}
						pcToken = strtok_s(NULL, ";", &pcTokenNext);
						if (pcToken != NULL  && pcTokenNext != NULL && strcmp(pcTokenNext,"\0") == 0)
						{
							printf("%s\n", pcToken);
							psresult->asresultlist[psresult->uirunsinlist].dtime = strtod(pcToken, &pcToken);
							if (strcmp(pcToken,"\n") != 0 && strcmp(pcToken, "\0") != 0)
							{
								printf("Die Zeit von %s %s ist nicht korrekt.", psresult->asresultlist[psresult->uirunsinlist].aclastname, psresult->asresultlist[psresult->uirunsinlist].acfirstname);
								iReturnValue = -1;
							}
							psresult->uirunsinlist++;
						}
						else
						{
							printf("There is more than 3 Tokens.");
							iReturnValue = -1;
						}
					}
					else
					{
						printf("There is less than 3 Tokens.");
						iReturnValue = -1;
					}
				}
				else
				{
					printf("There is less than 3 Tokens.");
					iReturnValue = -1;
				}
			}
		} while (pcReadStrReturn != NULL);
		fclose(pFile);
	}
	else
	{
		iReturnValue = -1;
	}
	pFile = NULL;
	free(pcStartOfToken);
	return iReturnValue;
}

int saveresults(char* pcfilename, struct result sresult)
{
	errno_t iErrorCode;
	FILE* pFile = NULL;
	iErrorCode = fopen_s(&pFile, pcfilename, "w");
	if (iErrorCode == 0)
	{
		for (unsigned int ui = 0; ui < sresult.uirunsinlist; ui++)
		{
			fprintf(pFile, "%s;%s;%lf\n",sresult.asresultlist[ui].aclastname, sresult.asresultlist[ui].acfirstname, sresult.asresultlist[ui].dtime);
		}
		fclose(pFile);
	}
	else
	{
		return -1;
	}
	pFile = NULL;
	return EXIT_SUCCESS;
}


