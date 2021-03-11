#include "PreparingData.h"
#include "main.h"
#include "Bush.h"
#include "Tree.h"


void prepareData(std::vector<std::string>& data, int currentLine, List& list)
{    
    std::string type, ageOrMonth, name, delimiter = ": ", fieldData, validityResult;
    int ageOrMonthFlag /*0 - Age, 1 - Month*/, indexOfField, lineIsBad;
    std::vector<checkedData> checkedDataOut;

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
                    lineIsBad = currentLine;
                    problemsWithInputLine(currentLine, validityResult);
                }
                else
                {
                        checkedData newDataPair;
                        newDataPair.index = indexOfField;
                        newDataPair.fieldData = fieldData;
                        checkedDataOut.push_back(newDataPair);
                }
                break;
            }
        }
    }
    if(lineIsBad != currentLine)
        validityResult = stringsToObjects(checkedDataOut, list);
    if(validityResult != "OK")
        problemsWithInputLine(currentLine, validityResult);
    std::vector<checkedData>().swap(checkedDataOut);
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
    return "OK";
}

std::string stringsToObjects(std::vector<checkedData>& data, List &list)
{
    if((data[0].fieldData == "\"tree\"" && data[1].index == 1 && data[2].index == 3) || (data[0].fieldData == "\"bush\"" && data[1].index == 2 && data[2].index == 3))
    {
        std::string currentType;
        Tree newTree;
        Bush newBush;
        for(int i = 0; i < data.size(); i++)
        {
            switch (data[i].index)
            {
                case 0:
                {
                    if(data[i].fieldData == "\"tree\"")
                    {
                        newTree.setType("tree");
                        currentType = "tree";
                    }
                    else if(data[i].fieldData == "\"bush\"")
                    {
                        newBush.setType("bush");
                        currentType = "bush";
                    }
                    break;
                }
                case 1:
                {
                    newTree.setAge(toLong(&(data[i].fieldData)));
                    break;
                }
                case 2:
                {
                    setMonthValue(newBush, data[i].fieldData);
                    break;
                }
                case 3:
                {
                    if(data[i].fieldData.find(" ") == std::string::npos)
                        data[i].fieldData = deleteQuotes(data[i].fieldData);
                    if(currentType == "tree")
                        newTree.setName(data[i].fieldData);
                    else if(currentType == "bush")
                        newBush.setName(data[i].fieldData);
                    break;
                }
            }
        }
    
    
        Forest* f;
        if(currentType == "tree")
        {
            f = &newTree;
        }
        else if(currentType == "bush")
        {
            f = &newBush;
        }
        list.addNewElement(*f);

        return "OK";
    }
    return "not correct fields";
}

std::string getMonthValue(int* month)
{
    switch (*month)
    {
        case 0: return "MONTH_JANUARY";
        case 1: return "MONTH_FEBRUARY";
        case 2: return "MONTH_MARCH";
        case 3: return "MONTH_APRIL";
        case 4: return "MONTH_MAY";
        case 5: return "MONTH_JUNE";
        case 6: return "MONTH_JULY";
        case 7: return "MONTH_AUGUST";
        case 8: return "MONTH_SEPTEMBER";
        case 9: return "MONTH_OCTOBER";
        case 10: return "MONTH_NOVEMBER";
        case 11: return "MONTH_DECEMBER";
        case 12: return "MONTH_INCORRECT";
        default: return "MONTH_INCORRECT"; 
    }
}

void setMonthValue(Bush& obj, std::string &fieldData)
{
    if(fieldData == "MONTH_JANUARY") obj.setMonth(Bush::MONTH_JANUARY);
    else if(fieldData == "MONTH_FEBRUARY") obj.setMonth(Bush::MONTH_FEBRUARY);
    else if(fieldData == "MONTH_MARCH") obj.setMonth(Bush::MONTH_MARCH);
    else if(fieldData == "MONTH_APRIL") obj.setMonth(Bush::MONTH_APRIL);
    else if(fieldData == "MONTH_MAY") obj.setMonth(Bush::MONTH_MAY);
    else if(fieldData == "MONTH_JUNE") obj.setMonth(Bush::MONTH_JUNE);
    else if(fieldData == "MONTH_JULY") obj.setMonth(Bush::MONTH_JULY);
    else if(fieldData == "MONTH_AUGUST") obj.setMonth(Bush::MONTH_AUGUST);
    else if(fieldData == "MONTH_SEPTEMBER") obj.setMonth(Bush::MONTH_SEPTEMBER);
    else if(fieldData == "MONTH_OCTOBER") obj.setMonth(Bush::MONTH_OCTOBER);
    else if(fieldData == "MONTH_NOVEMBER") obj.setMonth(Bush::MONTH_NOVEMBER);
    else if(fieldData == "MONTH_DECEMBER") obj.setMonth(Bush::MONTH_DECEMBER);
    else obj.setMonth(Bush::MONTH_INCORRECT);
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

long toLong(std::string* ageStr)
{
	try
	{
		return std::stol(*ageStr);
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

void toLowerCase(std::string* type)
{
    for(int i = 0; i < (*type).size(); i++)
        (&(*type))[i] = std::tolower((*type)[i]);
}