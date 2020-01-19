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

/****************************************
* iterator() does the job of repeating the output string
* so I don't have to keep retyping or pasting it.
****************************************/
std::string TaxBracket::iterator(){
   std::string displayBracket = "Your tax bracket is: ";
      std::cout << displayBracket;
      return displayBracket;
   }

/****************************************
* GetBrackets() needs to parse per array element in
* setBrackets() for this to work. Otherwise, I will need
* to establish a different getter for each of six brackets.
****************************************/
int TaxBracket::getBrackets(int brackets[5]){
   for(int i = 0; i <= 5; i++){
      brackets[0] = bracket1;
      brackets[1] = bracket2;
      brackets[2] = bracket3;
      brackets[3] = bracket4;
      brackets[4] = bracket5;
      brackets[5] = bracket6;
   }
   return 0;
}

/****************************************
 * setBrackets() calls getIncome() and sets the tax
 * bracket based on the user input.
 ****************************************/
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
         std::cout << iterate.getBrackets(int brackets[0]) << "%";
         break;
      case 2:
          std::cout << iterate.getBrackets(int brackets[1]) << "%";
         break;
      case 3:
          std::cout << iterate.getBrackets(int brackets[2]) << "%";
         break;
      case 4:
          std::cout << iterate.getBrackets(int brackets[3]) << "%";
         break;
      case 5:
          std::cout << iterate.getBrackets(int brackets[4]) << "%";
         break;
      case 6:
         std::cout << iterate.getBrackets(int brackets[5]) << "%";
         break;
   }
   std::cout << iterate.iterator() << income << std::endl;
}

/*****************************************
* GetIncome() prompts for income and stores it in
* the private income variable, enabling the program to
* effectively access that private member.
*****************************************/
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

/*****************************************
* Main() calls display(), which is going to call
* setBrackets().
*****************************************/
void TaxBracket::display(){
   TaxBracket temp;
   temp.setBrackets(bracket1,
                    bracket2,
                    bracket3,
                    bracket4,
                    bracket5,
                    bracket6);
}

/*****************************************
 * As it stands, main() should only have to call display()
 * to get the ball rolling.
 *****************************************/
int main()
{
   TaxBracket test;
   test.display();
}
