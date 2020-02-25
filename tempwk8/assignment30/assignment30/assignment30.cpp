/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a
*    Estimated:  1.0 hrs
*    Actual:     24 hrs
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cassert>
/***********************************************************************
*  prompt()
************************************************************************
int getGrades(int grades[], int i)
{
   for(int i = 0; i <= 10; i++)
   {
      std::cout << "Grade: ";
      std::cin >> grades[i];
      //assert(grades[i] <= 10);
   }
   return grades[i];
}*/

/***********************************************************************
*  prompt2
************************************************************************/
void getGrades2(int grades[10], int i)
{
   for(int j = 0; j <= 9; j++)
   {
      i++;
      //int sum = 0;
      std::cout << "Grade " << i <<  ": ";
      std::cin >> grades[j];//this is where the memory malfunction sigabrt was happening! Resolved that. Now we need to actually output the doggone average.
      //assert(grades[j] <= 10);
      //sum += grades[j];
   }
}

/***********************************************************************
*  average the grades from a file
************************************************************************/
int averageGrades(int average, int grades[10], int i)
{
   //average = sum / 10;
      average = (grades[i] + grades[i + 1] + grades[i + 2] + grades[i + 3] + grades[i + 4] + grades[i + 5]
      + grades[i + 6] + grades[i + 7] + grades[i + 8] + grades[i + 9]) / 10;
   return average;
}

/***********************************************************************
*  main() will declare the array to keep it on the stack when the function returns
************************************************************************/
int main()
{
   int i = 0;
   int grades[10] = {};
   getGrades2(grades, i);
   int average = 0;
   average = averageGrades(average, grades, i);
   //assert(*grades < 11);
   //averageGrades(average, grades, i);
   std::cout << "Average Grade: " << average << "%";
}

