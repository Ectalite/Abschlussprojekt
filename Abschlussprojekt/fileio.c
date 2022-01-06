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
	iErrorCode = fopen_s(&pFile, pcfilename, "r");
	if (iErrorCode == 0)
	{
		do
		{
			pcReadStrReturn = fgets(acLine, 255, pFile);
			if (pcReadStrReturn != NULL)
			{
				pcToken = strtok_s(acLine, ";", &pcTokenNext);
				printf("%s\n", pcToken);
				strncpy_s(psresult->asresultlist[psresult->uirunsinlist].aclastname, MAXLENGTH_NAMES, pcToken, MAXLENGTH_NAMES-1);
				pcToken = strtok_s(NULL, ";", &pcTokenNext);
				printf("%s\n", pcToken);
				strncpy_s(psresult->asresultlist[psresult->uirunsinlist].acfirstname, MAXLENGTH_NAMES, pcToken, MAXLENGTH_NAMES-1);
				pcToken = strtok_s(NULL, ";", &pcTokenNext);
				printf("%s\n", pcToken);
				psresult->asresultlist[psresult->uirunsinlist].dtime = strtod(pcToken, NULL);
				psresult->uirunsinlist++;
			}
		} while (pcReadStrReturn != NULL);
		fclose(pFile);
	}
	else
	{
		return -1;
	}
	pFile = NULL;
	free(pcStartOfToken);
	return EXIT_SUCCESS;
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


