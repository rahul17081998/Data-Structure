#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Declare globally variable
vector<int> b1, b2, b3;
unordered_map<string, int> mp;
// initialize the map 
void initializeMap()
{
    mp["ppp"] = 0;
    mp["ppm"] = 0;
    mp["pmp"] = 0;
    mp["mpp"] = 0;
    mp["mpm"] = 0;
    mp["mmp"] = 0;
    mp["pmm"] = 0;
    mp["mmm"] = 0;
}

// count how many each patterns are present in bicoloring.
void countPattern(vector<int> &b1, vector<int> &b2, vector<int> &b3)
{
    for(int i=0; i<b1.size(); i++)
    {
        if(b1[i]==1 && b2[i]==1 && b3[i]==1) mp["ppp"]++;
        else if(b1[i]==1 && b2[i]==1 && b3[i]==-1) mp["ppm"]++;
        else if(b1[i]==1 && b2[i]==-1 && b3[i]==1) mp["pmp"]++;
        else if(b1[i]==-1 && b2[i]==1 && b3[i]==1) mp["mpp"]++;
        else if(b1[i]==-1 && b2[i]==1 && b3[i]==-1) mp["mpm"]++;
        else if(b1[i]==-1 && b2[i]==-1 && b3[i]==1) mp["mmp"]++;
        else if(b1[i]==1 && b2[i]==-1 && b3[i]==-1) mp["pmm"]++;
        else if(b1[i]==-1 && b2[i]==-1 && b3[i]==-1) mp["mmm"]++;
    }
}

// imbalance calculate
int  calculate_Imbalance()
{
    if(mp["ppp"]>0 && mp["mmm"]>0) return 0;
    if(mp["ppm"]>0 && mp["mmp"]>0) return 0;
    if(mp["pmp"]>0 && mp["mpm"]>0) return 0;
    if(mp["pmm"]>0 && mp["mpp"]>0) return 0;

    if(mp["pmm"]>0 && mp["ppp"]>0 && mp["mmp"]>0 && mp["mpm"]) return 0;
    if(mp["mpp"]>0 && mp["mmm"]>0 && mp["ppm"]>0 && mp["pmp"]) return 0;
    if(mp["ppp"]>0 && (mp["pmm"]>0 || mp["mpm"]>0 || mp["mmp"]>0)) return 2;
    if(mp["mmm"]>0 && (mp["mpp"]>0 || mp["pmp"]>0 || mp["ppm"]>0)) return 2;
    if(mp["ppm"]>0 && mp["mpp"]>0) return 2;
    if(mp["pmp"]>0 && mp["mpp"]>0) return 2;
    if(mp["pmp"]>0 && mp["ppm"]>0) return 2;
    if(mp["mmp"]>0 && mp["mpm"]>0) return 2;
    if(mp["mmp"]>0 && mp["pmm"]>0) return 2;
    if(mp["pmm"]>0 && mp["mpm"]>0) return 2;
    return 3; // if all values are in a bicoloring
}

//write your function here
void balancing(vector<vector<int> > grid)
{
    b1 = grid[0], b2 = grid[1], b3 = grid[2];
    initializeMap(); // initialize map 
    countPattern(b1, b2, b3);   // count how many each patterns are present in bicoloring. Like ppp, ppm, mmp, ...etc coutnt
    int imb = calculate_Imbalance(); // imbalance calculate
    cout<<"imbalance: "<<imb<<endl;
}

int main(){
    // input
    
    vector<vector<int> > grid;
    vector<int> level;
    // B0 = 1 1 1 1 
    // B1 = -1 -1 1 -1 
    // B2 = 1 -1 1 1 
    // BrutForce Method: Imbalance = 2  -------  S = 2 3 
    // Effective Method: Imbalance = 2  -------  S = 3 3 
    level.push_back(1);
    level.push_back(1);
    level.push_back(1);
    level.push_back(1);
    grid.push_back(level);
    level.clear();

    level.push_back(-1);
    level.push_back(-1);
    level.push_back(1);
    level.push_back(-1);
    grid.push_back(level);
    level.clear();

    level.push_back(1);
    level.push_back(-1);
    level.push_back(1);
    level.push_back(1);
    grid.push_back(level);
    level.clear();

    balancing(grid);
    
    return 0;
}