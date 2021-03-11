#include <bits/stdc++.h>
using namespace std;

int R;

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

int dist(Antenna a, Building b){
    int x = abs(a.Ax - b.Bx);
    int y = abs(a.Ay - b.By);
    return x+y;
}

vector<int> r(Building b, vector<Antenna> ant){
    vector<int> res;
    for(int i = 0; i < ant.size(); i++){
        if(dist(ant[i], b) <= ant[i].Ar){
            res.push_back(i);
        }
    }
    return res;
}

int s(Antenna a, Building b){
    return (b.Bc * a.Ac) - (b.Bl*dist(a, b));
}

Antenna c(Building b, vector<Antenna> ant){
    int resS = 0;
    for(int i = 0; i < ant.size(); i++){
        resS = max(resS, s(ant[i], b));
    }
    return s;
}

int sBuild(Building b, vector<Antenna> ant){
    return s(C(b, ant), b);
    // If no antennas are reachable (r(b) = ∅) then s(b) = 0.
}

int reward(vector<Building> bui, vector<Antenna> ant){
    for(int i = 0; i < bui.size(); i++){
        vector<int> r0 = r(bui[i], ant);
        if(r0.size() == 0){
            return 0;
        }
    }
    return R;
}

int score(vector<Building> bui, vector<Antenna> ant){
    int res = 0;
    for(int i = 0; i < bui.size(); i++){
        res += sBuild(bui[i], ant);
    }
    res += reward(bui, ant);
    return res;
}