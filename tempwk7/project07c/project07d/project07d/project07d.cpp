/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar program.
*    Estimated:  1.0 hrs
*    Actual:     32 hrs
*       The most difficult part comprised passing testBed 4. Once that array loop was changed
* along with * including return statements as breakpoints for the numDays function, the program
* passed.
************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>

/**********************************************************************
* Check if leap year
**********************************************************************/
bool isLeapYear(int year)
{
   if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
           {
              return true;
           }
   return false;
}

/**********************************************************************
*gets the month's days
**********************************************************************/
int numDaysInMonth(int month, int year)
{
      //int numDays = 0;
      if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
      {
         return 31; //numDays = 31;
      }
      if(month == 4 || month == 6 || month == 9 || month == 11)
      {
         return 30; //numDays = 30;
      }
      if(month == 2)
      {
         if(isLeapYear(year))
         {
            return 29; //numDays = 29;
         } else
         {
            return 28; //numDays = 28;
         }
      }
      //return numDays;
   return 0;
}

/**********************************************************************
*NumDays in the year
**********************************************************************/
int numDaysInYear(int year)
{
   if(isLeapYear(year))
   {
      return 366;
   }
   return 365;
}
/**********************************************************************
* display header
**********************************************************************/
void displayHeader(int year, int month)
{
   std::string months[12] = {"January", "February", "March", "April", "May", "June", "July",
      "August", "Septmeber", "October", "November", "December"};
   std::cout << months[month - 1] << ", " << year << std::endl;
}
/**********************************************************************
*header called from here display is parent of the other ones on the chart; use the pseudocode for help
**********************************************************************/
void displayTable(int offset, int month, int year)
{
   std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
   int numDays = numDaysInMonth(month, year);
   if(offset != 6)
   {
      for(int i = 0; i <= offset; i++)
      {
         std::cout << "    ";
      }
   }
   
   for(int i = 1; i <= numDays; i++)
   {
      if((offset + i) % 7 == 0 && i > 1)//i > 1 accommodates for offset of 6/Sunday
      {
         std::cout << std::endl;
      }
     std::cout << std::setw(4) << i;
   }
   std::cout << "\n";
   }
/**********************************************************************
* display calls the other two
**********************************************************************/
void display(int year, int month, int offset)
{
   numDaysInMonth(month, year);
   displayHeader(year, month);
}
/**********************************************************************
* Gets the offset by deducing and holding the value of numDays between loops
**********************************************************************/
int computeOffset(int month, int year)
{
   int numDays = 0;
   for(int i = 1753; i < year; i++)
   {
      numDays += numDaysInYear(i);
   }
   for(int j = 1; j < month; j++)
   {
      numDays += numDaysInMonth(j, year);
   }
   int offset = numDays % 7;
   return offset;
}
/**********************************************************************
* Get the year
**********************************************************************/
int getYear()//don't need to pass in the year for getter
{
      int year;
      std::cout << "Enter year: ";
      std::cin >> year;
      while(year < 1753)
       {
         std::cin.fail();
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Year must be 1753 or later." << std::endl;
          std::cout << "Enter year: ";
         std::cin >> year;
       }
      std::cout << std::endl;
     return year;
}
/**********************************************************************
* Get the month
**********************************************************************/
int getMonth()
{
   int month;
   std::cout << "Enter a month number: ";
   std::cin >> month;
   while(month < 1 || month > 12)
   {
      std::cin.fail();
      std::cin.clear();
      std::cin.ignore();
      std::cout << "Month must be between 1 and 12." << "\n";
      std::cout << "Enter a month number: ";
      std::cin >> month;
   }
   return month;
}

/**********************************************************************
* "Driver"
**********************************************************************/
int main()
{
   int month = 0;
   int year = 0;
   int offset = 0;
   int numDays = 0;
   numDays = numDaysInMonth(month, year);
   month = getMonth();
   year = getYear();
   offset = computeOffset(month, year);
   display(year, month, offset);
   displayTable(offset, month, year);
}
