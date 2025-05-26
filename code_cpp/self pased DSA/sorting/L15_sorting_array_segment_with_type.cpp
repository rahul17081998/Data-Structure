#include<iostream>
using namespace std;
void segment(int arr[], int n)
{   int temp[n];
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]<0)
        {
            temp[count]=arr[i];
            count++;
        }
        else{
            continue;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(arr[i]>=0)
        {
            temp[count]=arr[i];
            count++;
        }
        else{
            continue;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout<<temp[i]<<" ";
    }
    
    
}
int main(){
    int arr[]={3,4,-23,3,-1,-235,12};
    int n= sizeof(arr)/sizeof(arr[0]);
    segment(arr, n);
    return 0;
}