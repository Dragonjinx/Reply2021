#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "structure.h"

void parse_building(int &number, std::vector<Building*> &Buildings, std::ifstream &input)
{
    int counter = number-1;
    int Bx, By, Bl, Bc;
    while(counter != 0)
    {
        input >> Bx >> By >> Bl >> Bc;
        std::cout << Bx << By << Bl << Bc;
        counter--;
        //Building * store = new Building(Bx, By, Bl, Bc);
        //Buildings.push_back(store);
    }
    //DO something with the structure
}

void parse_antenna(int &number, std::vector<Antenna*> &Antennas, std::ifstream &input)
{
    int counter = number-1;
    int Ar, Ac;
    while (counter !=0)
    {
        input >> Ar >> Ac;
        std::cout << Ar << Ac;
        counter--;
        //Antenna * store = new Antenna(Ar, Ac);
        //Antennas.push_back(store);
    }
    //Do something with the structure
}


int main(int Argc, char * Argv[])
{

    std::ifstream input_txt;
    std::cout << Argv[1] << "\n";
    input_txt.open(Argv[1]);
    std::cout << "Nice\n";

    int grid_x, grid_y, Buildings_N, Antenna_M, Reward_R;

    input_txt >> grid_x >> grid_y>> Buildings_N >> Antenna_M >> Reward_R;
    std::cout << grid_x <<grid_y << Buildings_N << Antenna_M << Reward_R;

    // std::cout << "X" << grid_x << "Y" << grid_y << "N" << Buildings_N << "M" << Antenna_M << "R" << Reward_R;

    std::vector<Building *> Buildings;
    std::vector<Antenna *> Antennas;

    parse_building(Buildings_N, Buildings, input_txt);
    parse_antenna(Antenna_M, Antennas, input_txt);
    
    return 0;
}
