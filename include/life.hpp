#pragma once


const int gMaxRow = 20;
const int gMaxCol = 60;

 constexpr int Alive = 1;
 constexpr int Dead = 0;

class Life
{
    public:
        void initialize();
        void update();
        void print();
    private:
        int  neighbor_count(int row, int col);

    // Data
        int grid[gMaxRow+2][gMaxCol+2]{0};
};