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

/******************You must change std::string to char ***************************/

#include <stdio.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
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
*getCharCount consider another function, but this will read the file a second time
************************************************************************/
char getCharCount()
{
   return 0;
}

/************************************************************************
*askQuestions
************************************************************************/
char* askQuestion()
{
   return 0;
}
/************************************************************************
*getFilelName && displayHeader; this only needs to get the file name, not read it, before passing
* it on to readFile.
************************************************************************/
char getFileName()//test with cout; working
{
   char fileName;
   std::cout << "Please enter the filename of the Mad Lib: ";
   std::cin >> fileName;
   return fileName;
}

/************************************************************************
*displayStory
* isolate readFile first, then come back to this
************************************************************************/
char displayStory()//memory misallocation happening here
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
*readFile; error check 1024 chars, 32 lines, 80 chars in each line, 256 words, and 32-char length
* words.
************************************************************************/
char readFile(char* fileName)//isolate this function first; it's not working
{
   int count = 0;
   std::ifstream fin(fileName);
   size_t lineNums = 0;
   while(fin)
   {
      lineNums++;
      for(std::string test; fin >> test; ++count)//cout used to confirm count (of words) is working
      {
         if(count <= 256 && !fin.fail())//check for max word count, failure to open file, and getline to count the chars
         {
               fin.seekg (0, fin.end);//sets position at file end
               long length = fin.tellg();
               fin.seekg (0, fin.beg);//resets position at file begin
               char* buffer = new char[length];//recall that this is already getting the quantity of chars!
            if(length > 1023 || length % 80 != 0)//get your modulus calc right for chars per line
            {
               fin.fail();
               fin.clear();
               fin.ignore();
               fin.close();
            }
            else
            {
               fin.read(buffer,length);
               //std::cout.write(buffer,length); //instead of writing out the buffer contents, call displayStory()!
               displayStory();
            }
               fin.close();
               delete[] buffer;//memory management
            } else
            {
               std::cout << "You done failed.";
                 break;
            }
   }//confirmed working with cout
      }
   return *fileName;
}

/************************************************************************
*main()
************************************************************************/
int main()
{
   char *fileName;
   //char aos[10][256];
   *fileName = getFileName();
   readFile(fileName);
}
