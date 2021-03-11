#include <iostream>
#include <vector>
#include <cstdlib>


void parse(void)
{

}





int main(int Argc, char * Argv[])
{
    int grid_x, grid_y, Buildings_N, Antenna_M, Reward_R;
    char newline_Dump;

    std::cin >> grid_x >> grid_y >> newline_Dump;
    std::cin >> Buildings_N >> Antenna_M >> Reward_R >> newline_Dump;

    std::cout << grid_y << grid_y << Buildings_N << Antenna_M << Reward_R;

    return 0;
}
