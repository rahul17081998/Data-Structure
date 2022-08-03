#include<iostream>
using namespace std;
/*
void search_infnite(int arr[], int x)
{   int y = -1;
    for (int i = 0; i <= x; i++)
    {
        if(arr[i]==x)
            cout<<i<<endl;
        else if(arr[i]>x)
            // return -1;
            break;
        
    }
   
}
*/
//Method 2: Most correct way to run a infnite loop
//Naive approch: T(n)=O(x)
int searchele(int arr[], int x)
{
    int i=0;
    while(true)
    {
        if(arr[i]==x) return i;
        if(arr[i]>x) return -1;
        i++;
    }
}

int main(){
    int arr[] = {2,4,7,12,23,27};
    int x=23;
    // search_infnite(arr, x);
    cout<<searchele(arr, x);
    return 0;
}