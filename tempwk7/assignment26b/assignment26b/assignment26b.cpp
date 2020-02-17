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

class Files{
private:
   float value;
   float sum, average;
   int count;
   char fileName[];
public:
/**********************************************************************
*Default Constructor
* (Inserted for muscle memory/habit.)
**********************************************************************/
   Files()
   {
      
   }
/**********************************************************************
*Non-default constructor
**********************************************************************/
   Files(char fileName[])
   {
      
   }
/*********************************************************************
*Accessors, which are needed only if calling private const members outside of the class.
* (I insert these for practice.)
*********************************************************************/
   float getAverage()
   {
      return average;
   }
/*********************************************************************
*Mutators
* (Inserted for practice's sake.)
*********************************************************************/
   void setAverage(float average)
   {
      this->average = average;
   }
/*********************************************************************
*getFileName() prompts for a file name to read from.
*********************************************************************/
   void getFileName()
   {
      std::cout << "Please enter the filename: ";
      std::cin >> fileName;
   }
   
/*********************************************************************
* readFile() computes the average as it reads ten floats from the file.
*********************************************************************/
   float readFile()
   {
      std::ifstream fin(fileName);
      fin.open(fileName);
      /*if(fin.fail())
      {
         std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
         return -1;
      }*/
      while(!fin.eof())//this should run while there are 10 values to manage and while the file successfully opens
           {
              if(count <= 10)
              {
                 fin >> value;//This does not work the way I expect it: It should associate value with the integers in the file.
                 count++;//this assumes that we start with zero integers in the file and prevents an infinite loop by incrementing count each time
                 sum += value;//The problem with this statement is that it doesn't know what sum is supposed to be or value, for that matter
                 average = (sum) / 10;
                 display(average);
                 fin.close();
              }
            if(count != 10)//The problem is: How do I associate "count" with the quantity of integers in the doggone file?
              {
                 std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
                 return -1;
              }
           }
       return average;
   }
     
      /*fin.open(fileName);
      count = 0;
      if(fin.is_open())
      {
          while(count == 0)
          {
             count++;
             fin >> value1 >> value2 >> value3 >> value4 >> value5 >> value6 >> value7 >> value8 >> value9 >> value10;
             sum = value1 + value2 + value3 + value4 + value5 + value6 + value7 + value8 + value9 + value10;
             average = (sum) / 10;
             display(average);
          }
      }
      while(value >= 10 || fin.fail())
      {
         std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
         return -1;
      }*/

/**********************************************************************
* Display will show the average on the console.
**********************************************************************/
   void display(float average)
   {
      this->average = average;
      std::cout << std::fixed;
      std::cout << std::setprecision(0);
      std::cout << "Average Grade: " <<  average <<  "%" << "\n";
   }
};

/*********************************************************************
*Main
*********************************************************************/
int main()
{
   Files file;
   //char &fileName = fileName;
   file.getFileName();
   file.readFile();
}
