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
* displayHeader
************************************************************************/
 void displayHeader()
{
   std::cout << "A B C D E F G H I" << std::endl;
}

/***********************************************************************
* read (and write) test
************************************************************************/
int read(std::string &fileName, int board[9][9])//had to pass by reference to get the value into this function
//and the write()
{
   int row = 9;
   int column = 9;
   std::cout << "Where is your board located? ";
   std::cin >> fileName;
   std::ifstream fin(fileName.c_str());
   fin.open(fileName);
   std::ofstream fout("/volumes/jaoshu2/byu-i/test.txt");//remove the file addend here for testBed,
   //but keep it for local testing
   fout.open("/volumes/jaoshu2/byu-i/test.txt");
   while(fin.is_open())
   {
      for(int i = 0; i < row; i++)
      {
         for(int j = 0; j < column; j++)
         {
            fin >> board[i][j];//instead of getline(fileName, 9);
            fout << " " << board[i][j];//put a space between the integers
         }
      }
      if(!fin.is_open())
      {
         std::cerr << "Fail." << std::endl;
      }
   }
   fin.close();
   fout.close();
   return board[8][8];
}
   
/***********************************************************************
* write
************************************************************************/
  void write(int board[9][9])
{
   int row = 9;
   int column = 9;
   std::ofstream fout("/volumes/jaoshu2/byu-i/test.txt");//tested using local file path; file created successfully but it's
   //empty
   fout.open("/volumes/jaoshu2/byu-i/test.txt");
   for(int i = 0; i < row; i++)
   {
      for(int j = 0; j < column; j++)
      {
   fout << board[i][j];//test.txt appears now in the drive, but nothing was written to it.
      }
   fout.close();
   }
}
   
/***********************************************************************
* main
************************************************************************/
int main()
{
   std::string fileName;
   int board[9][9];
   read(fileName, board);
   //write(board);
}
