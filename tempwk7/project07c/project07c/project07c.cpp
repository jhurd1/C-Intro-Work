/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar.
*    Estimated:  1.0 hrs
*    Actual:     3.5 hrs
*       The most difficult part comprised
************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <map>

/**********************************************************************
*Conclude whether it's a leap year.
**********************************************************************/
bool leapYear(bool isLeapYear, int year)
   {
   if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
           {
              isLeapYear = true;
           } else
              isLeapYear = false;
   return isLeapYear;
   }

/***********************************************************************
* Input check
***********************************************************************/
void inputCheck()
   {
         std::cin.fail();
         std::cin.clear();
         std::cin.ignore();
      }

/***********************************************************************
*Accessors
***********************************************************************/

/************************************************************************
* getTotalLeapYears()
************************************************************************/
int getCommonAndLeapDays(int year, int yearDiff, bool isLeapYear)
   {
      //loop through all the years from input to 1753 and check each one for leap year
      int count = 0;
      int commonYears = 0;
      int totalYearsDays = 0;
      int commonYearsDays = 0;
      int leapYearsDays = 0;
      
      if(year > 1753)
      {
          yearDiff = year - 1753;
      } else
         yearDiff = 1573 - year;
     
      int totalLeapYears = 0;
      for(int i = year; i > 1753; i--)
      {
         year--;
         //if(isLeapYear)
            if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
            {
               totalLeapYears = 1;
               count++;
               totalLeapYears += count;//need a variable holding the count of leap years and this doesn't do it
            }
      }
      if(totalLeapYears > yearDiff)
      {
         commonYears = totalLeapYears - yearDiff;
      }
      if(yearDiff > totalLeapYears)
      {
         commonYears = yearDiff - totalLeapYears;
      }
      commonYearsDays = commonYears * 365;
      leapYearsDays = totalLeapYears * 366;//These two new vars were returning arbitrary data because the program needed to know where to get them from
      //and instantiating them local to the method vs local to this block allowed the program to find the right values
      totalYearsDays = commonYearsDays + leapYearsDays;
  
      return totalYearsDays;
   }

int computeNumDays(int month, bool isLeapYear, int year)
{
   int numDays = 0;
   int addFebruarysExtraDay = 0;
   if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
   {
      numDays = 31;
   }
   if(month == 4 || month == 6 || month == 9 || month == 11)
   {
      numDays = 30;
   }
   if(month == 2)
   {
      numDays = 28;
   }
   if(leapYear(isLeapYear, year) && month == 2)//had to actually call the function here, otherwise it  will always be its original value in main
   {
      addFebruarysExtraDay = numDays + 1;
   }
   return numDays;
   }
   

int computeOffset(int offset, int year, int month, bool isLeapYear, int yearDiff, int totalYearsDays)//this is passing in the false value. Why?
{
   //Get the numDays for the input month
   int addFebruarysExtraDay = 0;
   int previousMonthsDays = 0;
   int totalDays =0;
   int numDays = 0;
   computeNumDays(month, isLeapYear, year);
   if(leapYear(isLeapYear, year) && month == 2)//had to actually call the function here, otherwise it  will always be its original value in main
   {
      //addFebruarysExtraDay = numDays + 1;//this isn't evaluating correctly as it should fire only for Feb
      totalDays = getCommonAndLeapDays(year, yearDiff, isLeapYear) + numDays + addFebruarysExtraDay + previousMonthsDays;
   }
   if(leapYear(isLeapYear, year))
   {
         totalDays = getCommonAndLeapDays(year, yearDiff, isLeapYear) + numDays + previousMonthsDays;
   }
   if(!leapYear(isLeapYear, year))
   {
      totalDays = getCommonAndLeapDays(year, yearDiff, isLeapYear) + numDays + previousMonthsDays;
   }
   offset = totalDays % 7;
         
    return offset;
   }

/***********************************************************************
*Display methods
***********************************************************************/
   void displayTable(int numDays, int offset, bool isLeapYear, int month, int totalYearsDays, int year, int yearDiff){
      int displayDays = 1;
      
     std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
     
     for(int j = 0; j <= offset; j++)
     {
         if(offset == 6)
         {
             break;//If the offset falls on Sunday, break out of the loop to prevent the addition of a space
         }
         std::cout << "    ";
     }
     /*for(int i = computeOffset(offset, year, month, isLeapYear, yearDiff, totalYearsDays) + 1; i <= numDays + computeOffset(offset, year, month, isLeapYear, yearDiff, totalYearsDays); i++, displayDays++)//This doesn't get an offset from computeOffset()*/
      for(int i = displayDays; displayDays <= numDays; i++)//last method I had to instantiate vars at the top of the method to get them to evaluate
     {
        std::cout << std::setw(4) << displayDays;
           if(offset % 7 == 6)
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

/**************************************************************************
* DisplayHeader
**************************************************************************/
void displayHeader(int year, int month)
{
   
    while(month < 1 || month > 13)
    {
        inputCheck();
       std::cout << "Month must be between 1 and 12." << "\n";
    }
  
   
   while(year < 1753){
       inputCheck();
      std::cout << "Year must be greater than 1752." << std::endl;
   }
  
   std::cout << std::endl;
   if(month == 1)
   {
      std::cout << "January" << ", " << year << std::endl;
   } else if (month == 2)
   {
      std::cout << "February" << ", " << year << std::endl;
   } else if (month == 3)
   {
      std::cout << "March" << ", " << year << std::endl;
   } else if (month == 4)
   {
      std::cout << "April" << ", " << year << std::endl;
   } else if (month == 5)
   {
      std::cout << "May" << ", " << year << std::endl;
   } else if (month == 6)
   {
      std::cout << "June" << ", " << year << std::endl;
   } else if (month == 7)
   {
      std::cout << "July" << ", " << year << std::endl;
   } else if (month == 8)
   {
      std::cout << "August" << ", " << year << std::endl;
   } else if (month == 9)
   {
      std::cout << "September" << ", " << year << std::endl;
   } else if (month == 10)
   {
      std::cout << "October" << ", " << year << std::endl;
   } else if (month == 11)
   {
      std::cout << "November" << ", " << year << std::endl;
   } else
   {
      std::cout << "December" << ", " << year << std::endl;
   }
}

int main()
{
   int year = 0;
   int month = 0;
   int yearDiff = 0;
   int totalYearsDays = 0;
   std::cout << "Enter a month number: ";
   std::cin >> month;
   std::cout << "Enter year: ";
   std::cin >> year;
   int offset = 0;
   int numDays = 0;
   bool isLeapYear = false;//change this to call the function instead after next step
   displayHeader(year,month);
   leapYear(isLeapYear, year);
   getCommonAndLeapDays(year, yearDiff, isLeapYear);
   displayTable(numDays, offset, isLeapYear, month, totalYearsDays, year, yearDiff);
}
