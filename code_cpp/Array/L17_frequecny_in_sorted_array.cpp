#include<iostream>
using namespace std;

void freuency(int arr[], int n)
{
    // int c=0;
    for (int i = 0; i < n; i++)
    {   
        int c=0;
        if(arr[i]!=arr[i-1])
        {

            for (int j = i; j < n; j++)
            {
                
                if(arr[i]==arr[j])
                {
                    c++;
                }
                
            }
            cout<<arr[i]<<" "<<c<<endl;
        }
        
    }
    
}
int main(){
    int arr[]={10,20,20,60,35,35,50,50};
    int n = sizeof(arr)/sizeof(arr[0]);
    freuency(arr, n);

    return 0;
}