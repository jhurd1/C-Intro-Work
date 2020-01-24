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
*    Actual:     3.0 hrs
*       The most difficult part comprised getting
* the tax calculator to recognize the income variable. I
* assumed that calling getIncome() would allow it to see
* it, but it didn't. Showing the method as part of the class
* allowed me to scope "income" in by itself without having
* to call extemporaneous methods, like getters. Conversely,
* I realized that instantiating a new object of the class before
* calling a getter on it did not work, either. Only calling the
* getter directly (without a class object fastened to it) or
* placing the variable itself allowed other methods to get access
* to these variables or data members.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
/**********************************************************************
* BudgetCT holds data members.
 *********************************************************************/
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
      //double tithe;
      double differenceTwo;
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
/*********************************************************************
 * Compute the user's tax bracket for projecting the tax imposition.
 *********************************************************************/
double computeTax(){
       annual = income * 12;
       if(annual >= 0 && annual <= 15100)
       {
          taxes = getBracket1() * income;
       }
       if((annual >= 15100) && (annual <= 61300))
       {
          taxes = (1510 + (getBracket2() * (annual - 15100))) / 12;
       }
       if((annual >= 61300) && (annual <= 123700))
       {
          taxes = (8440 + (getBracket3() * (annual - 61300))) / 12;
       }
       if((annual >= 123700) && (annual <= 188450))
       {
           taxes = (24040 + (getBracket4() * (annual - 123700))) / 12;
       }
       if((annual >= 188450) && (annual <= 336550))
       {
          taxes = (42170 + (bracket5 * (annual - 188450))) / 12;
       }
       if(annual >= 336550){
          taxes = (91043 + (getBracket6() * (annual - 336550))) / 12;
       }
   return taxes;
   }
      
   /******************************************
   * Accessors and mutators help provide programmers with
   * control over what parameters can be implemented
   * with child classes or using the parent class.
   *****************************************/
      //mutators
      double setTithing(double tithing){
         this->tithing = tithing;
         tithing = income * .1;
         return tithing;
      }
      
      double setOther(double other){
         this->other = other;
         other = income - (taxes + setTithing(tithing) + living);
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

       void displayIntro(){
               std::cout << "This program keeps track of your monthly budget" << std::endl;
               std::cout << "Please enter the following:" << std::endl;
       }
       
       void displayReport(){
          BudgetCT budget;
         double differenceInit = 0.00;
         difference = income - (actLiving + actTaxes + actTithe + actOther);
         std::cout << "The following is a report on your monthly expenses" << std::endl;
         std::cout << "\tItem" << std::setw(24) << "Budget" << std::setw(16) << "Actual" << std::endl;
         std::cout << "\t===============" <<  " " << "===============" <<  " ===============" << std::endl;
         std::cout << "\tIncome          $" << std::setw(11) << income <<  "    $" << std::setw(11) << income << std::endl;
         std::cout << "\tTaxes           $" << std::setw(11) << computeTax()  << "    $" << std::setw(11) << actTaxes << std::endl;
         std::cout << "\tTithing         $" << std::setw(11) << setTithing(tithing) << "    $"  << std::setw(11) << actTithe << std::endl;
         std::cout << "\tLiving          $" << std::setw(11) << living << "    $"  << std::setw(11) << actLiving << std::endl;
         std::cout << "\tOther           $" << std::setw(11) << setOther(other) <<  "    $"  << std::setw(11) << actOther << std::endl;
         std::cout << "\t===============" <<  " " << "===============" << " " <<  "===============" << std::endl;
         std::cout << "\tDifference" << std::setw(7) << "$" << std::setw(7) << "" << differenceInit << std::setw(5) << "$" << std::setw(11) << difference << std::endl ;
       }
   };

/******************************************
* Main accesses public members from class Budget
* before spinning the program up by tying them together.
* Getters and setters allow programmers to protect data
* members by making variables private.
*****************************************/
   int main()
   {
      std::cout << std::fixed;
      std::cout.precision(2);
      BudgetCT temp;
      temp.displayIntro();
      temp.getIncome();
      temp.getLiving();
      temp.getActLiving();
      temp.getActTax();
      temp.getActTithe();
      temp.getActOther();
      temp.displayReport();
      return 0;
   }
