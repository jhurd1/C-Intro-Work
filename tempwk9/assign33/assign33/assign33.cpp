/***********************************************************************
* Program:
*    Assignment 33, POINTERS
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a
*    Estimated:  1.0 hrs
*    Actual:     32 hrs
*       The most difficult part comprised
************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
/************************************************************************
*prompt to fill the accounts
************************************************************************/
float promptSue()//account needs to be here?
{
   float sue;
   std::cout << "What is Sue's balance?  ";
   std::cin >> sue;
   return sue;
}

/************************************************************************
*prompt to fill the accounts
************************************************************************/
float promptSam()//account needs to be here?
{
   float sam;
   std::cout << "What is Sam's balance?  ";
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
*calculate the cost
************************************************************************/
float calculate(float *pAccount, float sam, float sue, float dinner, float movie, float iceCream)
{
   float account;
   pAccount = &account;//float account;//to meet this challenge, account needs to go here for total
   //but the problem is, how do you do math with a pointer against sam and sue which are plain floats?
   if(sue > sam)
     {
        std::cout << "Sam's balance: " <<  "$" << sam << std::endl;
        account = (dinner + movie + iceCream) - sue;
        std::cout << "Sue's balance: " <<  "$" << account << std::endl;
     } else
     {
        //account = sam;
        account = (dinner + movie + iceCream) - sam;
        std::cout << "Sam's balance: " <<  "$" << account << std::endl;
        std::cout << "Sue's balance: " <<  "$" << sue << std::endl;
     }
   return account;
}

/************************************************************************
*calculate the cost
************************************************************************/
float balance(float sam, float sue)
{
   
   return 0;
}
/************************************************************************
*Reduce the value of the debit card according to the cost of the date
************************************************************************/
float date()
{
   float dinner;
   float movie;
   float iceCream;
   std::cout << "\tDinner:" << std::setw(5) << " ";
   std::cin >> dinner;
   std::cout << "\tMovie:" << std::setw(5) << " ";
   std::cin >> movie;
   std::cout << "\tIce Cream:" << std::setw(5) << " ";
   std::cin >> iceCream;
   return 0;
}

/************************************************************************
*main() leverage main to do much of the passing of values by holding them in variables
************************************************************************/
int main()
{
   float account, dinner, movie, iceCream;
   float *pAccount = &account;
   float sam = promptSam();
   float sue = promptSue();
   displayHeader();
   float temp = date();
   float calc = calculate(&account, sam, sue, dinner, movie, iceCream);
}
