#include<bits/stdc++.h>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*
Problem Statement:
Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible 
results.
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        // store the last occurance of char
        unordered_map<char, int> lastocc;
        for(int i=0; i<s.length(); i++)
        {
            lastocc[s[i]]=i;
        }
        
        stack<char> st;
        unordered_set<char> set;
        for(int i=0; i<s.length(); i++)
        {
            // check if you have alreday taken this character, then ignore it
            if(set.find(s[i])!=set.end()) continue;
            
            // check while top > s[i] and last occurance of top is greater than i, than pop it
            // also erase it from set
            while(!st.empty() && st.top() > s[i] && lastocc[st.top()] > i){
                set.erase(st.top());
                st.pop();
            }
            // push current char into stack and set
            st.push(s[i]);
            set.insert(s[i]);
        }
        
        // store the reamining char into ans and reverse it
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main(){
    string s = "cbacdcbc";
    Solution ob;
    cout<<ob.removeDuplicateLetters(s)<<endl;
    return 0;
}
/*
Input: s = "cbacdcbc"
Output: "acdb"
*/