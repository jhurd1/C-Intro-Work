/***********************************************************************
* Program:
*    Project 12, Sudoku First Draft
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program
*    Estimated:  1.0 hrs
*    Actual:     2.0 hrs
*      Please describe briefly what was the most difficult part:
************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>

/***********************************************************************
* displayHeader
************************************************************************/
 void displayHeader()
{
   std::cout << "A B C D E F G H I" << std::endl;
}

/***********************************************************************
* read
************************************************************************/
void read(std::string fileName, int board[9][9])
{
   std::cout << "Where is your board located?";
   std::cin >> fileName;
   std::ifstream fin(fileName);
   fin.open(fileName);
   do
   {
      if(fin.fail())
      {
         std::cerr << "failed read.";
          fin.close();
         break;
      } else
      {
         std::cout << board;
      }
   }while(fin >> board[9][9]);
}
/***********************************************************************
* main
************************************************************************/
int main()
{
   std::string fileName = "";
   int board[9][9];
   read(fileName, board);
}
