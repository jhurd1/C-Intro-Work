/***********************************************************************
* Program:
*    Assignment 35, Advanced Conditionals
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates an opportunity to practice switch-case and conditional operators.
* output including user input.
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
*computeLetterGrade(): input integer output a letter grade
************************************************************************/
std::string computeLetterGrade(std::string grades[], float score)
{
   switch((int)score)
   {
      case 1:
         if(score <= 100 && score >= 90)
         {
            std::cout << grades[0];
         }
         break;
      case 2:
         if(score <= 89 && score >= 80)
         {
            std::cout << grades[1];
         }
         break;
      case 3:
         if(score <= 79 && score >= 70)
         {
            std::cout << grades[2];
         }
         break;
      case 4:
         if(score <= 69 && score >= 60)
                 {
                    std::cout << grades[3];
                 }
         break;
      case 5:
        if(score <= 59)
                 {
                    std::cout << grades[4];
                 }
         break;
   }
   return *grades;
}
/************************************************************************
*and computeGradeSign()
 Additionally, a minus (-) will be added when the last digit is a 0, 1, or 2 for all grades except F's.
 A plus (+) will be added when the last digit is a 7, 8, or 9 for all grades except A's and F's.
************************************************************************/
std::string computeGradeSign(std::string grades[], float score)
{
   if((score / 10 >= 6 && score / 10 <= 8))//isolates the tens digit
   {
      if((int)score % 10 == 9 || (int)score % 10 == 8 || (int)score % 10 == 7)//isolates the ones digit for +
      {
         std::cout << "+";
   } else if ((int)score % 10 == 0 || (int)score % 10 == 1 || (int)score % 10 == 2)//ones digit for -
   {
      std::cout << "-";
   }
   }
   return *grades;
}

/************************************************************************
*main()
************************************************************************/
int main()
{
   float score = 0.0;
   std::string grades[6] = {
      "A", "B", "C", "D", "F"
   };
}
