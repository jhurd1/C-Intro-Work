/***********************************************************************
* Program:
*    Assignment 21, Debugging
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program contains the signatures or stub methods for the program outlined.
*
*    Estimated:  1.0 hrs
*    Actual:     .25 hrs
*       The most difficult part comprised not having more to do with it yet.
************************************************************************/
#include <stdio.h>
#include <iomanip>
#include <iostream>
/**********************************************************************
* Debug holds data members.
*********************************************************************/
class Debug{
private:
   double devalue;
   double periodCost;
   double usageCost;
   double mileage;
   double gas;
   double parking;
   double repairs;
   double tires;
   double insurance;
protected:
public:
/**********************************************************************
* Constructors
*********************************************************************/
   Debug(){
      
   }
   
   Debug(double devalue){
      
   }
/**********************************************************************
* Accessors and Mutators
*********************************************************************/
   double getPeriodCost(){
      promptParking();
      promptGas();
      promptRepairs();
      promptTires();
      promptInsurance();
      periodCost = parking + gas + repairs + tires + insurance;
      return periodCost;
   }
   
   double getUsageCost(){
      promptDevalue();
      promptMileage(mileage);
      usageCost = devalue + mileage;
      return usageCost;
   }
   
/**********************************************************************
* Class methods
*********************************************************************/
   void promptDevalue(){
      
   }
   
   void promptInsurance(){
      
   }
   
   void promptParking(){
      
   }
   
   double promptMileage(double mileage){
      return mileage;
   }
   
   void promptGas(){
      
   }
   
   void promptRepairs(){
      
   }
   
   void promptTires(){
      
   }
   
   void display(){
      std::cout << "Success\n";
   }
};

/**********************************************************************
* Main calls data members.
*********************************************************************/
int main()
{
   Debug debug;
   debug.display();
}
