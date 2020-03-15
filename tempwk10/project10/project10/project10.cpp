/***********************************************************************
* Program:
*    Project 10, MAD LIB
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates the final madLib assignment, taking in user input and replacing
* substitute bits with the user input and translating less friendly tokens with more human
* readable text.
*    Estimated:  1.0 hrs
*    Actual:     10 hrs
*       The most difficult part comprised getting rid of the initial space. I have not yet resolved
* the line with doudle quotes, but due to circumstances, I'm pressing forward with what I have.
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
void askQuestion(char word[])
{
      std::cout << "\t" << (char)(toupper(word[1]));
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
void getFileName(char fileName[])
{
   std::cout << "Please enter the filename of the Mad Lib: ";
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
         std::cout << '"';
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
void spaceManager(int count, char antecedent[], char temp[], char next[])
{
   switch(antecedent[1])
   {
      case '!':
         std::cout << temp;
         break;
      case '<':
         std::cout << temp;
         break;
      case '>':
         std::cout << temp;
         break;
      case '.':
         std::cout << " "  << temp;
         break;
      case ',':
         std::cout << " " << temp;
         break;
      default:
            std::cout << " " << temp;
         break;
   }
}

/************************************************************************
*displayStory
************************************************************************/
void displayStory(int count, char story[][32])
{
   std::cout << "\n";
   for(int i = 0; i < count; i++)
   {
       if (i == 0) {// || i == '<' did nothing for the line with two quotes
           std::cout << story[i]; //print first word without space
       } else {
           if(story[i][0] == ':') {
               switch(story[i][1])
               {
                  case '!':
                     std::cout << std::endl;
                     break;
                  case '<':
                     std::cout << " " << '"';
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
           } else {
               if(story[i-1][0] == ':') {
                   switch(story[i-1][1])
                   {
                      case '!':
                         std::cout << story[i];
                         break;
                      case '<':
                         std::cout << story[i];
                         break;
                      case '>':
                         std::cout << " " << story[i];
                         break;
                      case '.':
                         std::cout << " " << story[i];
                         break;
                      case ',':
                         std::cout << " " << story[i];
                         break;
                   }
               } else {
                   std::cout << " " << story[i]; //default space before word
               }
           }
       }
   }
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
      count = readFile(fileName, story);
      displayStory(count, story);
      std::cout << "\n";
      play = playAgain();
   }
}
