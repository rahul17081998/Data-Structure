#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Declare globally variable
vector<int> b1, b2, b3;
unordered_map<string, int> mp; // store pattern count
unordered_map<string, vector<int> > mpo; // if a pattern found than store index

vector<int> fun1(string x1, string x2)
{
    vector<int> tempAns;
    // vector<int> temp1 = mpo[x];
    tempAns.push_back(mpo[x1][0]);
    tempAns.push_back(mpo[x2][0]);
    return tempAns;
}

vector<int> fun2(string x1, string x2, string x3, string x4)
{
    vector<int> tempAns;
    tempAns.push_back(mpo[x1][0]);
    tempAns.push_back(mpo[x2][0]);
    tempAns.push_back(mpo[x3][0]);
    tempAns.push_back(mpo[x4][0]);
    return tempAns;
}
vector<int> fun3(string x1, string x2, string x3, string x4)
{
    vector<int> tempAns;
    tempAns.push_back(mpo[x1][0]);
    // take from any one of three
    if(mpo[x2].size()>0) tempAns.push_back(mpo[x2][0]);
    else if(mpo[x3].size()>0) tempAns.push_back(mpo[x3][0]);
    else if(mpo[x4].size()>0) tempAns.push_back(mpo[x4][0]);
    return tempAns;
}

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
        if(b1[i]==1 && b2[i]==1 && b3[i]==1) {mp["ppp"]++; mpo["ppp"].push_back(i);}
        else if(b1[i]==1 && b2[i]==1 && b3[i]==-1) {mp["ppm"]++; mpo["ppm"].push_back(i);}
        else if(b1[i]==1 && b2[i]==-1 && b3[i]==1) {mp["pmp"]++; mpo["pmp"].push_back(i);}
        else if(b1[i]==-1 && b2[i]==1 && b3[i]==1) {mp["mpp"]++; mpo["mpp"].push_back(i);}
        else if(b1[i]==-1 && b2[i]==1 && b3[i]==-1) {mp["mpm"]++; mpo["mpm"].push_back(i);}
        else if(b1[i]==-1 && b2[i]==-1 && b3[i]==1) {mp["mmp"]++; mpo["mmp"].push_back(i);}
        else if(b1[i]==1 && b2[i]==-1 && b3[i]==-1) {mp["pmm"]++; mpo["pmm"].push_back(i);}
        else if(b1[i]==-1 && b2[i]==-1 && b3[i]==-1) {mp["mmm"]++; mpo["mmm"].push_back(i);}
    }
}

// imbalance calculate
int  calculate_Imbalance(vector<int> &res)
{
    if(mp["ppp"]>0 && mp["mmm"]>0) {res=fun1("ppp", "mmm"); return 0;}
    if(mp["ppm"]>0 && mp["mmp"]>0) {res=fun1("ppm", "mmp"); return 0;}
    if(mp["pmp"]>0 && mp["mpm"]>0) {res=fun1("pmp", "mpm"); return 0;}
    if(mp["pmm"]>0 && mp["mpp"]>0) {res=fun1("pmm", "mpp"); return 0;}

    if(mp["pmm"]>0 && mp["ppp"]>0 && mp["mmp"]>0 && mp["mpm"]) {res=fun2("pmm", "ppp", "mmp", "mpm"); return 0;}
    if(mp["mpp"]>0 && mp["mmm"]>0 && mp["ppm"]>0 && mp["pmp"]) {res=fun2("mpp", "mmm", "ppm", "pmp"); return 0;}
    if(mp["ppp"]>0 && (mp["pmm"]>0 || mp["mpm"]>0 || mp["mmp"]>0)) {res=fun3("ppp", "pmm", "mpm", "mmp"); return 2;}
    if(mp["mmm"]>0 && (mp["mpp"]>0 || mp["pmp"]>0 || mp["ppm"]>0)) {res=fun3("mmm", "mpp", "pmp", "ppm"); return 2;}
    if(mp["ppm"]>0 && mp["mpp"]>0) {res=fun1("ppm", "mpp"); return 2;}
    if(mp["pmp"]>0 && mp["mpp"]>0) {res=fun1("pmp", "mpp"); return 2;}
    if(mp["pmp"]>0 && mp["ppm"]>0) {res=fun1("pmp", "ppm"); return 2;}
    if(mp["mmp"]>0 && mp["mpm"]>0) {res=fun1("mmp", "mpm"); return 2;}
    if(mp["mmp"]>0 && mp["pmm"]>0) {res=fun1("mmp", "pmm"); return 2;}
    if(mp["pmm"]>0 && mp["mpm"]>0) {res=fun1("pmm", "mpm"); return 2;}
    else {res.push_back(0); return 3;} // if all values are in a bicoloring
}


//write your function here
void balancing(vector<vector<int> > grid)
{
    b1 = grid[0], b2 = grid[1], b3 = grid[2];
    initializeMap(); // initialize map 
    countPattern(b1, b2, b3);   // count how many each patterns are present in bicoloring. Like ppp, ppm, mmp, ...etc coutnt
    vector<int> res;
    int imb = calculate_Imbalance(res); // imbalance calculate
    cout<<"imbalance: "<<imb<<"  -------  S = ";
    for(int i=0; i<res.size(); i++) cout<<res[i]+1<<" ";
    cout<<"\n";
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
    // level.push_back(1);
    grid.push_back(level);
    level.clear();

    level.push_back(1);
    level.push_back(-1);
    level.push_back(1);
    level.push_back(-1);
    // level.push_back(-1);
    grid.push_back(level);
    level.clear();

    level.push_back(1);
    level.push_back(-1);
    level.push_back(1);
    level.push_back(1);
    // level.push_back(-1);
    grid.push_back(level);
    level.clear();

    balancing(grid);
    
    return 0;
}