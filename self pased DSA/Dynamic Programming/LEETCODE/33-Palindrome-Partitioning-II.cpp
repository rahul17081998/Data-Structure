#include<bits/stdc++.h>
using namespace std;

//write your function here
/*
Approach:
The definition of 'cut' array is the minimum number of cuts of a sub string. More specifically, cut[n] stores 
the cut number of string s[0, n-1].

Here is the basic idea of the solution:

Initialize the 'cut' array: For a string with n characters s[0, n-1], it needs at most n-1 cut. Therefore, 
the 'cut' array is initialized as cut[i] = i-1

Use two variables in two loops to represent a palindrome:
The external loop variable 'i' represents the center of the palindrome. The internal loop variable 'j' represents 
the 'radius' of the palindrome. Apparently, j <= i is a must.
This palindrome can then be represented as s[i-j, i+j]. If this string is indeed a palindrome, then one possible 
value of cut[i+j] is cut[i-j] + 1, where cut[i-j] corresponds to s[0, i-j-1] and 1 correspond to the palindrome s[i-j, i+j];

When the loops finish, you'll get the answer at cut[s.length]
*/

class Solution {
public:
    int minCut(string s) {
        
        int n = s.length();
        vector<int> cut(n+1, 0);
        for(int i=0; i<=n; i++) cut[i] = i-1;  // initialize with max cut value needed for that position
        
        //  i is the center of the palindrome
        //  j is the radias 
        for(int i=0; i<n; i++)
        {
            // odd length cases
            // j as radius, i-j>=0 and i+j<n, and the string at position i-j and i+j should equal to be a palindrome
           
            // for string from index 0 to i+j (included), the cut value is cut[i+j+1] (s[0:i+j+1]) is equal to the cut value of string s[i-j+1] + 1
            int j=0;
            while(i-j>=0 and i+j<n and s[i-j]==s[i+j]){
                cut[i+j+1] = min(cut[i+j+1], 1 + cut[i-j]);
                j++;
            }
            // # even length
            // # radius is j-1 at left side so i>=j-1
            // # i belongs to the left part of palindrome
            // # i+1+j-1 = i+j < n
            j=1;
            while(i-j+1>=0 and i+j<n and s[i-j+1]==s[i+j]){
                cut[i+j+1] = min(cut[i+j+1], 1+cut[i-j+1]);
                j++;
            }
        }
        return cut[n];
    }
};

int main(){
    
    string s = "aab";
    
    Solution ob;
    cout<<ob.minCut(s)<<endl;
    return 0;
}

    // Input: s = "aab"
    // Output: 1