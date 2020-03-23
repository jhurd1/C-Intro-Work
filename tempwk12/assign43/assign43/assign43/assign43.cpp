/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Schwieder, CS124
* Author:
*    your name
* Summary:
*    This program takes command line input and outputs meter conversions, supposing the input
* represents feet.
*    Estimated:  1.5 hrs
*    Actual:     1.5 hrs
*      The most difficult part comprised the loop as an iterator, array range, and other options did
* prove elegant. I initially used stof() to do the conversion, but found it easier not to use it at all.
************************************************************************/

#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>
#include <cstdlib>

/********************************************************************
* translate meters and feet
* 1 foot = 0.3048 meters
* use the library function atof() to convert a string into a float
********************************************************************/
void convert(float array[])
{
   for(int i = 0; i < 5; i++)
   {
      if(array[i] == '\0')
      {
         std::cout << "";
      } else
      {
         std::cout << std::fixed;
         std::cout << std::setprecision(1);
         std::cout << array[i] << " feet is " << array[i] * .3048 << " meters" << std::endl;
      }
   }
}
/********************************************************************
* main
********************************************************************/
int main()
{
   float array[] = {
      1.0, 2.0, 3.0, 5.9, 100.0
   };
   convert(array);
}
