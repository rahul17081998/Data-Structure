#include<iostream>
using namespace std;

int majority(int arr[], int n)
{
    int res =0;
    for(int i=0; i<n; i++)
    {
        int count =1;
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
                res = max(res, count);
            if(res> n/2)
            {
                return i;
                
            }
            }
        }
        
    }
    return -1;
}
int main(){
    int arr[] = {20,30,40,50,50,50,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<majority(arr, n);
    return 0;
}