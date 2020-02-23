/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar program.
*    Estimated:  1.0 hrs
*    Actual:     20 hrs
*       The most difficult part comprised getting that pesky displayTable loop to run correctly
* with this new set of methods and variables. I deleted the class and global variables as ad-
* vised.
************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>

 int displayDays = 1;

/**********************************************************************
*Accessors
**********************************************************************/
int getMonth()
{
   int month;
   std::cin >> month;//point of failure from displayTable//it doesn't know what this is
   return month;
}

int getYear()
{
   int year;
   std::cin >> year;
   return year;
}

/*********************************************************************
* Mutators
**********************************************************************/
void setMonth(int month)
{
   
}
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

/********************************************************************
* Get the previous month's days
********************************************************************/
int getPreviousMonthsDays(int month, int numDays, bool isLeapYear, int year)
   {
      int totalPreviousDays = 0;
      int daysPerMonth[] = {31, (leapYear(isLeapYear, year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      for(int i = 1; i < month; ++i)
      {
         totalPreviousDays += daysPerMonth[i - 1];
      }
         numDays += totalPreviousDays;
         return totalPreviousDays;
      }
             

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
      leapYearsDays = totalLeapYears * 366;
      totalYearsDays = commonYearsDays + leapYearsDays;
  
      return totalYearsDays;
   }

/**************************************************************
 * compute the input month's days
 **************************************************************/
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
   if(leapYear(isLeapYear, year) && month == 2)
   {
      addFebruarysExtraDay = numDays + 1;
   }
   return numDays;
   }
   
/**************************************************************
* compute the offset
**************************************************************/
int computeOffset(int offset, int numDays, int year, int month, bool isLeapYear, int yearDiff, int totalYearsDays)
{
   
   bool leap = leapYear(isLeapYear, year);
   if(leap && month == 2)
   {
   int totalDays = getCommonAndLeapDays(year, yearDiff, isLeapYear) + computeNumDays(month, isLeapYear, year)  + getPreviousMonthsDays(month, numDays, isLeapYear, year);
      offset = totalDays % 7;
      return offset;
      
   }
   if(leap)
   {
     int totalDays = getCommonAndLeapDays(year, yearDiff, isLeapYear) + computeNumDays(month, isLeapYear, year)  + getPreviousMonthsDays(month, numDays, isLeapYear, year);
      offset = totalDays % 7;
      return offset;
      
   }
   if(!leap)
   {
      int totalDays = getCommonAndLeapDays(year, yearDiff, isLeapYear) + computeNumDays(month, isLeapYear, year)  + getPreviousMonthsDays(month, numDays, isLeapYear, year);
      offset = totalDays % 7;
      return offset;
   }
    return offset;//this statement should never be reached
   }

/***********************************************************************
*Display methods
***********************************************************************/
   void displayTable(int numDays, int offset, bool isLeapYear, int month, int totalYearsDays, int year, int yearDiff){
      
      //offset = computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays);
     std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
     
     for(int j = 0; j <= computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays); j++)
     {
         if(offset == 6)
         {
             break;//If the offset falls on Sunday, break out of the loop to prevent the addition of a space
         }
         std::cout << "    ";
     }
      for(int i = computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays) + 1; i <=  + offset; i++, displayDays++)
     {
        std::cout << std::setw(4) << displayDays;
           if(i % 7 == 6)
         {
             std::cout <<  std::endl;
         }
     }
      if((numDays = computeNumDays(month, isLeapYear, year) >= 30 && computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays) == 4))
     {
        std::cout << "";
     } else
      std::cout << "\n";
  }

/**************************************************************************
* prompt
**************************************************************************/
int promptMonth(int month)
{
   std::cout << "Enter a month: ";
   std::cin >> month;
   return month;
}

int promptYear(int year)
{
   std::cout << "Enter year: ";
   std::cin >> year;
   return year;
}

/**************************************************************************
* DisplayHeader
**************************************************************************/
void displayHeader(int year, int month)
{
   if(month < 1 || month > 12)
   {
        inputCheck();
       std::cout << "Month must be between 1 and 12." << "\n";
    }
   if(year < 1753)
   {
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
   int offset = 0;
   int numDays = 0;
   bool isLeapYear = false;
   month = promptMonth(month);
   year = promptYear(year);
   displayHeader(year,month);
   leapYear(isLeapYear, year);
   getCommonAndLeapDays(year, yearDiff, isLeapYear);
   displayTable(numDays, offset, isLeapYear, month, totalYearsDays, year, yearDiff);
}
