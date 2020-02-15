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
   float count, sum, score;
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
      //You must declare what fin is first.
      std::ifstream fin(fileName);
      //error test immediately after attempting to open
      fin.open(fileName);
      if(fin.fail())
      {
         std::cout << "Error reading file: " << "\"" << fileName << "\"";
         return -1;
      }
      //Read the data.
      //char sum[256];
      fin >> average >> sum;
      //for(int i = 0; i <= 10; i++)//only use "for" if you know a set number of reads that you're going to do
         //use while instead
      while(count <= 10)
      {
         //count, sum and score
         average = sum / 10;
         //while fin score
         if(count != 10)//if count not 10 error out and return negative one a second time
         {
            std::cout << "Error reading file: " << "\"" << fileName << "\"";
                    return -1;
         }
         //return casts as float a sum divided by the count
         //The error fileName << "\"\n"
         count++;//increment count and concat sum to score inside while block
         sum += score;
      }
      fin.close();
      return average;
   }

/**********************************************************************
* Display will show the average on the console.
**********************************************************************/
   void display(float average)
   {
      //getFileName(fileName);
      //std::ofstream fout(fileName);//fout not needed for this assignment but for the next one, yes
      std::cout << "Average Grade: " <<  std::endl;
      std::cout << getAverage();
      std::cout << "%";
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
