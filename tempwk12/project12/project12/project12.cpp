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
 void displayBoard(int board[][9])//and then display the margin line numbers, too
{
   std::cout << "   A B C D E F G H I" << std::endl;
   for(int row = 0; row < 9; row++)
   {
      int i = 0;
      std::cout << i + 1 << "  ";//display line numbers??
      for(int column = 0; column < 9; column++)
      {
         if(column == 0)
         {
            //print row number and spaces
            std::cout << board[row][column];
         }
         if(column == 2 || column == 5)
         {
            //print a bar
            std::cout << "|";
         } else if (column != 8)
         {
            //print a space
            std::cout << " ";
         }
        /* if(row % 10 == 4 || row % 10 == 8)
         {
            std::cout << "   ----+----+----" << std::endl;
         }
         //Maybe try '?' again later: syntax: "condition ? result_if_true : result_if_false"
         if(column % 10 == 12)
         {
            std::cout << std::endl;
         } else if(column % 10 == 5 || column % 10 == 9)
         {
            std::cout << "|";
         } else
         {*/
         std::cout << std::endl;
         }
      }
   }


/***********************************************************************
* read test
************************************************************************/
void read(int board[9][9])
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
   displayBoard(board);
   read(board);
   //write(board);//this is one of the last things to happen in the program
}
