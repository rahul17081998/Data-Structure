// variation of LIS problem
// Maximum length bitonic subsequence 
// Approch: dynamic programming
// Time = O(N^2), Space = O(N)
#include<bits/stdc++.h>
using namespace std;

void LIS(int arr[], int n, int lis[])
{
    
    lis[0] = 1;
    for(int i=1; i<n; i++){
        lis[i] = 1;
        // cheak if it's left side have smaller value
        // if yes, than "maximum of lis vlue + 1" will be current ith lis value
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                lis[i] = max(lis[i], lis[j]+1);
            }
        }
    }
   
}



int main(){
    int arr[] = {1,11,2,10,4,5,2,1};
    int n = sizeof(arr)/ sizeof(arr[0]);
    int lis[n];
    // lis: length of longest increasing part
    LIS(arr, n, lis);
    // reverse the array to find lds( length of longest decreasing part)
    reverse(arr,arr+n);
    int lds[n];
    LIS(arr,n,lds);
    // reverse the lds array now
    reverse(lds, lds+n); 
    // LBS: longest length of bitonic subsequence
    int lbs[n];
    cout<<"longest length of bitonic subsequence:\n";
    for(int i=0; i<n; i++)
    {
        lbs[i] = lis[i]+lds[i]-1;
        cout<<lbs[i]<<" ";
    }


   
    return 0;
}