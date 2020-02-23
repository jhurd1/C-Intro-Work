/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar program.
*    Estimated:  1.0 hrs
*    Actual:     24 hrs
*       The most difficult part comprised getting that pesky displayTable loop to run correctly
* with this new set of methods and variables. I deleted the class and global variables as ad-
* vised. I wrestled with the offset and displayTable until midnight. Sorry to say, I just couldn't
* get this one sorted out.
************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>

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
      for(int i = 1; i < month; ++i)//this is taking in the correct user's input for the month; confirmed
      {
         totalPreviousDays += daysPerMonth[i - 1];
      }
         numDays += totalPreviousDays;
         return totalPreviousDays;//this math is also confirmed: It returns the correct number of days for a leap year
      }
             
/***********************************************************************
* get just the given year's days
***********************************************************************/
int getJustTheInputYearsDays(int year, int yearDiff, bool isLeapYear)
{
   int justTheInputYearsDays = 0;
   int leapYearsDays = 0;

   if(year > 1753)
   {
       yearDiff = year - 1753;
   } else
      yearDiff = 1753 - year;
   bool leap = leapYear(isLeapYear, year);
   if(leap)
   {
      leapYearsDays = 1 * 366;
   } else
   {
      year = 1 * 365;
   }
   justTheInputYearsDays = year;
   return justTheInputYearsDays;
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
         yearDiff = 1753 - year;//spotted a typographical error here just now while debugging on the day after the due date; had set to 1573, but should be 1753
      //and this may have been my problem all along with the offset
      //therefore, be prepared to roll back to the former computeOffset code.
     
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
  
      return totalYearsDays;//The math is correct for totalYearsDays
   }
/**************************************************************
 * compute the input month's days
 **************************************************************/
int computeNumDays(int month, bool isLeapYear, int year)
{
   int numDays = 0;
   int addFebruarysExtraDay = 1;
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
   if(leapYear(isLeapYear, year) && month == 2)//this is the clause that adds the additional day for the leap year and month of February
   {
      numDays += addFebruarysExtraDay;
   }
   return numDays;//not successfully returning Feb's extra day with this logic
   }
   
/**************************************************************
* compute the offset
**************************************************************/
int computeOffset(int offset, int numDays, int year, int month, bool isLeapYear, int yearDiff, int totalYearsDays)
{
   //offset = (computeNumDays(month, isLeapYear, year) + getCommonAndLeapDays(year, yearDiff, isLeapYear) + getPreviousMonthsDays(month, numDays, isLeapYear, year)) % 7;
//is it possible I"m adding too many numbers here?
   
   int count = 0;
   
   for(int i = 1753; i < year; i++)
   {
      count += getJustTheInputYearsDays(year, yearDiff, isLeapYear);//concatenate with the days for the given year? Try it.
   }
   for(int j = 1; j < month; j++)
   {
      count += computeNumDays(month, isLeapYear, year);
   }
   offset = count % 7;
   return offset;
}

/***********************************************************************
*Display methods
***********************************************************************/
   void displayTable(int numDays, int offset, bool isLeapYear, int month, int totalYearsDays, int year, int yearDiff){
      int displayDays = 1;
     std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
      offset = computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays);//this appears to be passing in the value for offset to the next for loop, now. A step in the right direction.
      //std::cout << offset;
     for(int j = 0; j <= computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays); j++)//the offset tested was set to two, but mousing over the offset return a 0 value
        //but the offset should be 5 for March, 1760.
      
     {
         if(offset == 6)
         {
             break;//If the offset falls on Sunday, break out of the loop to prevent the addition of a space
         }
         std::cout << "    ";
     }
      for(int i = computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays) + 1; i <= computeNumDays(month, isLeapYear, year) + computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays); i++, displayDays++)
     {
        std::cout << std::setw(4) << displayDays;
           if(i % 7 == 6)
         {
             std::cout <<  std::endl;
         }
     }
      if((computeNumDays(month, isLeapYear, year) >= 30 && computeOffset(offset, numDays, year, month, isLeapYear, yearDiff, totalYearsDays) == 4))
     {
        std::cout << "";
     } else
     {
        std::cout << "\n";
     }
   
  }

/**************************************************************************
* prompt
**************************************************************************/
int promptMonth(int month)
{
   std::cout << "Enter a month number: ";
   std::cin >> month;
   while(month < 1 || month > 12)
   {
        inputCheck();
      std::cout << "Month must be between 1 and 12." << "\n";
      std::cout << "Enter a month number: ";
      std::cin >> month;
   }
   return month;
}

int promptYear(int year)
{
   std::cout << "Enter year: ";
   std::cin >> year;
   while(year < 1753)
     {
         inputCheck();
        std::cout << "Year must be 1753 or later." << std::endl;
        std::cout << "Enter year: ";
        std::cin >> year;
     }
   return year;
}

/**************************************************************************
* DisplayHeader
**************************************************************************/
void displayHeader(int year, int month)
{
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

/*******************************************************************
* main: In sum, I've confirmed that all my functions' math is correct, that the leapyear
* function returns the correct leap years, and that displayTable now properly receives
* computeOffset's offset value. Yet, I am not passing testBed because the offset is not
* correct or because my loop in displayTable is not correctly making use of the offset.
* 1. Review the loop in displayTable.
* 2. Review the calculation in computeOffset to ensure I'm not missing something.
*******************************************************************/
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
