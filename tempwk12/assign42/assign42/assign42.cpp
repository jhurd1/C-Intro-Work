/***********************************************************************
* Program:
*    Assignment 42, Dem Bones
*    Brother Schwieder, CS124
* Author:
*    your name
* Summary: 
*    This program will display the words to the song Dem Bones by
*    using the string class
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
*
* Task: write a program to display the first eight verses of the song. However, realizing that the song is * * highly repetitive, she would * * * like to write a function to help her with the task.
*
* Please write a function to generate the Dem Bones song. This function takes an array of strings as * * * input and returns a single string * that constitutes the entire song as output:
************************************************************************/

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

/********************************************************************
* clause one
********************************************************************/
std::string clauseOne(std::string clause1)
{
   clause1 = "connected from the ";
   return clause1;
}

/********************************************************************
* clause two
********************************************************************/
std::string clauseTwo(std::string clause2)
{
   clause2 = "connected to the ";
   return clause2;
}

/********************************************************************
* dangler
********************************************************************/
std::string getDangler(std::string dangler)
{
   dangler = "bone.";
   return dangler;
}
/********************************************************************
 * GENERATE SONG
 * This function will generate one long string that constitutes the
 * complete song "Dem Bones."  Note that the list of bones is provided
 * by the parameter list
 ********************************************************************/
std::string generateSong(std::string list[], int num, std::string clause1, std::string clause2,
                         std::string dangler)
{
   std::string output;
   
   // your code goes here
   for(int i = 0; list; i++)
   {
      std::cout << clause1 << " " << list[i] << " " << clause2 << " " << dangler;
   }
   return output;
}

/**********************************************************************
 * MAIN
 * In this program, MAIN is a driver program.  It will feed to generateSong()
 * the list of bones and get back the complete song as a string.  MAIN will
 * then display the song
 ***********************************************************************/
int main()
{
   std::string clause1 = "";
   std::string clause2 = "";
   std::string dangler = "";
   std::string getDatClause = clauseOne(clause1);
   std::string getDatClause2 = clauseTwo(clause2);
   std::string getDatDangler = getDangler(dangler);
   std::string list[9] =
   {
      "toe",
      "foot",
      "leg",
      "knee",
      "hip",
      "back",
      "neck",
      "jaw",
      "head"
   };

   // generate the song
   std::string song = generateSong(list, 9, getDatClause, getDatClause2, getDatDangler);

   // display the results
   std::cout << song;
   
   return 0;
}
