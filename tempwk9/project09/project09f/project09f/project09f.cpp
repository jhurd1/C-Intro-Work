/***********************************************************************
* Program:
*    Project 09f, MAD LIB
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
          std::cout << (char)(tolower(word[i]));//char casts tolower which converts to pure ASCII value
      }
   }
     std::cout << ": ";
   std::cin >> word;//replaces the input with an answer to hold the answer instead of the question
}
/************************************************************************
*getFilelName && displayHeader; this only needs to get the file name, not read it, before passing
* it on to readFile.
************************************************************************/
void getFileName(char fileName[])//test with cout; working
{
   //char* fileName;
   std::cout << "Please enter the filename of the Mad Lib: ";
   std::cin >> fileName;
}

/************************************************************************
*displayStory
* isolate readFile first, then come back to this
************************************************************************/
void displayStory()//memory misallocation happening here
{
   
}

/************************************************************************
*readFile; error check 1024 chars, 32 lines, 80 chars in each line, 256 words, and 32-char length
* words.
************************************************************************/
int readFile(char fileName[], char story[][32])//isolate this function first; it's not working
{
   int count = 0;
   //int i;
   std::ifstream fin(fileName);
   //while(fin)
   while(fin >> story[count])
   {
      //check for questions
      if(story[count][0] == ':' && isalpha(story[count][1]))
      {
         askQuestion(story[count]);
      }
      count++;
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
   //readFile();
}
