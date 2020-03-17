/***********************************************************************
* Program:
*    Assignment 40, MULTI-DIMENSIONAL ARRAYS
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates
*    Estimated:  1.0 hrs
*    Actual:     2 hrs
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <fstream>

/************************************************************************
* getFileName
************************************************************************/
void getFileName(char fileName[])
{
   std::cout << "Enter source file name: ";
   std::cin >> fileName;
   std::cin.ignore(256, '\n');
}

/************************************************************************
* getWriteFileName
************************************************************************/
void getWriteFileName(char writeFileName[])
{
   std::cout << "Enter destination filename: ";
   std::cin >> writeFileName;
   std::cin.ignore(256, '\n');
}

/************************************************************************
* writeToFile "stores" or writes to a file the tic tac toe results.
************************************************************************/
void writeToFile(char writeFileName[], char tic[][32])
{
   std::ofstream fout(writeFileName);
   int count = 32;
   fout.open(writeFileName);
   for(int i = 0; i < count; i++)//needs two for loops
   {
      fout << tic;
      fout.close();
   }
   std::cout << "File written.";
}

/************************************************************************
* readFile
************************************************************************/
int readFile(char fileName[], char tic[][32])
{
   int count = 0;
   int i = 0;
   std::ifstream fin(fileName);
   for(i = 0; i < 32; i++)
   {
      fin >> tic[i][count];
      count++;
   }
   return count;
}

/************************************************************************
* display
************************************************************************/
void display(char fileName[], char tic[][32])
{
   int count = 0;
   int i = 0;
   std::ifstream fin(fileName);
   while(fin.eof() == 0)
   {
      fin >> tic[i][count];
      std::cout << tic;
   }
}

/************************************************************************
*main()--a "driver"
************************************************************************/
int main()
{
   char fileName[256];
   char tic[256][32];
   char writeFileName[256];
   getFileName(fileName);
   getWriteFileName(writeFileName);
   writeToFile(writeFileName, tic);
   readFile(fileName, tic);
}
