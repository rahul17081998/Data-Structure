/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/

class Solution {
private:
    bool isPalindrome(string s, int i, int j){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else{
                return false;
            }
        }
        return true;
    } 
public:
    // main function
    bool validPalindrome(string s) {
        
        int start = 0, end = s.length()-1;
        while(start<end){
            while(start<end && s[start]==s[end]){
                start++;
                end--;
            }

            if(start>=end) return true;
            else{
                if(isPalindrome(s, start, end-1)) return true;
                else if(isPalindrome(s, start+1, end)) return true;
                else return false;
            }
        }
        return true;

    }
};
