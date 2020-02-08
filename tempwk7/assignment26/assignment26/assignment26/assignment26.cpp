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
   float uno, dos, tres, quatro, cinco, seis, siete, ocho, nueve, diez;
protected:
public:
/**********************************************************************
*Accessor
**********************************************************************/
   char getFileName(char filename[])
   {
      std::cout << "Please enter the filename: " << std::endl;
      std::cin >> fileName;
      inFile.open(fileName.c_str());
      return *filename;
   }
   
   float readFile(char fileName[])
   {
      float average = 0.0;
      std::ifstream temp(fileName, std::ios::in);
      for(int i = 0; i <= 10; i++)
      {
      if(!temp)
         std::cerr << "" << std::endl;
      while(temp >> uno >> dos >> tres >> quatro >> cinco >> seis >> siete >> ocho >> nueve >> diez)
      {
         int average = uno + dos + tres + quatro + cinco + seis + siete + ocho + nueve + diez / 10;
         std::cout << std::endl;
      }
      }
      temp.close();
      return average;
   }
   
   void display(float average)
   {
      getFileName(fileName);
      std::cout << "Average Grade: ";
   }
};

int main()
{
   float average = 0.0;
   Files foo;
   foo.display(average);
}
