#ifndef WORKINGWITHFILES_H
#define WORKINGWITHFILES_H

#include <fstream>
#include <iostream>
#include <vector>
#include "CycleList.h"

int checkIfFileExists(std::ifstream &in, char *TestsDir);
void getDataFromFile(std::ifstream &in);
void menu(List& list);

#endif