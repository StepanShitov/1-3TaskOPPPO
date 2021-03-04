#ifndef FOREST_H
#define FOREST_H

class Forest
{
public:
	Forest(std::string type, std::string name)
	{
		type_ = type;
		name_ = name;
	}

	virtual std::string getType() { return type_; }
	virtual std::string getName(){ return name_; }

	
	void setType(std::string type_){ Type = type_; }
	void setName(std::string name_){ Name = name_; }

	virtual long int getAge(){ return 1; }
	virtual BushColor::MonthOfTheYear getMonth(){ return BushColor::MONTH_JANUARY; }

private:
	std::string type_;	
	std::string name_;
};

#endif