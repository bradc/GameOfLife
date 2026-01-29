#include "../include/life.hpp"
#include <iostream>
#include <fstream>

void Life::initialize() 
{
/*
Pre: Life class has been allocated.
Post: The initial configuration has been created.
NOTE: This should, in future, be changed to read from a file rather than the command line.
*/
    // Ensure all elements in grid are set to a known value, 0.
    memset(grid,0, (gMaxCol+2)*(gMaxRow+2)*sizeof(int));

    std::cout << "List the coordinates for living cells." << std::endl;
    std::cout << "Terminate the list with the special pair -1 -1" << std::endl;
    
    int row{0}, col{0};  // initialize to dead
    std::cout << "Cell (e.g., row col)> ";
    std::cin >> row >> col; // read initial coordinates

    // prompt user for each pair.  Each pair should be specified as # #  (use a space between the numbers)
    while((row != -1) && (col != -1)) {
        // Ensure only the board is being updated and not the hedge.
        if((row >= 1) && (row <= gMaxRow))  {
            if((col >= 1) && (col <= gMaxCol)) {
                grid[row][col] = 1;
            } else {
                std::cout << "Column " << col  << " is out of range." << std::endl;
            }
        } else {
            std::cout << "Row " << row << " is out of range." << std::endl;
        }
        std::cout << "Cell (e.g., row col)> ";
        std::cin >> row >> col; // read next coordinates
    }

}

void Life::initialize(const std::string fileName)
{
    if(!fileName.empty())
        load_configuration_from_file(fileName);
}

bool Life::load_configuration_from_file(const std::string fileName) 
{
    bool result = true;  
    int row{0}, col{0};

    std::fstream in_str(fileName);
    if(!in_str) {
        std::cerr << "Error: file stream failed to open" << std::endl;
        return false;
    }

    in_str >> row >> col;
    while((row != -1) && (col != -1) && !in_str.eof())
    {
        if((row >= 1) && (row <= gMaxRow))  {
            if((col >= 1) && (col <= gMaxCol)) {
                grid[row][col] = 1;
            } else {
                std::cerr << "Column " << col  << " is out of range." << std::endl;
                result = false;                    
            }
        } else {
            std::cerr << "Row " << row << " is out of range." << std::endl;
            result = false;
        }

        if(!result) break;
        in_str >> row >> col;
    }
    return result;    
}


void Life::print() {
/*
Pre: A configuration is available to be displayed.
Post: The current configuration is displayed to the output.
*/
    std::cout << "\nThe current Life configuration is:" << std::endl;
    for(int row=1; row <= gMaxRow; row++){
        for(int col=1; col <= gMaxCol; col++){
            if(grid[row][col]) 
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Life::update() 
{
/*
Pre: A configuration exists and has been initialized.
Post: The next generation is prepared.
*/
    int row {0}, col{0};
    int new_grid[gMaxRow+2][gMaxCol+2]={Dead};  //  intermediary to house the new generation

    // Generate the next configuration
    for(row=1; row <= gMaxRow; ++row) 
    {
        for(col=1; col <= gMaxCol; ++col) 
        {
            switch(neighbor_count(row,col)) 
            {
                case 2:
                    new_grid[row][col] = grid[row][col]; // status stays the same :|
                    break;
                case 3:
                    new_grid[row][col] = Alive; // cell is now alive :)
                    break;
                default:
                    new_grid[row][col] = Dead; // cell is now dead :(
                    break;
            }
        }
    }

    // replace current configuration with the newly generated interim configuration
    std::memcpy(grid,new_grid, (gMaxCol+2)*(gMaxRow+2)*sizeof(int));
}

int Life::neighbor_count( int row, int col )
/*
Pre: a life configuration exists and (row, col) reference a cell in that configuration
Post: The neighbor count of the specified cell is returned
*/
{
    int count = 0;

    for(int r=row-1; r <= row+1; r++ ) {
        for(int c=col-1; c <= col+1; c++ ){
            count += grid[r][c];
        }
    }
    count -= grid[row][col]; // remove counting self
    return count;
}
