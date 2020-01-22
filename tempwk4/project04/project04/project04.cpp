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
*Use setters to allow main() to access private data members.
 *********************************************************************/
/*
void BudgetCT::setBracket1(double bracket1)
{
   this->bracket1 = bracket1;
}
void BudgetCT::setBracket2(double bracket2)
{
   this->bracket2 = bracket2;
}

void BudgetCT::setBracket3(double bracket3)
{
   this->bracket3 = bracket3;
}

void BudgetCT::setBracket4(double bracket4)
{
   this->bracket4 = bracket4;
}

void BudgetCT::setBracket5(double bracket5)
{
   this->bracket5 = bracket5;
}

void BudgetCT::setBracket6(double bracket6)
{
   this->bracket6 = bracket6;
}

void BudgetCT::setTaxes(double taxes)
{
   this->taxes = taxes;
}

void BudgetCT::setTithe(double tithing)
{
   this->tithing = tithing;
}

void BudgetCT::setOther(double other)
{
   this->other = other;
}

void BudgetCT::setDifference(double difference)
{
   this->difference = difference;
}

void BudgetCT::setIncome(double income)
{
   this->income = income;
}

void BudgetCT::setActIncome(double actIncome)
{
   this->actIncome = actIncome;
}

void BudgetCT::setActTaxes(double actTaxes)
{
   this->actTaxes = actTaxes;
}

void BudgetCT::setActTithe(double actTithe)
{
   this->actTithe = actTithe;
}

void BudgetCT::setactLiving(double actLiving)
{
   this->actLiving = actLiving;
}

void BudgetCT::setActOther(double actOther)
{
   this->actOther = actOther;
}*/

/*********************************************************************
* Use iterators to repeat the string when you calculate the tax bracket.
*********************************************************************/
std::string BudgetCT::iterator()
{
   std::string displayBracket = "Your tax bracket is ";
   return displayBracket;
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
      difference = income - (actLiving + actTaxes + actTithe + actOther);
      std::cout << "The following is a report on your monthly expenses" << std::endl;
      std::cout << "\tItem" << std::setw(24) << "Budget" << std::setw(16) << "Actual" << std::endl;
      std::cout << "\t===============" <<  " " << "===============" <<  " ===============" << std::endl;
      std::cout << "\tIncome          $" << std::setw(11) << budget.getIncome() <<  "    $" << std::setw(11) << budget.getIncome() << std::endl;
      std::cout << "\tTaxes           $" << std::setw(11) << budget.computeTax()  << "    $" << std::setw(11) << budget.getActTaxes() << std::endl;
      std::cout << "\tTithing         $" << std::setw(11) << budget.calcTithing() << "    $"  << std::setw(11) << budget.getActTithe() << std::endl;
      std::cout << "\tLiving          $" << std::setw(11) << budget.getLiving() << "    $"  << std::setw(11) << budget.getActLiving() << std::endl;
      std::cout << "\tOther           $" << std::setw(11) << budget.getOther() <<  "    $"  << std::setw(11) << budget.getActOther() << std::endl;
      std::cout << "\t===============" <<  " " << "===============" << " " <<  "===============" << std::endl;
      std::cout << "\tDifference" << std::setw(7) << "$" << std::setw(7) << "" << differenceInit << std::setw(5) << "$" << std::setw(11) << budget.getDifference() << std::endl ;
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

