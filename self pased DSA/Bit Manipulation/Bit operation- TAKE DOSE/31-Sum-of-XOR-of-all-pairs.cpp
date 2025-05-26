/*
Given an array of N integers, find the sum of xor of all pairs of numbers in the array.

Example 1:

Input : arr[ ] = {7, 3, 5}
Output : 12
Explanation:
All possible pairs and there Xor
Value: ( 3 ^ 5 = 6 ) + (7 ^ 3 = 4)+ ( 7 ^ 5 = 2 ) =  6 + 4 + 2 = 12
*/

//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	long long int res=0;
    	for(int i=31; i>=0; i--){
    	    long long int mask = 1<<i;
    	    // check how many set bits and non set bits
    	    int set=0, nonset=0;
    	    for(int k=0; k<n; k++){
    	        if((mask&arr[k])>0){
    	            set++;
    	        }
    	        else{
    	            nonset++;
    	        }
    	    }
    	    res += mask*set*nonset;
    	}
    	return res;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends