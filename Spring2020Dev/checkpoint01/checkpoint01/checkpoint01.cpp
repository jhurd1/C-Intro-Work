/***********************************************************************
* Program:
*    Assignment: Checkpoint01
*    Brother Alvey, CS165
* Author:
*    Jamie Hurd
* Summary:
*    Summaries are not necessary for checkpoint assignments.
* ***********************************************************************/

#include <iostream>

/**********************************************************************
* Display the text "Hello CS 165 World"
***********************************************************************/
void display()
{
   std::cout << "Hello CS 165 World!" << std::endl;
}

/**********************************************************************
* Prompt
***********************************************************************/
std::string prompt(std::string name)
{
   name = "";
   std::cout << "Please enter your first name: " ;
   std::cin >> name;
   return name;
}

/**********************************************************************
* Prompt age
***********************************************************************/
int age(int ageVar)
{
   ageVar = 0;
   std::cout << "Please enter your age: ";
   std::cin >> ageVar;
   return ageVar;
}

/**********************************************************************
* Display all
***********************************************************************/
void displayAll(int ageVar, std::string name)
{
   std::cout << std::endl;
   std::cout << "Hello " << name << ", you are " << ageVar << " years old.\n";
}

/**********************************************************************
 * Function: main
 * Purpose: This is the entry point and driver for the program.
 ***********************************************************************/
int main()
{
   int ageVar = 0;
   std::string name = "";
   display();
   std::string tempName = prompt(name);
   int tempInt = age(ageVar);
   displayAll(tempInt, tempName);
   return 0;
}
