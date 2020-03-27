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
void read(std::string fileName, int board[9][9], int row, int column)
{
   std::string temp = "";
   std::cout << "Where is your board located? ";
   std::cin >> fileName;
   std::ifstream fin(fileName);
   fin.open(fileName);
   for(int i = 0; i < row; i++)
   {
      for(int j = 0; j < column; j++)
      {
         //fscanf(fin, "%d", &board[i][j]);
         printf("%d", board[i][j]);
      }
   }
      /* while(countIntegers < board && fin >> tempInt)
         {
            std::getline(fin, fileName);
            fin >> temp;
            std::cout << temp;
         }*/
      std::cout << std::endl;
      fin.close();
      }
  
   
/***********************************************************************
* main
************************************************************************/
int main()
{
   std::string fileName = "";
   int row = 9;
   int column = 9;
   int board[row][column];
   read(fileName, *board[9], row, column);
}
