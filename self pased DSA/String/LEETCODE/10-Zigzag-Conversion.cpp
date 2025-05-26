/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()<=numRows || numRows==1) return s;
        vector<string> str(numRows, "");
        str[0].push_back(s[0]);
        int i=1, start=1;
        bool flag=true;
        while(i<s.length()){
            if(flag==true){
                for(int j=1; j<numRows && i<s.length(); j++){
                    str[j].push_back(s[i]);
                    i++;
                }
                // start = numRows-2;
                flag = !flag;
            }
            else{ // start = numRows-2
                for(int j=numRows-2; j>=0 && i<s.length(); j--){
                    str[j].push_back(s[i]);
                    i++;
                }
                flag = !flag;
                // start = 1;
            }
        }
        // assambel all the string 
        string ans="";
        for(auto st: str){
            ans += st;
            // cout<<st<<endl;
        }
        return ans;
    }
};