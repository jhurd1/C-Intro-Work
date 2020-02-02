/***********************************************************************
* Program:
*    Project 05, Calendar
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

/*I can think of a couple of ways to display the days. I could display the days as strings and
 create a different calendar configuration for each of seven years (focusing on the ones
 digit, beginning with three since 1753 is the first year) and for February on leap years
 . I could use math and output the days by returning one of 31 integers for each place
 and using a generic calendar format using variables to reference each of 31 dates;
 calculating the dates using an offset for each leap year and each of seven different
 ones digits in the years.
*/
#include <stdio.h>
#include <iomanip>
#include <iostream>
class Calendar{
private:
   int month;
   int year;
   bool isLeapYear;
   int offset;
protected:
public:
/***********************************************************************
 *Constructor. These are useful when doing actual OOP; when you need to instantiate a new
 *object of this class to call data members out of scope.
 ***********************************************************************/
   Calendar()
   {
      
   }
/***********************************************************************
*Non-default Constructor
***********************************************************************/
   Calendar(int month, int year)
   {
      
   }
/***********************************************************************
*Accessors
***********************************************************************/
   int getMonth()
   {
      return month;
   }
   
   int getYear()
   {
      return year;
   }
   
   bool getLeapYear()
   {
      return isLeapYear;
   }
   
   int getOffSet()
   {
      return offset;
   }
/***********************************************************************
*Mutators
***********************************************************************/
   void setMonth(int month){
      this->month = month;//may need to change the sequence of this line in the body of this code
   }
   
   void setYear(int year)
   {
      this->year = year;
   }
   
   void setLeapYear(bool isLeapYear)
   {
      this->isLeapYear = isLeapYear;
   }
   
   void setOffSet(int offset)
   {
      offset = 1;
      this->offset = offset;
   }
/***********************************************************************
*Calculate Leap Years
***********************************************************************/
   int leapYear()
   {
      //if the year is divisible by four and 400, the year is a leap year.
      if((year % 4 == 0) && (year % 400 == 0))
      {
         isLeapYear = true;
         
      }
      if(isLeapYear == true)
      {
         
      }
      return 0;
   }
/***********************************************************************
*Months
***********************************************************************/
void monthA()
   {
      for(int i = 0; i <= 0; i++){
         for(int j = 1; j <= 1; j++){
         //if((year >= 1753) && (month <= 12) && (month >= 1))
         //{
            std::cout <<   j  << " " <<   j <<  j <<      j  <<    j  <<   j  << std::endl;
            std::cout << "\t 7"  << "  8" << "  9" << "  10" << " 11" << " 12"  << " 13" << std::endl;
            std::cout << "\t14"  << "   15" << "   16" << "   17" << "   18" << "   19"  << std::endl;
            std::cout << "\t19"  << "   20" << "   21" << "   22" << "   23" << "   24"  << std::endl;
            std::cout << "\t25"  << "   26" << "   27" << "   28" << "   29" << "   30"  << std::endl;
         //}
      }
      }
   }
      /*
      std::cout << "\t     1"  << "   2" << "   3" << "   4" << "   5" << "   6"  << std::endl;
      std::cout << "\t 7"  << "  8" << "  9" << "  10" << " 11" << " 12"  << " 13" << std::endl;
      std::cout << "\t14"  << "   15" << "   16" << "   17" << "   18" << "   19"  << std::endl;
      std::cout << "\t19"  << "   20" << "   21" << "   22" << "   23" << "   24"  << std::endl;
      std::cout << "\t25"  << "   26" << "   27" << "   28" << "   29" << "   30"  << std::endl;*/
   
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

/***********************************************************************
*CheckInput comprises great practice for passing in data between functions.
***********************************************************************/
int checkInput()
   {
      Calendar checker;
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
*Display
***********************************************************************/
   void display()
   {
      std::cout << "\tSu  Mo  Tu  We  Th  Fr  Sa" << std::endl;
   }
};

int main()
{
   Calendar temp;
   //temp.prompt();
   //temp.checkInput();
   temp.display();
   temp.monthA();
}
