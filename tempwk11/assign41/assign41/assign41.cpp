/***********************************************************************
* Program:
*    Assignment 41, Allocating Memory
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates
*    Estimated:  1.0 hrs
*    Actual:     10 hrs
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <vector>
/************************************************************************
*storeStringInVec
************************************************************************/
void storeStringInVec(std::string test, std::string test2, std::vector<std::string> vecStrings)
{
   
}

/************************************************************************
*prompt
************************************************************************/
std::vector<std::string>* prompt(std::string test, std::string test2, std::vector<std::string> vecStrings)
{
   std::cout << "Number of characters: ";
   std::getline(std::cin, test);
   //if(vecStrings.size() <= 0)
   int j = std::atoi(test.c_str());
   for(int i = 0; i <= j; i++){
      if(j < 0)
      {
         std::cout << "Allocation failure!\n";
      } else if(j > 0)
      {
         std::cout << "Enter Text: ";
         std::getline(std::cin, test2);
         //vecStrings.push_back(test);
         vecStrings.push_back(test2);
         while(j < vecStrings.size())
         {
             std::cout << "Text: " << test2 << std::endl;
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
