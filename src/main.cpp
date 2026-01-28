#include <iostream>

#include "../include/life.hpp"
#include "../include/utility.hpp"

int main()
{
    /*
    Pre:
        The user supplies the initial configuration of living cells.
    Post:
        The program prints a sequence of pictures showing the changes in the configuration of living cells according 
        to the rules for the game of life.
    Uses:
        The class Life and its mnethods initialize(), print(), and update().
        The functions instructions(), user_says_yes()
    */
    Life configuration;
    instructions();
    configuration.initialize();
    configuration.print();
    std::cout << "Continue viewing new generations? " << std::flush;
    while(user_says_yes()) 
    {
        configuration.update();
        configuration.print();
        std::cout << "Continue viewing new generations? " << std::flush;
    }

    return 0;
}