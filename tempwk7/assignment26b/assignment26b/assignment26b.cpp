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
   float count, sum, average;
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
      std::cout << "Please enter the filename: ";
      std::cin >> fileName;
   }
   
/*********************************************************************
* readFile() computes the average as it reads ten floats from the file.
*********************************************************************/
   float readFile(char fileName[])
   {
      std::ifstream fin(fileName);
      fin.open(fileName);
      while(count <= 10)
      {
         if(count != 10 || fin.fail())
         {
            std::cout << "Error reading file: " << "\"" << fileName << "\"";
                    return -1;
         }
         sum = value1 + value2 + value3 + value4 + value5 + value6 + value7 + value8 + value9 + value10;
         average = sum / 10;
      }
      fin.close();
      return average;
   }

/**********************************************************************
* Display will show the average on the console.
**********************************************************************/
   void display(float average)
   {
      std::cout << "Average Grade: " << "\"" << getAverage() << "\"" <<  "%";
   }
};

/*********************************************************************
*Main
*********************************************************************/
int main()
{
   Files file;
   float average = 0.0;
   char *fileName = (char *) fileName;//I threw this in to resolve an error with accessing "fileName" from main(): "use of undeclared identifier"
   //and that's my principal problem right now: Getting main to actually "see" the data members
   file.getFileName(fileName);
   file.readFile(fileName);
   file.display(average);
}
