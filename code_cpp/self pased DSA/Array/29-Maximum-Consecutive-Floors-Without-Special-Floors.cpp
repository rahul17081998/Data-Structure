#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        
        int n = special.size();
        sort(special.begin(), special.end()); // sort the special array
        int maxConFloor=0;
        
        // corner cases 1: check how many non-special floors b/w bottom and special[0]
        if(special[0]!=bottom)
            maxConFloor = max(maxConFloor, special[0]-bottom);
        // corner cases 2: check how many non-special floors b/w top and special[n-1]
        if(special[n-1]!=top)
            maxConFloor = max(maxConFloor, top-special[n-1]);
        
        // only one condition can also manage abobe both corner case
        // maxConFloor = max(special[0]-bottom, top-special[n-1]);
        
        for(int i=1; i<n; i++)
        {
            // find non-special floors b/w two special floors
            maxConFloor = max(maxConFloor, special[i]-special[i-1]-1);
        }
        return maxConFloor;
        
    }
};

int main(){
    
    // input
    int bottom = 6, top = 8;
    vector<int> special;
    special.push_back(7);
    special.push_back(6);
    special.push_back(8);
    Solution ob;
    cout<<ob.maxConsecutive(bottom, top, special)<<endl;
    return 0;
}

/*
Input: bottom = 6, top = 8, special = [7,6,8]
Output: 0
*/