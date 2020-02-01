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
*Calculate the sum of the multiples less than 100
***********************************************************************/
   int calculate()
   {
      if(multiple < limit)
      {
         for(int i = 1; i < limit; i++)
         {
                //multiple += multiple;
            sum += i;
         }
      }
      if(multiple > 100)
      {
         std::cin.fail();
         std::cin.ignore();
         std::cin.clear();
         std::cout << "Ya done did wrong.";
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
