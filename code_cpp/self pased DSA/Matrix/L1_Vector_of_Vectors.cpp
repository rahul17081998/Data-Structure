#include <iostream>
#include <cmath>
#include <bits/stdc++.h> 
#include <climits>
#include <deque>
using namespace std;

int main(){
    int m=3,n=2;
    // creating 2D array
    vector<vector<int> > arr;
    for (int i = 0; i < m; i++)
    {
        vector<int> v;
        for (int j = 0; j < n; j++)
        {
            v.push_back(10);
        }
        arr.push_back(v);
        
    }
    // print all elements
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        
    }

    
    return 0;
}