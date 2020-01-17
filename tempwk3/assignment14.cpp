/***********************************************************************
* Program:
*    Assignment 14, Functions
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary: 
*    This program will address Peter's question to the Lord in 
*    Matthew 18:21-22
*
*    Estimated:  0.0 hrs   
*    Actual:     0.0 hrs
*      The most difficult part was submitting the assignment
* because I initialized the project in the wrong directory
* apparently, making it difficult to find the right file when
* submitting.
************************************************************************/
#include <iostream>
using namespace std;

/**********************************************************************
* Outputs to console Peter's important question on forgiveness.
***********************************************************************/
void questionPeter(){
    std::cout << "Lord, how oft shall my brother sin against me, and I forgive him?"
    << "\n" << "Till seven times?" << endl;
}

/**********************************************************************
* Computes 7 * 70
***********************************************************************/
int responseLord(){
    const int weekDays = 7;
    const int tenTimes = 70;
    const int compute = weekDays * tenTimes;
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
