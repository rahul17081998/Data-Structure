

#include<bits/stdc++.h>
#include<stack>
using namespace std;
/*Problem Statement:
You are given a string s and an integer repeatLimit. Construct a new string 
repeatLimitedString using the characters of s such that no letter appears more 
than repeatLimit times in a row. You do not have to use all characters from s.
Return the lexicographically largest repeatLimitedString possible.
A string a is lexicographically larger than a string b if in the first position 
where a and b differ, string a has a letter that appears later in the alphabet 
than the corresponding letter in b. If the first min(a.length, b.length) 
characters do not differ, then the longer string is the lexicographically larger one.
*/
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
        int n = s.length();
        // store the count of all char 
        vector<int> count(26, 0);
        for(int i=0; i<n; i++){
            count[s[i]-'a']++;
        }
        
        // store the char and count into stack 
        // alphabetically highr char will comes at top of stack
        stack<pair<char, int> > st;
        for(int i=0; i<26; i++)
        {
            if(count[i]>0)
            {
                st.push({char(i+'a'), count[i]});
                // cout<<char(i+'a')<<"    "<<count[i]<<endl;
            }
        }
        
        string ans="";
        
        while(!st.empty())
        {
            
            auto p = st.top();

            // find the count of char 
            char c = p.first;
            int count = p.second;
            // check if last char of ans is same as top char of stack than return ans 
            if(ans.back() == c)
                return ans;

           
            st.pop();
            
            // check if count1 is greater than repetelimit
            if(count >= repeatLimit)
            {
                int x = repeatLimit;
                while (x)
                {
                   ans.push_back(c);
                    x--;
                }
            }
            
            else
            {
                int x = count;
                while (x)
                {
                   ans.push_back(c);
                    x--;
                }
            }
            
            // now decrease the count1 by repetelimit
            count = count - repeatLimit;
            // 2nd char check of it is present take only one char 
            if(!st.empty() && count >0)
            {
                auto p2 = st.top();
                st.pop();
                char c2 = p2.first;
                int count2 = p2.second;
                ans.push_back(c2);
                count2--;
                // check now if count2 is more than 0 than push into stack
                if(count2>0){
                    st.push({c2, count2});
                }
            }
            // now check if count is greater than 0 push first char and count
            if(count > 0)
            {
                st.push({c, count});
            }  
        }
        
        
       return ans;
        
    }
};


int main(){

    // input
    string s = "zzzzzzcczacc";
    int limit=3;
    Solution ob;
    cout<<ob.repeatLimitedString(s, limit)<<endl;
    return 0;
}