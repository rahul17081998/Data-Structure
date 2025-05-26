#include<bits/stdc++.h>
using namespace std;

/*Problem Statement:
You are given a string s consisting of lowercase English letters. 
A duplicate removal consists of choosing two adjacent and equal letters 
and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. 
It can be proven that the answer is unique.



Approach:
use stack when you find top element is same as of current element of s[i] than just pop then
after that whatever remaining element left in stack store into a string ans return them as answer*/

class Solution {
public:
    string removeDuplicates(string s) {
        // use stack
        stack<char> st;
        for(int i=0; i<s.length(); i++)
        {
            if(st.empty()){
                st.push(s[i]); 
                continue;
            } 
            
            if(st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        
        
        string ans="";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    
    string s = "aaabdhdssbdhdd";
    Solution ob;
    cout<<ob.removeDuplicates(s)<<endl;
    return 0;
}