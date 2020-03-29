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
   int line = 1;
         for (int x=0; x < 9; x++) {//rows = x
            if(x == 1)//intersection line at rows 4 and 7
            {
               std::cout << "   -----+-----+-----" << std::endl;
            } else
            {
               std::cout << line << " " << board[x];
            }
             for (int y=0; y < 9; y++) {//columns = y
                if(y == 2 || y == 3)//vertical bar at columns 5 and 9
                {
                   std::cout << "|";
                }
                      std::cout << line << "  " << board[y];
                }
                  line++;
             }
             std::cout << std::endl;
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
  void write(int board[9][9])
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
* main
************************************************************************/
int main()
{
   int board[9][9];
   read(board);
   displayOptions();
   displayBoard(board);
   write(board);//this is one of the last things to happen in the program
}
