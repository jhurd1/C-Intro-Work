//
//  main.cpp
//  loopTest
//
//  Created by Jamie  Hurd on 2/1/20.
//  Copyright © 2020 Jamie  Hurd. All rights reserved.
//

#include <iostream>

int loopTest()
{
   int i;
   for(i = 0; i < 4; i++)
   {
      std::cout << "H";
      std::cout << std::endl;
   }
   return i;
}

char input()
{
   char input;
   do
   {
      std::cout << "input: ";
      std::cin >> input;
      std::cout << "\t" << input << std::endl;
   }
   while(input != 'x');
   return input;
}

int loopTestTwo()
{
   int i;
   for(i = 0; i <= 4; i++)
   {
      std::cout << "i == " << i << std::endl;
   }
   return i;
}

int sum()
{
   int sum = 0;
   int count;
   for(count = 0; count < 4; count++)
   {
      sum += count;
      std::cout << "sum == " << sum;
   }
   return sum;
}

int main(int argc, const char * argv[]) {
   sum();
}
