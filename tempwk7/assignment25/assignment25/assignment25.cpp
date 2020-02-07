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
   bool isLeapYear;
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
*Calculate Leap Years
***********************************************************************/
      int leapYear()
      {
         //if the year is divisible by four and 400, the year is a leap year.
         if((year % 4 == 0) && (year % 400 == 0))
         {
            isLeapYear = true;
            
         }
         if(isLeapYear == true)
         {
            
         }
         return 0;
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
* Remember to provide a table for each contingency, long vs. short months and leap year Feb
* vs. non-leap year Feb. Long months: 7. Short months: 6. If there are seven different days on
* which each month can start, that works out to (7 * 7) + (5 * 7). Then, add to this the 7 days
* on which February can begin and that's 2 * 7 (one for leap- and one for non-leap-year). It
* simply isn't feasible to code in 49 + 35 + 14 different month options.
***********************************************************************/
   void displayTable()
   {
      for(int i = year; i > 1753; i--)//decrement to count back so as to reach the beginning point for day one, 1753, which provides an anchor point in the math
         {
            numDays += 365;//concatenate numDays with 365 and assign it to itself
            if(isLeapYear)//if it's a leap year add an additional offset day
            {
               numDays += 1;
            }
            /*offset = 2;
            std::cout << "" << std::setw(offset) <<  month;
            set the offset with if statements per range.
             Then, pass in offset as a parameter to setw or
             a similar spacing method*/
            //offset = numDays % 7;get the remainder betwixt numDays and days of the week.
         }
      for(int j = 0; j <= 12; j++){
         if(offset == 0)
         {
            std::cout <<   " "  << " 1" <<   " 2" <<  " 3" <<  " 4"  <<  " 5"  <<   " 6"  << std::endl;
            std::cout << "\t 7"  << "  8" << "  9" << "  10" << " 11" << " 12"  << " 13" << std::endl;
            std::cout << "\t15"  << "   16" << "   17" << "   18" << "   19" << "   20"  << std::endl;
            std::cout << "\t21"  << "   22" << "   23" << "   24" << "   25" << "   26"  << std::endl;
            std::cout << "\t27"  << "   28" << "   29" << "   30" << "   31" << "  "  << std::endl;
         }
         if(offset == 1)
         {
            std::cout <<   " "  << "  " <<   " 1" <<  " 2" <<  " 3"  <<  " 4"  <<   " 5"  << std::endl;
            std::cout << "\t 6"  << "  7" << "  8" << "  9" << " 10" << " 11"  << " 12" << std::endl;
            std::cout << "\t13"  << "   14" << "   15" << "   16" << "   17" << "   18"  << std::endl;
            std::cout << "\t19"  << "   20" << "   21" << "   22" << "   23" << "   24"  << std::endl;
            std::cout << "\t25"  << "   26" << "   27" << "   28" << "   29" << "   30"  << std::endl;
            std::cout << "t31";
         }
         if(offset == 2)
         {
            std::cout <<   " "  << "  " <<   " " <<  " 1" <<  " 2"  <<  " 3"  <<   " 4"  << std::endl;
            std::cout << "\t 5"  << "  6" << "  7" << "  8" << " 9" << " 10"  << " 11" << std::endl;
            std::cout << "\t12"  << "   13" << "   14" << "   15" << "   16" << "   17"  << std::endl;
            std::cout << "\t18"  << "   19" << "   20" << "   21" << "   22" << "   23"  << std::endl;
            std::cout << "\t24"  << "   25" << "   26" << "   27" << "   28" << "   29"  << std::endl;
            std::cout << "t30" << " 31";
         }
         if(offset == 3)
         {
            std::cout <<   " "  << "  " <<   " " <<  " " <<  " 1"  <<  " 2"  <<   " 3"  << std::endl;
            std::cout << "\t 4"  << "  5" << "  6" << "  7" << " 8" << " 9"  << " 10" << std::endl;
            std::cout << "\t11"  << "   12" << "   13" << "   14" << "   15" << "   16"  << std::endl;
            std::cout << "\t17"  << "   18" << "   19" << "   20" << "   21" << "   22"  << std::endl;
            std::cout << "\t23"  << "   24" << "   25" << "   26" << "   27" << "   28"  << std::endl;
            std::cout << "t\29" << " 30" << " 31";
         }
         if(offset == 4)
         {
            
         }
      }
   }
   
   /***********************************************************************
   *Display
   ***********************************************************************/
      void displayColumnHeader()
      {
         std::cout << "\tSu  Mo  Tu  We  Th  Fr  Sa" << std::endl;
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
