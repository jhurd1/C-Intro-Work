/***********************************************************************
* Program:
*    Project02, Monthly Budget
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
*       The most difficult part comprised analyzing
* why we use float for this instead of double.
************************************************************************/
#include <iostream>
#include <iomanip>
#include <stdio.h>

/******************************************
*Main instantiates needed variables for holding
* user input and outputting the monthly budget
* for said user according to formatting requirements.
 *****************************************/
/**This program keeps track of your monthly budget
Please enter the following:
        Your monthly income: 1000.00
        Your budgeted living expenses: 650.00
        Your actual living expenses: 700.00
        Your actual taxes withheld: 100.00
        Your actual tithe offerings: 120.00
        Your actual other expenses: 150.00

The following is a report on your monthly expenses
        Item                  Budget          Actual
        =============== =============== ===============
        Income          $    1000.00    $    1000.00
        Taxes           $       0.00    $     100.00
        Tithing         $       0.00    $     120.00
        Living          $     650.00    $     700.00
        Other           $       0.00    $     150.00
        =============== =============== ===============
        Difference      $       0.00    $       0.00
*/
int main()
{
    std::cout << std::fixed;
    std::cout.precision(2);
    float income, budgetExp, livingExp, taxes, tithe, other, difference;
    float actIncome, actTaxes, actTithe, actLiving, actOther, differenceTwo;
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
    std::cout << "\tYour monthly income:  ";
    std::cin >> income;
    std::cout << "\tYour budgeted living expenses:  ";
    std::cin >> budgetExp;
    std::cout << "\tYour actual living expenses:  ";
    std::cin >> actLiving;
    std::cout << "\tYour actual taxes withheld:  ";
    std::cin >> actTaxes;
    std::cout << "\tYour actual tithe offerings:  ";
    std::cin >> actTithe;
    std::cout << "\tYour actual other expenses:  ";
    std::cin >> actOther;
    std::cout << std::endl;
    float differenceInit = 0.00;
    //difference = income - (livingExp + taxes + tithe + other);
    //differenceTwo = actIncome - (actLiving + actTaxes + actTithe + actOther);
    std::cout << "The following is a report on your monthly expenses" << std::endl;
    std::cout << "Item" << std::setw(23) << "Budget" << std::setw(18) << "Actual" << std::endl;
    std::cout << "===============" <<  "  " << "===============" << "  " <<  "===============" << std::endl;
    std::cout << "Income" << std::setw(12) << "$" << std::setw(4) << "" << income << std::setw(6) << "$" << std::setw(10) << income << std::endl;
    std::cout << "Taxes" << std::setw(13) << "$" << std::setw(7) << "" << taxes << std::setw(6) << "$" << std::setw(10) << actTaxes << std::endl;
    std::cout << "Tithing" << std::setw(11) << "$" << std::setw(7) << "" << tithe << std::setw(6) << "$" << std::setw(10) << actTithe << std::endl;
    std::cout << "Living" << std::setw(12) << "$" << std::setw(7) << "" << livingExp << std::setw(6) << "$" << std::setw(10) << actLiving << std::endl;
    std::cout << "Other" << std::setw(13) << "$" << std::setw(7) << "" << other << std::setw(6) << "$" << std::setw(10) << actOther << std::endl;
    std::cout << "===============" <<  "  " << "===============" << "  " <<  "===============" << std::endl;
    std::cout << "Difference" << std::setw(8) << "$" << std::setw(9) << "" << differenceInit << std::setw(4) << "$" << std::setw(10) << differenceInit << std::endl ;
    return 0;
}
