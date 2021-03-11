#ifndef WORKINGWITHFILES_H
#define WORKINGWITHFILES_H

#include <fstream>
#include <iostream>
#include <vector>
#include "CycleList.h"

int checkIfFileExists(std::ifstream &in, char *TestsDir, char *OutDir);
void getDataFromFile(std::ifstream &in, char *OutDir);
void menu(List& list, char *OutDir);

#endif