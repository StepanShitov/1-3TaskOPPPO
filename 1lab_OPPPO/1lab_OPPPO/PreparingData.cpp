#include "PreparingData.h"
#include "main.h"

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
		std::cout << "Wrong type, skip that element, line: " << ReadLinesCounter << std::endl;
		return;			
	}
	
	CroppedData[0] = DeleteQuotes(CroppedData[0]);
	CroppedData[2] = DeleteQuotes(CroppedData[2]);
	if(CroppedData[0] == "fail!" || CroppedData[2] == "fail!")
		AddElementResult = -1;
	else
		AddElementResult = AddNewElement(CroppedData, ElementType);
	if (AddElementResult == -1)
	{
		std::cout << "Wrong month or age, skip that element, line: " << ReadLinesCounter << std::endl;
		return;
	}
}

std::string DeleteQuotes(std::string Str)
{
	std::size_t pos = Str.find("\"");
	if(pos == std::string::npos)
		return "fail!";
	Str = Str.substr(pos + 1, Str.size());
	Str = Str.substr(0, Str.size() - 1);
	if(Str.size() == 0)
		return "fail!";
	return Str;
}

std::string OnlyAge(std::string Age)
{
	if(Age.size() > 4)
		Age = Age.substr(Age.find(":") + 2, Age.size());
	else return "Fail";
	return Age;
}

std::string OnlyMonth(std::string Month)
{
	int Pos = Month.find(": ");
	Month = Month.substr(Pos + 2, Month.size() - 1);
	return Month;
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

int toLong(std::string AgeStr)
{
	try
	{
		return std::stol(AgeStr);
	}
	catch(const std::invalid_argument & ia)
	{
		std::cout << "Mistake in age! ";
		return -1;
	}
	catch (const std::out_of_range& oor)
	{
		std::cout << "Mistake in age! ";
		return -1;
	}
	catch(const std::exception & e)
	{
		std::cout << "Mistake in age! ";
		return -1;
	}
}