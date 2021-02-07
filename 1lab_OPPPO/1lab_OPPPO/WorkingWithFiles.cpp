#include "WorkingWithFiles.h"
#include "PreparingData.h"

int checkIfFileExists(std::ifstream& in, char *testsDir)
{
	in.open(/*"tests/in_5.txt"*/testsDir);
	if (!in.is_open())
	{
		std::cout << "Problems with input file, check directory or file!" << std::endl;
		return -1;
	}
	else
	{
		getDataFromFile(in);
	}
	in.close();
	return 1;
}

void getDataFromFile(std::ifstream &in)
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