// https://www.geeksforgeeks.org/element-1st-array-count-elements-less-equal-2nd-array/
//{ Driver Code Starts
// C++ implementation of For each element in 1st 
// array count elements less than or equal to it
// in 2nd array

// Given two unsorted arrays arr1[] and arr2[]. They may contain duplicates. For each element in arr1[] count elements less than or equal to it in array arr2[].


#include <bits/stdc++.h>
 
using namespace std;


// } Driver Code Ends
// function to count for each element in 1st array,
// elements less than or equal to it in 2nd array
// elements less than or equal to it in 2nd array
int binarySearch(int target,int arr[],int l,int u)
    {
     int mid;
     while(l<=u)
     {
      mid=l+(u-l)/2;
      if(arr[mid]<=target)
       l=mid+1;
      else
       u=mid-1;
     }
     return l;
    }

class Solution{
  public:
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
    //Your code goes here
        vector<int> v;
        sort(arr2,arr2+n);
        
        for(int i=0; i<m; i++)
        {
            
            v.push_back(binarySearch(arr1[i],arr2, 0, n-1));
        }
        return v;

    }
};

//{ Driver Code Starts.
int main()
{
   
        int m,n;
        cin>>m>>n;
        int arr1[m],arr2[n];
        for(int i=0;i<m;i++)
        cin>>arr1[i];
        for(int j=0;j<n;j++)
        cin>>arr2[j];
        Solution obj;
        vector <int> res = obj.countEleLessThanOrEqual(arr1, arr2, m, n);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        
        cout<<endl;
    
    return 0;

/*
6 6
1 2 3 4 7 9
0 1 2 1 1 4

o/p: 
4 5 5 6 6 6 
*/
}
// } Driver Code Ends