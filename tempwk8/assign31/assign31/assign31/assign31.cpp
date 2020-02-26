/***********************************************************************
* Program:
*    Assignment 31, Array Design
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a test on array design.
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
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
      std::cin >> grades[j];
   }
}

/***********************************************************************
*  average the grades from a file
************************************************************************/
int averageGrades(int average, int grades[10], int i)
{
   int sum = 0;
   bool lessThanZero = false;
   int total = 9;
   for(int i = 0; i <= sizeof(grades) + 1; i++)//* dereference makes it cycle only five times
   {
      if(grades[i] != -1 && lessThanZero == false)
      {
         sum += grades[i];
         average = sum / total;//put the total into a var and decrement it per -1
      }
      else if(grades[i] == -1)
      {
         lessThanZero = true;
         total--;
      } else if (grades[i] >= 0)
      {
         lessThanZero = false;
      }
   }
   if(average == 0)
   {
      std::cout << "Average Grade: ---%\n";
   } else
   std::cout << "Average Grade: " << average << "%" << "\n";
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
}

