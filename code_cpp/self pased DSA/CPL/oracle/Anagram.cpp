//  https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
//  https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/avatar-and-his-quest-d939b13f/editorial/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int solve(string s){
    int n = s.length();
    unordered_map<char, int> mp;

    for(int i=n/2; i<n; i++){
        mp[s[i]]++;
    }

    int count = 0;
    for(int i=0; i<n/2; i++){
        if(mp.find(s[i])!=mp.end()){
            count++;
            mp[s[i]]--;
            if(mp[s[i]]==0){
                mp.erase(s[i]);
            }
        }
    }
    return n/2-count;

}

int main(){


    string s = "123122";
    cout<<solve(s)<<endl;
    return 0;
}

