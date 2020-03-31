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

/************************************************************************
* possibleValues **needs synthesizing**
************************************************************************/
int possibleValues(int board[][9])
{
   int value = 0;
   /*See which squares are filled.
    See what number is in those squares.
    Give the options as the unused remaining numbers.*/
   
   //consider using switch case here to test for values or a range of values
   for(int x = 0; x < 9; x++)
   {
      for(int y = 0; y < 9; y++)
      {
         if(board[x][y] == 0)
         {
            //output 1-9
         } else if (board[x][y] != 0)
         {
            
         }
      }
   }
   return value;
}

/***********************************************************************
* sudokuSquareEditor  **needs fixing**
************************************************************************/
int editSquare(int board[][9])
{
   int x = 0;
   int y = 0;
   std::cout << "What are the coordinates of the square: ";
   std::cin >> board[x][y];//isn't filling the user input here for some reason
   std::cout << x << " " << y;//a test cout also shows these values as 0 in spite of user input otherwise
         if(x > 9 || y > 9)
         {
             std::cout << "ERROR: Square " << board[x][y] << " is invalid";
         } else
         {
           switch(x)
           {
              case 1: //margin number
                 return 0; //array index value
                 break;
              case 2:
                 return 1;
                 break;
              case 3:
                 return 2;
                 break;
              case 4:
                 return 3;
                 break;
              case 5:
                 return 4;
                 break;
              case 6:
                 return 5;
                 break;
              case 7:
                 return 6;
                 break;
              case 8:
                 return 7;
                 break;
              case 9:
                 return 8;
                 break;
              default:
                 std::cout << "ERROR: Square " << board[x][y] << " is invalid";
                 break;
           }
           switch(y)//take an alpha and turn it into an int
           {
              case 'A':
                 return 0;
                 break;
              case 'B':
                 return 1;
                 break;
              case 'C':
                 return 2;
                 break;
              case 'D':
                 return 3;
                 break;
              case 'E':
                 return 4;
                 break;
              case 'F':
                 return 5;
                 break;
              case 'G':
                 return 6;
                 break;
              case 'H':
                 return 7;
                 break;
              case 'I':
                 return 8;
                 break;
              default:
                 std::cout << "ERROR: Square " << board[x][y] << " is invalid";
                 break;
           }
         }
    std::cout << "What is the value at " << "''" << board[x][y] << "'' : " << board[x][y];
    return board[x][y];
}
/***********************************************************************
* displayHeader **needs fixing**
************************************************************************/
 void displayBoard(int board[][9])//and then display the margin line numbers, too
{
     std::cout << "   A B C D E F G H I" << std::endl;
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
   std::cout << "   E " << std::setw(4) << " Edit one square" << std::endl;
   std::cout << "   S " << std::setw(4) << " Show the possible values for a square" << std::endl;
   std::cout << "   Q " << std::setw(4) << " Save and Quit" << std::endl << "\n";
   std::cout << "> ";
   std::cin >> option;
   if(option == 'D' || option == 'd')
   {
      displayBoard(board);
   } else if (option == 'E' || option == 'e')
   {
      editSquare(board);
   } else if (option == 'S' || option == 's')
   {
      
   } else if(option == 'Q' || option == 'q')
   {
      write(board);
   } else if(option == '?')
   {
      displayOptions(board);
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
