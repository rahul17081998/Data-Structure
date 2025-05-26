/*

Date: 23/08/2022
Easy Question
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity : O(n2)
    // Space Complexity : O(n2)
    vector<vector<int> > generate(int numRows) {
        
        int n = numRows;
        vector<vector<int> > ans;
        // fill first row
        vector<int> level;
        level.push_back(1);
        ans.push_back(level);
        
        for(int i=1; i<n; i++)
        {
            // create a temp array
            vector<int> temp;
            temp.push_back(1);
            for(int j=1; j<i; j++)
            {
                temp.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            temp.push_back(1);
            ans.push_back(temp);
        }
        return ans;
    }
};

void printTraingle(vector<vector<int> > triangle)
{
    // print pascal traingle
    for (auto level: triangle)
    {
        for(int val: level)
        {
            cout<<val<<" ";
        }
        cout<<"\n";
    }
    

}
int main(){
    // input
    int numRows=5;
    Solution ob;
    vector<vector<int> > triangle = ob.generate(numRows);
    // print Pascal's Triangle
    printTraingle(triangle);
    return 0;
}

/*
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
1 
1 1 
1 2 1 
1 3 3 1 
1 4 6 4 1 
*/