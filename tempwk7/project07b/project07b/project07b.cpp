/***********************************************************************
* Program:
*    Project 07, Calendar
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar.
*    Estimated:  1.0 hrs
*    Actual:     20 hrs
*       The most difficult part comprised
************************************************************************/

//next steps: Try it without global variables; review structure map for which variables need passing in and do it that way

#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <map>

/***********************************************************************
*CalendarFull class
***********************************************************************/
class CalendarFull
{
private:
   bool isLeapYear;
   int yearDays;
   int monthDays;
   int month;
   int year;
   int offset;
   int numDays;
   int yearDiff;
   int totalLeapYears;
   int previousMonthsDays;
   int totalPreviousDays;
   int addFebruarysExtraDay;
   int totalDays;
   int commonYears;
   int totalYearsDays;
   int commonYearsDays;
   int leapYearsDays;
public:

   
/***********************************************************************
*Constructors
***********************************************************************/
CalendarFull()
   {
      
   }
   
   CalendarFull(int month, int year)
   {
      
   }
   
/***********************************************************************
*Accessors
***********************************************************************/
int getMonth()
{
   int month;
   std::cin >> month;
   return month;
}

int getYear()
{
   int year;
   std::cin >> year;
   return year;
}

/*********************************************************************
* Get the previous month's days
*********************************************************************/
int getPreviousMonthsDays()
{
   //totalPreviousDays = 0;
   int daysPerMonth[] = {31, (leapYear() ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
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
   int getCommonAndLeapDays()
    {
       //loop through all the years from input to 1753 and check each one for leap year
       int count = 0;
       commonYearsDays = 0;
       leapYearsDays = 0;
       if(year > 1753)
       {
           yearDiff = year - 1753;
       } else
          yearDiff = 1573 - year;
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
* compute the offset
**************************************************************/
int computeOffset()
{
   int totalDays =0;
   
   if(leapYear() && month == 2)
   {
      totalDays = totalYearsDays + numDays + totalPreviousDays + 1;//gets previous days for Jan (31) and adds a day for February on a leap year.
   }
   if(leapYear())
   {
         totalDays = totalYearsDays + numDays  + getPreviousMonthsDays();//this calculates if we need 29 for Feb
   }
   if(!leapYear())//don't need this twice
   {
      totalDays = totalYearsDays + numDays  + getPreviousMonthsDays();//this calculates also if we don't need 29 for Feb but only for previous months
   }
   offset = totalDays % 7;
         
    return offset;
   }

   /**************************************************************
    * compute the input month's days
    **************************************************************/
   int computeNumDays()
   {
      numDays = 0;
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
      if(leapYear() && month == 2)
      {
         addFebruarysExtraDay = numDays + 1;
      }
      return numDays;
      }
   
/***********************************************************************
*Display methods
***********************************************************************/
   void displayTable(){
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
     for(int i = offset + 1; i <= numDays + offset; i++, displayDays++)//This is the break. It's not evaluating the body code because offset is not less than numDays. But why?
      //for(int displayDays = 1; displayDays <= numDays; displayDays++)
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

/**************************************************************************
* DisplayHeader
**************************************************************************/
void displayHeader()
{
   std::cout << "Enter a month number: ";
   std::cin >> month;
    while(month < 1 || month > 13)
    {
        inputCheck();
       std::cout << "Month must be between 1 and 12." << "\n";
    }
  
   std::cout << "Enter year: ";
   std::cin >> year;
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
   
/***********************************************************************
* Input check
***********************************************************************/
void inputCheck()
   {
         std::cin.fail();
         std::cin.clear();
         std::cin.ignore();
      }
   
/**********************************************************************
*Conclude whether it's a leap year.
**********************************************************************/
bool leapYear()
   {
   if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
           {
              isLeapYear = true;
           } else
              isLeapYear = false;
   return isLeapYear;
   }
};

int main()
{
   CalendarFull temp;
   temp.displayHeader();
   //temp.getTotalLeapYears();
   temp.computeNumDays();
   temp.computeOffset();
   temp.displayTable();
}
