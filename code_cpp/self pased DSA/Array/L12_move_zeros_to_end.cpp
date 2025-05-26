#include<iostream>
using namespace std;
/*
void movetoend(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==0)
        {
            for (int j = i+1; j < n; j++)
            {
                if (arr[j]!=0)
                {
                    swap(arr[j], arr[i]);
                    break;
                }
                
            }
            
        }
        
    }

}
*/


 // Effeciant solution
void move_zero_end(int arr[], int n)
{
    int count=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] !=0)
        {
            swap(arr[i], arr[count]);
            count++;
        }
        
    }
    
}

int main(){
    int arr[]={2,0,4,21,0,0,3,243,5};
    int n =sizeof(arr)/sizeof(arr[0]);
    // movetoend(arr, n);
    move_zero_end(arr, n);

       // new array
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}