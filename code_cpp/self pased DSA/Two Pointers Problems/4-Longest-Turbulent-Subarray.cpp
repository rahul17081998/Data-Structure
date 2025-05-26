/*
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
arr[k] < arr[k + 1] when k is odd.
 
*/
class Solution {
public:
    // helper function
    bool isTurbulence(int k ,vector<int>& arr){
        if(arr[k]>arr[k+1] && arr[k]>arr[k-1])
            return true;
        else if(arr[k]<arr[k+1] && arr[k]<arr[k-1])
            return true;
        return false;
    }
    // main function
    int maxTurbulenceSize(vector<int>& arr) {
        // we ll use two pointer approach
       int ans = 1; // by default if all valus are same
       int start = 0, end = 0;
       int n = arr.size();


       while(start+1<n){

           if(arr[start]==arr[start+1]){
               start++;
               continue;
           }
           end = start+1;
           // check if mountain-vally exist
           while(end+1<n && isTurbulence(end ,arr)){
               end++;
           }
           ans = max(ans, end-start+1);
           start=end;
       }

        return ans;
    }
};



/*
Input: arr = [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: arr[1] > arr[2] < arr[3] > arr[4] < arr[5]
*/