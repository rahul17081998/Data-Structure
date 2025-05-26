/*
DATE: 31/july/2022


i/o:
    B1 =+1,−1,+1,−1
    B2 =+1,−1,+1,+1
    B3 =−1,+1,−1,−1

o/p: 
    S = {1, 2}
*/

#include<bits/stdc++.h>
using namespace std;

void solve(int b1[], int b2[], int b3[], int n, vector<int> &S, int &imbalance)
{
    
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int sum =   abs(b1[i]+b1[j]) 
                      + abs(b2[i]+b2[j]) 
                      + abs(b3[i]+b3[j]);
            // check if sum is less than the previous imbalance value
            if(sum < imbalance)
            {
                imbalance = sum;
                vector<int> level;
                level.push_back(i+1);
                level.push_back(j+1);
                S = level;
            }
        }
    }
    // check if all elements can be included
    int sum1=0, sum2=0, sum3=0;
    for(int i=0; i<n; i++)
    {
        sum1 += b1[i];
        sum2 += b2[i];
        sum3 += b3[i];
    }
    int total_sum = abs(sum1) + abs(sum2) + abs(sum3);
    if(total_sum < imbalance)
    {
        imbalance = total_sum;
        vector<int> level;
        level.push_back(4);
        level.push_back(4);
        S = level;
    }
    // if imbalance is greater than 3 than we will chose only one element in S
    if(imbalance > 3)
    {
        vector<int> level;
        level.push_back(1);
        S=level;
        imbalance=3;
    }

}
int main(){

    // input
    

    int B1[]={+1, -1, +1, -1};
    int B2[]={+1, -1, +1, +1};
    int B3[]={-1, +1, -1, -1};


    // int B1[]={+1, +1, +1, -1};
    // int B2[]={+1, +1, +1, +1};
    // int B3[]={+1, +1, +1, +1};
   
    int n=sizeof(B1)/ sizeof(B1[0]);

    vector<int> S;
    int imbalance=INT_MAX;
    solve(B1, B2, B3, n, S, imbalance);

    // print output 
    cout<<"S = {";
    for(int i=0; i<S.size(); i++){
        if(i==S.size()-1) cout<<S[i];    
        else cout<<S[i]<<",";
    }
    cout<<"} has imbalance "<<imbalance<<endl;
    return 0;
}