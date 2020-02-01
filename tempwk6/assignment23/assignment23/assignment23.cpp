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
*    Actual:     2.5 hrs
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
         do
         {
            prompt();
         }
         while(multiple < 1 || multiple > 100);
         for(int i = 0; i < 100; i += multiple)
            {
                       sum += i;
            }
         display();
         return 0;
         }
   
/***********************************************************************
*Display
***********************************************************************/
void display()
   {
      std::cout << "The sum of multiples of " << multiple << " less than 100 are: " << sum << std::endl;
   }
};

/***********************************************************************
*Main
***********************************************************************/
int main()
{
   Loopy loop;
   loop.calculate();
}
