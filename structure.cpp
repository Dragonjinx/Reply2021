#include <bits/stdc++.h>
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
};

class Antenna{
    public:
        int Ar;
        int Ac;
        Antenna(int r, int c){
            Ar = r;
            Ac = c;
        }
};

int dist(int xa, int ya, int xb, int yb){
    int x = abs(xa - xb);
    int y = abs(ya - yb);
    return x+y;
}

vector<int> r(Building b, vector<Antenna> ant){
    vector<int> res;
    for(int i = 0; i < ant.size(); i++){
        if(dist(b.Bx, b.By, ))
    }
}