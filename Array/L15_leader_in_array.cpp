#include<iostream>
using namespace std;

void leader(int arr[], int n)
{
    
    for (int i = 0; i < n; i++)
    {
        bool flag = false;
        for (int j = i+1; j < n-1; j++)
        {
            if (arr[i] <= arr[j])
            {
                flag = true;
                break;
            }
            
        }



        if(flag==false)
        {
            cout<<arr[i]<<" ";
        }


    }

}

int main(){
    int arr[]={22,3,13,51,2,20,10};
    int n =sizeof(arr)/sizeof(arr[0]);
    // movetoend(arr, n);
    // left_rotate(arr, n);
    leader(arr, n);
    
    return 0;
}