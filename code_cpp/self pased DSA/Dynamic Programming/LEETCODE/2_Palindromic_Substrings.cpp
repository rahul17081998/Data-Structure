/**
 * Date: 20/08/2022
 * 
 * Given a string s, return the number of palindromic substrings in it.
    A string is a palindrome when it reads the same backward as forward.
    A substring is a contiguous sequence of characters within the string.
 * 
 * 
 * Input: s = "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 * 
 * 
 * 
 * **/

#include<iostream>
using namespace std;

class Solution {
public:

    int getCountOfPalSubstring(int start, int end, string s)
    {
        int tempCount=0;
        while(start>=0 && end<s.length() && s[start]==s[end])
        {
            start--;
            end++;
            tempCount++;
        }
        return tempCount;
    }
    // Method 2: TC =N^2
    int solve2(string s)
    {
        int count=0;
        for(int i=0; i<s.length(); i++)
        {
            // consider each index as a palindrome and find how many palindrome more can be found 
            // it will give all palindrome of odd length and middle element will s[i]
            // similarly for all even length palindrome whose middle element will be s[i] and s[i+1]
            // we will count than then sum to total count;
            count += getCountOfPalSubstring(i, i, s);   // aba, for odd length
            count += getCountOfPalSubstring(i, i+1, s); //abba, for even length
        }
        return count;
    }
    /*   *   */

    // Method 1: TC =N^3
    
    int solve1(string s)
    {
        int count=0;
        for(int i=0; i<s.length(); i++)
        {
            string temp1="";
            string temp2="";
            for(int j=i; j<s.length(); j++)
            {
                temp1 = temp1 + s[j];
                temp2 = s[j] + temp2;
                if(temp1==temp2)
                    count++;
            }
        }
        return count;
    }
    /*   *   */

    int countSubstrings(string s) {
        
        // return solve1(s);
        return solve2(s);
    }
};

int main(){
    
    // input 
    string str = "aaa";
    Solution ob;
    cout<<ob.countSubstrings(str)<<endl;
    return 0;
}

/*
Smaple input

i/p: "abc"
o/p: 3  

i/p: "a"
o/p: 1 

i/p: "aaa"
o/p: 6  


*/