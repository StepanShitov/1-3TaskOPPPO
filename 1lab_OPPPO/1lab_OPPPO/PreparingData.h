#ifndef PREPARINGDATA_H
#define PREPARINGDATA_H

#include <iostream>
#include <string>
#include <exception>
#include <vector>
#include <ctype.h>
#include "Bush.h"
#include "CycleList.h"
#include <fstream>

const std::vector<std::string> classesFields = { "Type", "Age", "Month", "Name" }; //here we have all types of fields in classes

struct checkedData
{
    int index;
    std::string fieldData;
};

void prepareData(std::vector<std::string>& data, int currentLine, List& list);
std::string getField(std::string lineToFind, std::string data);
int getFieldIndex(std::string data);
int RecognizeElement(std::string DataToRecognize[]);
std::string checkValidity(int *fieldIndex, std::string* dataAddress);
std::string checkQuotesToTypes(int* fieldIndex, std::string* data);
std::string checkIfLineIsEmpty(int* fieldIndex, std::string* data);
std::string checkAge(std::string* data);
std::string checkMonth(std::string* data);
std::string checkName(std::string* data);
std::string stringsToObjects(std::vector<checkedData>& data, List& list);
void problemsWithInputLine(int currentLine, std::string problem);
void setMonthValue(Bush& obj, std::string &fieldData);
std::string getMonthValue(int* month);
std::string GetSecondPart(std::string LineToCheck);
std::string deleteQuotes(std::string Str);
std::string OnlyAge(std::string Age);
std::string OnlyMonth(std::string Month);
long toLong(std::string *ageStr);
void toLowerCase(std::string* type);

#endif