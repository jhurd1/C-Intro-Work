/***********************************************************************
* Program:
*    Assignment 15, Full Tithe Payer
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program will compute if a user is a full tithe payer using
*    the complicated formula provided in the scriptures:
*        And after that, those who have thus been tithed shall
*        pay one-tenth of all their interest annually; and this
*        shall be a standard law unto them forever, for my holy
*        priesthood, saith the Lord.  D&C 119:4
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*      The most difficult part involved getting the logic correct
* in my if statement with the boolean because I kept getting
* false positives, which would have given every man a golden
* ticket into God's kingdom.
************************************************************************/
#include <iostream>

class WorkThatBool{
private:
   bool full = true;
   float income;
   float tithe;
   float total;
protected:
public:
   //Default constructor
   WorkThatBool(){
      
   }
   //Non-default constructor
   WorkThatBool(float income, float tithe){
      
   }
   
   float prompt(){
      // prompt user for income
      std::cout << "Income: ";
      std::cin  >> income;

      // prompt user for tithe
      std::cout << "Tithe: ";
      std::cin  >> tithe;
      total = income * .1;
      return total;
   }
   /*****************************************************
    *Call prompt, access the total and tithe, calculate tithing status
    * pass in boolean full to test.
    *****************************************************/
   bool isFullTithePayer()
   {
      WorkThatBool yo;
      yo.prompt();
      if(total > tithe){
      full = false;
      }
      if (full == true)
         std::cout << "You are a full tithe payer.\n";
      else
         std::cout << "Will a man rob God?  Yet ye have robbed me.\n"
              << "But ye say, Wherein have we robbed thee?\n"
              << "In tithes and offerings.  Malachi 3:8\n";
      return full;
   }
};

/**********************************************************************
 * Main will call isFullTithePayer() and display an appropriate message
 * to the user based on the results
 ***********************************************************************/
int main()
{
   WorkThatBool fool;
   fool.isFullTithePayer();
   return 0;
}
