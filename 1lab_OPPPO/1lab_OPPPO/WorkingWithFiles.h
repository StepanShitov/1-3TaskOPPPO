#ifndef WORKINGWITHFILES_H
#define WORKINGWITHFILES_H

#include <fstream>
#include <iostream>

int checkIfFileExists(std::ifstream &in, char *TestsDir);
void getDataFromFile(std::ifstream &in);

#endif