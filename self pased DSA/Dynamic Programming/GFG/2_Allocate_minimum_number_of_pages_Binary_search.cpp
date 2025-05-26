// { Driver Code Starts
// Initial template for C++
// Love Baber video
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    bool isSucessfull(int mid, int arr[], int n, int m)
    {
        int reqStudent=1;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum += arr[i];
            
            if(sum > mid)
            {
                reqStudent++;
                // check is no of student required is more than the given student 
                // means this mid can not be our ans
                if(reqStudent > m || arr[i] > mid)
                    return false;
                sum = arr[i];
            }
        }
        return true;
    }
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        int s=0;
        int end=0;
        for(int i=0; i<N; i++) 
            end += A[i];
        
        int ans=-1;
        
        // start while loop
        while(s <= end)
        {
            int mid = s + (end-s)/2;
            // check is mid could sucessfully be an answer
            if(isSucessfull(mid, A, N, M))
            {
                end = mid-1;
                ans = mid; // store the answer [we will check other best ans also]
            }
            else{ // if mid can not be an answer then we need to increase our mid position
            // for that we need to change our starting position 
                s = mid +1;
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int n=5; // no of books
    int m=3; // no of student's
    
    int A[] = {5, 10,30,20,15}; // pages corrosponding to the book
    
    Solution ob;
    cout << ob.findPages(A, n, m) << endl;

    return 0;
}
  // } Driver Code Ends

    /*
    input:

    3 5
    5 10 30 20 15
   */