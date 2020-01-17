/***********************************************************************
* Program:
*    Assignment 13, Expressions        (e.g. Assignment 10, Hello World)
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program converts Fahrenheit to Celsius
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*       The most difficult part comprised getting the loop to run.
* Initially, I had a for loop but the one proved unnecessary
* as I did not have numbers to count, so got rid of it and left the
* if statement.
************************************************************************/
#include <iostream>
/**********************************************************************
* Celsius contains data members used by main() to initialize
* and complete the program.
***********************************************************************/
class Celsius{
private:
    float celsius;
    float fahrenheit;
    const float third = 5.0;
    const float fourth = 9.0;
    const float fifth = 32.0;
    bool run = true;
protected:
public:
    //Default constructor
    Celsius(){
        
    }
    
    //Non-default consturctor passes in members
    Celsius(float first, float second){
        
    }
    /**********************************************************************
    * Convert() prompts, calculates, and displays the conversion.
    ***********************************************************************/
    void convert(){
            if(run == true){
                std::cout << "Please enter Fahrenheit degrees: ";
                std::cin >> fahrenheit;
                celsius = third / fourth * (fahrenheit - fifth);
                std::cout << "Celsius: " << celsius << std::endl;
            }
        }
};

/**********************************************************************
* Main initializes the program and
* outputs the celsius calculation to the console window.
***********************************************************************/
int main(int argc, const char * argv[]) {
    std::cout << std::fixed;
    std::cout.precision(0);
    Celsius callMe;
    callMe.convert();
}
