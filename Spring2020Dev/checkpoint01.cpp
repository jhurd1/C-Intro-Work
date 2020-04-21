/***********************************************************************
* Program:
*    Checkpoint01
*    Brother , CS165
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
   std::cout << "Please enter your first name: " << std::endl;
   std::cin >> name;
   return name;
}

/**********************************************************************
* Prompt age
***********************************************************************/
int age(int ageVar)
{
   ageVar = 0;
   std::cout << "Please enter your age: " << std::endl;
   std::cin >> age;
   return age;
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
   	prompt(name);
   	age(ageVar);
   	std::cout << "Hello " << name << ", you are " << age << " years old.";
   	return 0;
}