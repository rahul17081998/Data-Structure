#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    /*
    Approach: Just count the sum of bits in each position 
    for all the numbers 
    the maximum bit count will give the required answer
    */
    int largestCombination(vector<int>& candidates) {
        
        vector<int> bits_count(24,0);
        for(auto val: candidates)
        {
            for(int i=0; i<24; i++)
            {
                if(val & (1<<i))
                    bits_count[i]++;
            }
        }
        
        int ans = INT_MIN;
        for(int i=0; i<24; i++)
            ans = max(ans, bits_count[i]);
        
        return ans;
    }
};

int main(){
    
    // input
    
    vector<int> candidates;
    candidates.push_back(16);
    candidates.push_back(17);
    candidates.push_back(71);
    candidates.push_back(62);
    candidates.push_back(12);
    candidates.push_back(24);
    candidates.push_back(14);
    
    Solution ob;
    cout<<ob.largestCombination(candidates)<<endl;
    return 0;
}

/*
Input: candidates = [16,17,71,62,12,24,14]
Output: 4
*/