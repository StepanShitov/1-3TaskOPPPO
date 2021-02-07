#ifndef BUSH_H
#define BUSH_H

#include "Forest.h"

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

private:
	std::string Type;
	std::string Name;
};

#endif