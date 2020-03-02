/***********************************************************************
* Program:
*    Project 09, MAD LIB
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a
*    Estimated:  1.0 hrs
*    Actual:     3 hrs
*       The most difficult part comprised
************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cstring>
/************************************************************************
*main()
************************************************************************/


/************************************************************************
*main()
************************************************************************/

/************************************************************************
*readFile
************************************************************************/
char* readFile(std::string fileName)
{
   int i = 0;
   char j = ' ';
   char *aos[10][256];
   return aos[i][j];
}
/************************************************************************
*displayStory
************************************************************************/
std::string displayStory(char aos[10][256])//memory misallocation happening here
{
   std::cout << "\tPlural noun: " << "\n";//getLine()? since it's a file?
   std::cout << "\tPlural noun: " << "\n";
   std::cout << "\tType of liquid: " << std::endl;
   std::cout << "\tAdjective: " << std::endl;
   std::cout << "\tFunny noise: " << std::endl;
   std::cout << "\tAnother funny noise: " << std::endl;
   std::cout << "\tAdjective: " << std::endl;
   std::cout << "\tAnimal: " << std::endl;
   std::cout << "\tAnother animal: " << std::endl;
   return 0;
}
/************************************************************************
*displayHeader
************************************************************************/
std::string getFileName()//test with cout; working
{
   std::string fileName;
   std::cout << "Please enter the filename of the Mad Lib: " << std::endl;
   std::cin.ignore();
   std::getline(std::cin, fileName);
   return fileName;
}

/************************************************************************
*main()
************************************************************************/
int main()
{
   //char aos[10][256];
   getFileName();
   //displayStory(aos);
}
