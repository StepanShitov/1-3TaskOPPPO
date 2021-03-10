#ifndef FOREST_H
#define FOREST_H

class Forest
{
public:
	/*Forest(std::string type = " ", std::string name = " ")
	{
		type_ = type;
		name_ = name;
	}*/

	Forest()
	{
		type_ = " ";
		name_ = " ";
	}
	~Forest() { }

	virtual std::string getType() { return type_; }
	virtual std::string getName(){ return name_; }

	
	void setType(std::string type){ type_ = type; }
	void setName(std::string name){ name_ = name; }

private:
	std::string type_;	
	std::string name_;
};

#endif