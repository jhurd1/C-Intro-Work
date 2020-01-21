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
*       The most difficult part comprised comprehending
* access and scope so that my report table output the
* user input in addition to finding what other's calcu-
* lation should be.
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
int BudgetCT::getBracket1()
{
   return bracket1;
}

int BudgetCT::getBracket2()
{
   return bracket2;
}

int BudgetCT::getBracket3()
{
   return bracket3;
}

int BudgetCT::getBracket4()
{
   return bracket4;
}

int BudgetCT::getBracket5()
{
   return bracket5;
}

int BudgetCT::getBracket6()
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

double BudgetCT::getOther(){
   std::cin >> other;
   return other;
}

double BudgetCT::getDifference()
{
   return difference;
}

double BudgetCT::getIncome(){
   std::cout << "\tYour monthly income: ";
   std::cin >> income;
   return income;
}

double BudgetCT::getLiving(){
   std::cout << "\tYour budgeted living expenses: ";
   std::cin >> living;
   return living;
}

double BudgetCT::getActIncome()
{
   return actIncome;
}

double BudgetCT::getActTaxes(){
   std::cout << "\tYour actual taxes withheld: ";
   std::cin >> actTaxes;
   return actTaxes;
}

double BudgetCT::getActTithe(){
   std::cout << "\tYour actual tithe offerings: ";
   std::cin >> actTithe;
   return actTithe;
}

double BudgetCT::getActLiving(){
   std::cout << "\tYour actual living expenses: ";
   std::cin >> actLiving;
   return actLiving;
}

double BudgetCT::getActOther(){
   std::cout << "\tYour actual other expenses: ";
   std::cin >> actOther;
   std::cout << std::endl;
   return actOther;
}

double BudgetCT::getDifferenceTwo()
{
   return differenceTwo;
}

/*********************************************************************
*Use setters to allow main() to access private data members.
 *********************************************************************/
void BudgetCT::setBracket1(int bracket1)
{
   this->bracket1 = bracket1;
}
void BudgetCT::setBracket2(int bracket2)
{
   this->bracket2 = bracket2;
}

void BudgetCT::setBracket3(int bracket3)
{
   this->bracket3 = bracket3;
}

void BudgetCT::setBracket4(int bracket4)
{
   this->bracket4 = bracket4;
}

void BudgetCT::setBracket5(int bracket5)
{
   this->bracket5 = bracket5;
}

void BudgetCT::setBracket6(int bracket6)
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
}

void BudgetCT::setDifferenceTwo(double differenceTwo)
{
   this->differenceTwo = differenceTwo;
}

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
double BudgetCT::computeTax(double income){
   BudgetCT calc;
   std::cout << "Income: ";
   std::cin >> income;
   if((income > 0) && (income < 15100))
   {
      std::cout << calc.iterator() << calc.getBracket1() << "%" << std::endl;
   }
   if((income > 15100) && (income < 61300))
   {
      std::cout << calc.iterator() << calc.getBracket2() << "%" << std::endl;
   }
   if((income > 61300) && (income < 123700))
   {
      std::cout << calc.iterator() << calc.getBracket3() << "%" << std::endl;
   }
   if((income > 123700) && (income < 188450))
   {
       std::cout << calc.iterator() << calc.getBracket4() << "%" << std::endl;
   }
   if((income > 188450) && (income < 336550))
   {
      std::cout << calc.iterator() << calc.getBracket5() << "%" << std::endl;
   }
   if(income > 336550){
      std::cout << calc.iterator() << calc.getBracket6() << "%" << std::endl;
   }
   return income;
   }

/*********************************************************************
* Display the introduction for the report.
*********************************************************************/
void BudgetCT::displayIntro(){
            std::cout << "This program keeps track of your monthly budget" << std::endl;
            std::cout << "Please enter the following:" << std::endl;
    }
    
void BudgetCT::displayReport(){
       BudgetCT budget;
      double differenceInit = 0.00;
      taxes = 0.0;
      difference = income - (actLiving + actTaxes + actTithe + actOther);
      std::cout << "The following is a report on your monthly expenses" << std::endl;
      std::cout << "\tItem" << std::setw(24) << "Budget" << std::setw(16) << "Actual" << std::endl;
      std::cout << "\t===============" <<  " " << "===============" <<  " ===============" << std::endl;
      std::cout << "\tIncome          $" << std::setw(11) << income <<  "    $" << std::setw(11) << income << std::endl;
      std::cout << "\tTaxes           $" << std::setw(11) << taxes  << "    $" << std::setw(11) << actTaxes << std::endl;
      std::cout << "\tTithing         $" << std::setw(11) << tithing << "    $"  << std::setw(11) << actTithe << std::endl;
      std::cout << "\tLiving          $" << std::setw(11) << living << "    $"  << std::setw(11) << actLiving << std::endl;
      std::cout << "\tOther           $" << std::setw(11) << other <<  "    $"  << std::setw(11) << actOther << std::endl;
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
}

