/***********************************************************************
* Program:
*    Project 09, MAD LIB
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a preparatory MadLib exercise expecting a formatted
* output including user input.
*    Estimated:  1.0 hrs
*    Actual:     8 hrs
*       The most difficult part comprised an interruption due to an OS and IDE update, which
* resulted in buggy file access. I had to move my local Git repo to the local drive because
* Mac's Catalina--even after modifying permissions with chflags and other commands--refused
* to give XCode file access to my thumb drive, making yesterday an extremely worrisome
* day.
************************************************************************/
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
*askQuestions
************************************************************************/
void askQuestion(char word[])
{
   std::cout << "\t" << (char)(toupper(word[1]));//char casts toupper which converts to pure ASCII value
   for(int i = 2; word[i]; i++)
   {
      if(word[i] == '_')
      {
         std::cout << " ";
      } else
      {
         std::cout << (char)(tolower(word[i]));
      }
   }
   std::cout << ": ";
   std::cin.ignore();
   std::cin.getline(word, 32);
}
/************************************************************************
*getFilelName && displayHeader; this only needs to get the file name, not read it, before passing
* it on to readFile.
************************************************************************/
void getFileName(char fileName[])//test with cout; working
{
   std::cout << "Please enter the filename of the Mad Lib: ";
   std::cin >> fileName;
}

/************************************************************************
*displayStory
* isolate readFile first, then come back to this
************************************************************************/
void displayStory()
{
   std::cout << "Thank you for playing.\n";
}

/************************************************************************
*readFile; error check 1024 chars, 32 lines, 80 chars in each line, 256 words, and 32-char length
* words.
************************************************************************/
int readFile(char fileName[], char story[][32])//isolate this function first; it's not working
{
   int count = 0;
   std::ifstream fin(fileName);
   while(fin >> story[count])
   {
      if(story[count][0] == ':' && isalpha(story[count][1]))
      {
         askQuestion(story[count]);
      }
      count++;
   }
   if(fin.eof())
   {
       std::cout << "Thank you for playing.\n";
   }
   return count;
}

/************************************************************************
*main()
************************************************************************/
int main()
{
   char fileName[256];
   char story[256][32];
   getFileName(fileName);
   int numWords = readFile(fileName, story);
}
