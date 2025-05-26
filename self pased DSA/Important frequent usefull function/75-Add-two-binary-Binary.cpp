/*
Given two binary strings a and b, return their sum as a binary string.
Example 1:

Input: a = "11", b = "1"
Output: "100"
*/

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;

        int carry=0;
        string ans;
        while(i>=0 || j>=0){
            int sum = carry;
            if(i>=0) sum += a[i]-'0';
            if(j>=0) sum += b[j]-'0';
            i--; j--;
            // check if sum is greater than 1. if yes, then carry=1 other wise carry=0
            if(sum>1)
                carry=1;
            else 
                carry=0;
            // add the sum bit if sum is 1 or 3 then add 1 else 0
            ans += to_string(sum%2);
        }
        if(carry>0) ans += to_string(carry); // check if carry is 1
        reverse(ans.begin(), ans.end()); // reverse the answer
        return ans;
    }
};