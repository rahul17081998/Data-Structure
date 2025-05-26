//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


/*
Problem:Given an array A[] and positive integer K, the task is to count 
total number of pairs in the array whose sum is divisible by K.

Example1:
Input : 
A[] = {2, 2, 1, 7, 5, 3}, K = 4
Output : 5
Explanation : 
There are five pairs possible whose sum
is divisible by '4' i.e., (2, 2), 
(1, 7), (7, 5), (1, 3) and (5, 3)
*/

class Solution
{
    public:
    long long countKdivPairs(int A[], int n, int K)
    {
        //code here
        long long ans=0;
        // map will be used from storing reminder and their count
        // <reminder, count>
        unordered_map<int, int> mp;
        
        for(int i=0; i<n; i++)
        {
            int r = A[i]%K; // reminder
            int c = K-r; // complementry reminder
            if(r!=0)
                ans = ans + mp[c];
            else
                ans = ans + mp[0];
                
            mp[r]++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{

    int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int k;
    cin >> k;

    Solution ob;
    cout << ob. countKdivPairs(a, n , k) << "\n";


	return 0;
}

// } Driver Code Ends

/*
Smaple input:
6
2 2 1 7 5 3
4

O/P: 5
*/