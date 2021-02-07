#ifndef FOREST_H
#define FOREST_H

class Forest
{
public:

enum MonthOfTheYear {
		MONTH_JANUARY, MONTH_FEBRUARY, MONTH_MARCH, MONTH_APRIL, MONTH_MAY, MONTH_JUNE, MONTH_JULY,
		MONTH_AUGUST, MONTH_SEPTEMBER, MONTH_OCTOBER, MONTH_NOVEMBER, MONTH_DECEMBER
	} Month;

	virtual std::string getType() { return "No way"; }
	virtual std::string getName(){ return "No way"; }
	virtual long int getAge(){ return 1; }
	virtual MonthOfTheYear getMonth(){ return MONTH_JANUARY; }
};

#endif