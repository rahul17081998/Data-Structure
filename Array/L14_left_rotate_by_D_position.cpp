
#include<iostream>
using namespace std;

void left_rotate(int arr[], int n, int d)
{
    int x[n];
    for (int i = 0; i < n-d; i++)
    {
        x[i]=arr[i+d];
    }
  
    for (int i = 0; i < d; i++)
    {
        x[n-d+i]=arr[i];
    }
    

       // new array
    for (int i = 0; i < n; i++)
    {
        cout<<x[i]<<" ";
    }
}

int main(){
    int arr[]={2,3,243,5,5,0,100};
    int d =3;
    int n =sizeof(arr)/sizeof(arr[0]);
    // movetoend(arr, n);
    left_rotate(arr, n, d);

    
    return 0;
}


