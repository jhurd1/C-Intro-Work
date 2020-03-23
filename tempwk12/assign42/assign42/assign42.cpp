/***********************************************************************
* Program:
*    Assignment 42, Dem Bones
*    Brother Schwieder, CS124
* Author:
*    your name
* Summary: 
*    This program will display the words to the song Dem Bones by
*    using the string class
*    Estimated:  1.5 hrs
*    Actual:     1.5 hrs
*      The most difficult part comprised understanding whether I needed to output
* eight verses.
************************************************************************/

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

/********************************************************************
* clause two
********************************************************************/
std::string clauseTwo(std::string clause2)
{
   clause2 = " connected to the";
   return clause2;
}

/********************************************************************
* dangler
********************************************************************/
std::string getDangler(std::string dangler)
{
   dangler = "bone";
   return dangler;
}
/********************************************************************
 * GENERATE SONG
 ********************************************************************/
std::string generateSong(std::string list[], int num, std::string clause2,
                         std::string dangler)
{
   std::string output;
   
   // your code goes here
   for(int i = 0; i < 8; i++)
   {
      std::cout << list[i] << " " << dangler << clause2 << " " << list[i + 1] << " " << dangler << std::endl;
   }
   return output;
}

/**********************************************************************
 * MAIN
 ***********************************************************************/
int main()
{
   std::string clause2 = "";
   std::string dangler = "";
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
   std::string song = generateSong(list, 9, getDatClause2, getDatDangler);

   // display the results
   std::cout << song;
   
   return 0;
}
