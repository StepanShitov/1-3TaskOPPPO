#ifndef PREPARINGDATA_H
#define PREPARINGDATA_H

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <ctype.h>

const std::vector<std::string> classesFields = { "Type", "Age", "Month", "Name" }; //here we have all types of fields in classes

void prepareData(std::vector<std::string>& data, int currentLine);
std::string getField(std::string lineToFind, std::string data);
int getFieldIndex(std::string data);
int RecognizeElement(std::string DataToRecognize[]);
std::string checkValidity(int fieldIndex, std::string* dataAddress);
std::string checkQuotesToTypes(int* fieldIndex, std::string* data);
std::string checkIfLineIsEmpty(int* fieldIndex, std::string* data);
void problemsWithInputLine(int currentLine, std::string problem);
std::string GetSecondPart(std::string LineToCheck);
std::string deleteQuotes(std::string Str);
std::string OnlyAge(std::string Age);
std::string OnlyMonth(std::string Month);
int toLong(std::string AgeStr);

#endif