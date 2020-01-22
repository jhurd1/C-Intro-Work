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

#ifndef project04_hpp
#define project04_hpp

#include <stdio.h>
class BudgetCT{//budget-compute-tithing
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
   double differenceTwo;
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
   double getDifference();
   double getIncome();
   double getLiving();
   double getActIncome();
   double getActTaxes();
   double getActTithe();
   double getActLiving();
   double getActOther();
   double getDifferenceTwo();
   double getABunch();
   //mutators
   void setBracket1(double bracket1);
   void setBracket2(double bracket2);
   void setBracket3(double bracket3);
   void setBracket4(double bracket4);
   void setBracket5(double bracket5);
   void setBracket6(double bracket6);
   void setTaxes(double taxes);
   void setTithe(double tithing);
   void setOther(double other);
   void setDifference(double difference);
   void setIncome(double income);
   void setActIncome(double actIncome);
   void setActTaxes(double actTaxes);
   void setActTithe(double actTithe);
   void setactLiving(double actLiving);
   void setActOther(double actOther);
   void setDifferenceTwo(double differenceTwo);
   //other methods
   double calcTithing();
   double computeTax();
   std::string iterator();
   void displayIntro();
   void displayReport();
   void prompt();
   
};
#endif /* project04_hpp */
