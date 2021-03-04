#ifndef TREE_H
#define TREE_H

#include "Forest.h"

class Tree : public Forest
{
public:
	Tree()
	{
		Forest("tree", "");
		age_ = 0;
	}

	long int getAge(){ return age_;}

private:
	long int age_;
};

#endif