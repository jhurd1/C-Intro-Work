/***********************************************************************
* Program:
*    Project 03, Monthly Budget
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
*       The most difficult part comprised
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>

/******************************************
* A class to make the project easier to manage, including
* prompt functions.
 *****************************************/
class Budget{
public:
    float income, budgetExp, livingExp, taxes, tithe, other, difference;
    float actIncome, actTaxes, actTithe, actLiving, actOther, differenceTwo;
   //mutators
   
   //accessors
   float getIncome(){
      return income;
   }
   
   float getBudgetExp(){
      return budgetExp;
   }
   
   float getLivingExp(){
      return livingExp;
   }
   
   float getActOther(){
      return actOther;
   }
   
   float getactTithe(){
      return actTithe;
   }
   
   float getActTax(){
      return actTaxes;
   }
   
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
        std::cout << "\tItem" << std::setw(24) << "Budget" << std::setw(16) << "Actual" << std::endl;
        std::cout << "\t===============" <<  " " << "===============" <<  " ===============" << std::endl;
        std::cout << "\tIncome          $" << std::setw(11) << income <<  "    $" << std::setw(11) << income << std::endl;
        std::cout << "\tTaxes           $" << std::setw(11) << taxes  << "    $" << std::setw(11) << actTaxes << std::endl;
        std::cout << "\tTithing         $" << std::setw(11) << tithe << "    $"  << std::setw(11) << actTithe << std::endl;
        std::cout << "\tLiving          $" << std::setw(11) << budgetExp << "    $"  << std::setw(11) << actLiving << std::endl;
        std::cout << "\tOther           $" << std::setw(11) << other <<  "    $"  << std::setw(11) << actOther << std::endl;
        std::cout << "\t===============" <<  " " << "===============" << " " <<  "===============" << std::endl;
       std::cout << "\tDifference" << std::setw(7) << "$" << std::setw(7) << "" << difference << std::setw(5) << "$" << std::setw(11) << differenceTwo << std::endl ;
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

