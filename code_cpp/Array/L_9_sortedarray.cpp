#include<iostream>
using namespace std;

void sortedarray(int arr[], int n)
{   int c = 1;
    if (n==1)
    {
        cout<<"YES"<<endl;
    }
    for (int i = 1; i < n; i++)
    {
        if(arr[i]>=arr[i-1])
        {
            // cout<<"YES"<<endl;
            c++;
            
        }
        // else 
        // {
        //     cout<<"NO"<<endl;
        //     break;
        // }
    }
    // cout<<c<<endl;
    // cout<<n<<endl;
    if(c==n)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    
}

int main(){
    int arr[] = {30,40,50,60};
    int n = sizeof(arr)/sizeof(arr[0]);
    sortedarray(arr, n);
    return 0;
}