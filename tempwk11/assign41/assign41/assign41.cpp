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
*prompt
************************************************************************/
std::vector<std::string>* prompt(std::string test, std::string test2, std::vector<std::string> vecStrings)
{
   std::cout << "Number of characters: ";
   std::getline(std::cin, test);
   int j = std::atoi(test.c_str());
      if(j < 0)
      {
         std::cout << "Allocation failure!\n";
      } else if (j > 0)
      {
         std::cout << "Enter Text: ";
         std::getline(std::cin, test2);
         vecStrings.push_back(test2);
      }
   for(auto it = vecStrings.cbegin(); it != vecStrings.cend(); it++)
   {//possibly a nested for loop here would control iteration to "j"
      for(int i = 0; i <= j; i++)
      {
         if(j >= vecStrings.size())
         {
            break;
         } else
         {
             std::cout << "Text: " << *it << "\n";
         }
      }
      }
   return 0;
   }
/************************************************************************
*main
************************************************************************/
int main()
{
   std::string test = "";
   std::string test2 = "";
   try{
      std::vector<std::string> vecStrings;
      prompt(test, test2, vecStrings);
   } catch(std::bad_alloc& bad)
   {
      std::cerr << "Allocation failure!" << "\n";
   }
}
