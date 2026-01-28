#pragma once

#include "../include/utility.hpp"
#include <cctype>
#include <iostream>
#include <ostream>

void instructions()
{
    std::cout 
        << "This is Conway's Game of Life" 
        << "With an initial configuration, subsequent iterations will show mutations of the initial configuration. " << std::endl
        << "Cells will live, die and be born based on lonliness and overcrowding." << std::endl
        << std::endl;
}

bool user_says_yes()
{
    bool initial_response = true;
    int ch;

    do {
        if(initial_response)
            std::cout << " (y,n)? " << std::flush;
        else
            std::cout << "Respond with either y or n: " << std::flush;

        // capture user's input (should be only y or n (case insensitive))
        do {
            ch = std::cin.get();
        } while(std::isblank(ch) || std::iscntrl(ch));
        
        // turn off initial flag
        initial_response = false;

        // at this point the character should be an alphabetic, but test anyway.
        if(std::isalpha(ch))
                ch = std::tolower(ch);    // normalize to lowercase to make comparison less clunky.
            
    } while(ch != 'y' && ch != 'n');

    return (ch == 'y');
}