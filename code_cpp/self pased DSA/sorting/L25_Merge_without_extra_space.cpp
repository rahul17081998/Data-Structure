// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
class Solution{
    public:
        // void sortArray1(long long arr[], int n)
        // {
        //     for(int i=n-1; i>=1; i--)
        //     {
        //         if(arr[i]<arr[i-1]){
        //             swap(arr[i],arr[i-1]);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        
        // void sortArray2(long long arr[], int n)
        // {
        //     for(int i=0; i<n-1; i++)
        //     {
        //         if(arr[i]>arr[i+1]){
        //             swap(arr[i],arr[i+1]);
        //         }
        //         else{
        //             break;
        //         }
        //     }
        // }
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            // code here 
         
            int i=n-1;
            int j=0;
            while(i>=0 && j<m)
            {
                if(arr1[i] > arr2[j]){
                    swap(arr1[i--], arr2[j++]);
                }
                else{
                    j++;
                }
                
            }
            sort(arr1,arr1+ n);
            sort(arr2,arr2+ m);
            
        } 
};

// { Driver Code Starts.

int main() 
{ 
	
	 
    int n, m;
    cin >> n >> m;
    
    long long arr1[n], arr2[m];
    
    for(int i = 0;i<n;i++){
        cin >> arr1[i];
    }
    
    for(int i = 0;i<m;i++){
        cin >> arr2[i];
    }
    Solution ob;
    ob.merge(arr1, arr2, n, m); 

    for (int i = 0; i < n; i++) 
        cout<<arr1[i]<<" "; 
    
    
    for (int i = 0; i < m; i++) 
        cout<<arr2[i]<<" "; 
    
    cout<<endl;


	return 0; 
} 
  // } Driver Code Ends