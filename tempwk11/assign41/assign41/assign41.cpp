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
   std::cout << "Number of characters.";
   std::getline(std::cin, test);
   std::cout << "Enter text: ";
   std::getline(std::cin, test2);
   int i = 0;
   //std::cout << test << " " << test2; Success!
   //for(i = 0; i < sizeof(vecStrings);i++)
   //{
      vecStrings.push_back(test);
      vecStrings.push_back(test2);
//}
   //std::cout << vecStrings[i] << " " << " " << test2;
   return 0;
}
/************************************************************************
*main
************************************************************************/
int main()
{
   std::string test = "";
   std::string test2 = "";
    std::vector<std::string> vecStrings;
   prompt(test, test2, vecStrings);
   //storeStringInVec(test, test2, vecStrings);
}
