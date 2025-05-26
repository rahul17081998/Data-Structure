#include<bits/stdc++.h>
using namespace std;

/*Problem:
*You are given a 0-indexed 2D integer array flowers, where flowers[i] = [starti, endi] means the ith flower will be in full bloom from starti to endi (inclusive). You are also given a 0-indexed integer array persons of size n, where persons[i] is the time that the ith person will arrive to see the flowers.
Return an integer array answer of size n, where answer[i] is the number of flowers that are in full bloom when the ith person arrives.




Approah:
    *Notice that for any given time t, the number of flowers blooming at time t is equal to the number of flowers that have started blooming minus the number of flowers that have already stopped blooming.
    *We can obtain these values efficiently using binary search.
    *We can store the starting times in sorted order, which then allows us to binary search to find how many flowers have started blooming for a given time t.
    *We do the same for the ending times to find how many flowers have stopped blooming at time t.
*/

class Solution {
public:
    
    
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        
        // Method 2
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
            // No. of floweres that starts blooming, any given time t
            int bloomigFlowers = upper_bound(start.begin(), start.end(), p)-start.begin();
            // No. of floweres that alredy stop starts blooming, any given time t
            int dyingFlowers = lower_bound(End.begin(), End.end(), p) - End.begin();
            res.push_back(bloomigFlowers - dyingFlowers);
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
    // inputInput: 
    // flowers = [[1,6],[3,7],[9,12],[4,13]], persons = [2,3,7,11]
    // Output: [1,2,2,2]
    vector<vector<int>> flowers;
    vector<int> persons;

    Solution ob;
    vector<int> ans = ob.fullBloomFlowers(flowers, persons);
    return 0;
}