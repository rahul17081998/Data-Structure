#include<iostream>
using namespace std;

int getwater(int arr[], int n)
{
    int res=0;
    // left most and right most box can not store any water
    for (int i = 1; i < n-1; i++)
    {
        // left maximaum limit(wall)
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
        {
            lmax = max(lmax,arr[j]);
        }
        // right maximaum limit(wall)
        int rmax = arr[i];
        for (int j = i+1; j < n; j++)
        {
            rmax = max(rmax, arr[j]);
        }
        // calculating trap water for every box
        res += min(lmax,rmax)-arr[i];
    }
    return res;
}
int main(){
    int arr[]={1,2,0,1,3};
    int n= sizeof(arr)/sizeof(arr[0]);
    cout<<getwater(arr,n);
    return 0;
}