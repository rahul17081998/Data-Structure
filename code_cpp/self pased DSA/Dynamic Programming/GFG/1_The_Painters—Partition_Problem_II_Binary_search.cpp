//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
    
  public:
    bool isSuccessful(int mid, int arr[], int n, int k)
    {
        int reqPainter=1;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum = sum + arr[i];
            if(sum > mid){
                reqPainter++;
                sum = arr[i];
                if(reqPainter > k || arr[i] > mid)
                    return false;
            }
        }
        return true;
    }
  
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        
        long long s=0; // start
        long long end=0; // end --> sum of all painting time
        
        for(int i=0; i<n; i++) end += arr[i];
        long long ans = -1;
        
        while(s<=end)
        {
            int mid = s + (end-s)/2;
            // check is mid could be a successfully solution
            if(isSuccessful(mid, arr, n, k)){
                ans = mid;
                end = mid-1;
            }
            else{
                s = mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int arr[] = {5,10,30,20,15};
    int n=5;
    int k=3;
    Solution obj;
    cout << obj.minTime(arr, n, k) << endl;
	return 0;
}
// } Driver Code Ends