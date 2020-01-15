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
* A class to make the project easier to manage, including
* prompt functions.
 *****************************************/
class Budget{
public:
    float income, budgetExp, livingExp, taxes, tithe, other, difference;
    float actIncome, actTaxes, actTithe, actLiving, actOther, differenceTwo;
    //Default constructor
    Budget(){//Initialized this constructor with semicolon as you do in header and led to wonky, undebuggable error.
        
    }
    //Non-default constructor
    Budget(float income, float actIncome){
        
    }
        
    void promptProjected(){
        std::cout << "\tYour monthly income:" << std::endl;
        std::cin >> income;
        std::cout << "\tYour budget living expenses:" << std::endl;
        std::cin >> budgetExp;
        std::cout << "\tYour projected living expenses:" << std::endl;
        std::cin >> livingExp;
    }
    
    void promptActual(){
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
    }
    
    void display(){
            std::cout << "This program keeps track of your monthly budget" << std::endl;
            std::cout << "Please enter the following:" << std::endl;
            std::cout << "\tYour monthly income:" << "  " << income << std::endl;
            std::cout << "\tYour budgeted living expenses:" << "  " << budgetExp << std::endl;
            std::cout << "\tYour actual living expenses:" << "  " << actLiving << std::endl;
            std::cout << "\tYour actual taxes withheld:  " << actTaxes << std::endl;
            std::cout << "\tYour actual tithe offerings:  " << actTithe << std::endl;
            std::cout << "\tYour actual other expenses:  " << actOther << "\n" << std::endl;
    }
    
    void displayReport(){
        //float differenceInit = 0.00;
        difference = income - (livingExp + taxes + tithe + other);
        differenceTwo = actIncome - (actLiving + actTaxes + actTithe + actOther);
        std::cout << "The following is a report on your monthly expenses" << std::endl;
        std::cout << "Item" << std::setw(23) << "Budget" << std::setw(18) << "Actual" << std::endl;
        std::cout << "===============" <<  "  " << "===============" << "  " <<  "===============" << std::endl;
        std::cout << "Income" << std::setw(12) << "$" << std::setw(4) << "" << income << std::setw(6) << "$" << std::setw(10) << actIncome << std::endl;
        std::cout << "Taxes" << std::setw(13) << "$" << std::setw(7) << "" << taxes << std::setw(6) << "$" << std::setw(10) << actTaxes << std::endl;
        std::cout << "Tithing" << std::setw(11) << "$" << std::setw(7) << "" << tithe << std::setw(6) << "$" << std::setw(10) << actTithe << std::endl;
        std::cout << "Living" << std::setw(12) << "$" << std::setw(5) << "" << livingExp << std::setw(6) << "$" << std::setw(10) << actLiving << std::endl;
        std::cout << "Other" << std::setw(13) << "$" << std::setw(7) << "" << other << std::setw(6) << "$" << std::setw(10) << actOther << std::endl;
        std::cout << "===============" <<  "  " << "===============" << "  " <<  "===============" << std::endl;
        std::cout << "Difference" << std::setw(8) << "$" << std::setw(9) << "" << difference << std::setw(4) << "$" << std::setw(10) << differenceTwo << std::endl ;
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
    Budget budget;
    budget.promptProjected();
    budget.promptActual();
    budget.display();
    budget.displayReport();
    return 0;
}
