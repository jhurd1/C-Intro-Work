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
#include <algorithm>
#include<iterator>
#define ROW 9
#define COLUMN 9;

/**********************************************************************
* I had to encapsulate all functions in a class to keep recursive function calls.
**********************************************************************/
class Sudoku{
/***********************************************************************
* sudokuSquareEditor
************************************************************************/
public:
   
   void editSquare(int board[][9], char& charColumn, char& charRow, int & rowIndex, int & columnIndex)
{
   std::string square;
   std::cout << "What are the coordinates of the square: ";
   std::cin >> square;//program stops here on (B2) second iteration after error on A1 input
   
   if(isalpha(square[0]))//compensate for user char misplacement
   {
      charColumn = toupper(square[0]);
      charRow = toupper(square[1]);
   } else
   {
      charColumn = toupper(square[1]);
      charRow = toupper(square[0]);
   }
   rowIndex = int(charRow) - 49;//make the rowIndex hold the char of the row cast as an int
   columnIndex = int(charColumn) - 65;
   
   //I first attempted to use std::stoi(square) != 0 but this resulted in an unhandled exception
   if(board[rowIndex][columnIndex] != 0)
   {
      std::cout << "ERROR: " << "Square " << "'" << square << "'" << " is filled" << std::endl;
      std::cout << std::endl;
      return;
   }
   //handle inappropriate input
   if(rowIndex < 0 || rowIndex > 8 || columnIndex < 0 || columnIndex > 8)
   {
      //ERROR: Value '2' in square 'B2' is invalid
      std::cout << "ERROR: Value " << "'" << square << "'" << "is invalid" << std::endl;
      //write an if condition to see if the square already has a value
      editSquare(board, charColumn, charRow, rowIndex, columnIndex);
   } else
   {
      possibleValues(board, charColumn, charRow, rowIndex, columnIndex, square);
      }
   return;
   }

/************************************************************************
* translateValues
* call it from editSquare and possibleValues
* should know what existing values are from the read() of board
* should scan row, column, and nondrant for a match of the value input from possibleValues
* should compare that value with those in row, column, and nondrant
* returns available options for the value
************************************************************************/
int translateValues(int board[][9], int usersInputValue, int x, int y)
{
   bool printsOut = false;
   int i = 0;
   bool totalPossible[10];
   
   //nondrant math
   int minimumColumn = (y / 3) * 3;
   int minimumRow = (x / 3) * 3;
   
   //set each index to false at first
   for(int k = 0; k < 10; k++)
   {
      totalPossible[i] = printsOut;
   }
   
   //check row for input value from possibleValues()
   for(int i = 0; i < 9; i++)
   {
      //hold x as  the constant here to represent the row
      if((board[x][i] != usersInputValue) || (board[x][i] != *totalPossible))
      {
         //don't output zeroes as possible values
         if(board[x][i] != 0)
            {
               //set these values to true
               printsOut = true;
         }
         //for those values set to true, output them
         if(printsOut == true)
         {
            std::cout << totalPossible[i] << ", ";
            //otherwise, output nothing
         } else
         {
            std::cout << "";
         }
   }
   }
      //check column for input value from possibleValues()
      for(int j = 0; j < 9; j++)
      {
         if((board[j][y] != usersInputValue) || (board[j][y] != *totalPossible))
         {
            //don't output zeroes as possible values
            if(board[j][y] != 0)
               {
                  //set these values to true
                  printsOut = true;
            }
            //for those values set to true, output them
            if(printsOut == true)
            {
               std::cout << totalPossible[i] << ", ";
               //otherwise, output nothing
            } else
            {
               std::cout << "";
            }
      }
      }
   
         //second nested for loops checks nondrant rows x 3
         for(int i = minimumRow; i <= 3; i++)
           {
              for(int j = minimumColumn; j <= 3; j++)
              {
                 //compare existing board numbers, user's desired input, and totalPossible values
                 if((board[x][y] != usersInputValue) || (board[x][y] != *totalPossible))
                  {
                     //don't output zeroes as possible values
                     if(board[x][y] != 0)
                        {
                           //set these values to true
                           printsOut = true;
                     }
                     //for those values set to true, output them
                     if(printsOut == true)
                     {
                        std::cout << totalPossible[i] << ", ";
                        //otherwise, output nothing
                     } else
                     {
                        std::cout << "";
                     }
                  }
              }
           }
   return usersInputValue;
}

/************************************************************************
* possibleValues
* put the string inside the pop_back()
* call editSquare()
************************************************************************/
 int possibleValues(int board[][9], char& charColumn, char& charRow, int& rowIndex, int& columnIndex,
                    std::string square)//must copy code from editSquare into here instead of passing in square
{
   int x = 0, y = 0;
   int value = 0;
   //int x, y ;//valuesInt[9];
   int usersInputValue;
   std::cout << "What is the value at " << "'" << square << "'" << ": ";
   std::cin >> usersInputValue;
   if(rowIndex < 0 || rowIndex > 8 || columnIndex < 0 || columnIndex > 8)
     {
        //ERROR: Value '2' in square 'B2' is invalid
        std::cout << "ERROR: Value " << "'" << square << "'" << "is invalid" << std::endl;
        //write an if condition to see if the square already has a value
        editSquare(board, charColumn, charRow, rowIndex, columnIndex);
     } /*else
     {
        possibleValues(board, charColumn, charRow, rowIndex, columnIndex, square);
        }*/
   std::cout << "The possible values for '" << square <<  "' are: ";
   for(int i = 0; i < 9; i++)//iterates across the nondrant (ninth part of a "quadrant").
   {
      if(usersInputValue != 0)
      {
            translateValues(board, usersInputValue, x, y);
            std::cout << (value += usersInputValue) << ", ";//concatenate string values with possibleValues item
      }
   }
   return usersInputValue;
}

/***********************************************************************
* displayHeader
************************************************************************/
 void displayBoard(int board[][9])//shows garbage output
{
   std::cout << "   A B C D E F G H I" << std::endl;
   std::string grid = "   -----+-----+-----";
   //int lineNumber = 1;
   for(int x = 0; x < 9; x++)
   {
      std::cout << x + 1 << "  ";//this gets the first row number correct
      for(int y = 0; y < 9; y++)
      {
         std::cout << (board[x][y] == 0 ? ' ' : (char)(board[x][y] + 48));//this gets the first digit in the table correct
         std::cout << (y == 2 || y == 5 ? '|' : (y == 8 ? '\n' : ' '));
      }
      std::cout << (x == 2 || x == 5 ? grid + "\n" : "");
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
* pass those values as reference to make them changeable
************************************************************************/
   void displayOptions(int board[][9], char& charColumn, char& charRow, int & rowIndex, int & columnIndex)
{
   std::cout << "Options:" << std::endl;
   std::cout << "   " << "? " << std::setw(4) << " Show these instructions" << std::endl;
   std::cout << "   D " << std::setw(4) << " Display the board" << std::endl;
   std::cout << "   E " << std::setw(4) << " Edit one square" << std::endl;
   std::cout << "   S " << std::setw(4) << " Show the possible values for a square" << std::endl;
   std::cout << "   Q " << std::setw(4) << " Save and Quit" << std::endl << "\n";
}

/***********************************************************************
* read test
************************************************************************/
int read(int board[][9])
{
   int x = 0;
   int y = 0;
    std::string fileName;
    std::cout << "Where is your board located? ";
    std::cin >> fileName;
   std::ifstream fin(fileName.c_str());
   if(fin.fail())
   {
      std::cout << "Error opening.";
      fin.close();
   }
  for(int x = 0; x < 9; x++)
   {
      for(int y = 0; y < 9; y++)
      {
         fin >> board[x][y];
      }
    }
    fin.close();
   return board[x][y];
}

/************************************************************************
* interactions
* recursive call or a indefinite loop until Q is entered; or a do/while loop or for-each loop
************************************************************************/
 void interactions(int board[][9], char& charColumn, char& charRow, int & rowIndex, int & columnIndex,
                   std::string square)
{
   char option = ' ';
   std::cout << "> ";
   std::cin >> option;
   if(option == 'D' || option == 'd')
   {
      displayBoard(board);
   } else if (option == 'E' || option == 'e')
   {
      editSquare(board, charColumn, charRow, rowIndex, columnIndex);
   } else if (option == 'S' || option == 's')
   {
      possibleValues(board, charColumn, charRow, rowIndex, columnIndex, square);
   } else if(option == 'Q' || option == 'q')
   {
      write(board);
      return;//exits the loop back to interactions
   } else if(option == '?')
   {
      displayOptions(board, charColumn, charRow, rowIndex, columnIndex);
   } else
   {
      std::cout << "ERROR: Invalid command";
   }
   interactions(board, charColumn, charRow, rowIndex, columnIndex, square);
}
};//end of class
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
   std::string square;
   Sudoku temp;
   temp.read(board);
   temp.displayOptions(board, charColumn, charRow, rowIndex, columnIndex);
   temp.displayBoard(board);
   temp.interactions(board, charColumn, charRow, rowIndex, columnIndex, square);
}
