/***********************************************************************
* Program:
*    Assignment 30, Array Syntax
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a test on array syntax.
*    Estimated:  1.0 hrs
*    Actual:     24 hrs
*       The most difficult part comprised figuring out where my sigabrt error was happening. Once
* I changed the variable i to j in the one function, it resolved the problem.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cassert>

/***********************************************************************
*  prompt2
************************************************************************/
void getGrades2(int grades[10], int i)
{
   for(int j = 0; j <= 9; j++)
   {
      i++;

      std::cout << "Grade " << i <<  ": ";
      std::cin >> grades[j];//this is where the memory malfunction sigabrt was happening! Resolved that. Now we need to actually output the doggone average.
   }
}

/***********************************************************************
*  average the grades from a file
************************************************************************/
int averageGrades(int average, int grades[10], int i)
{
   
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
   std::cout << "Average Grade: " << average << "%" << "\n";
}

