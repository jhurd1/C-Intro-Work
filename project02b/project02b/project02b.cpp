/***********************************************************************
* Program:
*    Project 02, Monthly Budget
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a budget program
* which provides basic, essential math functions
* for formulating my monthly budget.
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*       The most difficult part comprised implem-
* enting a class  because
* I then had to go back and redo this project.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <stdio.h>

/******************************************
*Main instantiates needed variables for holding
* user input and outputting the monthly budget
* for said user according to formatting requirements.
 *****************************************/
int main()
{
    std::cout << std::fixed;
    std::cout.precision(2);
    float income, budgetExp, livingExp, taxes, tithe, other;
    float actIncome, actTaxes, actTithe, actLiving, actOther;
    income = 0.0;
    budgetExp = 0.0;
    livingExp = 0.0;
    taxes = 0.0;
    tithe = 0.0;
    other = 0.0;
    actIncome = 0.0;
    actTaxes = 0.0;
    actLiving = 0.0;
    actOther = 0.0;
    actTithe = 0.0;
    std::cout << "This program keeps track of your monthly budget" << std::endl;
    std::cout << "Please enter the following:" << std::endl;
    std::cout << "\tYour monthly income: ";
    std::cin >> income;
    std::cout << "\tYour budgeted living expenses: ";
    std::cin >> budgetExp;
    std::cout << "\tYour actual living expenses: ";
    std::cin >> actLiving;
    std::cout << "\tYour actual taxes withheld: ";
    std::cin >> actTaxes;
    std::cout << "\tYour actual tithe offerings: ";
    std::cin >> actTithe;
    std::cout << "\tYour actual other expenses: ";
    std::cin >> actOther;
    std::cout << std::endl;
    float differenceInit = 0.00;
    std::cout << "The following is a report on your monthly expenses" << std::endl;
    std::cout << "\tItem" << std::setw(24) << "Budget" << std::setw(16) << "Actual" << std::endl;
    std::cout << "\t===============" <<  " " << "===============" <<  " ===============" << std::endl;
    std::cout << "\tIncome          $" << std::setw(11) << income <<  "    $" << std::setw(11) << income << std::endl;
    std::cout << "\tTaxes           $" << std::setw(11) << taxes  << "    $" << std::setw(11) << actTaxes << std::endl;
    std::cout << "\tTithing         $" << std::setw(11) << tithe << "    $"  << std::setw(11) << actTithe << std::endl;
    std::cout << "\tLiving          $" << std::setw(11) << budgetExp << "    $"  << std::setw(11) << actLiving << std::endl;
    std::cout << "\tOther           $" << std::setw(11) << other <<  "    $"  << std::setw(11) << actOther << std::endl;
    std::cout << "\t===============" <<  " " << "===============" << " " <<  "===============" << std::endl;
    std::cout << "\tDifference" << std::setw(7) << "$" << std::setw(7) << "" << differenceInit << std::setw(5) << "$" << std::setw(11) << differenceInit << std::endl ;
    return 0;
}
