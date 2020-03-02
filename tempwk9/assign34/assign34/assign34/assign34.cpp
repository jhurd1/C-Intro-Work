/***********************************************************************
* Program:
*    Assignment 34, POINTER ARITHMETIC
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates an array traversal by address contra array index.
*    Estimated:  1.0 hrs
*    Actual:     2 hrs
*       The most difficult part comprised the comparison. I learned that the way to compare
* an index from one array to the pointer of another involves a syntax like that on line
* 29 and 32.
************************************************************************/
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>

/************************************************************************
*count the letters; const pointers must always refer to the same memory location
*************************************************************************/
char* countLetters(char input[], char test[])//arrays are const pointers
{
   int count = 0;
   for(char *p =test; *p; p++)
      {
         if(input[0] == *p)
         {
              count++;
         } else if (input[0] != *p)
         {
            std::cout << "";
         }
      }
    std::cout << "Number of " << "\'" << input[0] << "\'s: " << count << std::endl;
      return 0;
}

/************************************************************************
*main
*************************************************************************/
int main()
{
   char input[256];
   std::cout << "Enter a letter: ";
   //std::cin.ignore();
   std::cin.getline(input, 256);
   char test[256];
   std::cout << "Enter text: ";
   //std::cin.ignore();
   std::cin.getline(test, 256);
   countLetters(input, test);
}
