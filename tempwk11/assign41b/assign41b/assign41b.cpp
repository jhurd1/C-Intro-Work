/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates an allocation problem.
*    Estimated:  1.0 hrs
*    Actual:     10 hrs
*       The most difficult part comprised outputting to a certain index. I had this passing 3/4 tests
* but when I made changes, I now cannot get it to pass any of the tests. Very disappointing.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <vector>

/************************************************************************
*allocate memory
************************************************************************/
int getNumChars()
{
   int numberOfChars = 0;
   std::cout << "Number of characters: ";
   std::cin >> numberOfChars;
   std::cin.ignore();
   return numberOfChars;
}

void getText(char * &pText, int testNum)
{
   std::cout << "Enter Text: ";
   std::cin.getline(pText, testNum);
}

void display(char * pText)
{
   std::cout << "Text: ";
   for(char * p = pText; *p; p++)
   {
      std::cout << *p;
   }
   std::cout << std::endl;
}

/************************************************************************
*main
************************************************************************/
int main()
{
   int testNum = getNumChars() + 1;
   char * pText;
   try {
      pText = new char[testNum];
   } catch (std::bad_alloc& bad) {
      std::cout << "Allocation failure!" << std::endl;
      return 0;
   }
   getText(pText, testNum);
   //delete [] testNum;
   display(pText);
   delete [] pText;
}
