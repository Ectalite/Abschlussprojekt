#include "resultmaker.h"

int sort(struct result* psresult)
{
	double dtimeTemp;
	if (psresult != NULL)
	{
		for (unsigned int ui = 0; ui < psresult->uirunsinlist; ui++)
		{
			for (unsigned int uj = 0; uj < psresult->uirunsinlist - 1 - ui; uj++)
			{
				if (psresult->asresultlist[uj].dtime > psresult->asresultlist[uj + 1].dtime)
				{
					dtimeTemp = psresult->asresultlist[uj].dtime;
					psresult->asresultlist[uj].dtime = psresult->asresultlist[uj + 1].dtime;
					psresult->asresultlist[uj + 1].dtime = dtimeTemp;
				}
			}
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

int calcstatistics(struct result sresult, struct statistics* psstatistics)
{
	if (psstatistics != NULL && sresult.uirunsinlist > 0) //uirunsinlist should have a value bigger than 0 to calculate range
	{
		double dSum = 0;
		double dTemp;
		printf("Sum calc...\n");
		for (unsigned int ui = 0; ui < sresult.uirunsinlist; ui++)
		{
			dSum = dSum + sresult.asresultlist[ui].dtime;
		}
		psstatistics->darithmeticmean = dSum / sresult.uirunsinlist;
		printf("Median value calc...\n");
		if (sresult.uirunsinlist % 2 == 0)
		{
			psstatistics->dmedianvalue = (sresult.asresultlist[(sresult.uirunsinlist) / 2].dtime + sresult.asresultlist[(sresult.uirunsinlist + 1) / 2].dtime)/2;
		}
		else
		{
			psstatistics->dmedianvalue = sresult.asresultlist[(sresult.uirunsinlist) / 2].dtime;
		}
		printf("Range calc...\n");
		psstatistics->drange = sresult.asresultlist[sresult.uirunsinlist - 1].dtime - sresult.asresultlist[0].dtime;
		printf("Variance calc...\n");
		dSum = 0;
		for (unsigned int ui = 0; ui < sresult.uirunsinlist; ui++)
		{
			dTemp = sresult.asresultlist[ui].dtime - psstatistics->darithmeticmean;
			dSum = dSum + (dTemp * dTemp);
		}
		psstatistics->dvariance = dSum / sresult.uirunsinlist;
		printf("Standard deviation calc...\n");
		psstatistics->dstandarddeviation = sqrt(psstatistics->dvariance);
		printf("Getting the number of elements\n");
		psstatistics->uielements = sresult.uirunsinlist;
		return 0;
	}
	else
	{
		return -1;
	}

}