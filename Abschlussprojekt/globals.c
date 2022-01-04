#include "resultmaker.h"

volatile sresult_t sresult;
volatile sstatistics_t sstatistics;
volatile sprogramdata_t sprogramdata = {.acinputfilename = "c:\\temp\\input.txt", .acoutputfilename = "c:\\temp\\output.txt",.eprgstate = init};