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
#include <iomanip>
#include <iostream>
#include <map>

/**********************************************************************
*CalendarFull class
**********************************************************************/
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
public:

   
/**********************************************************************
*Constructors
**********************************************************************/
CalendarFull()
   {
      
   }
   
   CalendarFull(int month, int year)
   {
      
   }
   
/**********************************************************************
*Accessors
**********************************************************************/
int getMonth()
{
   std::cout << "Month: ";
   return month;
}

int getYear()
{
   return year;
}

/********************************************************************
* Get the previous month's days
********************************************************************/
int getPreviousMonthsDays()
   {
      int previousMonthsDays = month - 1;
        month = previousMonthsDays;
        if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
           numDays = 31;
        }
        if(month == 4 || month == 6 || month == 9 || month == 11)
        {
           numDays = 31;
        } else numDays = 28;
      return numDays;
   }

/**********************************************************************
*ComputeOffset
**********************************************************************/
int computeOffset()
{
   if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
   {
      numDays = 31;
   }
   if(month == 4 || month == 6 || month == 9 || month == 11)
   {
      numDays = 30;
   } else numDays = 28;
   //return numDays;
   
   if(isLeapYear == false)
   {
      yearDiff = (year - 1753) * 365;
   }
   else
   {
      yearDiff = (year - 1753) * 366;
   }
   int totalDays = yearDiff + numDays + getPreviousMonthsDays();
   
   int sum = totalDays % 7;
         switch(sum)
         {
            case 1:
               offset = 0;
               break;
            case 2:
               offset = 1;
               break;
            case 3:
               offset = 2;
               break;
            case 4:
               offset = 3;
               break;
            case 5:
               offset = 4;
               break;
            case 6:
               offset = 5;
               break;
            case 7:
               offset = 6;
               break;
         }
    return offset;
   }

/**********************************************************************
*Display methods
**********************************************************************/
void display()
{
   
}

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

void displayHeader()
{
   std::cout << "Enter a month number: ";
   std::cin >> month;
   inputCheck();
   std::cout << "Enter year: ";
   std::cin >> year;
   inputCheck();
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
   
/**********************************************************************
* Input check
**********************************************************************/
void inputCheck()
   {
      if(month < 1 || month > 12)
      {
         std::cin.fail();
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Month must be between 1 and 12." << "\n";
      if(year < 1753)
      {
         std::cin.fail();
         std::cin.clear();
         std::cin.ignore();
         std::cout << "Year must be greater than 1752." << std::endl;//endl actually clears the memory cache
      }
   }
}
/**********************************************************************
*Calculate the number of days
**********************************************************************/
int numDaysInYear()
{
   return yearDays;
}

int numDaysInMonth()
{
   return monthDays;
}
   
/**********************************************************************
*Conclude whether it's a leap year.
**********************************************************************/
bool leapYear()
   {
   if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//this logic was tough
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
   temp.computeOffset();
   temp.displayTable();
}
