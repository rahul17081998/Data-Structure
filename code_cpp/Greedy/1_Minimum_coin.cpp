// minimum coin problem
#include<bits/stdc++.h>
using namespace std;

int minCoin(int arr[], int n, int amount)
{
    sort(arr, arr+n);
    reverse(arr, arr+n);
    int res=0;
    for(int i=0; i<n; i++){
        if(arr[i] < amount && amount!=0){
            int t = amount/arr[i];
            res=res+t;
            amount=amount-arr[i]*t;
        }
        
    }
    return res;
}
int main(){
    int arr[]={1,10,2,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<minCoin(arr,n,52)<<endl;
    min
    return 0;
}