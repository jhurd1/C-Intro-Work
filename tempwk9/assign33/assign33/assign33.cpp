/***********************************************************************
* Program:
*    Assignment 33, POINTERS
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates practice with pass by address (pointer) and pass by value.
*    Estimated:  1.0 hrs
*    Actual:     3 hrs
*       The most difficult part comprised figuring out how to pass by value the ice cream, dinner,
* and movie. Once I deposited those into the total variable as a container, I succeeded in pass-
* ing them between main, date, and calculate.
************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
/************************************************************************
*prompt to fill the accounts
************************************************************************/
float promptSue()
{
   float sue;
   std::cout << "What is Sue's balance? ";
   std::cin >> sue;
   return sue;
}

/************************************************************************
*prompt to fill the accounts
************************************************************************/
float promptSam()
{
   float sam;
   std::cout << "What is Sam's balance? ";
   std::cin >> sam;
   return sam;
}

/************************************************************************
*display the header detail
************************************************************************/
void displayHeader()
{
   std::cout << "Cost of the date:" << std::endl;
}

/************************************************************************
*Reduce the value of the debit card according to the cost of the date
************************************************************************/
float date(float dinner,
float movie,
float iceCream)
{
   std::cout << "\tDinner:" << std::setw(4) << " ";
   std::cin >> dinner;
   std::cout << "\tMovie:" << std::setw(5) << "  ";
   std::cin >> movie;
   std::cout << "\tIce cream:"  << " ";
   std::cin >> iceCream;
   float total = dinner + movie + iceCream;
   return total;
}

/************************************************************************
*calculate the cost
************************************************************************/
float calculate(float *pAccount, float sam, float sue,  float total)
{
   float account = 1;
   pAccount = &account;//pass by reference can be held in memory on the heap//tested with "2" from main; it's successful
   if(sue > sam)
     {
        std::cout << "Sam's balance: " <<  "$" << sam << std::endl;
        account = sue - (total);
        std::cout << "Sue's balance: " <<  "$" << account << std::endl;
     } else
     {
        //account = sam;
        account = sam - (total);
        std::cout << "Sam's balance: " <<  "$" << account << std::endl;
        std::cout << "Sue's balance: " <<  "$" << sue << std::endl;
     }
   return account;
}

/************************************************************************
*main() leverage main to do much of the passing of values by holding them in variables
************************************************************************/
int main()
{
   float account, dinner, movie, iceCream, total;
   float *pAccount = &account;
   account = 2;
   float sam = promptSam();
   float sue = promptSue();
   displayHeader();
   total = date(dinner, movie, iceCream);//encapsulating this in a var and returning the total from it allowed me to pass by value into calculate
   calculate(&account, sam, sue, total);
}
