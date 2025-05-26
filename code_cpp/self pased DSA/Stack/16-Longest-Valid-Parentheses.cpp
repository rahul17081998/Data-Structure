#include<bits/stdc++.h>
using namespace std;
/* Problem statement:
Given a string containing just the characters '(' and ')', find the length 
of the longest valid (well-formed) parentheses substring.



Approach: 
basically we wan to know those indexed which makes string unbalanced and by using that indexes 
we will going to find good substring length and compare whoever maximum we will return as answer.

Take each index of strign one by one and do following 
1. if stack is empty just push whatever s[i] and continue.
2. if stack has alredy elements then check if top of stack contain '(' if yes then 
check if you have s[i]=')' then pop the top element if stack if not then push into stack, 
and if top of stack do not contain '(' then push s[i] into stack, whatever it has

3. Find all valid substring length and whoever is maximim keep into ans: 
once you push push-pop all elements then use remaining indexes of stacks to find valid ubstring length

take a terminial index initialize with length of String S.
start a while loop untill it is not empty
take top elemnts and find length of substring between "st.top() +1" index to 
terminal index store into ans variable, by using formula
[possible length = terminal - st.top() -1]
and update, terminal = st.top(); and pop the top element of stack

4.Corner Case: at last when while loop terminate we whs to handel a coorner case 
where we have to find the valid string length 0th index to terminal-1 the index

5. return ans
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st; // store index of each parenthesis
        
        for(int i=0; i<s.length(); i++)
        {
            // check if stack is empty,if yes then push that index 
            if(st.empty()){
                st.push(i);
                continue;
            }
            
            // check if top element of stack contain '(' 
            if(s[st.top()]=='(')
            {
                if(s[i]==')') // 
                    st.pop();
                else // it means s[i]='(' then push
                    st.push(i);
            }
            else{
                st.push(i);
            }
        }
        
        // remaining element (if any) in stack are index where string get's unbalanced
        // we will use that index to find length of valid parenthesis
        int n = s.length();
        if(st.empty()) return n; // all char are valid
        
        int ans=0;
        int terminal=n;
        while(!st.empty())
        {
            int possibleLength = terminal- st.top() - 1;
            terminal = st.top();
            // cout<<terminal<<" ";
            st.pop();
            ans = max(ans, possibleLength);
        }
        // corner case: handel starting to last index present into stack(terminal-1) good parenthesis 
        ans = max(ans, terminal);
        return ans;
    }
};


int main(){
    string s = "()())())())";
    // o/p: 4
    Solution ob;
    cout<<ob.longestValidParentheses(s)<<endl;
    return 0;
}
/*
Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
*/