#include<bits/stdc++.h>
using namespace std;


/*Problem Statement:
You are given a string s, which contains stars *.In one operation, you can:
Choose a star in s.
Remove the closest non-star character to its left, as well as remove the star itself.
Return the string after all stars have been removed.

Approach:
Use stack when you find current element of s[i] is "*" than just pop top element of stack then
after that whatever remaining element left in stack store into a string ans return them as answer*/

class Solution {
public:
    string removeStars(string s) {
        
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='*')
                st.pop();
            else
                st.push(s[i]);
        }
        
        string ans="";
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

    string s = "leet**cod*e";
    Solution ob;
    cout<<ob.removeStars(s)<<endl;
    return 0;
}