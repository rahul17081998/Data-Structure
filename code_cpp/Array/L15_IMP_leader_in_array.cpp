#include<iostream>
using namespace std;

// naive approch T(n) = O(n^2)
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


// Effieciant method T(n) = O(n)
void effecianmetchod(int arr[], int n)
{
    int curr_led=arr[n-1];
    cout<<curr_led<<" ";
    for (int i = n-2; i >=0; i--)
    {
        if(curr_led<arr[i])
        {
            curr_led=arr[i];
            cout<<curr_led<<" ";
        }
    }
    
}
int main(){
    int arr[]={22,3,13,51,2,20,10};
    int n =sizeof(arr)/sizeof(arr[0]);
   
    // leader(arr, n);
    effecianmetchod(arr, n);
    
    return 0;
}