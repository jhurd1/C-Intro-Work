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
#define ROW 9
#define COLUMN 9;

/***********************************************************************
* prompt
************************************************************************/
std::string prompt(std::string &fileName)
{
   std::cout << "Where is your board located? ";
   std::cin >> fileName;
   return fileName;
}
/***********************************************************************
* displayOptions
************************************************************************/
void displayOptions()
{
   std::cout << "Options:" << std::endl;
   std::cout << "   " << "? " << std::setw(4) << " Show these instructions" << std::endl;//tab works in
   //this program and IDE but fails testBed strangely
   //So I replaced "\t" with spaces
   std::cout << "   D " << std::setw(4) << " Display the board" << std::endl;
   std::cout << "   E " << std::setw(4) << " Edit one square" << std::endl;
   std::cout << "   S " << std::setw(4) << " Show the possible values for a square" << std::endl;
   std::cout << "   Q " << std::setw(4) << " Save and Quit" << std::endl << "\n";
}
/***********************************************************************
* displayHeader
************************************************************************/
 void displayHeader()//and then display the margin line numbers, too
{
   std::cout << "A B C D E F G H I" << std::endl;
}

/***********************************************************************
* read (and write) test
************************************************************************/
int read(std::string &fileName, int board[][9])
{
   std::ifstream fin(fileName);
   if(fin.is_open())
   {
      while(std::getline(fin, fileName))
      {
               std::cout << fileName << "\n";
      }
   }
   fin.close();
   return board[8][8];
}
   
/***********************************************************************
* write
************************************************************************/
  void write(std::string &fileName, int board[][9])
{
   //Brother Schwieder: No file name declared here [for testBed]
   std::ofstream fout;
   fout.open("/volumes/jaoshu2/byu-i/test.txt");
   fout << board;
   fout.close();
}
   
/***********************************************************************
* main
************************************************************************/
int main()
{
   std::string fileName;
   int board[9][9];
   prompt(fileName);
   displayOptions();
   read(fileName, board);
   //write(board);//this is one of the last things to happen in the program
}
