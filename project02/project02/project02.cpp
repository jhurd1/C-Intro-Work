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

int main()
{
    std::cout << std::fixed;
    std::cout.precision(2);
    float income, budgetExp, livingExp, taxes, tithe, other;
    income = 0.0;
    budgetExp = 0.0;
    livingExp = 0.0;
    taxes = 0.0;
    tithe = 0.0;
    other = 0.0;
    std::cout << "This program keeps track of your monthly budget" << std::endl;
    std::cout << "Please enter the following:" << std::endl;
    std::cout << "\tYour monthly income:" << std::endl;
    std::cin >> income;
    std::cout << "\tYour budget living expenses:" << std::endl;
    std::cin >> budgetExp;
    std::cout << "\tYour actual living expenses:" << std::endl;
    std::cin >> livingExp;
    std::cout << "\tYour actual taxes withheld:" << std::endl;
    std::cin >> taxes;
    std::cout << "\tYour actual tithe offerings:" << std::endl;
    std::cin >> tithe;
    std::cout << "\tYour actual other expenses:\n" << std::endl;
    std::cin >> other;
    std::cout << "The following is a report on your monthly expenses" << std::endl;
    std::cout << "Item" << std::setw(15) << "Budget" << std::setw(18) << "Actual" << std::endl;
    std::cout << "===============" <<  "  " << "===============" << "  " <<  "===============" << std::endl;
    /**Income          $    1000.00    $    1000.00
    Taxes           $       0.00    $     100.00
    Tithing         $       0.00    $     120.00
    Living          $     650.00    $     700.00
    Other           $       0.00    $     150.00
    =============== =============== ===============
    Difference      $       0.00    $       0.00*/
    std::cout << "Income" << std::setw(12) << "$" << std::setw(5) << income << std::endl ;
}
