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
#include <iostream>
#include <fstream>

//std::string fileName;


void getFileName(char fileName[])
{
   std::cout << "Please enter the filename: ";
   std::cin >> fileName;
}

void display(float average)
{
   std::cout << "Average Grade: " <<  average << "%";
}

float readFile(char fileName[])
   {
      float sum = 0.0;
      float count = 10;
      float average = sum / count;
      std::ifstream fin;
      std::cin.getline(fileName,10);
      fin.open(fileName);
      if(!fin.is_open())
      {
         std::cout << "Error reading file" << "\"" << fileName << "\"";
         return -1;
      }
      while(fin >> count)
      {
         sum+=count;
         display(average);
      }
      return 0;
   }

//My point of disgust revolves on misunderstanding how to reference the right memory block from main.
int main(int argc, const char * argv[]) {
   getFileName(fileName);
}
