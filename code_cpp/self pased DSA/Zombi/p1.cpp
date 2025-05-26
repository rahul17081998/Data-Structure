/*
DATE: 31/july/2022

i/o: B1 = +1,−1,+1,−1, 
o/p: S = {1,2} or S = {1, 4}
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int b1[], int n, vector<int> &S, int &imbalance)
{
    int i;
    for(i=1; i<n; i++)
    {
        // check if you get two different color
        if(b1[0]==-b1[i])
        {
            S.push_back(1);
            S.push_back(i+1);
            imbalance=0;
            break;
        }
    }
    // if coloring contain  only single color
    if(i==n){
        imbalance=3;
        S.push_back(1);
    }
    
}
int main(){

    // input
    int B1[]={-1, -1, +1, +1};
    int n=sizeof(B1)/ sizeof(B1[0]);

    vector<int> S;
    int imbalance=INT_MAX;
    solve(B1, n, S, imbalance);

    // print output 
    cout<<"S = {";
    for(int i=0; i<S.size(); i++){
        if(i==S.size()-1) cout<<S[i];    
        else cout<<S[i]<<",";
    }
    cout<<"} has imbalance "<<imbalance<<endl;
    return 0;
}