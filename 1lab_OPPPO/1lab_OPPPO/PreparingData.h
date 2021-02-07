#ifndef PREPARINGDATA_H
#define PREPARINGDATA_H

#include <iostream>
#include <exception>

void StringCrop(std::string Readline, int ReadLinesCounter);
int RecognizeElement(std::string DataToRecognize[]);
std::string GetSecondPart(std::string LineToCheck);
std::string DeleteQuotes(std::string Str);
std::string OnlyAge(std::string Age);
std::string OnlyMonth(std::string Month);
int toLong(std::string AgeStr);

#endif