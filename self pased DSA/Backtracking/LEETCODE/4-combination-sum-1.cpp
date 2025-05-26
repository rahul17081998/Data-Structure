#include<bits/stdc++.h>
using namespace std;

/*

problem;
Given an array of distinct integers candidates and a target integer target, return a list of all unique 
combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique 
if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less 
than 150 combinations for the given input.



Approach:
General discussion on how we devlop approach-

This was a problem where we have to explore all possibility, make each combination and if sum of a combination 
becomes equal to target sum then we have to store that possible combination in our answer array.

One more thing we have to notice here is that, for a particular element we have unlimited choice i.e we can 
choose a element as many times as we want.

But their is some restiction also on choosing a number.

See for every number in making our target sum, we have two possibility i.e

Whether to include that element in making our target sum.
Whether not to include that element in making our target sum.
We will try and explore each possible combination and if at a point we got our sum as zero then we will say 
yeah!!, we find a possible combination and include that combination in our answer.

Suppose if at any point our target sum becomes less than zero, then we will return from that point and will 
not explore further possibility by saying that, ok our target sum becomes negative that means from now no any 
combination is possible because we have given a non - negative array.

See below tree diagram for more clarity.*/

class Solution{
public:
    vector<vector<int> > ans;
    void solve(int i, vector<int> &currarr, int sum, int target, vector<int> &arr)
    {
        // base casees
        if(i==arr.size()) return;
        if(sum>target) return;
        if(sum==target){
            ans.push_back(currarr);
            return;
        }


        // two option either take or skip the element

        // skip it: increase the current index
        solve(i+1, currarr, sum, target, arr); //  <---

        // take it
        currarr.push_back(arr[i]);
        solve(i, currarr, sum+arr[i], target, arr); //  <---
        currarr.pop_back(); // back track

    }
    void printGrid(vector<vector<int> > grid)
    {    
        for (int i = 0; i < grid.size(); i++)
        {
            for(int j=0; j< grid[i].size(); j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    void CobSum1(vector<int> &arr, int target)
    {
        vector<int> currarr;
        int sum=0;
        solve(0, currarr, sum, target, arr);
        printGrid(ans);
    }
};

int main(){
    int target=12;
    // array have all distinct element
    vector<int> arr;
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(6);
    Solution obj;
    obj.CobSum1(arr, target);
    return 0;
}