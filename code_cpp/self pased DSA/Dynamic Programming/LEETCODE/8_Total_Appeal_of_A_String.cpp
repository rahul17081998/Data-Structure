/**
 * Data: 21/08/2022
 * Total Appeal of A String:
The appeal of a string is the number of distinct characters found in the string.
For example, the appeal of "abbca" is 3 because it has 3 distinct characters: 'a', 'b', and 'c'.
Given a string s, return the total appeal of all of its substrings.
A substring is a contiguous sequence of characters within a string.


*/

#include<bits/stdc++.h>
#include<unordered_set>

using namespace std;

class Solution {
public:
    // Method 3: Much more simpler and understandable
    // time = O(N*26)
    long long Counter(string s, char ch)
    {
        long long n=s.length();
        long long res=0; // store total No of substring without containing character 'ch'
        long long cnt=0;    // store the how many char contain string have untill ch comes
        // Example: abbca
        for(int i=0; i<n; i++)
        {
            if(ch==s[i]){
                res += cnt*(cnt+1)/2;
                cnt=0;
            }
            else
                cnt++;
        }
        
        res += cnt*(cnt+1)/2; // calculate no of substring which do not contain character ch
        return n*(n+1)/2 - res; // calculate no of substring which contain character ch [total substring- substring wothout containing ch letter]
    }
    
    long long  solve2(string s)
    {
        long long total_count=0;
        // 
        for(char ch='a'; ch<='z'; ch++)
        {
            // for each character present in string do:
            // how many substring contain atleast one character ch and
            // add them with result
            total_count += Counter(s, ch);
        }
        return total_count;
    }
    /****** Method 3: End *******/
    
    // Method 2: Dp
    long long solve(string s)
    {
        int n = s.length();
        // crate a dp array
        vector<long long > dp(n+1, 0);
        // create a last index array
        vector<int> lastOccurance(26, -1);
        
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            int c = s[i]-'a';
            dp[i+1] = dp[i] + i - lastOccurance[c];
            ans += dp[i+1];
            // update lastocuurance
            lastOccurance[c]=i;
        }
        return ans;
    }
    
    /****** Method 2: End *******/
    
    // Method 1: Naive Approach
    // Time complexity = O(N^2)
    // space = O(N)
    
    long long allSubString(string s)
    {
        // step 1: generate all substring
        // step 2: calculate number of distinct characters and sum with ans
        // we will use set to get distinct count of characters
        long long  total_sum=0;
        // unordered_set<string> set;
        
        // generating all substring
        for(int i=0; i<s.length(); i++)
        {
            string substr="";
            unordered_set<char> set;
            for(int j=i; j<s.length(); j++)
            {
                // substr.push_back(s[j]);
                set.insert(s[j]);
                total_sum += set.size();
            }
            // total_sum += set.size();
            // set.clear();
        }
        
        return total_sum;
        
    }
    /****** Method 1: End *******/
    
    long long appealSum(string s) {
        
        // Method 3: O(N*26)
        return solve2(s);
        
        // Method 2: DP
        // return solve(s);
        
        // Method 1: O(N^2)
        // return allSubString(s);
    }
};


int main(){
    // input
    string s = "abbca";
    // O/P: 28 --->  [9 + 11 + 8]
    Solution ob;
    cout<<ob.appealSum(s)<<endl;
    return 0;
}