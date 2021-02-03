#include <iostream>
#include <fstream>
#include <string>

void OpenFile(std::ifstream &in, char *TestsDir);
void ReadFile(std::ifstream &in);
void StringCrop(std::string Readline, int ReadLinesCounter);
int RecognizeElement(std::string DataToRecognize[]);
std::string GetSecondPart(std::string LineToCheck);
int AddNewElement(std::string ElementData[], int ElementType);

struct Elements
{
	std::string Type;
	long int Age;
	enum Month { MONTH_JANUARY, MONTH_FEBRUARY, MONTH_MARCH, MONTH_APRIL, MONTH_MAY, MONTH_JUNE, MONTH_JULY, 
		MONTH_AUGUST, MONTH_SEPTEMBER, MONTH_OCTOBER, MONTH_NOVEMBER, MONTH_DECEMBER };
	std::string Name;
	Elements* Next;
	Elements* Prev;
};

int main(int argc, char *argv[])
{
	char TestsDir[] = "tests/";
	std::cout << "Get data from: " << argv[1] << "; Save data to: " << argv[2] << std::endl;
	std::ifstream in;
	strcat(TestsDir, argv[1]);

	OpenFile(in, TestsDir);

	system("pause");
	return 0;
}

void OpenFile(std::ifstream& in, char *TestsDir)
{
	in.open(TestsDir);
	if (!in.is_open())
	{
		std::cout << "Problems with input file, check directory or file!" << std::endl;
	}
	else
	{
		ReadFile(in);
	}
	in.close();
}

void ReadFile(std::ifstream &in)
{
	int ReadLinesCounter = 0;
	std::string ReadLine;
	while (getline(in, ReadLine))
	{
		ReadLinesCounter++;
		//std::cout << ReadLine << std::endl;
		StringCrop(ReadLine, ReadLinesCounter);
	}
	if (ReadLinesCounter == 0)
		std::cout << "File is empty!" << std::endl;
}

void StringCrop(std::string Line, int ReadLinesCounter) //Crop Result string, add to the List
{
	std::string CroppedLine, CroppedData[3];
	int PairOfDataPosition, ElementType, AddElementResult;
	for (int i = 0; i < 3; i++)
	{
		PairOfDataPosition = Line.find(";");
		CroppedLine = Line.substr(0, PairOfDataPosition);
		if(i < 2)
			Line = Line.substr(PairOfDataPosition + 2, Line.size() - CroppedLine.size());

		switch (i)
		{
		case 0:
			CroppedData[0] = CroppedLine;
			break;
		case 1: 
			CroppedData[1] = CroppedLine;
			break;
		case 2:
			CroppedData[2] = CroppedLine;
			break;
		}
	}

	ElementType = RecognizeElement(CroppedData);	//Get type of element: -1 - Not found, 0 - tree, 1 - bush
	if (ElementType == -1)	//Check if element type is correct (-1)
	{
		std::cout << "Something wrong, skip that element, line: " << ReadLinesCounter << std::endl;
		return;
	}
	
	AddElementResult = AddNewElement(CroppedData, ElementType);
	if (AddElementResult == -1)
		std::cout << "Type not found!" << std::endl;


}

int RecognizeElement(std::string DataToRecognize[]) //Find out what type element is
{	//0 - Tree, 1 - Bush
	std::string ElementType;

	ElementType = GetSecondPart(DataToRecognize[0]);
	if (ElementType == "tree")
		return 0;
	else if (ElementType == "bush")
		return 1;
	return -1;
}

std::string GetSecondPart(std::string LineToCheck) //Get data witch stays after :
{
	std::string Result;
	Result = LineToCheck.substr(LineToCheck.find(" ") + 2, LineToCheck.find(" ") - 1);
	for (unsigned int i = 0; i < Result.size(); i++)
		Result[i] = std::tolower(Result[i]);
	return Result;
}

int AddNewElement(std::string ElementData[], int ElementType)
{
	std::string NewElementType = ElementData[0];
	switch (ElementType)
	{
	case 0:	//if element has tree type
		
		break;
	case 1:

		break;
	default:
		std::cout << "Check entered data! Type is not found!" << std::endl;
		return -1;
	}
	return -1;
}


