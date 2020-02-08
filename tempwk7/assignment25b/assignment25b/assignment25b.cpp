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
   int otherWidth = 3;
   int testWidth = 4;
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
      std::cout << t << std::setw(testWidth) << "Su"
      << std::setw(testWidth) << "Mo"
      << std::setw(testWidth) << "Tu"
      << std::setw(testWidth) << "We"
      << std::setw(testWidth) << "Th"
      << std::setw(testWidth)<< "Fr"
      << std::setw(testWidth) << "Sa"
      << std::endl;
   }

/*******************************************************************
*A template to manage the formatting of the numDays
*******************************************************************/
template<typename T> void printNext(T t, const char& width)
   {
      for(int i = 0; i <= 6; i++)
      {
           std::cout << t << std::setw(otherWidth) << numDays++;// increments numDays from 1-31
      }
      std::cout << std::endl;
   }

/*******************************************************************
*displayTable()
*******************************************************************/
   int displayTable(int numDays, int offset)
   {
      numDays = 1;
      printElement(' ', otherWidth);
      //for(int i = 1; i <= 31; i++)
      //{
         while(numDays > 0 && numDays < 5)
         {
            printNext(' ', otherWidth);
            numDays++;
           // break;
         }
         /*while(numDays >= 6 && numDays < 13)
         {
            printNext(' ', width);
            numDays++;
            break;
         }*/
      //}
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
