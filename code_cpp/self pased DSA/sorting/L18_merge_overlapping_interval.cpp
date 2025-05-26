#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void mergingInterval(pair<int,int> arr[],int n)
{
int x,y;
    pair<int,int> temp[n];
    int count=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int larger=max(arr[i].first,arr[j].first);
            if(arr[i].second>=larger and arr[j].second>=larger)
            {
                x = min(arr[i].first,arr[j].first);
                y = max(arr[i].second,arr[j].second);
                temp[count]=make_pair(x,y);
                count++;
            }
        }
        
    }
    // print
    cout<<"Merged paies\n";
    for (int i = 0; i < count; i++)
    {
        arr[i]=temp[i];
        cout<<temp[i].first<<","<<temp[i].second<<endl;
    }
}

int main(){
    pair<int,int> arr[]={make_pair(7,9),make_pair(6,10),make_pair(4,5),make_pair(1,3),make_pair(2,4)};
    int n=sizeof(arr)/sizeof(arr[0]);
    // printing original pairs
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i].first<<","<<arr[i].second<<endl;
    }
    // merging pairs
    mergingInterval(arr,n);
    // mergingInterval(arr,n);

    
    return 0;
}