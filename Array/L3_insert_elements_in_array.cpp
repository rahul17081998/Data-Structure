#include<iostream>
#include<cmath>
using namespace std;

int insert(int arr[], int n, int x, int cap, int pos)
{
    if(n>=cap)
        return n;

    int index = pos-1;
    for(int i=n-1; i>=index; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[index]=x;
    return n+1;
}


/*
int main(){
    int arr[5]={2,43,7};
    int n = sizeof(arr)/sizeof(arr[0]); // size of array
    int cap = 6;
    int x =22;
    int pos =2;
    cout<<insert(arr, n, x, cap, pos)<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}*/


int main() {
	
       int arr[5], cap = 5, n = 3;
       arr[0] = 5; arr[1] = 10; arr[2] = 20;
       cout<<"Before Insertion"<<endl;
       for(int i=0; i < n; i++)
       {
       	cout<<arr[i]<<" ";
       }
       cout<<endl;
        /**********/
       int x = 7, pos = 2;
       n = insert(arr, n, x, cap, pos);
       cout<<"After Insertion"<<endl;
       for(int i=0; i < n; i++)
       {
       		cout<<arr[i]<<" ";
       }
    
}