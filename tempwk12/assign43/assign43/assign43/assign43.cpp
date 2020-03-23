/***********************************************************************
* Program:
*    Assignment 43, Command Line
*    Brother Schwieder, CS124
* Author:
*    your name
* Summary:
*    This program will
*    Estimated:  1.5 hrs
*    Actual:     1.5 hrs
*      The most difficult part comprised
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
   //std::string feet = "";
   //float foot = std::stof((feet).c_str(), 0) * .3048;
   for(int i = 0; i < (int)*array; i++)
   {
      if(array[i] != '\0')
      {
            std::cout << std::fixed;
            std::cout << std::setprecision(1);
            std::cout << array[i] << " feet is " << array[i] * .3048 << " meters" << std::endl;
      } else
      {
         std::cout << "";
         break;
      }
   }
   //return foot;
}

/********************************************************************
* display
********************************************************************/
/*void display(float foot, float array[])
{
   std::cout << foot << "feet is " << convert(array) << "meters" << std::endl;
   std::cout << convert(array)  << std::endl;
}*/
/********************************************************************
* main
********************************************************************/
int main()
{
   float array[] = {
      1.0, 2.0, 3.0, 5.9, 100.0
   };
   float foot = 0.0;
   convert(array);
}
