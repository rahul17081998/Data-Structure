#include<bits/stdc++.h>
#include<string>
#include<unordered_map>

using namespace std;
// solve function
unordered_map<string, bool> mp;

bool solve(string a, string b)
{
    // if both string is equal
    if(a.compare(b)==0)
        return true;
    if(a.length()<=1)
        return false;
    ////// memoization main work is here

    // create key
    string key = a;
    key.push_back(' ');
    key.append(b);
    // search if key present in map
    if(mp.find(key)!=mp.end())
        return mp[key];
    //////


    int n=a.length();
    bool flag = false; // we are assuming that a and b are not scrambled

    for(int i=1; i<=n-1; i++)
    {
        // if(cond1 || cond2) flag=true, break;
        if((solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i)))
            || 
           (solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i)))   )
        {
            flag=true;
            break;
        }
    }
    mp[key] = flag;
    return flag;
}
// main fun
bool scrambled(string a, string b)
{
    if(a.length() != b.length())
        return false;
    if(a.length()==0 && b.length()==0)
        return true;
    // call solve function
    return solve(a, b);
}
int main(){
    string a="great";
    string b="rgeat";
    mp.clear();
    
    cout<<"Do both string are scrambled: "<<scrambled(a, b)<<endl;
    return 0;
}

/*
Input: s1 = "great", s2 = "rgeat"
Output: true

Input: s1 = "abcde", s2 = "caebd"
Output: false
*/