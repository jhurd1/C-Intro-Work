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
*    Actual:     1.5 hrs
*       The most difficult part comprised deciding whether I'll be docked points
* for using a switch statement instead of if statements.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include "assignment16.h"

void TaxBracket::setIncome(int income){
   this->income = income;
}

std::string TaxBracket::iterator(){
   std::string displayBracket = "Your tax bracket is: ";
      std::cout << displayBracket;
      return displayBracket;
   }

void TaxBracket::setBrackets(const int bracket1,
const int bracket2,
const int bracket3,
const int bracket4,
const int bracket5,
                 const int bracket6){
   TaxBracket iterate;
   int income = iterate.getIncome();
   switch(income){
      case 1:
         std::cout << bracket1 << "%";
         break;
      case 2:
          std::cout << bracket2 << "%";
         break;
      case 3:
          std::cout << bracket3 << "%";
         break;
      case 4:
          std::cout << bracket4 << "%";
         break;
      case 5:
          std::cout << bracket5 << "%";
         break;
      case 6:
         std::cout << bracket6 << "%";
         break;
   }
   std::cout << iterate.iterator() << income << std::endl;
}

int TaxBracket::getIncome(){
   int income;
   std::cout << "Income: ";
   std::cin >> income;
   return income;
}
//default constructor
TaxBracket::TaxBracket()
{
   
}
//non-default constructor
TaxBracket::TaxBracket(int income)
{
   
}

void TaxBracket::display(){
   TaxBracket temp;
   temp.setBrackets(bracket1,
                    bracket2,
                    bracket3,
                    bracket4,
                    bracket5,
                    bracket6);
}

int main()
{
   TaxBracket test;
   test.display();
}
