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
   int countOffset;
   bool isLeapYear = false;
   int year; //represents the year input by a user
   int anchorYear = 1753;//represents the start year for this program
   int leapFeb;
   int month = 1;
   int displayDays = 1;
   int leapOffsetAnchor = 3;//represents first month of the first leap year from the anchorYear 1753
   int commonOffsetAnchor = 0;//represents the first month of the first common year of 1753
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
         std::cout << "Enter a month number: ";
         std::cin >> month;
         checkInput();
         //for the months in the map, if the month from the user matches,
         //input that value into the calculation
     /*
      The debugger was observed sequencing through the cases
      beginning with the input month. I don't need or want that. I only
      need to pluck the case I need and nothing more.
      
      Checking up on the possibility of an iterator
      for the processOffset() method.
      
      switch(month)
         {
            case 1:
               months[1];
               numDays = 31;
            case 2:
               months[2];
               numDays = 28;
            case 3:
               months[3];
               numDays = 31;
            case 4:
               months[4];
               numDays = 30;
            case 5:
               months[5];
               numDays = 31;
            case 6:
               months[6];
               numDays = 30;
            case 7:
               months[7];
               numDays = 31;
            case 8:
               months[8];
               numDays = 31;
            case 9:
               months[9];
               numDays = 30;
            case 10:
               months[10];
               numDays = 31;
            case 11:
               months[11];
            case 12:
               months[12];
               numDays = 31;
         }*/
         std::cout << "Enter year: ";
         std::cin >> year;
         checkInput();
      }

/***********************************************************************
*CheckInput comprises great practice for passing in data between functions.
***********************************************************************/
   int checkInput()
      {
         MonthYear checker;
         if((month > 12) && (year < 1753))
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
   
   //rework this logic to work with the month and year input from the user
   //the offset depends on the month and year
   void displayTable()
   {
      MonthYear temp;
      temp.processOffset();//calculates the right offset for month and year
      
      std::cout << "  " << std::setw(4) << "Su  "<< "Mo  "<< "Tu  " << "We  " << "Th  " << "Fr  " << "Sa\n";
      
      //formatTheTable();
      
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
      int leapYear(int year)
      {
         this->year = year;
         //if the year is divisible by four and 400, the year is a leap year.
         if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))//this logic was tough
         {
            isLeapYear = true;
         }
         if(isLeapYear == true)
         {
            //add 1 to 28 for the second month
            months[2] = numDays + 1;//I think adding one here is sufficient, so change this operator to + 1 only instead of concatenation
         }
         return year;
      }
   
/***********************************************************************
 *Process the year (and month) for setting the offset per year, month, and leapYear
 * As it stands, this logic is quite verbose; maybe can be made more succinct, especially for larger
 * years where we subtract the year from anchorYear 1753.
 ***********************************************************************/
int processOffset()
   {
      countOffset = year - anchorYear;//tells us the number of years from 1753
      for(int k = 0; k < countOffset; k++)//loop through the total years
      {
         if(isLeapYear == true)
         {
              offset = ((offset + 365 + year) % 7);//figures the year's offset
            //Note how regardless of year and month, the offset possibilities will always range between 0 and 6 (7)
         }
         for(int l = 1; l < month; l++)
         {
            offset += year + (month) % 7;//somewhere in here I need to pass in the prompt with its map
         }
      }
        return offset;
   }
   
/***********************************************************************
*formatTheTable appears to conflict with processOffset
* it may be necessary to give the variables different names
***********************************************************************/
   int formatTheTable()
   {
      //This loop formats the calendar table.
      for(int j = 0; j <= offset; j++)
      {
          if(offset == 6)
          {
              break;//If the offset falls on Sunday, break out of the loop to prevent the addition of a space
          }
          std::cout << "    ";
      }
      return offset;
   }
   
};

/***********************************************************************
*Main()
***********************************************************************/
int main()
{
   MonthYear temp;
   temp.prompt();
   temp.processOffset();
   temp.displayTable();
}
