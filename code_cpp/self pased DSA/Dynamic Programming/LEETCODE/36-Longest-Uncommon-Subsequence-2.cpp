#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    // length comparision function for sorting function
    static bool cmp(string a, string b)
    {
        return a.size() >b.size();
    }
    //check string x is a subsequence of y or not
    bool isSubsequence(string x, string y)
    {
        if(x.length() > y.length()) return false;
        int i=0, j=0;
        while(j < y.size())
        {
            if(x[i]==y[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if (i==x.length())
            return true;
        return false;
    }
    // check if strs[i] can be as Uncommon Subsequence
    bool isLUS(vector<string>& strs, string x, int index)
    {
        for(int i=0; i<strs.size(); i++)
        {
            if(i==index) continue; // ignore same string
            if(isSubsequence(x, strs[i])) //check string x is a subsequence of y 
                return false;
        }
        return true;
    }
    int findLUSlength(vector<string>& strs) {
        
        int n = strs.size();
        // sorting by maximum length first
        sort(strs.begin(), strs.end(), cmp);
        for(int i=0; i<n; i++)
        {
            // check if strs[i] can be as Uncommon Subsequence
            if(isLUS(strs, strs[i], i))
                return (int)strs[i].length();
        }
        return -1;
    }
};

int main(){
    vector<string> strs;
    strs.push_back("aaa");
    strs.push_back("aaa");
    strs.push_back("aa");
    Solution ob;
    cout<<ob.findLUSlength(strs)<<endl;
    return 0;
}
    // Input: strs = ["aaa","aaa","aa"]
    // Output: -1