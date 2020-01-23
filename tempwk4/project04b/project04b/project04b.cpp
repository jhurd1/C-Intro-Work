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

/**Brother Schwieder:
 *Make variables local when they won't pass testbed,
 *simplify the code by deleting the class completely
 *then see if it passes testbed
 *(copy project03 in as needed.)
 *Won't be going into classes in this class
 *but will be addressing pointers.
 */

class BudgetCT{
private:
   double annual;
     double tithing;
     double income;
     double bracket1 = .10;
     double bracket2 = .15;
     double bracket3 = .25;
     double bracket4 = .28;
     double bracket5 = .33;
     double bracket6 = .35;
     double living;
     double taxes;
     double other;
     double difference;
     double actIncome;
     double actTaxes;
     double actTithe;
     double actLiving;
     double actOther;
   public:
  
/*********************************************************************
* Construct an object to work from.
*********************************************************************/
BudgetCT()
{
   
}

/*********************************************************************
*Use getters to allow main() to access private data members.
 *********************************************************************/
double getBracket1()
{
   return bracket1;
}

double getBracket2()
{
   return bracket2;
}

double getBracket3()
{
   return bracket3;
}

double getBracket4()
{
   return bracket4;
}

double getBracket5()
{
   return bracket5;
}

double getBracket6()
{
   return bracket6;
}

double getTaxes()
{
   return taxes;
}

double getTithe()
{
   return tithing;
}

double getOther()
{
   return other;
}

void prompt()
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

   
double getIncome(){
   return income;
}

double getLiving(){
   return living;
}

double getActIncome()
{
   return actIncome;
}

double getActTaxes(){
   return actTaxes;
}

double getActTithe(){
   return actTithe;
}

double getActLiving(){
   return actLiving;
}

double getActOther(){
   return actOther;
}

/*********************************************************************
 * Compute the user's tax bracket for projecting the tax imposition.
 *********************************************************************/
double computeTax(){
   BudgetCT calc;
   annual = income * 12;
   if((annual > 0) && (annual < 15100))
   {
      //calc.getBracket1();
      taxes = bracket1 * income;
   }
   if((annual > 15100) && (annual < 61300))
   {
     //calc.getBracket2();
      taxes = bracket2 * income;
   }
   if((annual > 61300) && (annual < 123700))
   {
      //calc.getBracket3();
      taxes = bracket3 * income;
   }
   if((annual > 123700) && (annual < 188450))
   {
       //calc.getBracket4();
       taxes = bracket4 * income;
   }
   if((annual > 188450) && (annual < 336550))
   {
      //calc.getBracket5();
      taxes = bracket5 * income;
   }
   if(annual > 336550){
      //calc.getBracket6();
      taxes = bracket6 * income;
   }
   return taxes;
   }

/*********************************************************************
* Calculate the tithing.
*********************************************************************/
double calcTithing()
{
   BudgetCT forTithe;
   forTithe.getIncome();
   tithing = income * .1;
   return tithing;
}

/*********************************************************************
* Display the doubleroduction for the report.
*********************************************************************/
void displayIntro(){
      BudgetCT dis;
      std::cout << "This program keeps track of your monthly budget" << std::endl;
      std::cout << "Please enter the following:" << std::endl;
      dis.prompt();
   }
    
void displayReport(){
   std::cout << std::fixed;
   std::cout.precision(2);
   BudgetCT budget;
   double differenceInit = 0.00;
   taxes = 0.0;
   difference = income - (actLiving + actTaxes + actTithe + actOther);
   std::cout << "The following is a report on your monthly expenses" << std::endl;
   std::cout << "\tItem" << std::setw(24) << "Budget" << std::setw(16) << "Actual" << std::endl;
   std::cout << "\t===============" <<  " " << "===============" <<  " ===============" << std::endl;
   std::cout << "\tIncome          $" << std::setw(11) << income <<  "    $" << std::setw(11) << income << std::endl;
   std::cout << "\tTaxes           $" << std::setw(11) << budget.computeTax()  << "    $" << std::setw(11) << actTaxes << std::endl;
   std::cout << "\tTithing         $" << std::setw(11) << budget.calcTithing() << "    $"  << std::setw(11) << actTithe << std::endl;
   std::cout << "\tLiving          $" << std::setw(11) << living << "    $"  << std::setw(11) << actLiving << std::endl;
   std::cout << "\tOther           $" << std::setw(11) << actOther <<  "    $"  << std::setw(11) << actOther << std::endl;
   std::cout << "\t===============" <<  " " << "===============" << " " <<  "===============" << std::endl;
   std::cout << "\tDifference" << std::setw(7) << "$" << std::setw(7) << "" << differenceInit << std::setw(5) << "$" << std::setw(11) << difference << std::endl ;
}
};
/*********************************************************************
* Spin up the program with main.
*********************************************************************/
int main()
{
   BudgetCT begin;
   begin.displayIntro();
   begin.displayReport();
}
