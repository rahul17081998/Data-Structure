#include<iostream>
using namespace std;

// wrong method
/*
int odd_even_subarray(int arr[], int n)
{
    int res=0;
    for (int i = 0; i < n; i++)
    {  
        if(arr[i]%2 == 0)  // even
        {
            int count =1;
            for (int j = i+1; j < n; j++)
            {
               if(arr[j]%2 == 0) 
               {
                   break;
               }
               else{
                   count++;
               }
            }
            res = max(res, count);
        
        }  


        if(arr[i]%2 != 0)
        {
            int count =1;
            for (int j = i+1; j < n; j++)
            {
               if(arr[j]%2 != 0) 
               {
                   break;
               }
               else{
                   count++;
               }
               
            }
            res = max(res, count);
        }          
    }
    return res;
}
*/

// correct method
void oddeven(int arr[], int n)
{
    int count=1;
    int res=0;
    for (int i = 1; i < n; i++)
    {
        if((arr[i-1]%2==0 and arr[i]%2 !=0) or (arr[i-1]%2 !=0 and arr[i]%2 ==0))
        {
            count++;
            res = max(res, count);
        }
        
        else
        {
            count = 1;
        }
    }
    cout<<res;
}
int main(){
    int arr[]={17,10,13,4,10,12,3,2,7,34};
    int n = sizeof(arr)/sizeof(arr[0]);
    // cout<<odd_even_subarray(arr, n);
    oddeven(arr, n);
    return 0;
}