// varitaion of LIS:
// Longest chain of pairs

/*
problem statement:

we have given an array of pairs the first element is always smaller than second
we need to form longest chain of pairs such that:
if we have two pairs (a,b) and (c,d) then
c>b     //(we already know b>a).

*/

// NOTE: This problem is similat to activity problem in greedy chapter
//     which can be solved in O(N) after soting the array.






// Approch: dynamic programming
// Time = theta(N^2), Space = theta(N)
#include<bits/stdc++.h>
using namespace std;

int longestChain(pair<int,int> arr[], int n)
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
            // if(arr[j].second<arr[i].first){
            if(arr[j].second < arr[i].first){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }

    // longest chain pairs get maximum of from all the possible chain pairs from lis list
    int res=lis[0];
    for(int i=0; i<n; i++){
        res = max(res, lis[i]);
    }

    return res;
}



int main(){

    pair<int,int> arr[] = { make_pair(5,24), make_pair(39,60), make_pair(15,28), make_pair(27,40), make_pair(50,90) };
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Longest common subsequence length: "<<longestChain(arr, n)<<endl;
    return 0;
}

//output: 3     // (5,24), (27,40), (50,90)
