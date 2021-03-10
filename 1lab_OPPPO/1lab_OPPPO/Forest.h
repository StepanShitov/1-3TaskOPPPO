#ifndef FOREST_H
#define FOREST_H

//#include "Bush.h"

class Forest
{
public:
	Forest()
	{
		type_ = " ";
		name_ = " ";
	}
	~Forest() { std::cout << "destruct";}

	std::string getType() { return type_; }
	std::string getName(){ return name_; }
	virtual long int getAge(){ return 0;}
	virtual int getMonth() { return 0; }

	
	void setType(std::string type){ type_ = type; }
	void setName(std::string name){ name_ = name; }

private:
	std::string type_;	
	std::string name_;
};

#endif