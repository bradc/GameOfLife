#pragma once

#include <iostream>
#include <istream>

const int gMaxRow = 20;
const int gMaxCol = 60;

 constexpr int Alive = 1;
 constexpr int Dead = 0;

class Life
{
    public:
        void initialize();
        void initialize(const std::string fileName);
        void update();
        void print();
    private:
        bool load_configuration_from_file(const std::string);
        int  neighbor_count(int row, int col);

    // Data
        int grid[gMaxRow+2][gMaxCol+2]{0};
};