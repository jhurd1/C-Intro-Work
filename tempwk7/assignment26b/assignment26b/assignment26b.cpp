/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates...
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*       The most difficult part comprised...
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
      std::cout << std::fixed << std::setprecision(0) << "Average Grade: " <<  ((float)average) <<  "%" << "\n";
   }

/*********************************************************************
* readFile() computes the average as it reads ten floats from the file.
*********************************************************************/
   float readFile()
   {
      int x = 0;
      float total = 0;
      int counter = 0;
      fin.open(fileName);//I realized that by making this "fin" local, it wasn't getting passed in appropriately, so I made it global (above)
      if(!fin)//alt: if(!fin.is_open())
      {
         std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
         return -1;
      }
      while(fin >> x)
         {
            total += x;//total is going to be sum all counts.
            counter++;//tells me how many loops we've done; this while loop just needs to tell us the quantity of loops to get the average
            std::cout << x << std::endl;
            /*average = (sum) / 10;
            display();
            fin.close();*/
         }
      
         if(counter < 10 || counter > 10)//The problem is: How do I associate "count" with the quantity of integers in the doggone file?
         {
            std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
            return -1;
         }
     
       return total/counter;
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
