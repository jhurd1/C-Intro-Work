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
***********************************************************************/
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>

class ReadFile
{
private:
   std::string fileName;
   float count;
   float firstValue;
   float secondValue;
   float thirdValue;
   float fourthValue;
   float fifthValue;
   float sixthValue;
   float seventhValue;
   float eighthValue;
   float ninthValue;
   float tenthValue;
   float sum;
   float average;
public:
/**********************************************************************
*Default Constructor
**********************************************************************/
      ReadFile()
      {
         
      }
/**********************************************************************
*Non-default constructor
**********************************************************************/
      ReadFile(float average)
      {
         
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
         if(fin.is_open())
         {
            while(fin >> firstValue >> secondValue >> thirdValue >> fourthValue >> fifthValue >>
                  sixthValue >> seventhValue >> eighthValue >> ninthValue >> tenthValue)//testBed sees this statement reference three values only; we need 10
            {
               count = 10;
               sum = firstValue + secondValue + thirdValue + fourthValue + fifthValue
               + sixthValue + seventhValue + eighthValue + ninthValue + tenthValue;
               average = sum / 10;
               //std::cout << count << " " << sum << " " << average << std::endl;
            }
            fin.close();
         }
         if(fin.fail())
         {
            std::cout << "Error reading from file: " << "\"" << fileName << "\"";
            return -1;
         }
         if(count != 10)
         {
            std::cout << "Error reading from file: " << "\"" << fileName << "\"";
            return -1;
         }
         return average;
      }
   
/**********************************************************************
* Display will show the average on the console.
**********************************************************************/
      void display(float average)
      {
         this->average = average;
         //getFileName(fileName);
         //std::ofstream fout(fileName);//fout not needed for this assignment but for the next one, yes
         std::cout << "Average Grade: " <<  std::endl;
         std::cout << average;
         std::cout << "%";
      }
};

int main()
{
   float average = 0.0;
   char* fileName = nullptr;
   ReadFile temp;
   temp.getFileName(fileName);
   temp.readFile(fileName);
   temp.display(average);
}
