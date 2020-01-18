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
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*       The most difficult part comprised comprehending
* access and scope so that my report table output the
* user input in addition to finding what other's calcu-
* lation should be.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>

/******************************************
* A class to make the project easier to manage, including
* prompt functions.
 *****************************************/
class Budget{
private:
   double income;
   double living;
   double taxes;
   double tithe;
   double other;
   double difference;
   double actIncome;
   double actTaxes;
   double actTithe;
   double actLiving;
   double actOther;
   double differenceTwo;
public:
   
   /******************************************
   * Accessors and mutators help provide programmers with
   * control over what parameters can be implemented
   * with child classes or using the parent class.
    *****************************************/
   //mutators
   double setTithing(double tithe){
      this->tithe = income * .1;
      return tithe;
   }
   
   double setOther(double other){
      this->other = income - (taxes + tithe + living);
      return other;
   }
   //accessors
   double getIncome(){
      std::cout << "\tYour monthly income: ";
      std::cin >> income;
      return income;
   }
   
   double getLiving(){
      std::cout << "\tYour budgeted living expenses: ";
      std::cin >> living;
      return living;
   }
   
   double getActLiving(){
      std::cout << "\tYour actual living expenses: ";
      std::cin >> actLiving;
      return actLiving;
   }
   
   double getOther(){
      std::cin >> other;
      return other;
   }
   
   double getActOther(){
      std::cout << "\tYour actual other expenses: ";
      std::cin >> actOther;
      std::cout << std::endl;
      return actOther;
   }
   
   double getActTithe(){
      std::cout << "\tYour actual tithe offerings: ";
      std::cin >> actTithe;
      return actTithe;
   }
   
   double getActTax(){
      std::cout << "\tYour actual taxes withheld: ";
      std::cin >> actTaxes;
      return actTaxes;
   }
   
    //Default constructor
    Budget(){
        
    }
    //Non-default constructor
    Budget(double income, double actIncome){
        
    }
    
    void displayIntro(){
            std::cout << "This program keeps track of your monthly budget" << std::endl;
            std::cout << "Please enter the following:" << std::endl;
    }
    
    void displayReport(){
       Budget budget;
      double differenceInit = 0.00;
      taxes = 0.0;
      difference = income - (actLiving + actTaxes + actTithe + actOther);
      std::cout << "The following is a report on your monthly expenses" << std::endl;
      std::cout << "\tItem" << std::setw(24) << "Budget" << std::setw(16) << "Actual" << std::endl;
      std::cout << "\t===============" <<  " " << "===============" <<  " ===============" << std::endl;
      std::cout << "\tIncome          $" << std::setw(11) << income <<  "    $" << std::setw(11) << income << std::endl;
      std::cout << "\tTaxes           $" << std::setw(11) << taxes  << "    $" << std::setw(11) << actTaxes << std::endl;
      std::cout << "\tTithing         $" << std::setw(11) << tithe << "    $"  << std::setw(11) << actTithe << std::endl;
      std::cout << "\tLiving          $" << std::setw(11) << living << "    $"  << std::setw(11) << actLiving << std::endl;
      std::cout << "\tOther           $" << std::setw(11) << other <<  "    $"  << std::setw(11) << actOther << std::endl;
      std::cout << "\t===============" <<  " " << "===============" << " " <<  "===============" << std::endl;
      std::cout << "\tDifference" << std::setw(7) << "$" << std::setw(7) << "" << differenceInit << std::setw(5) << "$" << std::setw(11) << difference << std::endl ;
    }
};

/******************************************
*Main accesses public members from class Budget
* before spinning the program up by tying them together.
* Getters and setters allow programmers to protect data
* members by making variables private.
 *****************************************/
int main()
{
   std::cout << std::fixed;
   std::cout.precision(2);
   double tithe = 0.0;
   double other = 0.0;
   Budget temp;
   temp.displayIntro();
   temp.getIncome();
   temp.getLiving();
   temp.getActLiving();
   temp.getActTax();
   temp.getActTithe();
   temp.setTithing(tithe);
   temp.setOther(other);
   temp.getActOther();
   temp.displayReport();
   return 0;
}
