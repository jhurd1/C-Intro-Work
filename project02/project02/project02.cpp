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

class Budget{
public:
    float income, budgetExp, livingExp, taxes, tithe, other, difference;
    float actIncome, actTaxes, actTithe, actLiving, actOther;
    //Default constructor
    Budget();
    //Non-default constructor
    Budget(float income, float actIncome){
    }
        
    float promptProjected(){
        std::cout << "\tYour monthly income:" << std::endl;
        std::cin >> income;
        std::cout << "\tYour budget living expenses:" << std::endl;
        std::cin >> budgetExp;
        std::cout << "\tYour actual living expenses:" << std::endl;
        std::cin >> livingExp;
        return income;
        }
    
    float promptActual(){
        std::cout << "\tYour actual monthly income:" << std::endl;
               std::cin >> actIncome;
               std::cout << "\tYour actual living expenses:" << std::endl;
               std::cin >> actLiving;
               std::cout << "\tYour actual taxes withheld:" << std::endl;
               std::cin >> actTaxes;
               std::cout << "\tYour actual tithe offerings:" << std::endl;
               std::cin >> actTithe;
               std::cout << "\tYour actual other expenses:\n" << std::endl;
               std::cin >> actOther;
        return actIncome;
    }
};

/******************************************
*Main instantiates needed variables for holding
* user input and outputting the monthly budget
* for said user according to formatting requirements.
 *****************************************/

int main()
{
    std::cout << std::fixed;
    std::cout.precision(2);
    float income, budgetExp, livingExp, taxes, tithe, other, difference;
    income = 0.0;
    budgetExp = 0.0;
    livingExp = 0.0;
    taxes = 0.0;
    tithe = 0.0;
    other = 0.0;
    difference = income - (livingExp + taxes + tithe + other);
    Budget prompt;
    std::cout << "This program keeps track of your monthly budget" << std::endl;
    std::cout << "Please enter the following:" << std::endl;
    prompt.promptProjected();
    std::cout << "The following is a report on your monthly expenses" << std::endl;
    std::cout << "Item" << std::setw(23) << "Budget" << std::setw(18) << "Actual" << std::endl;
    std::cout << "===============" <<  "  " << "===============" << "  " <<  "===============" << std::endl;
    std::cout << "Income" << std::setw(12) << "$" << std::setw(8) << "" << income << std::endl ;
    std::cout << "Taxes" << std::setw(13) << "$" << std::setw(8) << "" << taxes << std::endl ;
    std::cout << "Tithing" << std::setw(11) << "$" << std::setw(8) << "" << tithe << std::endl ;
    std::cout << "Living" << std::setw(12) << "$" << std::setw(8) << "" << livingExp << std::endl ;
    std::cout << "Other" << std::setw(13) << "$" << std::setw(8) << "" << other << std::endl ;
    std::cout << "===============" <<  "  " << "===============" << "  " <<  "===============" << std::endl;
    std::cout << "Difference" << std::setw(8) << "$" << std::setw(9) << "" << difference << std::endl ;
}
