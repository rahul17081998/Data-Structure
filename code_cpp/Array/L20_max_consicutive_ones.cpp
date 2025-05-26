#include<iostream>
using namespace std;
// Method 1: Naive approch 
int maxcons_ones(int arr[], int n)
{
   int result =0;
   for (int i = 0; i < n; i++)
   {
       int curr = 0;
       for (int j = i; j < n; j++)
       {
           if(arr[j]==1)
           {
               curr++;
           }
           else
           {
               break;
           }
       }
       result = max(result,curr);
   }
   return result;
}


// Method 2: effeciant solution
int conone(int arr[], int n){
    int res=0;
    int curr=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0)
        {
            curr=0;
        }
        else
        {
            curr++;
            res = max(curr, res);
        }
    }
    return res;
}


int main(){
    int arr[] = {1,1,0,1,0,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<maxcons_ones(arr, n)<<endl;   //Naive approch T(n)=O(n^2)
    cout<<conone(arr, n)<<endl;         //Efficiant apporach T(n)=O(n)
    return 0;
}