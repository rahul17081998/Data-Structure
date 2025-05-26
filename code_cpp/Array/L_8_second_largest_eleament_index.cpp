#include<iostream>
using namespace std;
/* Largest element index*/
int getlargest(int arr[], int n)
{
    int large=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>arr[large])
        {
            large=i;
        }
        
    }
    return large;
}
/* second Largest element index*/
int secondlargest(int arr[], int n)
{
    int largest = getlargest(arr, n);
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[largest])
        {
            if(res == -1)
                res = i;
            else if(arr[i]>arr[res])
                res=i;
        }
        
    }
    return res;
}


int main()
{
    int arr[]={2,53,24,78,3,490};
    int n;
    n=sizeof(arr)/sizeof(arr[0]);
    cout<<secondlargest(arr, n)<<endl;
    cout<<getlargest(arr, n);
    
   return 0;
}