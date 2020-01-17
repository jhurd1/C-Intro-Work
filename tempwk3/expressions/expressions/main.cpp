/***********************************************************************
* Program:
*    Prepare 1.3, Expressions        (e.g. Assignment 10, Hello World)
*    Brother Schwieder, CS124
* Author:
*    Jamie Hurd
* Summary:
*    This program converts Fahrenheit to Celsius
*
*    Estimated:  0.0 hrs
*    Actual:     0.0 hrs
*       The most difficult part comprised
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
    float third = 5.0;
    float fourth = 9.0;
    float fifth = 32.0;
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
                std::cout << "Celsius: " << celsius;
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
