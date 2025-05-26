#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > allComb;
vector<vector<int> > bicolors;

void printX(vector<int> x){
    cout<<"X = ";
    for(int i=0; i<x.size(); i++) cout<<x[i]<<" ";
    cout<<"\n";
}
// calculate max(bi)
int maxBi()
{
    vector<int> biVal;
    for(auto X: allComb){

        int maxi = INT_MIN;

        int sumbi=0, sumOfbiSquare=0;
        for(auto Bi: bicolors)
        {
            int bi=0;
            for(int i=0; i<X.size(); i++)
            {
                bi += Bi[i]*X[i];
            }
            maxi= max(maxi, abs(bi));
            sumbi += abs(bi);
            sumOfbiSquare += bi*bi;
        }
        printX(X);
        cout<<"Maximum bi value: "<<maxi<<endl;
        cout<<"Sum of bi values: "<<sumbi<<endl;
        cout<<"Sum of bi square values: "<<sumOfbiSquare<<endl;
        biVal.push_back(maxi);
        cout<<"\n";
    }
    // print maximum of biVal
    /*
    int maxi=INT_MIN;
    for(int i=0; i<biVal.size(); i++) maxi = max(maxi, biVal[i]);
    cout<<"Final maximim bi: "<<maxi<<endl;
    */
}


 
// ************* Generating All inputs ********************//
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
// generates all combinations
void AllCombination(int n){
    int t = pow(2, n);
    // generte all 2^n-2 non-trivial combinations
    for(int i=1; i<pow(2,n)-1; i++){
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
// ************* End : Generating All inputs ********************//


int main(){
    
    int n = 3;
    AllCombination(n);
    // print 2D vector allcomb
    printGrid(allComb);



    // manual input for bicoloring
    vector<int> level;

    level.push_back(1);
    level.push_back(-1);
    level.push_back(1);
    bicolors.push_back(level);
    level.clear();

    level.push_back(-1);
    level.push_back(-1);
    level.push_back(-1);
    bicolors.push_back(level);
    level.clear();

    level.push_back(-1);
    level.push_back(1);
    level.push_back(1);
    bicolors.push_back(level);
    level.clear();


    maxBi();
    return 0;
}
