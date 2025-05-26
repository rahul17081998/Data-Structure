/*
Given an unsorted array Arr of size N of positive integers. One number 'A' from set {1, 2, N} is missing 
and one number 'B' occurs twice in array. Find these two numbers.

Input:
N = 3
Arr[] = {1, 3, 3}
Output: 3 2
Explanation: Repeating number is 3 and 
smallest positive missing number is 2.
*/

//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    // method2: using XOR, TC = O(N), SC = O(1)
    int *findTwoElement(int *arr, int n) {
       int *ans=new int[2];
       // apply bit manupulation
       int xorall=0;
       for(int i=0; i<n; i++){
           xorall ^=arr[i];
           xorall ^=(i+1);
       }
       
        //   now xorall = missing^repeating
        
        // --- find right most set bit in xorall number
        int rightMostSet=xorall & (~(xorall-1)); 
        
        int set1=0, set2=0;
        for(int i=0; i<n; i++){
           if((rightMostSet&arr[i]) >0){
               set1 ^=arr[i];
           }
           else{
               set2 ^=arr[i];
           }
       }
       
       // xor with 1 to n number also
       for(int val=1; val<=n; val++){
           if((rightMostSet&val)>0){
               set1 ^=val;
           }
           else{
               set2 ^=val;
           }
       }
        
       // find which is repeting
       for(int i=0; i<n; i++){
           if(arr[i]==set1){
               ans[0]=set1;
               ans[1]=set2;
           }
           else if(arr[i]==set2){
                ans[0]=set2;
               ans[1]=set1;
           }
       }
       return ans;
    }
    
    /*
    // Method 1: TC = O(N), SC = O(1)
    // sign conversion method
    // you have to return an array
    int *findTwoElement(int *arr, int n) {
        // code here
        // vector<int> ans;
        int *ans = new int[2];
        
        for(int i=0; i<n; i++){
            int index = abs(arr[i])-1;
            
            // check if this index already visited then this is a repeating number
            if(arr[index]<0){
                // repeating number
                ans[0]=abs(arr[i]);
            }
            else{
                arr[index]=-arr[index];
            }
        }
        
        // check which index is +ve value
        for(int i=0; i<n; i++){
            // missing number
            if(arr[i]>0){
                ans[1]=i+1;
            }
        }
        return ans;
        
    }*/
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends