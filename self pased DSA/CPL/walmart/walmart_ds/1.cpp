#include<bits/stdc++.h>
#include<set>
using namespace std;

//write your function here
void solve(vector<int> &v, int x){
    int n = v.size();
    vector<int> ans(n);
    set<pair<int,int> > s1,s2;

    for(int i=0; i<n; i++){

        while(s2.size() >0 && (*s2.begin()).first + x <= v[i]){
            ans[(*s2.begin()).second]=v[i];
            s2.erase(s2.begin());
        }

        while(s1.size() >0 && (*s1.begin()).first + x<=v[i]){
            s2.insert(*s1.begin());
            s1.erase(s1.begin());
        }
        s1.insert(make_pair(v[i], i));
    }


    while(s2.size() > 0){
        ans[(*s2.begin()).second]=-1;
        s2.erase(s2.begin());
    }
    
    while(s1.size() > 0){
        ans[(*s1.begin()).second]=-1;
        s1.erase(s1.begin());
    }
    
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }

}

int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(6);
    v.push_back(7);
    int x = 2;

    solve(v, x);
    return 0;
}

/*
vector<int> v={1,2,3,4,5};
    int x=2;
    int n=v.size();
    vector<int> ans(n);
    set<pair<int,int>> s1,s2;
    
    for(int i=0; i<n; i++){
        while(s2.size()&&(*s2.begin()).first+x<=v[i]){
            ans[(*s2.begin()).second]=v[i];
            s2.erase(s2.begin());
        }
        while(s1.size()&&(*s1.begin()).first+x<=v[i]){
            s2.insert(*s1.begin());
            s1.erase(s1.begin());
        }
        s1.insert({v[i],i});
    }
    while(s2.size()){
        ans[(*s2.begin()).second]=-1;
        s2.erase(s2.begin());
    }
    while(s1.size()){
        ans[(*s1.begin()).second]=-1;
        s1.erase(s1.begin());
    }
    
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    */