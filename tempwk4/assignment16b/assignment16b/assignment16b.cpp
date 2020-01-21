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
*       The most difficult part comprised deciding whether I'll be docked points
* for using a switch statement instead of if statements.
************************************************************************/
#include <stdio.h>
#include <iostream>

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
   void setIncome(int income){
       this->income = income;
   }
   
   void setBrackets(int bracket1,
                    int bracket2,
                    int bracket3,
                    int bracket4,
                    int bracket5,
                    int bracket6){
      TaxBracket setObj;
      setObj.calcBracket(income);
   }
   
   int calcBracket(int income){
      TaxBracket calc;
      calc.getIncome();
      if((income > 0) && (income < 15100))
           {
              std::cout << calc.iterator() << bracket1;
           }
           if((income > 15100) && (income < 61300))
           {
              std::cout << calc.iterator() << bracket2;
           }
           if((income > 61300) && (income < 123700))
           {
              std::cout << calc.iterator() << bracket3;
           }
           if((income > 123700) && (income < 188450))
           {
               std::cout << calc.iterator() << bracket4;
           }
           if((income > 188450) && (income < 336550))
           {
              std::cout << calc.iterator() << bracket5;
           }
           if(income > 336550){
              std::cout << calc.iterator() << bracket6;
           }
      return 0;
   }
   
   int getIncome()
   {
      int income;
      std::cout << "Income: ";
      std::cin >> income;
      return income;
   }
   
   //default constructor
   TaxBracket()
   {
      
   }
   //non-default constructor
   TaxBracket(int income)
   {
      
   }
   
   //iterator
std::string iterator()
   {
      std::string displayBracket = "Your tax bracket is: ";
      return displayBracket;
   }
   
   //display results
   void display()
   {
      TaxBracket displayObj;
      displayObj.setBrackets(bracket1,
      bracket2,
      bracket3,
      bracket4,
      bracket5,
      bracket6);
   }
};

/*****************************************
 * As it stands, main() should only have to call display()
 * to get the ball rolling.
 *****************************************/
int main()
{
   TaxBracket test;
   test.display();
}
