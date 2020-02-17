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

   int value, value1, value2, value3, value4, value5, value6, value7, value8, value9, value10;
   int sum, average;
   int count;
   int array[11];
   char fileName[50];
   std::ifstream fin(fileName);
   std::vector<int> totalOfIntegers;
   
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
   void display()
   {
      std::cout << std::fixed << std::setprecision(0) << "Average Grade: " <<  ((float)average) <<  "%" << "\n";
   }

/*********************************************************************
* readFile() computes the average as it reads ten floats from the file.
*********************************************************************/
   float readFile()
   {
      fin.open(fileName);//I realized that by making this "fin" local, it wasn't getting passed in appropriately, so I made it global (above)
      if(!fin)//alt: if(!fin.is_open())
      {
         std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
         return -1;
      }
      while(!fin.eof())
         {
            for(std::string line; std::getline(fin, line);)
            {
               if (fin.is_open()) {
                   int i = 0;
                   while (fin >> count) {
                       array[i++] = count;
                      size_t size = (sizeof array / sizeof array[0]);
                      std::cout << size << std::endl;
                   }
               }
            }
            fin >> value >> value1 >> value2 >> value3 >> value4 >> value5 >> value6 >> value7 >> value8 >> value9;
            //std::cout << "total ints: " << totalOfIntegers.size();
            sum = value + value1 + value2 + value3 + value4 + value5 + value6 + value7 + value8 + value9;
            average = (sum) / 10;
            display();
            fin.close();
         }
      
         if(count < 10 || count > 10)//The problem is: How do I associate "count" with the quantity of integers in the doggone file?
         {
            std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
            return -1;
         }
       return ((float)average);
   }

/*********************************************************************
*Main
*********************************************************************/
int main()
{
   getFileName();
   readFile();
}
