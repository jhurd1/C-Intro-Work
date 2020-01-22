/***********************************************************************
* Program:
*    Project 04, Monthly Budget
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
*       The most difficult part comprised getting
* the tax calculator to recognize the income variable. I
* assumed that calling getIncome() would allow it to see
* it, but it didn't. Showing the method as part of the class
* allowed me to scope "income" in by itself without having
* to call extemporaneous methods, like getters.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include "project04.hpp"

/*********************************************************************
* Construct an object to work from.
*********************************************************************/
BudgetCT::BudgetCT()
{
   
}

/*********************************************************************
*Use getters to allow main() to access private data members.
 *********************************************************************/
double BudgetCT::getBracket1()
{
   return bracket1;
}

double BudgetCT::getBracket2()
{
   return bracket2;
}

double BudgetCT::getBracket3()
{
   return bracket3;
}

double BudgetCT::getBracket4()
{
   return bracket4;
}

double BudgetCT::getBracket5()
{
   return bracket5;
}

double BudgetCT::getBracket6()
{
   return bracket6;
}

double BudgetCT::getTaxes()
{
   return taxes;
}

double BudgetCT::getTithe()
{
   return tithing;
}

double BudgetCT::getOther()
{
   return other;
}

double BudgetCT::getDifference()
{
   return difference;
}

void BudgetCT::prompt()
{
   std::cout << "\tYour monthly income: ";
   std::cin >> income;
   std::cout << "\tYour budgeted living expenses: ";
   std::cin >> living;
   std::cout << "\tYour actual living expenses: ";
   std::cin >> actLiving;
   std::cout << "\tYour actual taxes withheld: ";
   std::cin >> actTaxes;
   std::cout << "\tYour actual tithe offerings: ";
   std::cin >> actTithe;
   std::cout << "\tYour actual other expenses: ";
   std::cin >> actOther;
   std::cout << std::endl;
}

double BudgetCT::getIncome(){
   return income;
}

double BudgetCT::getLiving(){
   return living;
}

double BudgetCT::getActIncome()
{
   return actIncome;
}

double BudgetCT::getActTaxes(){
   return actTaxes;
}

double BudgetCT::getActTithe(){
   return actTithe;
}

double BudgetCT::getActLiving(){
   return actLiving;
}

double BudgetCT::getActOther(){
   return actOther;
}

/*********************************************************************
 * Compute the user's tax bracket for projecting the tax imposition.
 *********************************************************************/
double BudgetCT::computeTax(){
   BudgetCT calc;
   annual = calc.getIncome() * 12;
   if((annual > 0) && (annual < 15100))
   {
      calc.getBracket1();
      taxes = bracket1 * income;
   }
   if((annual > 15100) && (annual < 61300))
   {
     calc.getBracket2();
      taxes = bracket2 * income;
   }
   if((annual > 61300) && (annual < 123700))
   {
      calc.getBracket3();
      taxes = bracket3 * income;
   }
   if((annual > 123700) && (annual < 188450))
   {
       calc.getBracket4();
       taxes = bracket4 * income;
   }
   if((annual > 188450) && (annual < 336550))
   {
      calc.getBracket5();
      taxes = bracket5 * income;
   }
   if(annual > 336550){
      calc.getBracket6();
      taxes = bracket6 * calc.getIncome();
   }
   return taxes;
   }

/*********************************************************************
* Calculate the tithing.
*********************************************************************/
double BudgetCT::calcTithing()
{
   BudgetCT forTithe;
   forTithe.getIncome();
   tithing = income * .1;
   return tithing;
}

double BudgetCT::calcDiff()
{
   BudgetCT diff;
   difference = diff.getIncome() - (diff.getActLiving() + diff.getActTaxes() + diff.getActTithe() + diff.getActOther());
   return difference;
}
/*********************************************************************
* Display the doubleroduction for the report.
*********************************************************************/
void BudgetCT::displayIntro(){
      BudgetCT dis;
      std::cout << "This program keeps track of your monthly budget" << std::endl;
      std::cout << "Please enter the following:" << std::endl;
      dis.prompt();
   }
    
void BudgetCT::displayReport(){
       BudgetCT budget;
      double differenceInit = 0.00;
      taxes = 0.0;
      difference = budget.getIncome() - (budget.getActLiving() + budget.getActTaxes() + budget.getActTithe() + budget.getActOther());
      std::cout << "The following is a report on your monthly expenses" << std::endl;
      std::cout << "\tItem" << std::setw(24) << "Budget" << std::setw(16) << "Actual" << std::endl;
      std::cout << "\t===============" <<  " " << "===============" <<  " ===============" << std::endl;
      std::cout << "\tIncome          $" << std::setw(11) << budget.getIncome() <<  "    $" << std::setw(11) << budget.getIncome() << std::endl;
      std::cout << "\tTaxes           $" << std::setw(11) << budget.computeTax()  << "    $" << std::setw(11) << budget.getActTaxes() << std::endl;
      std::cout << "\tTithing         $" << std::setw(11) << budget.calcTithing() << "    $"  << std::setw(11) << budget.getActTithe() << std::endl;
      std::cout << "\tLiving          $" << std::setw(11) << budget.getLiving() << "    $"  << std::setw(11) << budget.getActLiving() << std::endl;
      std::cout << "\tOther           $" << std::setw(11) << budget.getOther() <<  "    $"  << std::setw(11) << budget.getActOther() << std::endl;
      std::cout << "\t===============" <<  " " << "===============" << " " <<  "===============" << std::endl;
      std::cout << "\tDifference" << std::setw(7) << "$" << std::setw(7) << "" << differenceInit << std::setw(5) << "$" << std::setw(11) << difference << std::endl ;
    }

/*********************************************************************
* Spin up the program with main.
*********************************************************************/
int main()
{
   BudgetCT begin;
   begin.displayIntro();
   begin.displayReport();
}

