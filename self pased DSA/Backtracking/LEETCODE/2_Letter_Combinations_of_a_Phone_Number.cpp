/**
 * Date: 21/08/2022
 * Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible 
letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

 * Example 1:
 
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // create a mapping array of digit vs string
    /*
    2 ---> "abc"
    3 ---> "def"
    4 ---> "ghi"
    5 ---> "jkl" and soon...
    
    */
    string keyPad[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    void BackTracking(string digits, string &path, vector<string> &ans ,int index)
    {
        
       
        // base case if index reached at size of digits length than this is our answer
        if(index==digits.size()){
            ans.push_back(path);
            return;
        }
        
        for (char c : keyPad[digits[index]-'0'])
        {
             // path[index] = c; // this will also work 
             path.push_back(c);
             BackTracking(digits, path, ans, index+1);
             path.pop_back();
        }
        
    }
    // Time: O(4^N * N), where N <= 4 is length of digits string. Here, 4 is chosen    
    // assuming the worst case where each digit will be 7 or 9.
    // Extra Space (without counting output as space): O(N), it's the depth of stack memory.
    vector<string> letterCombinations(string digits) {
        
        // we will try to solve first using backtracking
        
        // we will generate all combinations
         vector<string> ans;
        
        // coorner case: 
        if(digits.length()==0)
            return ans;
        
        
        // string path=digits; // copy the digits to path
        string path=""; // copy the digits to path
        BackTracking(digits, path, ans ,0); // 0---? starting index
        return ans;
    }
};


// print all the solutions/latters
void print(vector<string> ans)
{
    for(int i; i<ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
}
int main(){
    // input 
    string digits="25";
    Solution ob;
    vector<string> ans;
    ans = ob.letterCombinations(digits);
    print(ans);
    return 0;
}