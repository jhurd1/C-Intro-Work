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
   std::cout << "Month: ";
   return month;
}

int getYear()
{
   return year;
}

/*********************************************************************
* Get the previous month's days
*********************************************************************/
int getPreviousMonthsDays()
   {
      previousMonthsDays = 12 - month;
      //iterate across those to hit each of the remaining months and get their days.
        month = previousMonthsDays;
      for(int i = previousMonthsDays; i <= previousMonthsDays; i++)
      {
         if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
         {
            numDays = 31;
         }
         if(month == 4 || month == 6 || month == 9 || month == 11)
         {
            numDays = 31;
         }
         if(month == 2)
         {
               numDays = 28;
         }
         numDays += totalPreviousDays;
      }
      return totalPreviousDays;
   }

   /************************************************************************
   * getTotalLeapYears()
   ************************************************************************/
   int getTotalLeapYears()
      {
         //loop through all the years from input to 1753 and check each one for leap year
         if(year > 1753)
         {
             yearDiff = year - 1753;
         } else
            yearDiff = 1573 - year;
        
         totalLeapYears = 0;
         for(int i = yearDiff; i >= 0; i++)
         {
               if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//this isn't working for some reason
               {
                  totalLeapYears += year;
               }
         }
         commonYears = totalLeapYears - yearDiff;
         return totalLeapYears;
      }

/***********************************************************************
*ComputeOffset
***********************************************************************/
int computeOffset()
{
   //Get the numDays for the input month
   if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
   {
      numDays = 31;
   }
   if(month == 4 || month == 6 || month == 9 || month == 11)
   {
      numDays = 30;
   } else numDays = 28;
   if(isLeapYear == true)
   {
      addFebruarysExtraDay = numDays + 1;
      totalDays = yearDiff + totalLeapYears + numDays + addFebruarysExtraDay + previousMonthsDays;
   } else

      totalDays = yearDiff + totalLeapYears + numDays + previousMonthsDays;
   
   offset = totalDays % 7;
         
    return offset;
   }

/***********************************************************************
*Display methods
***********************************************************************/
   void displayTable(){
     std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
     
     for(int j = 0; j <= offset; j++)
     {
         if(offset == 6)
         {
             break;//If the offset falls on Sunday, break out of the loop to prevent the addition of a space
         }
         std::cout << "    ";
     }
     //for(int i = offset + 1; i <= numDays + offset; i++, displayDays++)//This is the break. It's not evaluating the body code because offset is not less than numDays. But why?
      for(int displayDays = 1; displayDays <= numDays; displayDays++)
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
   temp.getTotalLeapYears();
   temp.computeOffset();
   temp.displayTable();
}
