/*
You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.



*/



class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        
        int left=0, right=0;
        int ans =0;
        while(right<fruits.size()){
            mp[fruits[right]]++;
            // check if size of map is greater than 2 means we have more than 2 types of fruit
            // delete from left side
            while(mp.size()>2){
                mp[fruits[left]]--;
                // if left side fruit count is zero erase it from map
                if(mp[fruits[left]]==0)
                    mp.erase(fruits[left]);
                left++; // increase left pointer
            }
            // find answer
            ans = max(ans, (right-left+1));
            right++;
        }
        return ans;
    }
};