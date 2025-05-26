
/*
Random m bicolring generator given n size

*/

#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// random input (+1 and -1) generator
void random_Bicolor_Generator(int n, int m, vector<vector<int> > &bicolor)
{
    srand(time(0));  // Initialize random number generator.

    for(int j=0; j<m; j++)
    {
        vector<int> v;
        for(int i=0; i<n; i++)
        {
            if((rand() % 2) == 0)
            {
                // cout<<-1<<" ";
                v.push_back(-1);
            }
            else
            {
                // cout <<1<<" ";
                v.push_back(1);
            }
        }
        bicolor.push_back(v);
        // cout<<endl;

    }
}
 
void print_2D_Array(vector<vector<int> > bicolor)
{
    for (int i = 0; i < bicolor.size(); i++)
    {
        cout<<"B"<<i<<" = ";
        for(int j=0; j < bicolor[0].size(); j++)
        {
            cout<<bicolor[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main() 
{
    // input 
    int n=8;
    int m=4;
    vector<vector<int> > bicolor;
    random_Bicolor_Generator(n, m, bicolor);
    print_2D_Array(bicolor);
    

    return 0; 
}