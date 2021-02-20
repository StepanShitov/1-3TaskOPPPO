#include "PreparingData.h"
#include "main.h"

void prepareData(std::vector<std::string>& data, int currentLine)
{
    /*for(int i = 0; i < data.size(); i++)
        std::cout << data[i] << " ";
    std::cout << std::endl;*/
    std::string type, ageOrMonth, name, delimiter = ": ", fieldData, validityResult;
    int ageOrMonthFlag /*0 - Age, 1 - Month*/, indexOfField;

    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < classesFields.size(); j++)
        {
            if(data[i].find(classesFields[j] + delimiter) != std::string::npos)
            {
                indexOfField = getFieldIndex(data[i]);
                fieldData = getField(classesFields[j] + delimiter, data[i]);
                validityResult = checkValidity(&indexOfField, &fieldData);                
                if(validityResult != "OK")
                {
                    //std::cout << fieldData << " " << indexOfField << " " << validityResult << std::endl;
                    problemsWithInputLine(currentLine, validityResult);
                }
                break;
            }
        }
    }
}

std::string getField(std::string lineToFind, std::string data)
{   
    int indexOfField;
    data = data.substr(data.find(lineToFind) + lineToFind.size());
    return data;
}

int getFieldIndex(std::string data)
{
    std::string delimiter = ": ";
    for(int i = 0; i < classesFields.size(); i++)
    {
        if(data.find(classesFields[i] + delimiter) != std::string::npos) 
            return i;
    }
    return -1;
}

std::string deleteQuotes(std::string data)
{
    if(data.find("\"") != std::string::npos)
    {
        data = data.substr(data.find("\"") + 1);
        if(data.find("\"") != std::string::npos)
        {
            data = data.substr(0, data.find("\""));
            //std::cout << "----------"<< data << "-------------"<< std::endl;
            return data;
        }
    }
    return "check data fields!";
}

std::string checkValidity(int *fieldIndex, std::string* dataAddress) //fun. check validity of data, if it returns 0 - smth wrong, 1 - ok
{
    std::string status;
    status = checkQuotesToTypes(&(*fieldIndex), &(*dataAddress));
    if(status != "OK")   return status;
    status = checkIfLineIsEmpty(&(*fieldIndex), &(*dataAddress));
    if(status != "OK")   return status;
    switch (*fieldIndex)
    {
        case 1:
        {
            status = checkAge(&(*dataAddress));
            if(status != "OK")   return status;
            break;
        }
        case 2:
        {
            status = checkMonth(&(*dataAddress));
            if(status != "OK")   return status;
            break;
        }
        case 3:
        {
            status = checkName(&(*dataAddress));
            if(status != "OK")   return status;
            break;
        }
    }
    return "OK";
}

std::string checkQuotesToTypes(int* fieldIndex, std::string* data)
{
    if(*fieldIndex == 1 || *fieldIndex == 2) // then we shouldn't find quotes
        if((*data).find("\"") != std::string::npos)
            return "in field " + classesFields[*fieldIndex] + " not correct format of data";
    if(*fieldIndex == 0 || *fieldIndex == 3)
    {
        int quotesPosition = -1;
        for(int i = 0; i < 2; i++)
        {
            quotesPosition = (*data).find("\"", quotesPosition + 1);
            if(quotesPosition == std::string::npos)
                return "in field " + classesFields[*fieldIndex] + " not correct format of data";
        }
    }
    return "OK";
}

std::string checkIfLineIsEmpty(int* fieldIndex, std::string* data)
{
    if(*fieldIndex == 1 || *fieldIndex == 2)
        if((*data).size() == 0)
            return classesFields[*fieldIndex] + " field is empty";
    if(*fieldIndex == 0 || *fieldIndex == 3)
        if(deleteQuotes(*data).size() == 0)
            return classesFields[*fieldIndex] + " field is empty";
    return "OK";
}

std::string checkAge(std::string* data)
{
    if(toLong(&(*data)) == -1)
        return "in field Age, cannot convert to number";
    return "OK";
}

std::string checkMonth(std::string* data)
{
    if((*data).find("MONTH_") == std::string::npos)
        return "in field Month, check month information";
    return "OK";
}

std::string checkName(std::string* data)
{
    if(isupper((*data)[1]) == 0)
        return "check Name field data";
    if((*data).find(" ") != std::string::npos)
        *data = "\"" + *data + "\"";
    return "OK";
}

void problemsWithInputLine(int currentLine, std::string problem)
{
    std::cout << "There are problems in line # " << currentLine << " problem is: " << problem << std::endl;
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

long toLong(std::string* AgeStr)
{
	try
	{
		return std::stol(*AgeStr);
	}
	catch(const std::invalid_argument & ia)
	{
		return -1;
	}
	catch (const std::out_of_range& oor)
	{
		return -1;
	}
	catch(const std::exception & e)
	{
		return -1;
	}
}