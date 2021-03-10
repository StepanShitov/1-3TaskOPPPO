#include "main.h"
#include "Tree.h"
#include "Bush.h"
#include "WorkingWithFiles.h"
//#include "PreparingData.h"


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


