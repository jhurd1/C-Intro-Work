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
   return 0;
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
float calculate(float *pAccount)
{
   float account = 0;
   float dinner = 0;
   float movie = 0;
   float iceCream = 0;
   float total;
   pAccount = &account;
   float sam = 0;
   float sue = 0;
   if(sue > sam)
     {
        account = sue;
        total = (dinner + movie + iceCream) - sue;
        //set the account to sue
       //deduct from sue
     } else
     {
        account = sam;
        total = (dinner + movie + iceCream) - sam;
        //set the account to sam
        //deduct from sam
     }
   return total;
     //output the remainder of sam
     //output the remainder of sue
}

/************************************************************************
*Reduce the value of the debit card according to the cost of the date
************************************************************************/
//The * symbol refers to both the address-of (when declaring a pointer) and * retrieval ("derefer-
//ence") from the given address. Therefore, if it's an instantiation of, it's an address-of, otherwise
//it's a retrieval-from.
void date(float *pAccount)//Here we declare the pAccount as a master copy or "weblink" of a resume
//using the address-of symbol
{
   
   float account = 0;
   pAccount = &account;
   float dinner = 0;
   float movie = 0;
   float iceCream = 0;
   displayHeader();
   /*pAccount = &account;//get the address of account with the alias or "address-of" char: &
   std::cout << *pAccount;//retrieve the data pAccount points to using the "dereference" or retrieval operator.*/
   std::cout << "\tDinner:" << std::setw(5) << " ";
   std::cin >> dinner;
   std::cout << "\tMovie:" << std::setw(5) << " ";
   std::cin >> movie;
   std::cout << "\tIce Cream:" << std::setw(5) << " ";
   std::cin >> iceCream;
   calculate(pAccount);
}

float balance(float sam, float sue)
{
   std::cout << "Sam's balance: " <<  "$" << sam << std::endl;
   std::cout << "Sue's balance: " <<  "$" << sue << std::endl;
   return 0;
}


/************************************************************************
*main()
************************************************************************/
int main()
{
   float account;
   float *pAccount;
   pAccount = &account;
   float sam, sue;
   prompt(sam, sue);
   date(pAccount);
   balance(sam, sue);
}
