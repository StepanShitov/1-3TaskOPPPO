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
	char delimiter = ';';
	int readLinesCounter = 0;
	std::string readLine;
	std::vector<std::string> dataFromCropeedLine;
	while (getline(in, readLine, delimiter))
	{
		if(readLine.find('\n') != std::string::npos)
		{
			readLinesCounter++;
			prepareData(dataFromCropeedLine, readLinesCounter);
			std::vector<std::string>().swap(dataFromCropeedLine);  //clear vector
		}
		dataFromCropeedLine.push_back(readLine);
	}
	if(dataFromCropeedLine.size() > 0)
	{
		readLinesCounter++;
		prepareData(dataFromCropeedLine, readLinesCounter);
		std::vector<std::string>().swap(dataFromCropeedLine);  //clear vector
	}
	if (readLinesCounter == 0)
		std::cout << "File is empty!" << std::endl;
}