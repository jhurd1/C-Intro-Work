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
#include <iomanip>
#include <iostream>
#include <map>

class MonthYear
{
private:
   int numDays;
   int offset;
   bool isLeapYear;
   int year;
   int month;
public:
   std::map  <int, std::string> months;
   /***********************************************************************
   *Constructors
   ***********************************************************************/
MonthYear()
   {
      
   }
   
   MonthYear(int numDays, int offset)
   {
      
   }
   
/***********************************************************************
*Accessors
***********************************************************************/
   void put(const std::string& key, const std::string& value)
   {
      months[1] = "January";//always 31 days
      months[2] = "February";//sometimes 28, other times 29
      months[3] = "March";//always 31
      months[4] = "April";//always 30
      months[5] = "May";//always 31
      months[6] = "June";//always 30
      months[7] = "July";//always 31
      months[8] = "August";//always 31
      months[9] = "September";//30
      months[10] = "October";//31
      months[11] = "November";//30
      months[12] = "December";//31
   }
   
/***********************************************************************
*Prompt
***********************************************************************/
      void prompt()
      {
         std::cout << "Enter a month number: " << std::endl;
         std::cin >> month;
         //for the months in the map, if the month from the user matches,
         //input that value into the calculation
            if(month == months[i])//how does one compare user input of an integer to the keys of the map
            {
               
            }
         std::cout << "Enter year: " << std::endl;
         std::cin >> year;
      }

/***********************************************************************
*CheckInput comprises great practice for passing in data between functions.
***********************************************************************/
   int checkInput()
      {
         MonthYear checker;
         if((month > 12) || (year < 1753))
         {
            std::cin.fail();
            std::cin.clear();
            std::cin.ignore();
            checker.prompt();
         }
         return 0;
      }
/***********************************************************************
*displayTable()
***********************************************************************/
   void displayTable()
   {
      //std::cout << "Number of days: ";
      std::cin >> numDays;
      //std::cout << "Offset: ";
      std::cin >> offset;
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
   /***********************************************************************
   *Calculate Leap Years
   ***********************************************************************/
      int leapYear()
      {
         //if the year is divisible by four and 400, the year is a leap year.
         if((year % 4 == 0) && (year % 100 == 0) && (year % 400 == 0))
         {
            isLeapYear = true;
            
         }
         if(isLeapYear == true)
         {
            //add 1 to 28
         }
         return 0;
      }
};


/***********************************************************************
*Main()
***********************************************************************/
/***********************************************************************
*Main()
***********************************************************************/

/***********************************************************************
*Main()
***********************************************************************/
int main()
{
   MonthYear temp;
   temp.displayTable();
}
