#include <iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
    int arr[n];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    // for(int i=n-1; i>=0; i--)
    // {
    //     cout<<arr[i]<<" ";
    // }

    int low = 0;
    int high = n-1;
    for(int i=0; i<n/2; i++)
    {
        swap(arr[low],arr[high]);
        low++;
        high--;
    }


    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
	return 0;
}
