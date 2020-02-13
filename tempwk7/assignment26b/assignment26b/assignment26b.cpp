/***********************************************************************
* Program:
*    Assignment 26, Files
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*       The most difficult part comprised
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
   float average;
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
   Files(float average)
   {
      
   }
/*********************************************************************
*Accessors, which are needed only if calling private const members outside of the class.
* (I insert these for memory's sake.)
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
      std::cout << "Please enter the filename: ";
      std::cin >> fileName;
   }
   
/*********************************************************************
* readFile() computes the average as it reads ten floats from the file.
*********************************************************************/
   float readFile(char fileName[])
   {
      std::ifstream fin(fileName);
      for(int i = 0; i <= 10; i++)
      {
         if(i > 10)
         {
            fin.fail();
            std::cout << "Error reading file " << "\"" << fileName << "\"";
            return -1;
         }
         average = value1 + value2 + value3 + value4 + value5 + value6 + value7 + value8 + value9 + value10 / 10;
         fin >> average;
      }
      fin.close();
      return average;
   }

/**********************************************************************
* Display will show the average on the console.
**********************************************************************/
   void display(float average)
   {
      std::cout << average;
   }
};

/*********************************************************************
*Main
*********************************************************************/
int main()
{
   Files file;
   float average = 0.0;
   char *fileName = (char *) fileName;
   file.getFileName(fileName);
   file.readFile(fileName);
   file.display(average);
}
