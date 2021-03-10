#ifndef TREE_H
#define TREE_H

#include "Forest.h"

class Tree : public Forest
{
public:
	Tree() //: Forest()
	{
		age_ = 0;
	}
	
	~Tree() { }

	virtual long int getAge(){ return age_;}
	void setAge(long int age) { age_ = age; };

private:
	long int age_;
};

#endif