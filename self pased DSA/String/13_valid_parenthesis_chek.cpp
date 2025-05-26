#include<bits/stdc++.h>
#include<string>
using namespace std;

class Solution{
public:
    // check is a string of parenthesis is valid
    bool isValid(string s)
    {
        int bal=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
                bal += 1;
            else 
                bal -= 1;

            // check bal is negative or not
            if(bal < 0)
                return false;

        }
        if(bal!=0)
            return false;

        return true;
    }
};

int main(){
    // input
    string s = "(()())";
    Solution ob;
    cout<<ob.isValid(s)<<endl;
    return 0;
}