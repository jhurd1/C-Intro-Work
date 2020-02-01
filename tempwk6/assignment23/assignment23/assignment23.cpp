/***********************************************************************
* Program:
*    Assignment 23, Loop Syntax
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a lesson in loop syntax.
*
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*       The most difficult part comprised calculating multiples or doing the math.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdexcept>

/***********************************************************************
*One loop class to rule all the loops.
***********************************************************************/
class Loopy{
private:
   int multiple;
   int doTheMath;
   int limit = 100;
   int sum = 0;
protected:
public:
/***********************************************************************
*Constructors
***********************************************************************/
Loopy()
   {
      
   }
   
Loopy(int multiple, int doTheMath)
{
      
}

/***********************************************************************
*Accessors and Mutators
***********************************************************************/
int getMultiple()
   {
      return multiple;
   }
   
int getTheMath()
   {
      return doTheMath;
   }
   
int getLimit()
   {
      return limit;
   }
   
void setMultiple(int multiple)
   {
      this->multiple = multiple;
   }
   
void setTheMath(int doTheMath)
   {
      this->doTheMath = doTheMath;
   }
   
void setLimit(int limit)
   {
      this->limit = limit;
   }
/***********************************************************************
*Prompt for the multiple
***********************************************************************/
void prompt()
   {
      std::cout << "What multiples are we adding? ";
      std::cin >> multiple;
   }
   
/***********************************************************************
*Manage incorrect input.
***********************************************************************/
void errorCheck()
   {
      while(std::cin.fail())
      {
         std::cin.clear();
         std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
         std::cin >> multiple;
      }
   }
   
/***********************************************************************
*Calculate the sum of the multiples less than 100
***********************************************************************/
   int calculate()
   {
      if(multiple < limit)
      {
         for(int i = 0; i < limit - multiple; i++)
         {
            sum += multiple;
         }
      }
      if(multiple > 100)
      {
         errorCheck();
      }
      return sum;
   }
   
/***********************************************************************
*Display
***********************************************************************/
void display()
   {
      std::cout << "The sum of multiples of " << multiple << " less than 100 are: " << calculate() << std::endl;
   }
};

/***********************************************************************
*Main
***********************************************************************/
int main()
{
   Loopy loop;
   loop.prompt();
   loop.calculate();
   loop.display();
}
