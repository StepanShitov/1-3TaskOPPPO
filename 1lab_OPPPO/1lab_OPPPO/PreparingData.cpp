#include "PreparingData.h"
#include "main.h"

void prepareData(std::vector<std::string>& data, int currentLine)
{
    std::vector<std::string> classesFields = { "Type", "Age", "Month", "Name" }; //here we have all types of fields in classes
    std::string type, ageOrMonth, name, delimiter = ": ", fieldData, validityResult;
    int ageOrMonthFlag /*0 - Age, 1 - Month*/, indexOfField;

    for(int i = 0; i < data.size(); i++)
    {
        for(int j = 0; j < classesFields.size(); j++)
        {
            if(data[i].find(classesFields[j] + delimiter) != std::string::npos)
            {
                indexOfField = getFieldIndex(classesFields, data[i]);
                fieldData = getField(classesFields[j] + delimiter, data[i]);
                validityResult = checkValidity(indexOfField, &fieldData);
                if(validityResult != "OK")
                    problemsWithInputLine(currentLine, validityResult);
                break;
            }
        }
    }
}

std::string getField(std::string lineToFind, std::string data)
{   
    int indexOfField;
    data = data.substr(data.find(lineToFind) + lineToFind.size());
    if(data.find("\"") != std::string::npos)
        data = deleteQuotes(data);    
    return data;
}

int getFieldIndex(std::vector<std::string>& fields, std::string data)
{
    std::string delimiter = ": ";
    for(int i = 0; i < fields.size(); i++)
    {
        if(data.find(fields[i] + delimiter) != std::string::npos) 
            return i;
    }
    return -1;
}

std::string deleteQuotes(std::string data)
{
    data = data.substr(data.find("\"") + 1);
    data = data.substr(0, data.find("\""));
    return data;
}

std::string checkValidity(int fieldIndex, std::string* dataAddress) //fun. check validity of data, if it returns 0 - smth wrong, 1 - ok
{
    std::string data = *dataAddress;
    if(data.size() == 0)
    {
        return "field is empty";
    }

    if(fieldIndex == 3)
    {
        if(std::isupper(data[0]) != 0)
        {
            if(data.find(" ") != std::string::npos)
            {
                data = "\"" + data + "\"";
                *dataAddress = data;
            }
            return "OK";
        }
        return "check name format";
    }
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