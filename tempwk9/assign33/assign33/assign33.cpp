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
   std::cout << "What is Sam's balance?  " << std::endl;
   std::cin >> sam;
   std::cout << "What is Sue's balance?  " << std::endl;
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
*Reduce the value of the debit card according to the cost of the date
************************************************************************/
//The * symbol refers to both the address-of (when declaring a pointer) and * retrieval ("derefer-
//ence") from the given address
void date(float *pAccount)//Here we declare the pAccount as a master copy or "weblink" of a resume
//using the address-of symbol
{
   float account = 0;
   float sam = 0;
   float sue = 0;
   pAccount = &account;//get the address of account with the alias or "address-of" char: &
   std::cout << *pAccount;//retrieve the data pAccount points to using the "dereference" or retrieval operator.
   std::cout << "\tDinner:" << std::setw(5) << " " << std::endl;
   std::cout << "\tMovie:" << std::setw(5) << " " << std::endl;
   std::cout << "\tIce Cream:" << std::setw(5) << " " << std::endl;
   prompt(sam, sue);
   if(sue > sam)
   {
      //set the account to sue
     //deduct from sue
   } else
   {
      //set the account to sam
      //deduct from sam
   }
   //output the remainder of sam
   //output the remainder of sue
}

/************************************************************************
*main()
************************************************************************/
int main()
{
   displayHeader();
}
