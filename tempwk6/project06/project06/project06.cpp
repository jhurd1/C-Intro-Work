/***********************************************************************
* Program:
*    Project 06, Calendar
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar, which
* calculates the days of the month for a year  after 1752.
*
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>

/***********************************************************************
*The Calendar class
***********************************************************************/
class Calendar
{
private:
/***********************************************************************
*Variables
***********************************************************************/
   int month;
   int year;
   int days;
   int leapDiff;
   int leapDays;
   int commonYears;
   int commDiff;
   int bothDiffs;
   bool leapYear;
   int sumDays;
   int sumLeapDays;
   int sumNonLeapDays;
   int sumCommDays;
   int daysSinceJanuary;
   int total;
   int offset;
protected:
public:
/***********************************************************************
*Mutators
***********************************************************************/
   void setYear(int year)
   {
      this->year = year;
   }
   
   void setMonth(int month)
   {
      this->month = month;
   }
/***********************************************************************
* Compute the Days.
* Get the total number of days for offset()
* Get the total years. For example, 2020 - 1753.
* Get the total common year days.
* Get the total leap year days.
* Get the total days between the input day and the days of the year input.
* Add them all together.
* Establish the day of the week based on the ones digit (?).
***********************************************************************/
int computeDays(int month, int year)
   {
      setYear(year);
      setMonth(month);
      leapYear = false;
      
      //Determine the quantity of leap years since January 1, 1753
      //based on the user input; use today's date for testing
      for(int i = year; i > 1753; i++)
      {
         if((year % 4 == 0) && (year % 400 == 0))
         {
            leapYear = true;
            leapDiff = year - 1753;
            //output to console to ensure math happens right
            std::cout << "leapDiff " << leapDiff << std::endl;
         }
      }
      
      //Determine how many days there were between all the leap years
      for(int i = leapDiff; i > 0; i++){
         leapDays = leapDiff * 366;
         //verify by outputting to console
         std::cout << "leapDays " << leapDays << std::endl;
      }
      //Determine how many days there were between all the common years
      for(int i = year; i > 1753; i++)
      {
         if((year % 4 != 0) && (year % 400 != 0))
         {
            commDiff = 365 * (year  - 1753);
            std::cout << "commDiff" << commDiff << std::endl;
         }
      }
      
      //Add the total
      bothDiffs = leapDays + commDiff;
      //Subtract the number of days since January 1 for the month input
      //This math needs to calculate the days for the previous months
      //and add them together first
      for(int i = month; i >= 1; i++)
      {
         if((month == 1) || (month == 3) || (month == 5) || (month == 7)||
            (month == 8) || (month == 10) || (month == 12))
         {
            for(int i = 0; i < 13; i += month)
            {
               sumDays += i;
            }
         }
         if((month == 2) && (year == leapYear))
         {
            for(int i = 0; i < 13; i += month)
            {
               sumLeapDays += i;
            }
           
         } else if ((month == 2) && (year != leapYear))
         {
             for(int i = 0; i < 13; i += month)
             {
                sumNonLeapDays += i;
             }
         }
         if((month == 4) || (month == 6) || (month == 10) || (month == 11))
         {
             for(int i = 0; i < 13; i += month)
             {
                sumCommDays += i;
             }
         }
         daysSinceJanuary = sumCommDays + sumNonLeapDays + sumLeapDays + sumDays;
      }
      //Add the difference to total to decipher the total days since January 1, 1753
      total = bothDiffs + daysSinceJanuary;
      //Determine the offset by the total days
      std::cout << "total " << total << std::endl;
      return total;
   }

/***********************************************************************
*Offset
***********************************************************************/
int computeOffset()
   {
      computeDays(month, year);
      for(int i = 0; i < 1; i++)
      {
         if(i == 1)
         {
            offset = days;
         }
      }
      std::cout << "offset " << offset << std::endl;
      return offset;
   }
   
/***********************************************************************
*Prompt
***********************************************************************/
   void prompt()
      {
         std::cout << "Enter a month number: " << std::endl;
         std::cin >> month;
         std::cout << "Enter year: " << std::endl;
         std::cin >> year;
      }
};

int main()
{
   Calendar cal;
   cal.prompt();
   cal.computeOffset();
}
