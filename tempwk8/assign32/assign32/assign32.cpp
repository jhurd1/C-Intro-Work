/***********************************************************************
* Program:
*    Assignment 32, Strings
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a string comparison using chars.
*    Estimated:  1.0 hrs
*    Actual:     24 hrs
*       The most difficult part comprised the bad memory access, which I fixed by placing a pointer
* in the function's signature after changing from std::string to char[]. ignore() was popping off
* the first letter in the array, causing issues, so I commented that out for a fix.
************************************************************************/
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>

/************************************************************************
*count the letters
*************************************************************************/
char* countLetters(char input[], char test[])//placing a pointer in the signature of this function dissolved the bad access error
{//but the function is still not counting the matching letters
   int count = 0;
      for(int i=0; test[i]; i++)
      {
         if(input[0] == test[i])
         {
              count++;
         } else if (input[i] != test[i])
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
