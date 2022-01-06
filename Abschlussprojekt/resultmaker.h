#pragma once

#define MAXLENGTH_PATHFILE 255
#define MAXLENGTH_NAMES 30
#define NUMBER_RUNNERS 20
#define STATIC_ALLOCATION

//Header include
#include <stdio.h>
#include <stdlib.h>

//Structs deklaration

struct run
{
	char acfirstname[MAXLENGTH_NAMES];
	char aclastname[MAXLENGTH_NAMES];
	double dtime;
};

struct statistics
{
	unsigned int uielements;
	double darithmeticmean;
	double dmedianvalue;
	double drange;
	double dvariance;
	double dstandarddeviation;
};

struct result
{
#ifdef STATIC_ALLOCATION
	struct run asresultlist[NUMBER_RUNNERS];
#else
	struct run* asresultlist;
	unsigned int uisizeresultlist;
#endif
	unsigned int uirunsinlist;
};

enum programstate { init = 0, readdone = 1, sortdone = 2, statdone = 3 };
enum programerror { running = 2, error = 1, stop = 0};

struct programdata
{
	char acinputfilename[MAXLENGTH_PATHFILE];
	char acoutputfilename[MAXLENGTH_PATHFILE];
	enum programstate eprgstate;
};

//Typedef
typedef struct run srun_t;
typedef struct statistics sstatistics_t;
typedef struct result sresult_t;
typedef struct programdata sprogramdata_t;

//Funktion deklaration
int readresults(char* pcfilename, struct result* psresult);
int saveresults(char* pcfilename, struct result sresult);
int sort(struct result* psresult);
int calcstatistics(struct result sresult, struct statistics* psstatistics);
void printmenue(void);
void printprogramstate(struct programdata sprgdata);
void printresults(struct result sresult);
void printstatistics(struct statistics sstatistics);
void enterfilename(char* psfilename);