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
*getCharCount consider another function, but this will read the file a second time
************************************************************************/
std::string getCharCount()
{
   return 0;
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
* words.
************************************************************************/
std::string readFile(std::string fileName)
{
   int count = 0;
   //int countChar = 0;
   std::ifstream fin(fileName);
   //std::cin.ignore(std::numeric_limits<std::streamsize>::max());//ignore was faulting the data flow here;
      //perhaps call ignore after getline(), if need be
   fin.clear();//is this necessary?
   for(std::string test; fin >> test; ++count)//cout used to confirm count (of words) is working
   {
      if(count <= 256 && !fin.fail() && getline(fin, fileName))//check for max word count, failure to open file, and getline to count the chars
      {
            //countChar += fileName.length();
            /*if(countChar > 1023 || countChar % 80 > 0)//add an OR condition here to check 80 chars per line
            {
               fin.fail();
               fin.clear();
               fin.ignore();
               fin.close();
            }*/
            std::getline(std::cin, fileName);
            fin.seekg (0, fin.end);//sets position at file end
            long length = fin.tellg();
            fin.seekg (0, fin.beg);//resets position at file begin
            char* buffer = new char[length];//recall that this is already getting the quantity of chars!
         if(length > 1023 || length % 80 != 0)
         {
            fin.fail();
            fin.clear();
            fin.ignore();
            fin.close();
         }
         else
         {
            fin.read(buffer,length);
            std::cout.write(buffer,length);
         }
           //instead of writing out the buffer contents, write out the required content for the project
            fin.close();
            delete[] buffer;//memory management
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
