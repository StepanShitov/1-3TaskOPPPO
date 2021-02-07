#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <memory>
#include <exception>
#include "main.h"
#include "Tree.h"
#include "Bush.h"
#include "WorkingWithFiles.h"
#include "PreparingData.h"

struct Node
{
	std::shared_ptr<Forest> Element;
	int num;
	Node *next;
	Node *prev;
};
Node *FirstNode, *CurrNode;

int main(int argc, char *argv[])
{
	char TestsDir[] = "tests/";	
	if(argc <= 2)
	{
		std::cout << "Check entered data!" << std::endl;
		return 0;
	}
	std::cout << "Get data from: " << argv[1] << "; Save data to: " << argv[2] << std::endl;
	std::ifstream in;
	strcat(TestsDir, argv[1]);
	if(checkIfFileExists(in, TestsDir) == -1) return 0;	

	system("pause");
	return 0;
}

int AddNewElement(std::string ElementData[], int ElementType)
{
	int MonthCount;
	switch (ElementType)
	{
	case 0:	//if element has tree type
	{
		std::string AgeStr = OnlyAge(ElementData[1]);
		if(AgeStr == "Fail")
			return -1;
		if(AgeStr.size() <= 0)
			return -1;
		long int Age = toLong(AgeStr);

		if(Age == -1)
			return -1;
		
		Tree NewTree(ElementData[0], Age, ElementData[2]);
		
		return 1;
		break;
	}
	case 1:
	{
		ElementData[1] = OnlyMonth(ElementData[1]);
		Bush NewBush(ElementData[0], Bush::MONTH_JANUARY, ElementData[2]);

		if(ElementData[1] == "MONTH_JANUARY") NewBush.Month = Bush::MONTH_JANUARY;
		else if(ElementData[1] == "MONTH_FEBRUARY") NewBush.Month = Bush::MONTH_FEBRUARY;
		else if(ElementData[1] == "MONTH_MARCH") NewBush.Month = Bush::MONTH_MARCH;
		else if(ElementData[1] == "MONTH_APRIL") NewBush.Month = Bush::MONTH_APRIL;
		else if(ElementData[1] == "MONTH_MAY") NewBush.Month = Bush::MONTH_MAY;
		else if(ElementData[1] == "MONTH_JUNE") NewBush.Month = Bush::MONTH_JUNE;
		else if(ElementData[1] == "MONTH_JULY") NewBush.Month = Bush::MONTH_JULY;
		else if(ElementData[1] == "MONTH_AUGUST") NewBush.Month = Bush::MONTH_AUGUST;
		else if(ElementData[1] == "MONTH_SEPTEMBER") NewBush.Month = Bush::MONTH_SEPTEMBER;
		else if(ElementData[1] == "MONTH_OCTOBER") NewBush.Month = Bush::MONTH_OCTOBER;
		else if(ElementData[1] == "MONTH_NOVEMBER") NewBush.Month = Bush::MONTH_NOVEMBER;
		else if(ElementData[1] == "MONTH_DECEMBER") NewBush.Month = Bush::MONTH_DECEMBER;
		else return -1;
		
		return 1;
		break;
	}
	default:
		std::cout << "Check entered data! Type is not found!" << std::endl;
		return -1;
	}
	return -1;
}

