#include<bits/stdc++.h>
using namespace std;

// recursive function
void solve(int n, vector<int> &res){
    if(n<0) return;
    res.push_back(n);
    return solve(n-1, res);
}

vector<int> printDec(int n){
    vector<int> res;
    solve(n, res);
    return res;
}


int main(){
    vector<int> ans;
    ans = printDec(19);
    for(auto x: ans) cout<<x<<" ";
    return 0;
}