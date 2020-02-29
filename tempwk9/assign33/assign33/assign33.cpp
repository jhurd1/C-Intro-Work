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
float prompt(float sam, float sue)//account needs to be here?
{
   std::cout << "What is Sam's balance?  ";
   std::cin >> sam;
   std::cout << "What is Sue's balance?  ";
   std::cin >> sue;
   return sue;
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
float calculate(float *pAccount, float account, float sam, float sue, float dinner, float movie, float iceCream)
{
   float total;
   pAccount = &account;//store account's address in the account pointer
   if(sue > sam)
     {
        account = sue;
        total = (dinner + movie + iceCream) - sue;
     } else
     {
        account = sam;
        total = (dinner + movie + iceCream) - sam;
     }
   return total;
}

float balance(float sam, float sue)
{
   std::cout << "Sam's balance: " <<  "$" << sam << std::endl;
   std::cout << "Sue's balance: " <<  "$" << sue << std::endl;
   return 0;
}
/************************************************************************
*Reduce the value of the debit card according to the cost of the date
************************************************************************/
void date(float *pAccount, float account, float sam, float sue, float dinner, float movie, float iceCream)//Here we declare the pAccount as a master copy or "weblink" of a resume
//using the address-of symbol
{
   pAccount = &account;
   std::cout << "\tDinner:" << std::setw(5) << " ";
   std::cin >> dinner;
   std::cout << "\tMovie:" << std::setw(5) << " ";
   std::cin >> movie;
   std::cout << "\tIce Cream:" << std::setw(5) << " ";
   std::cin >> iceCream;
   //calculate(pAccount, account, sam, sue, dinner, movie, iceCream);
   balance(sam, sue);
}

/************************************************************************
*main() leverage main to do much of the passing of values by holding them in variables
************************************************************************/
int main()
{
   float sam, sue, account, dinner, movie, iceCream, *pAccount;
   prompt(sam, sue);
   displayHeader();
   date(pAccount, account, sam, sue, dinner, movie, iceCream);
}
