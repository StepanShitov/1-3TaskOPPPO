#ifndef TREE_H
#define TREE_H

#include "Forest.h"

class Tree : public Forest
{
public:
	Tree(std::string _Type, long int _Age, std::string _Name)
	{
		Type = _Type;
		Age = _Age;
		Name = _Name;
	}
	std::string getType() override { return Type;}
	long int getAge(){ return Age;}
	std::string getName(){ return Name;}

private:
	std::string Type;
	long int Age;
	std::string Name;
};

#endif