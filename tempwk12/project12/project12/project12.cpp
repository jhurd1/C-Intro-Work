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
* read
************************************************************************/
void read(std::string fileName, int board[9][9])
{
   int row = 9;
   int column = 9;
   std::string temp = "";
   std::cout << "Where is your board located? ";
   std::cin >> fileName;
   std::ifstream fin(fileName.c_str());
   fin.open(fileName);
   while(fin)//still can't get this method to work. Moving on in the interest of time.
   {
      for(int i = 0; i < row; i++)
      {
         for(int j = 0; j < column; j++)
         {
            fin >> board[i][j];//instead of getline(fileName, 9);
            printf("%d", board[i][j]);
         }
      }
      if(!fin.is_open())
      {
         std::cerr << "Fail." << std::endl;
      }
      fin.close();
   }
}
   
/***********************************************************************
* write
************************************************************************/
  void write(std::string fileName)
{
   int temp = 0;
   std::ofstream fout(fileName);//tested using local file path; file created successfully but it's
   //empty
   /*if(fout.fail())
   {
      std::cerr << "failed.";
   }*/
   fout.open(fileName);
   fout << temp;//test.txt appears now in the drive, but nothing was written to it.
   fout.close();
}
   
/***********************************************************************
* main
************************************************************************/
int main()
{
   std::string fileName = "";
   //int row = 9;
   //int column = 9;
   int board[9][9];
   read(fileName, board);
   write(fileName);
}
