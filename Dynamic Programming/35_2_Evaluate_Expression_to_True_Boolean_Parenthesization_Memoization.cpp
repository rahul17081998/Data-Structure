#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// unordered_map<string, int> mp;
unordered_map<string, int> mp;
// Evaluate Expression to True Boolean Parenthesization Memoization
int solve(string s, int i, int j, bool istrue)
{
    // base case

    // string is empty
    if(i>j) 
        return false;
    // string have size 1
    if(i==j)
    {
        if(istrue==true) return s[i]=='t';
        else return s[i]=='f';
    }
    // making a temp input in (i j istrue) fromate to search in map
    string temp = to_string(i);
    temp.push_back(' ');
    temp.append(to_string(j));
    temp.push_back(' ');
    temp.append(to_string(istrue));
    // searching in map is available return
    if(mp.find(temp)!=mp.end())
        return mp[temp];
    // main code
    int ans=0;
    for(int k=i+1; k<j; k=k+2)
    {
        int lt = solve(s, i, k-1, true);
        int lf = solve(s, i, k-1, false);
        int rt = solve(s, k+1, j, true);
        int rf = solve(s, k+1, j, false);
        // check for operator
        
        if(s[k]=='&'){ // AND operator
            if(istrue==true) 
                ans=ans+lt*rt;
            else 
                ans=ans+lf*rf+lf*rt+lt*rf;
        }else if(s[k]=='|'){ // OR operator
                if(istrue==true) 
                    ans+=(lt*rt)+(lt*rf)+(lf*rt);
                else 
                    ans+=(lf*rf);
        }else if(s[k]=='^'){ // XOR operatorf
                if(istrue==true) 
                    ans+=lt*rf+rt*lf;
                else 
                    ans+=lt*rt+lf*rf;
        }
    }
    mp[temp] = ans; // store result into map
    return ans;
}
int main(){
    
    string s="t|t&f^t";
    int i=0,j=s.length()-1;
    mp.clear();
    cout<<solve(s,i,j,true);
    

    return 0;
}
/*
output: 4
*/