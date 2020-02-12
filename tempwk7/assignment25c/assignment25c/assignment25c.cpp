/***********************************************************************
* Program:
*    Assignment 25, Loop Design
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar displayTable, which
* calculates the days of the month conjunctive with an offset,
* then displays the days in calendar format with or without a new line.
*
*    Estimated:  1.0 hrs
*    Actual:     7.5 hrs
*       The most difficult part comprised figuring out how to coordinate the offset and numDays
* between day names and the last line when the final day lands on Saturday.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
class TableTest
{
private:
protected:
public:
   int numDays;
   int offset;
   int temp = 1;
   bool doesntNeedNewLine = false;
   /**********************************************************************
   *Constructors
   **********************************************************************/
TableTest()
   {
      
   }
   
   TableTest(int numDays, int offset)
   {
      
   }
   
   /**********************************************************************
   *displayTable(), where the number of days shown depends on how many the user
   * inputs into the prompt
   **********************************************************************/
   void displayTable(int numDays, int offset)
   {
      std::cout << "Number of days: ";
      std::cin >> numDays;
      std::cout << "Offset: ";
      std::cin >> offset;
      std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
      
      for(int j = 0; j <= offset; j++)
      {
          if(offset == 6)
          {
              break;//If the offset falls on Sunday, break out of the loop to prevent the addition of a space
          }
          std::cout << "    ";
      }

      int displayDays = 1;
      
      for(int i = offset + 1; i <= numDays + offset; i++, displayDays++)//increments month's days and considers the offset
      {
         std::cout << std::setw(4) << displayDays;
            if(i % 7 == 6)
          {
              std::cout <<  std::endl;//carriage return at each line's end except for the last line
          }
      }
      if(numDays >= 30 && offset == 4)
      {
         std::cout << "";
      } else
       std::cout << "\n";
   }
};

int main()
{
   TableTest test;
   int numDays = 0;
   int offset = 0;
   test.displayTable(numDays, offset);
}
