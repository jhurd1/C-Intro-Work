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
* I found help at   //https://www.geeksforgeeks.org/sum-multiples-number-n/
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
*Others
***********************************************************************/
void prompt()//Line 77 is the point of failure. By trying to pass in multiple, the rest of the program could not discern which multiple it needed.
   {
      std::cout << "What multiples are we adding? " << std::endl;
      std::cin >> multiple;
   }
   
   int doingTheMath()
   {
      doTheMath = limit / multiple;//limit was okay in output; we're not getting multiple for some reason
      //int doMoreMath = getMultiple() * doTheMath;
      return doTheMath;
   }
   
void display()
   {
      std::cout << "The sum of multiples of  " << multiple << " less than 100 are: " << doingTheMath() << std::endl;
   }
};

/***********************************************************************
*Main
***********************************************************************/
int main()
{
   Loopy loop;
   loop.prompt();
   loop.display();
}
