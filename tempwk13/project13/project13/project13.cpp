/***********************************************************************
* Program:
*    Project 13, Sudoku
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
* sudokuSquareEditor
************************************************************************/
void editSquare(char& charColumn, char& charRow, int & rowIndex, int & columnIndex)
{
   std::string square;
   std::cout << "What are the coordinates of the square: " << std::endl;
   std::cin >> square;
   
   if(isalpha(square[0]))//compensate for user char misplacement
   {
      charColumn = toupper(square[0]);
      charRow = toupper(square[1]);
   } else
   {
      charColumn = toupper(square[1]);
      charRow = toupper(square[0]);
   }
   
   rowIndex = int(charRow);//make the rowIndex hold the char of the row cast as an int
   columnIndex = int(charColumn);//similarly
   
   //handle inappropriate input
   if(rowIndex < 0 || rowIndex > 8 || columnIndex < 0 || columnIndex > 8)
   {
      std::cout << "Error" << "\n";
      editSquare(charColumn, charRow, rowIndex, columnIndex);
   }
   return;
}

/************************************************************************
* translateValues
************************************************************************/
void translateValues(int board[][9], int x, int y, int valuesInt[9])
{
   
}

/************************************************************************
* possibleValues
* put the string inside the pop_back()
* call editSquare()
************************************************************************/
int possibleValues(int board[][9], char& charColumn, char& charRow, int& rowIndex, int& columnIndex)
{
   //int x = 0;
   //int y = 0;
   int valuesInt[9];
   //char coordinate[3];
   editSquare(charColumn, charRow, rowIndex, columnIndex);
   
   //translateValues(board, x, y, valuesInt); call here
   std::string values = "";
   for(int i = 0; i < 9; i++)
   {
      if(valuesInt[i] != 0)
      {
         values += valuesInt[i] + ',';
         values.pop_back();
      }
      
      std::cout << "The possible values for '" << charColumn << " and " << charRow << "' are: '" << values;
   }
   return valuesInt[8];
}

/***********************************************************************
* displayHeader
************************************************************************/
 void displayBoard(int board[][9])//shows garbage output
{
   std::cout << "   A B C D E F G H I" << std::endl;
   std::string grid = "   -----+-----+-----";
   int lineNumber = 1;
   for(int x = 0; x < 9; x++)
   {
      std::cout << x + 1 << "  ";//this gets the first row number correct
      for(int y = 0; y < 9; y++)
      {
         std::cout << (board[x][y] == 0 ? ' ' : (char)(board[x][y] + 48));//this gets the first digit in the table correct
         std::cout << (y == 2 || y == 5 ? '|' : (y == 8 ? '\n' : ' '));
         //std::cout << lineNumber << "  " << board[x][y] - 48;//this gets the second digit in the table wrong
         //literally returning 41, the answer of 48 - 7.
         //lineNumber++;
         //not sure what lines 108 and 110 were supposed to do, but they were responsible for the  garbage
         //output
      }
      //std::cout << std::endl;//added an unnecessary carriage return
      std::cout << (x == 2 || x == 5 ? grid + "\n" : "");
   }
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
* pass those values as reference to make them changeable
************************************************************************/
void displayOptions(int board[][9], char& charColumn, char& charRow, int & rowIndex, int & columnIndex)
{
   //char option = ' ';
   std::cout << "Options:" << std::endl;
   std::cout << "   " << "? " << std::setw(4) << " Show these instructions" << std::endl;
   std::cout << "   D " << std::setw(4) << " Display the board" << std::endl;
   std::cout << "   E " << std::setw(4) << " Edit one square" << std::endl;
   std::cout << "   S " << std::setw(4) << " Show the possible values for a square" << std::endl;
   std::cout << "   Q " << std::setw(4) << " Save and Quit" << std::endl << "\n";
   //std::cin >> option;
}

/************************************************************************
* interactions
************************************************************************/
void interactions(int board[][9], char& charColumn, char& charRow, int & rowIndex, int & columnIndex)
{
   char option = ' ';
   std::cout << "> ";
   std::cin >> option;
   if(option == 'D' || option == 'd')
   {
      displayBoard(board);
   } else if (option == 'E' || option == 'e')
   {
      editSquare(charColumn, charRow, rowIndex, columnIndex);
   } else if (option == 'S' || option == 's')
   {
      possibleValues(board, charColumn, charRow, rowIndex, columnIndex);
   } else if(option == 'Q' || option == 'q')
   {
      write(board);
   } else if(option == '?')
   {
      displayOptions(board, charColumn, charRow, rowIndex, columnIndex);
   } else
   {
      std::cout << "ERROR: Invalid command";
   }
}

/***********************************************************************
* read test
************************************************************************/
void read(int board[][9])
{
    std::string fileName;
    std::cout << "Where is your board located? ";
    std::cin >> fileName;
   std::ifstream fin(fileName.c_str());
   if(fin.fail())
   {
      std::cout << "Error opening.";
      fin.close();
      return;
   }
  for(int row = 0; row < 9; row++)
   {
      for(int column = 0; column < 9; column++)
      {
         
         fin >> board[row][column];
         //std::cout << board[row][column];//confirms that the program is opening
         //and reading the file successfully
      }
    }
    fin.close();
}
   

/***********************************************************************
* main
************************************************************************/
int main()
{
   char charColumn = ' ';
   char charRow = ' ';
   int rowIndex = 0;
   int  columnIndex = 0;
   int board[9][9];
   read(board);
   displayOptions(board, charColumn, charRow, rowIndex, columnIndex);
   displayBoard(board);
   //interactions(board, charColumn, charRow, rowIndex, columnIndex);
}
