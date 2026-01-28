#include <iostream>
#include "../include/utility.hpp"

/* Test driver for the utility function user_says_yes() */

int main()
{
    std::cout << "Enter y or n: ";
    bool y_or_n = user_says_yes();
    std::cout << "User said: ";
    std::cout << ((y_or_n) ? "Yes" : "No") << std::endl;

    return 0;
}