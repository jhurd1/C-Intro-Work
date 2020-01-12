/***********************************************************************
* Program:
*    Assignment 12, Input and Variables
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program provides practice for outputting user input.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*       The most difficult part comprised analyzing
* why we use float for this instead of double.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdio.h>

int main()
{
    std::cout << std::fixed;
    std::cout.precision(2);
    float income = 0.0;
    std::cout << "\tYour monthly income: ";
    std::cin >> income;
    std::cout << "Your income is: $" << std::setw(9) << income << std::endl;
}
