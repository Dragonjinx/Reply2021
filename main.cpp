#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "structure.h"

void parse_building(int &number, std::vector<Building*> &Buildings, std::ifstream &input)
{
    int counter = number;
    int Bx, By, Bl, Bc;
    while(counter != 0)
    {
        input >> Bx >> By >> Bl >> Bc;
        counter--;
        Building * store = new Building(Bx, By, Bl, Bc);
        Buildings.push_back(store);
    }
    //DO something with the structure
}

void parse_antenna(int &number, std::vector<Antenna*> &Antennas, std::ifstream &input)
{
    int counter = number;
    int Ar, Ac;
    while (counter !=0)
    {
        input >> Ar >> Ac;
        counter--;
        Antenna * store = new Antenna(Ar, Ac);
        Antennas.push_back(store);
    }
    //Do something with the structure
}

void center_of_mass(std::vector<Building*> Buildings,  int stop, int &x, int &y, int subdivision)
{
    float sum_of_latence = 0;
    double sum_of_wc_x = 0;
    double sum_of_wc_y = 0;
    int start = stop - subdivision;
    for(int i = 0; i < subdivision; i++)
    {
        Buildings[start+i]->print();
        sum_of_latence += Buildings[start+i]->Bl;
        sum_of_wc_x += Buildings[start+i]->Bl * Buildings[start+i]->Bx;
        sum_of_wc_y += Buildings[start+i]->Bl * Buildings[start+i]->By;
    }
    x = (int)  (sum_of_wc_x / sum_of_latence);
    y = (int) (sum_of_wc_y / sum_of_latence);
}

int main(int Argc, char * Argv[])
{
    std::ifstream input_txt;
    std::ofstream output_txt;
    std::cout << Argv[1] << "\n";
    input_txt.open(Argv[1]);
    output_txt.open(Argv[2]);
    std::cout << "Nice\n";

    int grid_x, grid_y, Buildings_N, Antenna_M, Reward_R;

    input_txt >> grid_x >> grid_y>> Buildings_N >> Antenna_M >> Reward_R;
    output_txt << Antenna_M << "\n";

    std::vector<Building *> Buildings;
    std::vector<Antenna *> Antennas;

    parse_building(Buildings_N, Buildings, input_txt);
    parse_antenna(Antenna_M, Antennas, input_txt);

    int subdivision_index = (int)( Buildings_N / Antenna_M);

    for(int i = 0; i < Antenna_M; i++)
    {
        int a_x, a_y;
        center_of_mass(Buildings, (i+1) *subdivision_index, a_x, a_y, subdivision_index);
        output_txt << i << "  " << a_x << "  " << a_y << "\n";
    }
    input_txt.close();
    output_txt.close();
    return 0;
}
