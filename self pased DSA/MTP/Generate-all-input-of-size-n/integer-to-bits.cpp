#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > allComb;
vector<vector<vector<int> > > triplets;



 // convert number into bits
vector<int> intToBits(int a, int n)
{
    // string s="";
    vector<int> s;
    while(a){
        if(a%2==0)
            s.push_back(0);
        else
            s.push_back(1);
        a = a/2;
    }
    while(s.size() < n){
        s.push_back(0);
    }
    reverse(s.begin(), s.end());
    return s;
}
// Generates all triplets
void generateTriplets(int n){
    // int t = pow(2, n);
    int t = allComb.size();
    for(int i=0; i<t-2; i++){
        vector<vector<int> > oneTrip;
        oneTrip.push_back(allComb[i]);

        for(int j=i+1; j<t-1; j++){
            oneTrip.push_back(allComb[j]);

            for(int k=j+1; k<t; k++){
                oneTrip.push_back(allComb[k]);
                triplets.push_back(oneTrip);
                oneTrip.pop_back(); // pop last inserted item from oneTrip vector
            }
            oneTrip.pop_back(); // pop back 
        }
        oneTrip.pop_back(); // pop back
    }
}

// generates all combinations
void AllCombination(int n){
    int t = pow(2, n);

    for(int i=0; i<pow(2,n); i++){
        vector<int> bits = intToBits(i, n);
        allComb.push_back(bits);
    } 
    
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
// print all triplets
void Print3Dvector(){
    cout<<"All triplets are:-\n";
    cout<<"Triplets size: "<<triplets.size()<<endl;
    for(int i=0; i<triplets.size(); i++)
    {
        cout<<i+1<<"th Triplet\n";
        printGrid(triplets[i]);
        cout<<endl<<endl<<endl;
    }
}


int main(){
    
    int n = 20;
    AllCombination(n);
    // print 2D vector allcomb
    printGrid(allComb);
    // generateTriplets(n);
    // Print3Dvector();
    return 0;
}
/*
0000000001101

*/