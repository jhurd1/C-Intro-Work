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
*    Actual:     2 hrs
*       The most difficult part comprised figuring out how to use float/int as my case scenarios. I
* finally figured out I could use ranges and this is what worked. For the computeGradeSign,
* I saw that neither of my if conditions were evaluated, so I encapsulated those in a do-while
* loop and voila, the thing works! One other problem I'm having is a segFault or memory probl-
* em. I can't seem to figure out why the program won't exit with code 0, but it has something to
* do with computeGradeSign.
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
      case 90 ... 100:
            std::cout << grades[0];
         break;
      case 80 ... 89:
            std::cout << grades[1];
         break;
      case 70 ... 79:
            std::cout << grades[2];
         break;
      case 60 ... 69:
                    std::cout << grades[3];
         break;
      case 0 ... 59:
                    std::cout << grades[4];
         break;
      default:
         std::cout << "Invalid.";
   }
   return "";
}
/************************************************************************
*and computeGradeSign()
 Additionally, a minus (-) will be added when the last digit is a 0, 1, or 2 for all grades except F's.
 A plus (+) will be added when the last digit is a 7, 8, or 9 for all grades except A's and F's.
************************************************************************/
std::string computeGradeSign(std::string grades[], float score)
{
   int i = 0;
   char plus = '+';
   char neg = '-';
   do
   {
      i++;
   if((score / 10 >= 0 && score / 10 <= 9) && score > 59)//isolates the tens digit
   {
      if((int)score % 10 == 9 || (int)score % 10 == 8 || (int)score % 10 == 7)//isolates the ones digit for +
      {
         std::cout << plus;
   } else if ((int)score % 10 == 0 || (int)score % 10 == 1 || (int)score % 10 == 2)//ones digit for -
   {
      std::cout << neg;
   }
   } else
   {
      std::cout << "";
   }
}
   while(i < 1);
   return "\n";
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
   std::cout << "Enter number grade: ";
   std::cin >> score;
   std::cout << score <<  "%" << " is " <<computeLetterGrade(grades, score) << computeGradeSign(grades, score);
}
