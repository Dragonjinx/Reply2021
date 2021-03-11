#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cstdlib>
using namespace std;

class Building{
    public:
        int Bx;
        int By;
        int Bl;
        int Bc;
        Building(int x, int y, int l, int c){
            Bx = x;
            By = y;
            Bl = l;
            Bc = c;
        }
        void print()
        {
            cout << Bx << " " << By << " " << Bl << " " << Bc << "\n";
        }
};

class Antenna{
    public:
        int Ax;
        int Ay;
        int Ar;
        int Ac;
        Antenna(int r, int c){
            Ar = r;
            Ac = c;
            Ax = 0;
            Ay = 0;
        }
};

int dist(Antenna* a, Building* b){
    int x = abs(a->Ax - b->Bx);
    int y = abs(a->Ay - b->By);
    return x+y;
}

vector<int> r(Building* b, vector<Antenna *> ant){
    vector<int> res;
    for(int i = 0; i < ant.size(); i++){
        if(dist(ant[i], b) <= ant[i]->Ar){
            res.push_back(i);
        }
    }
    return res;
}

int s(Antenna * a, Building * b){
    return (b->Bc * a->Ac) - (b->Bl*dist(a, b));
}

Antenna * c(Building * b, vector<Antenna *> ant){
    int resS = 0;
    Antenna * resA = ant[0];
    for(int i = 0; i < ant.size(); i++){
        if(s(ant[i], b) > resS){
            resA = ant[i];
        }
    }
    return resA;
}

int sBuild(Building * b, vector<Antenna* > ant){
    return s(c(b, ant), b);
    // If no antennas are reachable (r(b) = ∅) then s(b) = 0.
}

int reward(vector<Building*> bui, vector<Antenna*> ant, int R){
    for(int i = 0; i < bui.size(); i++){
        vector<int> r0 = r(bui[i], ant);
        if(r0.size() == 0){
            return 0;
        }
    }
    return R;
}

int score(vector<Building*> bui, vector<Antenna*> ant, int R){
    int res = 0;
    for(int i = 0; i < bui.size(); i++){
        res += sBuild(bui[i], ant);
    }
    res += reward(bui, ant, R);
    return res;
}

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
