#include <iostream>
#include <vector>
#include <cstdlib>


void parse_building(int &number)
{
    int counter = number-1;
    int Bx, By, Bl, Bc;
    while(counter != 0)
    {
        std::cin >> Bx >> By >> Bl >> Bc;
        counter--;
    }
    //DO something with the structure
}

void parse_antenna(int &number)
{
    int counter = number-1;
    int Ar, Ac;
    while (counter !=0)
    {
        std::cin >> Ar >> Ac;
        counter--;
    }
    //Do something with the structure
}


int main(int Argc, char * Argv[])
{
    int grid_x, grid_y, Buildings_N, Antenna_M, Reward_R;

    std::cin >> grid_x >> grid_y>> Buildings_N >> Antenna_M >> Reward_R;; 

    // std::cout << "X" << grid_x << "Y" << grid_y << "N" << Buildings_N << "M" << Antenna_M << "R" << Reward_R;
    
    parse_building(Buildings_N);
    parse_antenna(Antenna_M);
    
    return 0;
}
