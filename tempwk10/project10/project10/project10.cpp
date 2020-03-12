/***********************************************************************
* Program:
*    Project 10, MAD LIB
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates
*    Estimated:  1.0 hrs
*    Actual:     8 hrs
*       The most difficult part comprised
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
   char answer;
   std::cout << "Do you want to play again (y/n)?";
   std::cin >> answer;
   answer = tolower(answer);
   if(answer == 'n')
   {
      return false;
   } else
   return true;
}

/************************************************************************
*askQuestions
* The only conditions when a space is not inserted is when the preceding character is an open
* quote or a newline, or when the following character is a closed quote, period, or comma.
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
   std::cin.getline(word, 32);
}
/************************************************************************
*getFilelName && displayHeader; this only needs to get the file name, not read it, before passing
* it on to readFile.
************************************************************************/
void getFileName(char fileName[])//tested with cout; working
{
   std::cout << "Please enter the filename of the Mad Lib: ";
   std::cin >> fileName;
   std::cin.ignore(256, '\n');
}

/************************************************************************
*displayStory
* isolate readFile first, then come back to this
  if(word[i] == '"' || word[i] == '.' || word[i] == ',' || word[i] == (char)13)
************************************************************************/
void displayStory(char fileName[256], char story[][32], char word[256])
{
   std::ifstream fin(fileName);//need line break and whitespace between words
   int i = 0;
   while(fin >> word)
   {
      if(word[i] == '"' || word[i] == '.' || word[i] == ',' || word[i] == (char)13 || isspace(word[i]))
      {
         std::cout << " ";
      }
      std::cout << word;
   }
   std::cout << "Thank you for playing.\n";
}

/************************************************************************
*readFile; error check 1024 chars, 32 lines, 80 chars in each line, 256 words, and 32-char length
* words.
************************************************************************/
int readFile(char fileName[], char story[][32])
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
   return count;
}

/************************************************************************
*main()
* The easiest way to handle this is to have a while loop in main()
************************************************************************/
int main()
{
   bool play = true;
   char word[256];
   while(play)
   {
      char fileName[256];
      char story[256][32];
      getFileName(fileName);
      /*int numWords =*/
      readFile(fileName, story);
      displayStory(fileName, story, word);
      play = playAgain();
   }
}
