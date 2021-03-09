#include "Bush.h"

Bush::MonthOfTheYear Bush::getMonthValue(std::string* fieldData)
{
    if(ElementData[1] == "MONTH_JANUARY") return(Bush::MONTH_JANUARY);
    else if(ElementData[1] == "MONTH_FEBRUARY") return(Bush::MONTH_FEBRUARY);
    else if(ElementData[1] == "MONTH_MARCH") return(Bush::MONTH_MARCH);
    else if(ElementData[1] == "MONTH_APRIL") return(Bush::MONTH_APRIL);
    else if(ElementData[1] == "MONTH_MAY") return(Bush::MONTH_MAY);
    else if(ElementData[1] == "MONTH_JUNE") return(Bush::MONTH_JUNE);
    else if(ElementData[1] == "MONTH_JULY") return(Bush::MONTH_JULY);
    else if(ElementData[1] == "MONTH_AUGUST") return(Bush::MONTH_AUGUST);
    else if(ElementData[1] == "MONTH_SEPTEMBER") return(Bush::MONTH_SEPTEMBER);
    else if(ElementData[1] == "MONTH_OCTOBER") return(Bush::MONTH_OCTOBER);
    else if(ElementData[1] == "MONTH_NOVEMBER") return(Bush::MONTH_NOVEMBER);
    else if(ElementData[1] == "MONTH_DECEMBER") return(Bush::MONTH_DECEMBER);
    else return -1;
}