//{ Driver Code Starts
//Initial template for C++
/*
Approach:
Maintain a window and add the elements till it contain less or equal to k distict characters
and keep updaing our result. if unique elements exceed (that is unique_ele > k) then keep removing elements from
left side of the window untill quique elements in window becomes = k
*/

#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    // use unordered_map
    unordered_map<char, int> mp;
    int maxi=-1;
    int i=0; // slow pointer
    int j=0; // fast pointer
    
    while(j<s.length())
    {
        // store current element and its count into map
        mp[s[j]]++;
        
        // if you have k unique char in map then find string length 
        // and update with maximum length
        if(mp.size()<=k){
            maxi = max(maxi, j-i+1);
        }
        // while you have more than k char into map
        // keep decreasing s[i] count in map and increase i by 1;
        while(mp.size()>k && i<=j)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
                mp.erase(s[i]);
            i++;
        }
        // increase fast pointer
        j++;
        
    }
    return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    
    string S = "aabacbebebe";
    int K = 2;
    // string S;
    // cin >> S;
    
    // int K;
    // cin >> K;
    
    Solution ob;
    cout << ob.longestKSubstr(S, K) << endl;

}

// } Driver Code Ends