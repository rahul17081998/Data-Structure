#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int solve(vector<int> &v) {
    int n = v.size();
    unordered_map<int, int> um;
    for (int i = 0; i < n; i++) {
        um[v[i]]++;
    }
    int pos_sum = 0, neg_sum = 0;
    for (auto &x : um) {
        if (x.second == 1) {
            if (x.first > 0) pos_sum += x.first;
            else neg_sum += x.first;
        }
    }
    int diff = abs(pos_sum - neg_sum);
    return diff;
}

int solve2(vector<int> scores){
    int n = scores.size();
    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[scores[i]]++;
    }

    int posSum=0, negSum=0;
    for(auto it: mp){
        if(it.second==1){
            if(it.first>0)
                posSum += it.first;
            else
                negSum += it.first;
        }
    }
    return abs(posSum-negSum);
}

int main(){
  
    vector<int> scores;
    // scores.push_back(5);
    // scores.push_back(8);
    // scores.push_back(-1);
    // scores.push_back(7);
    scores.push_back(-10);
    scores.push_back(-20);
    scores.push_back(-30);
    // cout<<solve(scores)<<endl;
    cout<<solve2(scores)<<endl;
    return 0;
}
/*
Ex1:
4
5 8 -1 7
o/p: 21

Ex2:
3
-10 -20 -30
o/p: 60
*/