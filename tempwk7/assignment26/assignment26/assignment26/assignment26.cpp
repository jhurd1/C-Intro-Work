/***********************************************************************
* Program:
*    Assignment 26, Loop Design
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a calendar, which
* calculates the days of the month conjunctive with an offset,
* then displays the days in calendar format.
*
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

class Files{
private:
   std::ifstream inFile;
   std::ofstream outFile;
   std::string fileName;
protected:
public:
/**********************************************************************
*Accessor
**********************************************************************/
   void getFileName(char filename[])
   {
      std::cout << "Please enter the filename: " << std::endl;
      std::cin >> fileName;
      inFile.open(fileName.c_str());
   }
   
   float readFile(char fileName[])
   {
      return 0;
   }
   
   void display(float average)
   {
      std::cout << "Average Grade: ";
   }
};

int main()
{
   
}
