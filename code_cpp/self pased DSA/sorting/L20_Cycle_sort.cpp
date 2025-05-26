#include<iostream>
using namespace std;
void CycleSortDistint(int arr[],int n)
{
    // chose item one by one
    for (int cs = 0; cs < n-1; cs++)
    {
        int item = arr[cs];
        int pos = cs;
        // Count number of elements less than right(position) of the item
        for (int i = cs+1; i < n; i++)
        {
            if(arr[i]<item)
                pos++;
        }
        // swap the item to there correct position
        swap(item,arr[pos]);
        // Fix rest of items
        while (pos!=cs)
        {
            pos=cs;
            for (int i = cs+1; i < n; i++)
            {
                if(arr[i]<item)
                    pos++;
            }
            swap(item,arr[pos]);
        }
        
        
    }
    // print sorted array
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main(){
    int arr[]={1,8,5,9,18,12,5,18};
    int n= sizeof(arr)/sizeof(arr[0]);
    CycleSortDistint(arr,n);// Function call
    
    return 0;
}