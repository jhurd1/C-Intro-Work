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
*    Actual:     3.0 hrs
*       The most difficult part comprised figuring out how to code
* the math for adding all the multiples together, including how to
* code the loop. First I tried if statements with a for loop, then a
* nested for loop, and finally a few iterations of a do-while loop.
* While I didn't use my accessors and mutators, I left them in for
* later use, if need be. Presumably, the do-while loop works best
* in this situation because I need the loop to run at least one time
* while the if statement may not evaluate every time.
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
