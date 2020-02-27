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
bool isLeapYear(int year)
{
   if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
           {
              return true;
           }
   return false;
}
/**********************************************************************
*gets the previous month's days??
**********************************************************************/
int numDaysInMonth(int month, int year)
{
      int numDays = 0;
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
         if(isLeapYear(year))
         {
            numDays = 29;
         } else
         {
             numDays = 28;
         }
      }
      return numDays;
}
/**********************************************************************
*
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
*
**********************************************************************/
void displayHeader(int year, int month)
{
   std::string months[12] = {"January", "February", "March", "April", "May", "June", "July",
      "August", "Septmeber", "October", "November", "December"};
   for(int i = 0; i <= 12; i++)//sizeof caused a bad access error, so now I use 12
   {
      if(months[i] == months[month])
      {
         std::cout << months[i - 1] << ", " << year << std::endl;;
      }
   }
}
/**********************************************************************
*header called from here display is parent of the other ones on the chart; use the pseudocode for help
**********************************************************************/
void displayTable(int offset, int numDays, int month, int year)
{
   std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
   /*int dow = (offset + 1) % 7;
   int dom = numDays;
   std::cout << "days " << numDays;
   for(int i = 0; i <= dow; i++)
   {
      std::cout << std::setw(4)  << "    ";
   }
   for(dom = 1; dom < numDays; dom++)
   {
      std::cout << dom;
      dow++;
      if(dow % 7 == 0)
      {
         std::cout << std::endl;
      }
      if(dow % 7 != 0)
      {
         std::cout << std::endl;
      }
   }*/
   
   for(int i = 0; i <= offset; i++)
   {
      if(offset == 6)
      {
         break;//previously: break;
      }
       std::cout << "    ";
   }
      int displayDays = 1;
      for(int i = offset + 1; i <= numDaysInMonth(month, year) + offset; i++, displayDays++)
      {
         std::cout << std::setw(4) << displayDays;
         if(i % 7 == 6)
         {
            std::cout << std::endl;
         }
      }
     if(numDays >= 30 && offset == 4)//this one is not creating the extra line
     {
        std::cout << "";
     } /*else
     {
        std::cout << "\n";//this one is creating the unnecessary new line
     }*/
   }
/**********************************************************************
*
**********************************************************************/
void display(int year, int month, int offset)
{
   numDaysInMonth(month, year);
   displayHeader(year, month);
   //displayTable(offset, numDays);
}
/**********************************************************************
*
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
*
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
*
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
*
**********************************************************************/
int main()
{
   int month = 0;
   int year = 0;
   int offset = 0;
   int numDays = 0;
   numDays = numDaysInMonth(month, year);

   //std::string months[12] = {};
   month = getMonth();
   year = getYear();
   offset = computeOffset(month, year);
   display(year, month, offset);
   displayTable(offset, numDays, month, year);
   //displayTable(numDays, offset);
   /*displayHeader(year, month);
   computeOffset(month, year);
   displayTable(numDays, offset);*/
}
