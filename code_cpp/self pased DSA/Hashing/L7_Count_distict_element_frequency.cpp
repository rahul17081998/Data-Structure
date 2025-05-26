#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
/*
// time=O(n^2)
// aux.sp=O(1)
void countFrequency(int arr[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=INT_MAX)
        {
            int count=0;
            int temp=arr[i];
            for (int j = 0; j <n; j++)
            {
                if(temp==arr[j])
                {
                    count++;
                    arr[j]=INT_MAX;
                }
            }
            cout<<temp<<" "<<count<<endl;
            
        }
    }
    
}
*/
// time=O(n)
// aux.sp=O(n)
void countFreq(int arr[], int n,unordered_map<int,int> &h)
{
    
    // This is also a correct but time comp is high 
    // for (int i = 0; i < n; i++)
    // {
    //     int c=0;
    //     if(h.count(arr[i])>0)
    //     {
    //         for(auto x:h)
    //             if(x.first==arr[i])
    //                 c=x.second;
    //     c++;
    //     h[arr[i]]=c;
    //     }
    //     else
    //     {
    //         h[arr[i]]=1;
    //     }
    // }
    for (int i = 0; i < n; i++)
    {
        h[arr[i]]++;
    }
    
    for(auto z:h)
    {
        cout<<z.first<<" "<<z.second<<endl;
    }
    
}
int main(){
    int arr[]={10,12,10,15,10,20,12,12 };
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_map<int,int> h;
    // countFrequency(arr,n);
    cout<<"unordered map method "<<endl;
    countFreq(arr,n,h);
    return 0;
}