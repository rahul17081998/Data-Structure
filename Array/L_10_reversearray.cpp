#include<iostream>
using namespace std;

void reverse(int arr[], int n)
{
    int temp;
    int x[n];
    for (int i = 0; i <n; i++)
    {
        x[i]=arr[n-i-1];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<x[i]<<" ";
    }
    
    
}

int main(){
    int array_1[]={32,4,1,55,23};
    int n = sizeof(array_1)/sizeof(array_1[0]);
    reverse(array_1, n);
    return 0;
}