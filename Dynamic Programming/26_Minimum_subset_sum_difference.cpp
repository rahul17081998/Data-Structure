#include<bits/stdc++.h>
using namespace std;

void isSubsetSum(int arr[], int n, int sum, vector<int> &v)
{
    // base case
    bool t[n+1][sum+1];
    // initialize the t array
    for(int i=0; i<n+1; i++)
    {
        for(int j=0; j<sum+1; j++)
        {
            if(i==0)
                t[i][j] = false;
            if(j==0)
                t[i][j] = true;
        }
    }   
    
    
    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<sum+1; j++)
        {
            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j-arr[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }   
    // store last rows half of sum index value (which are actually true) into vector
    for(int j=0; j<=(sum)/2; j++){
        if(t[n][j] == true)
            v.push_back(j);
    }
    
}
int minDifference(int arr[], int n)  { 
    // Your code goes here
    // find range
    int range = 0;
    for(int i=0; i<n; i++){
        range = range + arr[i];
    }
    // strore s1 values into v vector
    vector<int> v;
    isSubsetSum(arr, n, range, v);
    
    int mn = INT_MAX;
    for(int i=0; i<v.size(); i++){
        mn = min(mn, range- 2*v[i]);
    }
    return mn;
} 



int main(){
    int arr[] = {1, 6, 5, 11};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Minimum subset sum difference: "<<minDifference(arr, n)<<endl;
    return 0;

    /*

    correct output: 1 


    Exaplanation:
    {1, 6, 5} is one set and {11} is another set
    sum1 = 1+6+5 = 12
    sum2 = 11
    abs(sum1-sum2) = 1 (ANS)                         



    */                  
}                                                   