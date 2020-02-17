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

class Files{
private:
   float value1, value2, value3, value4, value5, value6, value7, value8, value9, value10;
   float value, sum, average;
   int count;
   char fileName;
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
   void getFileName(char fileName[])
   {
      this->fileName = *fileName;
      std::cout << "Please enter the filename: ";
      std::cin >> fileName;
   }
   
/*********************************************************************
* readFile() computes the average as it reads ten floats from the file.
*********************************************************************/
   float readFile(char fileName[])
   {
      this->fileName = *fileName;
      int ARRAY_SIZE = 10;
      int value[ARRAY_SIZE];
      std::ifstream fin(fileName);
      fin.open(fileName);
      if(fin.good())
           {
              count = 0;
              while(count < ARRAY_SIZE && fin >> value[count])
              {
                 count++;
                 /*if(fin >> value1 >> value2 >> value3 >> value4 >> value5 >> value6 >> value7 >> value8 >> value9 >> value10)
                 {*/
                    sum = value1 + value2 + value3 + value4 + value5 + value6 + value7 + value8 + value9 + value10;
                    average = (sum) / 10;
                    display(average);
                    fin.close();
                 }
           } else if(/*value* < 0 || value* > 10*/count > ARRAY_SIZE && fin >> value[count])
           {
                 std::cout << "Error reading file " << "\"" << fileName << "\"" << "\n";
                 return -1;
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
   char fileName[50];
   //char &fileName = fileName;
   file.getFileName(fileName);
   file.readFile(fileName);
}
