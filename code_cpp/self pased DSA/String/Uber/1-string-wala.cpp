#include<bits/stdc++.h>
using namespace std;

string solve(string s, int k) {
    
    int pos = 0;
    string ans = "";
    while (pos < s.length() - k + 1)
    {
        map<char, int> mp;
        for (int i = pos; i < (pos + k); i++)
        {
            mp[s[i]] = i;
        }
        ans += mp.begin()->first;
        pos = mp.begin()->second + 1;
    }
    sort(ans.begin(), ans.end());
    return ans;
}



int main(){
    int k = 4;
    string s = "aacaa";
    cout<<solve(s, k)<<endl;
    return 0;
}