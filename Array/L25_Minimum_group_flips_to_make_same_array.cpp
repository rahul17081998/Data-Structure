#include<iostream>
using namespace std;

/*
// Naive method(Not correct method)
void flip_group(int arr[], int n)
{   int once_gr = 0;
    int zero_gr = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==1)
        {
            for (int j = i+1; j < n; j++)
            {
                if (arr[j] ==1)
                {
                    break;
                }
                else
                {
                    once_gr++;
                }
                
            }
            
        }

        if (arr[i]==0)
        {
            for (int j = i+1; j < n; j++)
            {
                if (arr[j] ==0)
                {
                    break;
                }
                else
                {
                    zero_gr++;
                }
                
            }
            
        }
        
    }
    cout<<once_gr<<endl;
    cout<<zero_gr<<endl;
}
*/

// Efficiant solution : Correct method
void flip_array(int arr[], int n)
{
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] != arr[i+1] and arr[i]==1)
        {
            ones++;
        }

        if(arr[i] != arr[i+1] and arr[i]==0)
        {
            zeros++;
        }
    }
    /*
    // Boundry condition for last element of arraya
    if(arr[n-1] != arr[n-2] and arr[n-1]==1)
    {
        ones++;
    }
    else if(arr[n-1] != arr[n-2] and arr[n-1]==0)
    {
        zeros++;
    }
    */

    cout<<"zeros goup: "<<zeros<<endl;
    cout<<"once group: "<<ones<<endl<<endl;
    // Deciding wether zreo or ones, which one should flip 
    // Whoever Minimum groups we will flip them.
    if (zeros>ones)
    {
        cout<<"Flip the all ones\nIndex are: ";
        for (int i = 0; i < n; i++)
        {
            if (arr[i]==1)
            {
                cout<<i<<"th ";
            }
            
        }
        
    }

    else if(zeros<ones)
    {
        cout<<"Flip the all zeros\nIndex are:  ";
        for (int i = 0; i < n; i++)
        {
            if (arr[i]==0)
            {
                cout<<i<<"th ";
            }
            
        }
    }

    else{
        cout<<"group of zeros and once are same.\nSo you can change any one. "<<endl;
    }
    
     
}
int main(){
    int arr[]={1,0,1,1,0,1,0,1};
    int n = sizeof(arr)/sizeof(arr[0]); 
    // flip_group(arr, n);
    flip_array(arr, n);
    return 0;
}