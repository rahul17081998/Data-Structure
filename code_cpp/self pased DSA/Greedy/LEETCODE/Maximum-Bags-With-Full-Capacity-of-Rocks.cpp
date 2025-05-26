/*
You have n bags numbered from 0 to n - 1. You are given two 0-indexed integer arrays capacity and rocks. The ith bag 
can hold a maximum of capacity[i] rocks and currently contains rocks[i] rocks. You are also given an integer additionalRocks, 
the number of additional rocks you can place in any of the bags.
Return the maximum number of bags that could have full capacity after placing the additional rocks in some bags.
*/


class Solution {
public:
    bool static cmp(vector<int> &a, vector<int> &b){
        if(a[1]-a[0]<b[1]-b[0]) return true;
        return false;
    }

    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<vector<int>> rockCap;
        int n = rocks.size();

        for(int i=0; i<n; i++){
            rockCap.push_back({ rocks[i], capacity[i]});
        }

        // sort the rockCap bases on minimum differece between cap[i]-rock[i]
        sort(rockCap.begin(), rockCap.end(), cmp);
        int count=0;
        for(int i=0; i<n && additionalRocks>0; i++){
            vector<int> tempRock = rockCap[i];
            if(tempRock[1]!=tempRock[0]){
                int diff=tempRock[1]-tempRock[0];
                if(diff<= additionalRocks){
                    tempRock[0] = diff;
                    additionalRocks =additionalRocks-diff;
                    count++;
                }
                else{
                    break;
                }
            }
            else{
                count++;
            }
        }
        return count;
    }
};