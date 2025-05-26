// variation of LIS: Maximum sum increasing subsequence
// Approch: dynamic programming
// Time = theta(N^2), Space = theta(N)
#include<bits/stdc++.h>
using namespace std;

int MSIS(int arr[], int n)
{
    int msis[n];
    
    for(int i=0; i<n; i++){
        msis[i] = arr[i];
        // cheak if it's left side have smaller value
        // if yes, than "maximum of (msis, msis + arr[i])" will be current ith lis value
        for(int j=0; j<i; j++){
            if(arr[j]<arr[i]){
                msis[i] = max(msis[i], msis[j]+arr[i]);
            }
        }
    }
    // return maximum of msis array
    int res=msis[0];
    for(int i=0; i<n; i++){
        res = max(res, msis[i]);
    }
    return res;
}



int main(){
    int arr[] = {5, 10, 3, 6, 7, 8};
    int n = sizeof(arr)/ sizeof(arr[0]);
    cout<<"Maximum sum increasing subsequence: "<<MSIS(arr, n)<<endl;
    return 0;
}