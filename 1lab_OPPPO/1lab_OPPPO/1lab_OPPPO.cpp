#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <memory>
#include <exception>

int OpenFile(std::ifstream &in, char *TestsDir);
void ReadFile(std::ifstream &in);
void StringCrop(std::string Readline, int ReadLinesCounter);
int RecognizeElement(std::string DataToRecognize[]);
std::string GetSecondPart(std::string LineToCheck);
int AddNewElement(std::string ElementData[], int ElementType);
std::string DeleteQuotes(std::string Str);
std::string OnlyAge(std::string Age);
std::string OnlyMonth(std::string Month);

class Forest
{
public:

enum MonthOfTheYear {
		MONTH_JANUARY, MONTH_FEBRUARY, MONTH_MARCH, MONTH_APRIL, MONTH_MAY, MONTH_JUNE, MONTH_JULY,
		MONTH_AUGUST, MONTH_SEPTEMBER, MONTH_OCTOBER, MONTH_NOVEMBER, MONTH_DECEMBER
	} Month;

	virtual std::string getType() { return "No way"; }
	virtual std::string getName(){ return "No way"; }
	virtual long int getAge(){ return 1; }
	virtual MonthOfTheYear getMonth(){ return MONTH_JANUARY; }
};

class Tree : public Forest
{
private:
	std::string Type;
	long int Age;
	std::string Name;

public:
	Tree(std::string _Type, long int _Age, std::string _Name)
	{
		Type = _Type;
		Age = _Age;
		Name = _Name;
	}
	std::string getType() override { return Type;}
	long int getAge(){ return Age;}
	std::string getName(){ return Name;}

};

int AddToList(std::shared_ptr <Forest> NewF);
int NodesCntr;

class Bush : public Forest
{

public:

	Bush()
	{
		Type = "";
		Month = static_cast<MonthOfTheYear>(1);
		Name = "";

	}

	Bush(std::string _Type, Bush::MonthOfTheYear _Month , std::string _Name)
	{
		Type = _Type;
		Month = _Month;
		Name = _Name;
	}

	~Bush()
	{		
	}
	
	void setType(std::string _Type){ Type = _Type; }
	void setName(std::string _Name){ Name = _Name; }

	std::string getType() override { return Type;}
	std::string getName(){ return Name;}
	Bush::MonthOfTheYear getMonth() { return Month; }

	std::string getName1() { return Name; }

private:
	std::string Type;
	std::string Name;
};

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
	NodesCntr = 0;
	char TestsDir[] = "tests/";	
	if(argc <= 2)
	{
		std::cout << "Check entered data!" << std::endl;
		return 0;
	}
	std::cout << "Get data from: " << argv[1] << "; Save data to: " << argv[2] << std::endl;
	std::ifstream in;
	strcat(TestsDir, argv[1]);
	if(OpenFile(in, TestsDir) == -1) return 0;
	

	system("pause");
	return 0;
}

int OpenFile(std::ifstream& in, char *testsDir)
{
	in.open(/*"tests/in_5.txt"*/testsDir);
	if (!in.is_open())
	{
		std::cout << "Problems with input file, check directory or file!" << std::endl;
		return -1;
	}
	else
	{
		ReadFile(in);
	}
	in.close();
	return 1;
}

void ReadFile(std::ifstream &in)
{
	int ReadLinesCounter = 0;
	std::string ReadLine;
	while (getline(in, ReadLine))
	{
		ReadLinesCounter++;
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
		Forest &NTree = NewTree;
		std::shared_ptr <Forest> NewF(&NTree);
		if(AddToList(NewF) != 1) 
		{
			std::cout << "Node adding fail!" << std::endl;
			return -1;
		}

		//std::cout << A->Element->getType() << " " << A->Element->getAge() << " " << A->Element->getName() << std::endl;*/
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
		
		Forest &NBush = NewBush;
		Forest *p;
		p = &NBush;
		std::shared_ptr <Forest> NewF(&NBush);
		if(AddToList(NewF) != 1) 
		{
			std::cout << "Node adding fail!" << std::endl;
			return -1;
		}
		return 1;
		break;
	}
	default:
		std::cout << "Check entered data! Type is not found!" << std::endl;
		return -1;
	}
	return -1;
}

int AddToList(std::shared_ptr <Forest> NewF)
{
	Node *A = new Node;
	if(NodesCntr == 0)
	{
		FirstNode = A;
		A->prev = A;
		A->next = A;
	}
	else
	{
		A->prev = CurrNode;
		CurrNode->next = A;
		A->next = FirstNode;
	}
	NodesCntr++;
	if(NodesCntr > 1)
		std::cout << CurrNode->prev->num << std::endl;
	A->num = NodesCntr;
	A->Element = std::move(NewF);
	std::cout << A->Element->getType() << A->num << std::endl;
	if(NodesCntr > 1) std::cout << A->prev->Element->getType() << A->prev->num << std::endl;
	CurrNode = A;
	

	return 1;
}

