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
   int width = 2;
   int otherWidth = 4;
   char separator = ' ';
   int numDays = 1;
   int offset;
protected:
public:
/*********************************************************************
*A template to manage formatting of the table column headers
* reference: https://stackoverflow.com/questions/14765155/how-can-i-easily-
* format-my-data-table-in-c
*********************************************************************/
   template<typename T> void printElement(T t, const char& width)
   {
      //make this formatted line reflect a calendar line
      std::cout << t << std::setw(otherWidth) << "Su"
      << std::setw(otherWidth) << "Mo"
      << std::setw(otherWidth) << "Tu"
      << std::setw(otherWidth) << "We"
      << std::setw(otherWidth) << "Th"
      << std::setw(otherWidth)<< "Fr"
      << std::setw(otherWidth) << "Sa"
      << std::endl;
   }

/*******************************************************************
*A template to manage the formatting of the numDays
*******************************************************************/
template<typename T> void printNext(T t, const char& width)
   {
      std::cout << t << std::setw(otherWidth) << numDays++;// increments numDays from 1-31
   }

/*******************************************************************
*displayTable()
*******************************************************************/
   int displayTable(int numDays, int offset)
   {
      offset = 6;
      printElement(' ', width);
      if(offset == 6)
      {
      for(int i = 1; i <= 31; i++)
         {
                printNext(' ', width);
         }
      }
      // Implement the offset here, later: if(offset == )
      return 0;
   }
};

/******************************************************************
*Main initializes the members in the class.
******************************************************************/
int main()
{
   LoopDesign test;
   test.displayTable(' ', 6);
}
