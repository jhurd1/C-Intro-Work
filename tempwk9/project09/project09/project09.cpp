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
#include <fstream>
/************************************************************************
*bool playAgain()
************************************************************************/
bool playAgain()
{
   bool play = false;
   return play;
}

/************************************************************************
*askQuestions
************************************************************************/
char* askQuestion(char aos[10][256])
{
   return 0;
}
/************************************************************************
*getFilelName && displayHeader; this only needs to get the file name, not read it, before passing
* it on to readFile.
************************************************************************/
std::string getFileName()//test with cout; working
{
   std::string fileName;
   std::cout << "Please enter the filename of the Mad Lib: ";
   std::cin >> fileName;
   return fileName;
}
/************************************************************************
*readFile; error check 1024 chars, 32 lines, 80 chars in each line, 256 words, and 32-char length
* words
************************************************************************/
std::string readFile(std::string fileName)
{
   /*int i = 0;
   char j = ' ';
   char *aos[10][256];*/
   std::ifstream fin(fileName);
   //std::cin.ignore(std::numeric_limits<std::streamsize>::max());//ignore was faulting the data flow here;
      //perhaps call ignore after getline(), if need be
   fin.clear();
   std::getline(std::cin, fileName);
   fin.seekg(0, std::ios_base::beg);//presumably counts the bytes or chars in a file; may need eof method to help
   while(!fin.eof())//why is this an infinite loop? It's supposed to stop at file's end!
   {
      if(!fin.fail())
        {
           int count = 0;
                  count++;
           std::cout << "Count: " << std::endl;
        } else
        {
           std::cout << "You done failed.";
             break;
        }
   }
   return fileName;
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
*main()
************************************************************************/
int main()
{
   std::string fileName;
   //char aos[10][256];
   fileName = getFileName();
   readFile(fileName);
}
