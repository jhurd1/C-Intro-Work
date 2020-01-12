/***********************************************************************
* Program:
*    Assignment 11, Output
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program provides practice for formatting with \t and setw().
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*       The most difficult part comprised remembering
* which operator outputs the string to the console.
************************************************************************/

#include <iostream>
#include <iomanip>
#include <stdio.h>

int main()
    {
        std::cout << std::fixed;
        std::cout.precision(2);
        double income, taxes, tithing, living, other, delta;
        income = 1000.00;
        taxes = 100.00;
        tithing = 100.00;
        living = 650.00;
        other = 90.00;
        delta = 60.00;
        std::cout << "\t" << "Item" << "           " << "Projected" << std::endl;
        std::cout << "\t" << "=============" <<  "  " << "==========" << std::endl;
        std::cout << "\tIncome" << std::setw(10) << "$" << std::setw(9)  << income << std::endl;
        std::cout << "\tTaxes" << std::setw(11) << "$" << std::setw(9)  << taxes << std::endl;
        std::cout << "\tTithing" << std::setw(9) << "$" << std::setw(9)  << tithing << std::endl;
        std::cout << "\tLiving" << std::setw(10) << "$" << std::setw(9)  << living << std::endl;
        std::cout << "\tOther" << std::setw(11) << "$" << std::setw(9)  << other << std::endl;
        std::cout << "\t" << "============="  << "  " << "==========" << std::endl;
        std::cout << "\tDelta" << std::setw(11) << "$" << std::setw(9)  << delta << std::endl;
}
