#include<bits/stdc++.h>
using namespace std;

/*
Note: code is corrent it runs perfectally on leetcode
Due to lack of updatation of cpp compiler it does not run here.

Problem Statement:
You are given a string s and an integer k, a k duplicate removal consists of choosing k 
adjacent and equal letters from s and removing them, causing the left and the right side 
of the deleted substring to concatenate together.
We repeatedly make k duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. 
It is guaranteed that the answer is unique.
    
Approach:
Use stack of type pair<char,int> that is we will store char and there previous 
continuous repetation count and store store tham into stacks and if se that char 
count reach k in stach that we have k s[i] continuouly so remove top k element from 
stack basically those top k elements are same charecter so we are removing them, After 
this Process whatever elements left into stack store into a string and return them as answer*/

class Solution {
public:
    string removeDuplicates(string s, int k) {
        
        int n = s.length();
        stack<pair<char,int> > st;
        st.push({s[0], 1});
        
        // /*
        for(int i=1; i<n; i++)
        {
            if(st.empty()==true){
                st.push({s[i], 1});
                continue;
            } 
            if(!st.empty() && s[i]==st.top().first)
            {
                int lastCount = st.top().second;
                if(lastCount==k-1)
                {
                    int j = k-1;
                    while(j>0){
                        st.pop();
                        j--;
                        // continue;
                    }
                        
                }
                else
                {
                    lastCount = st.top().second;
                    st.push({s[i], lastCount+1});
                }
            }
            else{
                st.push({s[i], 1});
            }
        }
        // */
        string ans="";
        // /*
        while(!st.empty())
        {
            ans.push_back(st.top().first);
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        // */
        return ans;
    }
};
int main(){
    
    string s = "deeedbbcccbdaa";
    int  k = 3;
    Solution ob;
    cout<<ob.removeDuplicates(s, k)<<endl;
    return 0;
}
/*
Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
*/