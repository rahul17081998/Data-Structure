/*
input:  a1[] = {10, 20, 30, 40, 50}
        a2[] = {5, 15, 25, 35, 45}
output  27.5    // {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}
*/
#include<iostream>
using namespace std;

void mergearr(float res[], int arr1[], int arr2[], int n, int m)
{
    // Merge two array
   int i=0, j=0, k=0;
   while(i<n)
    {
        res[k]=arr1[i];
        i++;
        k++;
    }

    while(j<m)
    {
        res[k]=arr2[j];
        j++;
        k++;
    }
    sort(res, res+n+m);  // Sort the array which we get after merge

    // Printing the sorted array
    for (int i = 0; i < n+m; i++)
    {
        cout<<res[i]<<" ";
    }
    // Calculating median
    int x= n+m;
    float z = (res[x/2]+res[(x/2)-1])/2;
    if(x%2==0)
    {
        cout<<"Median: "<<z<<endl;
    }
    else
    {
        cout<<"Median: "<<res[x/2]<<endl;
    }
    
    
}

int main()
{
    int arr1[] = {10, 20, 30, 40, 50}; //sorted array
    int n = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {5, 15, 25, 35}; //sorted array
    int m = sizeof(arr2)/sizeof(arr2[0]);
    float res[n+m];

    mergearr(res,arr1,arr2,n,m);

    return 0;
}