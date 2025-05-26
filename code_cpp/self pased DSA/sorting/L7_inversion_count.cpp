#include<iostream>
using namespace std;
// Method 1: Naive approch --> O(n^2)
/*
void inversion(int arr[], int n)
{
    int count=0;
    for (int i = 0; i <n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]>arr[j])
                count++;
        }
        
    }
    cout<<count<<endl;
}*/

int countandmerge(int arr[],int l,int m,int r)
{
    int n1=m-l+1, n2=r-m;
    int left[n1],right[n2];

    for(int i=0; i<n1; i++){left[i]=arr[l+i];}
    for(int i=0; i<n2; i++){right[i]=arr[m+1+i];}

    int res=0,i=0,j=0,k=l;
    while(i<n1 and j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            i++;
        }
        else
        {   arr[k]=right[j];
            j++;
            res = res+(n1-i);
        }
        k++;    
    }
    while(i<n1)
    {
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        arr[k]=right[j];
        j++;
        k++;
    }
    return res;
    
}

int Count(int arr[], int l, int r)
{
    int res=0;
    if(l<r)
    {
        int m = l+(r-l)/2;
        res +=Count(arr, l, m);
        res +=Count(arr, m+1, r);
        res +=countandmerge(arr,l,m,r);
    }
    return res;
}

int main(){
    int arr[]={2,4,1,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int l=0;
    int r=n-1;
    /*inversion(arr, n);*/
    cout<<Count(arr,l,r);
    return 0;
}