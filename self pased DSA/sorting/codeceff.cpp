#include<iostream>
using namespace std;
int find(int arr[],int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==k)
            return 1;
    }
    return -1;
}

int main(){
    int N; // size of array
    int k; // to find element
    cin>>N;
    cin>>k;
    int arr[N];
    for (int i = 0; i < N; i++)
    {
        cin>>arr[i];
    }
    cout<<find(arr, N, k);
    return 0;
}