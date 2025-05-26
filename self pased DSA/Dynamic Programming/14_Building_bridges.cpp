// varitaion of LIS:
// Building bridges

/*
problem statement:

we have given an array of pairs of cities pair 
first element represent first side of river and 
second element represent second side of rever
these pairs represent requirments for a bridges
but condition is not to bridges can cross each other
how many maximum bridges can formed using these pairs
*/



// Approch: dynamic programming
// Time = theta(N^2), Space = theta(N)
#include<bits/stdc++.h>
using namespace std;

int bridge(pair<int,int> arr[], int n)
{
    // sort the array A/c to first value
    // if 1st value is same the take 2nd value
    sort(arr,arr+n);

    // longest common subsequence for all elements
    int lis[n];
    lis[0] = 1;
    // find lis using 2nd value
    for(int i=1; i<n; i++){
        lis[i] = 1;
        // cheak if it's left side have smaller value
        // if yes, than "maximum of lis vlue + 1" will be current ith lis value
        for(int j=0; j<i; j++){
            if(arr[j].second<arr[i].second){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }

    // maximum bridge that can be formed
    int res=lis[0];
    for(int i=0; i<n; i++){
        res = max(res, lis[i]);
    }

    return res;
}



int main(){
    pair<int,int> arr[] = {make_pair(1,5), make_pair(2,6), make_pair(4,3), make_pair(6,2), make_pair(1,3)};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Longest common subsequence length: "<<bridge(arr, n)<<endl;
    return 0;
}
/*
output: 3 // (1,3), (1,5), (2,6)
*/