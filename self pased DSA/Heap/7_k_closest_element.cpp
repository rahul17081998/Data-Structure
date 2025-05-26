#include<bits/stdc++.h>
using namespace std;

void printKCosest(int arr[],int n,int x,int k)
{
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i]=false;
    }
    
    for (int i = 0; i < k; i++)
    {
        int mindiff=INT_MAX;
        int md_index;
        for(int j=0; j<n; j++)
        {
            if(visited[j]==false && abs(arr[j]-x)<mindiff)
            {
                mindiff=abs(arr[j]-x);
                md_index=j;
            }
        }
        cout<<arr[md_index]<<" ";
        visited[md_index]=true;
    }
    
}
int main(){
    int arr[]={20,40,5,100,150};
    int n=sizeof(arr)/sizeof(arr[0]);
    int x=100,k=3;
    cout<<k<<" closest elemets of "<<x<< " is: ";
    printKCosest(arr,n,x,k);
    return 0;
}