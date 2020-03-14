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
*trim: citation, tiptip.ca/2010/03/trim-leading-or-trailing-white-spaces.html
 ///https://www.youtube.com/watch?v=W_defvKTiVc
************************************************************************/
void removeASpace(char * p, char c)
{
   if(NULL == p)
   {
      return;
   }
      char * pDest = p;
      while(*p)
      {
         if(*p != c)
         {
            *pDest++ = *p;
            p++;
         }
         *pDest = '\0';
      }
   }

/************************************************************************
*bool flag()
************************************************************************/
void flag(int count, char temp[])
{
   count = 0;
   for(int i = 0; i < count; i++)
   {
      if(count)//first index
      {
         std::cout << "";//take out the first space on the line
      } else
      {
         std::cout << " " << temp;//add a space between words thereafter
      }
   }
}

/************************************************************************
*bool playAgain()
************************************************************************/
bool playAgain()
{
   char answer;
   std::cout << "Do you want to play again (y/n)? ";
   std::cin >> answer;
   answer = tolower(answer);
   if(answer == 'n')
   {
       std::cout << "Thank you for playing.\n";
      return false;
   } else
   return true;
}

/************************************************************************
*askQuestions
* The only conditions when a space is not inserted is when the preceding character is an open
* quote or a newline, or when the following character is a closed quote, period, or comma.
************************************************************************/
void askQuestion(char word[])//This function, remember, outputs the list of replacement words and its prompts
{
      std::cout << "\t" << (char)(toupper(word[1]));//char casts toupper which converts to pure ASCII value
   for(int i = 2; word[i]; i++)
   {
     if(word[i] == '_')
      {
         std::cout << " "; //This is not the culprit of the extra space preceding the first char, either.
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
   std::cout << "Please enter the filename of the Mad Lib: ";//This space didn't cause the extra space ont he line below.
   std::cin >> fileName;
   std::cin.ignore(256, '\n');
}

/************************************************************************
*Manage the tokens.
************************************************************************/
void tokenManager(char antecedent[], char temp[], char next[])
{
   switch(temp[1])
   {
      case '!':
         std::cout << std::endl;
         break;
      case '<':
         std::cout << ' ' << '"';//This is not causing the anamalous space on the first line preceding the first char
         break;
      case '>':
         std::cout << '"';
         break;
      case '.':
         std::cout << '.';
         break;
      case ',':
         std::cout << ',';
         break;
   }
}

/************************************************************************
*Manage spacing
************************************************************************/
void spaceManager(int count, char antecedent[], char temp[], char next[])//represents the first three words
{
   //std::cout << antecedent[1] << "antecedent [1]"; prints the second letter of the first word
   //flag(count); flag isn't doing anything here
   switch(antecedent[1])
   {
      case '!':
         std::cout << temp;
         //std::cout << "\n";
         break;
      case '<':
         std::cout << temp;
         break;
      case '>':
         std::cout << temp;
         break;
      case '.':
         //std::cout << " "  << temp;
         flag(count, temp);
         break;
      case ',':
         //std::cout << " " << temp;
         flag(count, temp);
         break;
         //What happens if you insert a new case where there is no space, for the very first word?
      
         //What happens if you change this default to case ' '? // it inserts an entirely new line and no text displays
      default:
         //flag(count, temp);
            std::cout << " " << temp;//Removing the default case only leaves a new line on the first line from somewhere and stops printing every subsequent word
         break;
   }
}

/************************************************************************
*displayStory
************************************************************************/
void displayStory(int count, char story[][32])
{
   std::cout << "\n";//removing this caused the program to time out
   for(int i = 0; i < count; i++)//count is the story array's size
   {
      if(story[i][0] == ':')//change the second index from 0 to i-- Doing so prints all the words on the first line rather than line breaking.
         //Change the first index of the first array from i to i + 1; doing so skips the line break and prints everything on the first line again
      {
         //flag(count, temp); did nothing
         //Changing the last parameter from i + 1 to 1 did not resolve the extra space at the start of the lines. What about i - 1? i - 1 didn't do anything that I can tell here.
         tokenManager(story[1], story[i], story[i + 1]);//Changing this first parameter from i - 1 to 1, appears to have separated that pesky article 'a' from the first word
         //std::cout << story[i + 1] << "This is the test."; //This prints after the first word at the first space.
         //std::cout << story[1] << "TEST [1]"; This prints the first word and when it does now the subsequent lines are left-aligned correctly but not the very first one.
         //std::cout << story[i - 1] << "TEST [i - 1"; This prints the last word on the line
      } else
      {
         //flag(count, temp); did nothing
         //what about changing the last parameter here from i + 1 to 1? Did nothing. Try i - 1 for third parameter now. Did nothing.
         spaceManager(count, story[1], story[i], story[i + 1]);//Changing the first parameter from i - 1 to 1 put the uppercase back on the first char, but didn't resolve the extra space preceding it
      }
}
    std::cout << "\n";
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
   int count = 0;
   while(play)
   {
      char fileName[256];
      char story[256][32];
      getFileName(fileName);
      /*int numWords =*/
      count = readFile(fileName, story);
      displayStory(count, story);
      play = playAgain();
   }
}
