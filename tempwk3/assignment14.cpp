/***********************************************************************
* Program:
*    Assignment 14, Matthew 18:21-22
*    Brother {Neff, Jones, Helfrich, Smith, Grimmett, Sloan, Comeau}, CS124
* Author:
*    you name here
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      Please describe briefly what was the most difficult part
************************************************************************/
#include <iostream>
using namespace std;

void questionPeter(){
    std::cout << "Lord, how oft shall my brother sin against me, and I forgive him?"
    << "\n" << "Till seven times?" << endl;
}

int responseLord(){
    int weekDays = 7;
    int tenTimes = 70;
    int compute = weekDays * tenTimes;
    return compute;
}
/**********************************************************************
* You are not allowed to change MAIN in any way; just implement the two
* functions: questionPeter() and responseLord()
***********************************************************************/
int main()
{
   // ask Peter's question
   questionPeter();

   // the first part of the Lord's response
   cout << "Jesus saith unto him, I say not unto thee, Until seven\n";
   cout << "times: but, Until " << responseLord() << ".\n";

   return 0;
}
