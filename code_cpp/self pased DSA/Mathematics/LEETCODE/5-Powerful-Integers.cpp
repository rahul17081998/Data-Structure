/*
Given three integers x, y, and bound, return a list of all the powerful integers that have a value less than or equal to bound.

An integer is powerful if it can be represented as xi + yj for some integers i >= 0 and j >= 0.

You may return the answer in any order. In your answer, each value should occur at most once.

 

Example 1:

Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 20 + 30
3 = 21 + 30
4 = 20 + 31
5 = 21 + 31
7 = 22 + 31
9 = 23 + 30
10 = 20 + 32
Example 2:

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]

*/
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        // put all pow of y which are less than bound into map
        vector<int> powOfy;
        
        int i=0;
        int prev=0;
        while(pow(y,i)<bound){
            powOfy.push_back(pow(y,i));
           
            if(prev==pow(y,i)) break; // coorner case if y=1, then 1^i is always 1, we will stuck unto  the while loop
            prev = pow(y,i);
            i++;
        }
        
        // now check how may value for pow(x,j) have values in powOfy such that
        // pow(x,j) + temp <= bound, find all the temp values
        set<int> st;
        i=0;
        prev=0;
        while(pow(x,i)<bound){
           for(auto val: powOfy){
               if(val + pow(x,i) <= bound){
                   st.insert(val + pow(x,i));
               }
               else
                   break;
           }
            if(prev==pow(x,i)) break; // coorner case if x=1, then 1^i is always 1, we will stuck unto  the while loop
            prev = pow(x,i);
            i++;
        }
        
        vector<int> ans;
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};