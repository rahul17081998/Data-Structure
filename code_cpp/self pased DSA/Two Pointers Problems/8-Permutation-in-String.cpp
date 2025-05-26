/*
Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // we will store the frequency of each character 
        if(s1.length()>s2.length()) return false;
        
        int n = s1.size();
        vector<int> arr1(26,0); // store all character frequency of s1
        vector<int> arr2(26,0); // store a window of size n character from s2
        for(int i=0; i<n; i++){
            arr1[s1[i]-'a']++;
            arr2[s2[i]-'a']++;
        }
        if(arr1==arr2) return true;
        
        int s=0, e=n;
        while(e<s2.length()){
            arr2[s2[e]-'a']++;
            arr2[s2[s]-'a']--;
            e++;
            s++;
            if(arr1==arr2) return true;
        }
        return false;

    }
};
