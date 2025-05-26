#include<iostream>
using namespace std;

void stock_market(int price[], int n)
{
    int profit = 0;
    
    for (int i = 1; i < n; i++)
    {
        if (price[i]>price[i-1])
        {
            profit += price[i]-price[i-1];
        }
        
    }
    cout<<profit<<endl;

}

int main(){
    int arr[]={1,5,3,1,2,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    stock_market(arr,n);
    return 0;
}