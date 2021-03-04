#ifndef BUSH_H
#define BUSH_H

#include "Forest.h"

class Bush : public Forest
{
public:
	Bush()
	{
		Forest("bush", "");
		month_ = MONTH_JANUARY;
	}

	~Bush()
	{		
	}

	enum MonthOfTheYear {
	MONTH_JANUARY, MONTH_FEBRUARY, MONTH_MARCH, MONTH_APRIL, MONTH_MAY, MONTH_JUNE, MONTH_JULY,
	MONTH_AUGUST, MONTH_SEPTEMBER, MONTH_OCTOBER, MONTH_NOVEMBER, MONTH_DECEMBER
	};

	void setColor(Bush::MonthOfTheYear month) { month_ = month; }
	BushColor::MonthOfTheYear getMonth() { return month_; }

private:
	Bush::MonthOfTheYear month_;
};

#endif