/***********************************************************************
* Program:
*    Project 12, Sudoku First Draft
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program outputs Sudoku board without error checks.
*    Estimated:  1.0 hrs
*    Actual:     15.0 hrs
*      Please describe briefly what was the most difficult part: Everything!
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
* displayHeader
************************************************************************/
 void displayBoard(int board[][9])//and then display the margin line numbers, too
{
   std::string grid = "   -----+-----+-----";
   int lineNumber = 1;
   for(int x = 0; x < 9; x++)
   {
      for(int y = 0; y < 9; y++)
      {
         if(x == 4 || x == 8)
         {
            std::cout << grid;
         }
         if(y == 5 || y == 9)
         {
            std::cout << "|";
         }
         if(y % 10 == 9)
         {
            std::cout << std::endl;
         }
         if(x > 11)
         {
            break;//stop print lines after the eleventh one
         }
         std::cout << lineNumber << "  " << board[x][y] - 48;
         lineNumber++;
      }
   }
             std::cout << std::endl;
}

/***********************************************************************
* write
************************************************************************/
  void write(int board[][9])
  {
      std::string fileName;
      std::cout << "What file would you like to write your board to: ";
      std::cin >> fileName;
      std::ofstream fout(fileName);
      
      for (int x=0; x < 9; x++) {
          for (int y=0; y < 9; y++) {
              fout << board[x][y]; // writes board char by char to output file
          }
          fout << std::endl; //writes new line at end of each row
      }
      fout.close();
  }

/***********************************************************************
* displayOptions
************************************************************************/
void displayOptions(int board[][9])
{
   char option = ' ';
   std::cout << "Options:" << std::endl;
   std::cout << "   " << "? " << std::setw(4) << " Show these instructions" << std::endl;
   std::cout << "   D " << std::setw(4) << " Display the board" << std::endl;
   //std::cin >> option;
   std::cout << "   E " << std::setw(4) << " Edit one square" << std::endl;
   //std::cin >> option;
   std::cout << "   S " << std::setw(4) << " Show the possible values for a square" << std::endl;
   //std::cin >> option;
   std::cout << "   Q " << std::setw(4) << " Save and Quit" << std::endl << "\n";
   //std::cin >> option;
   if(option == 'D' || option == 'd')
   {
      std::cin >> option;
      displayBoard(board);
   } else if (option == 'E' || option == 'e')
   {
      std::cin >> option;
   } else if (option == 'S' || option == 's')
   {
      std::cin >> option;
   } else if(option == 'Q' || option == 'q')
   {
      std::cin >> option;
      write(board);
   }
    std::cout << "   A B C D E F G H I" << std::endl;
}

/***********************************************************************
* read test
************************************************************************/
void read(int board[][9])
{
    std::string fileName;
    std::string line;
    int x=0, y=0;
     
    std::cout << "Where is your board located? ";
    std::cin >> fileName;
    std::ifstream fin(fileName);
    while(getline(fin, line)) {
        for (int i=0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                board[x][y] = int(line[i])-48; // converts char number to its int equivalent
                y++;
            }
        }
        x++;
        y=0;
    }
    fin.close();
}
   
/***********************************************************************
* main
************************************************************************/
int main()
{
   int board[9][9];
   read(board);
   displayOptions(board);
}