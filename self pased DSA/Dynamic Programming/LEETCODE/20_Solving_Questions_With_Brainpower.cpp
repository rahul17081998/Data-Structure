#include<bits/stdc++.h>
using namespace std;

/*
Approach
Our dp array contains maximum points we get if we start from question i.
We calculate it going right to left, and the answer for position i is the maximum of:
Take: points[i] + dp[i + 1 + brainpower[i]],
Skip: dp[i + 1].

*/

class Solution {
public:
    long long mostPoints(vector<vector<int> >& questions) {
        
        int n = questions.size();
        vector<long long> profit(n);
        
        for(int i=n-1; i>=0; i--)
        {
            long long point=questions[i][0]; // point that we are geeting to solve this question
            int BP=questions[i][1]; // brain power 
            
            int fi = i+BP+1;  // future index for ith index
            // check if future index not out of index
            if(fi<n){
                profit[i] = point + profit[fi];
            }
            else{
                profit[i] = point;
            }
            
            // update current dp[i] value if it iss less than next dp[i+1]
            if(i<n-1){
                profit[i] = max(profit[i], profit[i+1]);
            }
        }
        
       
        return profit[0];
        
    }
};


int main(){
    // input
    // Input: questions = [[3,2],[4,3],[4,4],[2,5]]
    // Output: 5
    vector<vector<int> > questions;
    vector<int> level;


    level.push_back(3);
    level.push_back(2);
    questions.push_back(level);
    level.clear();

    
    level.push_back(4);
    level.push_back(3);
    questions.push_back(level);
    level.clear();

    level.push_back(4);
    level.push_back(4);
    questions.push_back(level);
    level.clear();

    level.push_back(2);
    level.push_back(5);
    questions.push_back(level);
    level.clear();

    Solution ob;
    cout<<ob.mostPoints(questions)<<endl;
    return 0;
}