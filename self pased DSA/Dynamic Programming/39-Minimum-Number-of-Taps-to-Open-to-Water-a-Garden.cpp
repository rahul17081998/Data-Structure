#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jumpGame2(vector<int> jumps, int n){
        
//         int currEnd  = 0;
//         int maxReach = 0;
//         int count    = 0;
//         for(int i = 0; i<n; i++) {
//             maxReach = max(maxReach, jumps[i]+i);
            
//             if(i == currEnd) {
//                 count++;
//                 currEnd = maxReach;
//             }
//         }
        
//         if(currEnd >= n)
//             return count;
//         return -1;
        int maxReach=0;
        int currEnd=0;
        int count=0;
        
        for(int i=0; i<jumps.size(); i++){
            
            if(i > maxReach) return -1;
            if(i>currEnd){
                currEnd = maxReach;
                count++;
            }
            maxReach = max(maxReach, i + jumps[i]);
                
        }
  
            return count;
        
            
    }
    
    int minTaps(int n, vector<int>& ranges) {
        // find the array
        
        vector<int> arr(n+1, 0);
        for(int i=0; i<ranges.size(); i++){
            
            
            int left = max(0, i-ranges[i]);
            int right = min(n, i + ranges[i]);
            arr[left]= max(arr[left], right-left);
        }
        // apply jump game 2
        return jumpGame2(arr,n);
        
    }
};


int main(){
    int n=5;
    vector<int> ranges;
    ranges.push_back(3);
    ranges.push_back(4);
    ranges.push_back(1);
    ranges.push_back(1);
    ranges.push_back(0);
    ranges.push_back(0);

    Solution ob;
    cout<<ob.minTaps(n, ranges)<<endl;
    return 0;
}
/*Input: n = 5, ranges = [3,4,1,1,0,0]
Output: 1
*/