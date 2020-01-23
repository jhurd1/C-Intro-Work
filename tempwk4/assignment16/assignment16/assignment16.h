/***********************************************************************
* Program:
*    Assignment 16, If Statements
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program incorporates a tax bracket determination algorithm.
*
*    Estimated:  1.0 hrs
*    Actual:     1.5 hrs
*       The most difficult part comprised
************************************************************************/
#ifndef TaxBracket_H
#define TaxBracket_H
class TaxBracket{
private:
   int income;
   int bracket1 = 10;
   int bracket2 = 15;
   int bracket3 = 25;
   int bracket4 = 28;
   int bracket5 = 33;
   int bracket6 = 35;
protected:
public:
   //mutators
   void setIncome(int income);
   void setBrackets(const int bracket1,
                    const int bracket2,
                    const int bracket3,
                    const int bracket4,
                    const int bracket5,
                    const int bracket6);
   //accessors
   int getIncome();
   int getBrackets();
   //default constructor
   TaxBracket();
   //non-default constructor
   TaxBracket(int income);
   //iterator
   std::string iterator();
   //calculate bracket
   void calcBracket();
   //display results
   void display();
};
#endif