#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(int Argc, char * Argv[])
{
    ifstream infile;
    ofstream outfile;
    infile.open ("data_scenarios_f_tokyo.in");
    outfile.open("f.in");
    // myfile << "Writing this to a file.\n";
    // myfile.close();

    int grid_x, grid_y, Buildings_N, Antenna_M, Reward_R;

    infile >> grid_x >> grid_y>> Buildings_N >> Antenna_M >> Reward_R;
    if(Antenna_M <= Buildings_N){
        outfile << Antenna_M << "\n";
        int Bx, By, Bl, Bc;
        for(int i = 0; i < Antenna_M; i++){
            infile >> Bx >> By >> Bl >> Bc;
            outfile << i << " " << Bx << " " << By << "\n";
        }
    }
    else{
        outfile << Buildings_N << "\n";
        int Bx, By, Bl, Bc;
        for(int i = 0; i < Buildings_N; i++){
            infile >> Bx >> By >> Bl >> Bc;
            outfile << i << " " << Bx << " " << By << "\n";
        }
    }
    infile.close();
    outfile.close();
    
    return 0;
}