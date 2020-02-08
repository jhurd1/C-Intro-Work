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
   char space = ' ';
   int numDays = 1;
   int offset;
   bool isLeapYear = false;
   int month;
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
*A template to manage the formatting of the calendar's integers
*******************************************************************/
template<typename T> void printNext(T t, const char& width)
   {
      std::cout<< t << std::setw(otherWidth) << std::setfill(space) << numDays++;
   }
/*******************************************************************
*Accessors
*******************************************************************/
   int getDays()
   {
      return numDays;
   }
/*******************************************************************
*Mutators
*******************************************************************/
void setDays(int numDays)
   {
      this->numDays = numDays;
   }
/*******************************************************************
*calcOffset()
*******************************************************************/
void setOffset(int offset)
   {
      this->offset = offset;
   }
   
int getOffset()
   {
      return offset;
   }
   
void calcOffset()
      {
         for(int i = 0; offset <= i; i++)
         {
            if(offset == 0)
            {
               //space = "  ";
            }
            if(offset == 1)
            {
               //space = "   ";
            }
            if(offset == 2)
            {
               //space = "       ";
            }
            if(offset == 3)
            {
               //space = "             ";
            }
            if(offset == 4)
            {
               //space = "                     ";
            }
            if(offset == 5)
            {
               //space = "                              ";
            }
            if(offset == 6)
            {
               //space = "                                        ";
            }
            if(offset == 7)
            {
               //space = "                                                      ";
            }
      }
   }
/*******************************************************************
*displayTable()
*******************************************************************/
   int displayTable(int numDays, int offset)
   {
      numDays = 1;
      offset = 0;
      month = 3;
      isLeapYear = false;
      printElement(' ', otherWidth);
         while(numDays > 0 && numDays < 8)
         {
            printNext(' ', otherWidth);
            numDays++;
         }
      std::cout << std::endl;
         while(numDays >= 8 && numDays < 13)
         {
            printNext(' ', otherWidth);
            numDays++;
         }
      std::cout << std::endl;
      while(numDays >= 13 && numDays < 20)
      {
         printNext(' ', otherWidth);
         numDays++;
      }
      std::cout << std::endl;
      while(numDays >= 20 && numDays < 27)
      {
         printNext(' ', otherWidth);
         numDays++;
      }
      std::cout << std::endl;
      while(numDays >= 27 && numDays < 32)
      {
         //if(isLeapYear && month != 2)//this logic will be changed later; just testing for now
         //{
            printNext(' ', otherWidth);
                    numDays++;
         //}
      }
      std::cout << std::endl;
        return 0;
      }
};

/******************************************************************
*Main initializes the members in the class.
******************************************************************/
int main()
{
   LoopDesign test;
   /*std::cout << "Number of days: " << std::endl;
   test.setDays(numDays);
   std::cin >> numDays;
   std::cout << "Offset: " << std::endl;
    Place the prompt in a separate function.*/
   test.displayTable(' ', 6);
}
