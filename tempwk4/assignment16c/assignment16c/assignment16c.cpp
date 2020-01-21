/***********************************************************************
* Program:
*    Assignment 16, If Statements
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a tax bracket determination algorithm.
*
*    Estimated:  1.0 hrs
*    Actual:     3 hrs
*       The most difficult part comprised figuring out how to get an array to work for me.
* After spending a larger block of time researching why I couldn't seem to get my array
* (holding the bracket variables as elements), I scrapped that effort and moved on.
************************************************************************/
#include <stdio.h>
#include <iostream>

/**********************************************************************
* Class Brackets contains only essential members.
 *********************************************************************/
class Brackets{
public:
      int income;
      int bracket1 = 10;
      int bracket2 = 15;
      int bracket3 = 25;
      int bracket4 = 28;
      int bracket5 = 33;
      int bracket6 = 35;
   
   //Default constructor
   Brackets(){
      
   }
 
   //iterator repeats a phrase
std::string iterator()
{
   std::string displayBracket = "Your tax bracket is ";
   return displayBracket;
}

   /**********************************************************************
   * Compute the tax bracket conjunctive with a call to iterator.
    *********************************************************************/
int computeTax(int income){
   Brackets calc;
   std::cout << "Income: ";
   std::cin >> income;
   if((income > 0) && (income < 15100))
   {
      std::cout << calc.iterator() << bracket1 << "%" << std::endl;
   }
   if((income > 15100) && (income < 61300))
   {
      std::cout << calc.iterator() << bracket2 << "%" << std::endl;
   }
   if((income > 61300) && (income < 123700))
   {
      std::cout << calc.iterator() << bracket3 << "%" << std::endl;
   }
   if((income > 123700) && (income < 188450))
   {
       std::cout << calc.iterator() << bracket4 << "%" << std::endl;
   }
   if((income > 188450) && (income < 336550))
   {
      std::cout << calc.iterator() << bracket5 << "%" << std::endl;
   }
   if(income > 336550){
      std::cout << calc.iterator() << bracket6 << "%" << std::endl;
   }
   return income;
   }
};

/**********************************************************************
* Main spins it all up with an inital call to computeTax().
 *********************************************************************/
int main()
{
   int income = 0;
   Brackets run;
   run.computeTax(income);
}
