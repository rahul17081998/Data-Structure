#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Solution 1: Binary Seach
    Intuition
    Blooming flowers = started flowers - ended flowers

    Explanation
    Collect start bloom time point array, then sort it.
    Collect end bloom time point array, then sort it.

    For each time point t in persons:

    Binary search the upper bound of t in start, then we find the started flowers.
    Binary search the lower bound of t in end, then we find the started flowers.
    Blooming flowers = started flowers - ended flowers

    Complexity
    Time O(nlogn + mlogn)
    Space O(n)*/
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        
        vector<int> res;
        vector<int> start, End;
        for(auto f:flowers)
        {
            start.push_back(f[0]);
            End.push_back(f[1]);
        }
        // sort both array
        sort(start.begin(), start.end());
        sort(End.begin(), End.end());
        
        for(int i=0; i<persons.size(); i++)
        {
            int p = persons[i];
            int started = upper_bound(start.begin(), start.end(), p)-start.begin();
            int ended = lower_bound(End.begin(), End.end(), p) - End.begin();
            res.push_back(started - ended);
        }
        return res;
        /*
        unordered_map<int, int> mp; // keep record of at current hour flower count
        
        for(auto flower: flowers)
        {
             // check if starting end ending time is same
            if(flower[0]==flower[1]){
                mp[flower[0]]++;
                continue;
            }
            
            for(int i=flower[0]; i<=flower[1]; i++){
                mp[i]++;
            }
        }
        
        vector<int> res;
        // Now check each person's hour into map
        for(auto hrs: persons){
            res.push_back(mp[hrs]);
        }
        return res;*/
    }
};

int main(){
    
    return 0;
}