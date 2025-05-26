#include<bits/stdc++.h>
using namespace std;
// vector<vector<int> > allComb;
 // convert number into bits
vector<int> intToBits(int a, int n)
{
    // string s="";
    vector<int> s;
    while(a){
        if(a%2==0)
            s.push_back(-1);
        else
            s.push_back(1);
        a = a/2;
    }
    while(s.size() < n){
        s.push_back(-1);
    }
    reverse(s.begin(), s.end());
    return s;
}
// generates all combinations
vector<vector<int> > AllCombination(int n){
    int t = pow(2, n);
    vector<vector<int> > allComb;
    for(int i=0; i<pow(2,n); i++){
        vector<int> bits = intToBits(i, n);
        allComb.push_back(bits);
    } 
    return allComb;
}

// print 2D vector
void printGrid(vector<vector<int> > grid){

    for (int i = 0; i < grid.size(); i++){
        for(int j=0; j< grid[i].size(); j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(){
    
    int n = 8;
    vector<vector<int> > allComb = AllCombination(n);
    // print 2D vector allcomb
    printGrid(allComb);
  
    return 0;
}
/*
0000000001101

*/