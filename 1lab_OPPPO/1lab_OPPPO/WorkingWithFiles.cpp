#include "WorkingWithFiles.h"
#include "PreparingData.h"

int checkIfFileExists(std::ifstream& in, char *testsDir, char *OutDir)
{
	in.open(/*"tests/in_5.txt"*/testsDir);
	if (!in.is_open())
	{
		std::cout << "Problems with input file, check directory or file!" << std::endl;
		return -1;
	}
	else
	{
		getDataFromFile(in, OutDir);
	}
	in.close();
	return 1;
}

void getDataFromFile(std::ifstream &in, char *OutDir)
{
	List list;
	char delimiter = ';';
	int readLinesCounter = 0;
	std::string readLine;
	std::vector<std::string> dataFromCropeedLine;
	while (getline(in, readLine, delimiter))
	{
		if(readLine.find('\n') != std::string::npos)
		{
			readLinesCounter++;
			prepareData(dataFromCropeedLine, readLinesCounter, list);
			std::vector<std::string>().swap(dataFromCropeedLine);  //clear vector
		}
		dataFromCropeedLine.push_back(readLine);
	}	
	
	if (readLinesCounter == 0)
		std::cout << "File is empty!" << std::endl;
	else
	{
		list.printList();
		char TestsDir[] = "tests/";	
		strcat(TestsDir, OutDir);
		menu(list, TestsDir);
	}

	/*if(dataFromCropeedLine.size() > 0)
	{
		readLinesCounter++;
		prepareData(dataFromCropeedLine, readLinesCounter, list);
		std::vector<std::string>().swap(dataFromCropeedLine);  //clear vector
	}*/
}

void menu(List& list, char *OutDir)
{	
	std::string choiceStr;
	long choiceNum;
	while(1)
	{
		std::cout << "what's next? 1-Delete element of given name; 2 - Sort by name length; 3 - Print out to file; 4 - exit" << std::endl;
		std::cin >> choiceStr;
		choiceNum = toLong(&choiceStr);
		if(choiceNum != -1) 
		{
			switch (choiceNum)
			{
				case 1:
				{
					std::cout << "Enter list name ";
					std::string name;
					std::getline(std::cin >> std::ws, name);
					Node *node = list.find(name);
					if(node == NULL)
					{
						std::cout << "Check entered data!" << std::endl;
					}
					else
					{
						list.deleteNode(node);
						list.printList();
						if(list.howmany_links() == 0)
						{
							std::cout << "List is empty, do you want to print out it? 1 - Y; 2 - N ";
							std::cin >> choiceStr;
							choiceNum = toLong(&choiceStr);
							if(choiceNum != -1) 
							{
								if(choiceNum == 1)
								{
									list.printOut(OutDir);
									std::cout << "Data is printed out!" << std::endl;
								}
								std::cout << "Exiting..." << std::endl;
							}
							return;
						}
					}
					break;
				}
				case 2:
				{
					list.sortlist();
					list.printList();
					break;
				}
				case 3:
				{
					list.printOut(OutDir);
					list.printList();
					std::cout << "Data is printed out!" << std::endl;
					break;
				}
				case 4:
					return;
				default:
				{
					std::cout << "Check entered choice!" << std::endl;
					break;
				}
			}
		}
	}
}