/***********************************************************************
* Program:
*    Assign32, Strings
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a
*    Estimated:  1.0 hrs
*    Actual:     24 hrs
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>

/************************************************************************
*count the letters
*************************************************************************/
std::string countLetters(std::string input, std::string test)
{
   int count = 0;
   int j = 0;
   for(int i=0; i < test.size(); i++)
   {
      if(input[j] == test[j])
      {
           count++;
      } else if (input[j] != test[j])
      {
         std::cout << "";
      }
   }
    std::cout << count << std::endl;
      return 0;
}

/************************************************************************
*main
*************************************************************************/
int main()
{
   std::string input;
   std::cout << "Enter a letter: ";
   std::cin.ignore();
   std::getline(std::cin, input);//input here is a letter, which we'll use for the comparison
   std::string test;
   std::cout << "Enter text: ";
   std::cin.ignore();
   std::getline(std::cin, test);
   countLetters(input, test);
}
