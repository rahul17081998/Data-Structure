/*
Given a string S. The task is to print all unique permutations of the given string in lexicographically sorted order.
*/

#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	    void backtrack(string s, int idx, set<string> &ans)
	    {
	        if(idx==s.length()){
	            ans.insert(s);
	            return;
	        }
	       
            for(int i=idx; i<s.length(); i++)
            {
	            swap(s[i], s[idx]);
	            backtrack(s, idx+1, ans);
	            swap(s[i], s[idx]);
            }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		   
		    int n = S.length();
		    set<string> ans;
		    backtrack(S, 0, ans); // find all premutations
		    
		    vector<string> v;
		    for(auto str: ans){
		        v.push_back(str);
		    }
		    return v;
		}
};

int main(){
    string s = "ABC";
    Solution ob;
    vector<string> res = ob.find_permutation(s);
    // print
    for(auto str:res) cout<<str<<" ";
 	return 0;
}