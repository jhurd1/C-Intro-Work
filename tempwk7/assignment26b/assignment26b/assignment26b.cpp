/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a file reader that takes 10 integers from a text file
* sums them, and calculates their average.
*    Estimated:  1.0 hrs
*    Actual:     20 hrs
*       The most difficult part comprised the body code and while loop condition.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <istream>
#include <vector>
#include <cmath>

   char fileName[50];
   std::ifstream fin(fileName);
   
/*********************************************************************
*getFileName() prompts for a file name to read from.
*********************************************************************/
   void getFileName()
   {
      std::cout << "Please enter the filename: ";
      std::cin.getline(fileName, 50);
   }

/**********************************************************************
* Display will show the average on the console.
**********************************************************************/
   void display(int average)
   {
      average = average + 1;
      std::cout << std::fixed << std::setprecision(0) << "Average Grade: " << ((float)average) <<  "%" << "\n";
   }

/*********************************************************************
* readFile() computes the average as it reads ten floats from the file.
*********************************************************************/
   float readFile()
   {
      int x = 0;
      float total = 0;
      int counter = 0;
      fin.open(fileName);
      if(!fin)
      {
         std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
         return -1;
      }
      while(fin >> x)
         {
            total += x;//total is going to sum all.
            counter++;//tells me how many loops we've done; this while loop just needs to tell us the quantity of loops to get the average
         }
      
         if(counter < 10 || counter > 10)//The problem is: How do I associate "count" with the quantity of integers in the doggone file?
            //Answer: counter counts the quantity of loops and points to the quantity of integers in the text file
         {
            std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
            return -1;
         }
     
       return (total/counter);
   }

/*********************************************************************
*Main
*********************************************************************/
int main()
{
   int avg = 0;
   getFileName();
   avg = readFile();
   if(avg != -1)
   {
      display(avg);
   }
}
