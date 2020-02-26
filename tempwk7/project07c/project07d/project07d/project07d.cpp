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
*
**********************************************************************/
bool isLeapYear(int year, bool isLeapYear)
{
   if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
           {
              isLeapYear = true;
           } else
              isLeapYear = false;
   return isLeapYear;
}
/**********************************************************************
*
**********************************************************************/
int numDaysInMonth(int year, int month, int numDays)
{
      numDays = 0;
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
      if(isLeapYear(year, &isLeapYear) && month == 2)//Why do I need the address of isLeapYear?
      {
         numDays += addFebruarysExtraDay;
      }
      return numDays;
}
/**********************************************************************
*
**********************************************************************/
int numDaysInYear(int year, int numDays)
{
   int month = 0;
   year = year - 1753;
   int yearsDays = 0;
   if(isLeapYear(year, &isLeapYear))
   {
      yearsDays = 366;
   } else
   {
      yearsDays = 365;
   }
   numDays = numDaysInMonth(year, month, numDays) + yearsDays;
   return numDays;
}
/**********************************************************************
*
**********************************************************************/
void displayHeader(int year, int month)
{
   std::string months[12] = {"January", "February", "March", "April", "May", "June", "July",
      "August", "Septmeber", "October", "November", "December"};
   for(int i = 0; i <= sizeof(months); i++)
   {
      if(months[i] == months[month])
      {
          std::cout << months[i];
      }
   }
}
/**********************************************************************
*
**********************************************************************/
void displayTable(int numDays, int offset)
{
   std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
   for(int i = 0; i <= offset; i++)
   {
      if(offset == 6)
      {
         offset -= 1;//previously: break;
      }
       std::cout << "   ";
      for(int displayDays = 1; displayDays <= numDays; displayDays++)
      {
         std::cout << std::setw(4) << displayDays;
         if(displayDays == 6)
         {
            std::cout << std::endl;
         }
      }
     if(numDays >= 30 && offset == 4)
     {
        std::cout << "";
     } else
     {
        std::cout << "\n";
     }
   }
}
/**********************************************************************
*
**********************************************************************/
void display()
{
   
}
/**********************************************************************
*
**********************************************************************/
int computeOffset(int month, int year)
{
   int offset = (((year -1) * 365) + ((year - 1) / 4 ) - ((year - 1) / 100) + ((year) / 400)) % 7;
   return offset;
}
/**********************************************************************
*
**********************************************************************/
int getYear(int year)
{
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
     return year;
}
/**********************************************************************
*
**********************************************************************/
int getMonth(int month)
{
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
*
**********************************************************************/
int main()
{
   int month = 0;
   int year = 0;
   int offset = 0;
   int numDays = 0;
   getMonth(month);
   getYear(year);
   displayHeader(year, month);
   displayTable(numDays, offset);
}
