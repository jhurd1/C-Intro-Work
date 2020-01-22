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
* to call extemporaneous methods, like getters..
************************************************************************/

#ifndef project04_hpp
#define project04_hpp
#include <stdio.h>

class BudgetCT{
private:
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
protected:
public:
   double annual;
   //constructor
   BudgetCT();
   //non-default constructor
   BudgetCT(double tithing);
   //accessors
   double getBracket1();
   double getBracket2();
   double getBracket3();
   double getBracket4();
   double getBracket5();
   double getBracket6();
   double getTaxes();
   double getTithe();
   double getOther();
   double getIncome();
   double getLiving();
   double getActIncome();
   double getActTaxes();
   double getActTithe();
   double getActLiving();
   double getActOther();
   //mutators
   //other methods
   double calcTithing();
   double computeTax();
   std::string iterator();
   void displayIntro();
   void displayReport();
   void prompt();
   double calcDiff();
};
#endif /* project04_hpp */
