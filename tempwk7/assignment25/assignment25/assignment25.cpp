/***********************************************************************
* Program:
*    Assignment 25, Loop Design
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar, which
* calculates the days of the month conjunctive with an offset,
* then displays the days in calendar format.
*
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>

class LoopDesign
{
private:
   int numDays;
   int offset;
   int month;
   int year;
protected:
public:
/***********************************************************************
*Constructor
***********************************************************************/
LoopDesign()
   {
      
   }
   
   LoopDesign(int numDays, int offset)
   {
      
   }

/***********************************************************************
*Accessors and Mutators
***********************************************************************/
void setNumDays(int numDays)
   {
      this->numDays = numDays;
   }
   
   int getNumDays()
   {
      return numDays;
   }
   
   void setOffset(int offset)
   {
      this->offset = offset;
   }
   
   int getOffset()
   {
      return offset;
   }

/***********************************************************************
*Prompt
***********************************************************************/
   int prompt()
   {
      std::cout << "Number of days: " << std::endl;
      std::cin >> numDays;
      std::cout << "Offset: ";
      std::cin >> offset;
      return 0;
   }
/***********************************************************************
*Display Table
***********************************************************************/
   void displayTable()
   {
      for(int i = 0; i < 31; i++)
         if(year > 1753)
         {
            offset = 2;
            std::cout << "" << std::setw(offset) <<  month;
            /*set the offset with if statements per range.
             Then, pass in offset as a parameter to setw or
             a similar spacing method*/
         }
   }
   
   void displayMonth()
   {
      std::cout <<   " 1"  << " 2" <<   " 3" <<  " 4" <<  " 5"  <<  " 6"  <<   " 7"  << std::endl;
      std::cout << "\t 7"  << "  8" << "  9" << "  10" << " 11" << " 12"  << " 13" << std::endl;
      std::cout << "\t14"  << "   15" << "   16" << "   17" << "   18" << "   19"  << std::endl;
      std::cout << "\t19"  << "   20" << "   21" << "   22" << "   23" << "   24"  << std::endl;
      std::cout << "\t25"  << "   26" << "   27" << "   28" << "   29" << "   30"  << std::endl;
   }
};

int main()
{
   
}
