/***********************************************************************
* Program:
*    Assignment 40, MULTI-DIMENSIONAL ARRAYS
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates
*    Estimated:  1.0 hrs
*    Actual:     2 hrs
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

/************************************************************************
* getFileName
************************************************************************/
std::string getFileName()
{
   std::string fileName;
   std::cout << "Enter source file name: ";
   std::cin >> fileName;
   return fileName;
}

/************************************************************************
* getWriteFileName
************************************************************************/
std::string getWriteFileName()
{
   std::string writeFileName;
   std::cout << "Enter destination filename: ";
   std::cin >> writeFileName;
   return writeFileName;
}

/************************************************************************
* writeToFile "stores" or writes to a file the tic tac toe results.
************************************************************************/


/************************************************************************
* readFile
************************************************************************/
std::string readFile(std::string fileName)
{
   std::ifstream fin(fileName);
   std::string line;
   //fin.open(fileName);//opening the file here broke the loop below so it never evaluated
   while(std::getline(fin, line))//loop not evaluating
   {
      if(fin.fail())
      {
         return 0;
      } else
      {
         fin >> line;
         std::cout << "Line: " << line;
         fin.close();
      }
   }
   return line;
}

/************************************************************************
* display
************************************************************************/
void display(std::string ticTacToe[][25])
{
   
}

/************************************************************************
*main()--a "driver"
************************************************************************/
int main()
{
   std::string fileName;
   std::string writeFileName;
   std::string temp;
   std::string ticTacToe[25][25];
   temp = getFileName();
   readFile(temp);
   //getWriteFileName();
}
