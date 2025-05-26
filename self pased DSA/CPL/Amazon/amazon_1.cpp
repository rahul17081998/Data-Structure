/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>locations;
    int m,n;
    vector<int>moved_from;
    vector<int>moved_to;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int q;
        cin>>q;
        locations.push_back(q);
        
    }
    for(int i=0;i<m;i++)
    {
        int q;
        cin>>q;
        moved_from.push_back(q);
    }
    for(int i=0;i<m;i++)
    {
        int q;
        cin>>q;
        moved_to.push_back(q);
    }
    map<int,int>ma;
    for(int i=0;i<n;i++)
    {
        ma[locations[i]]=1;
    }
    for(int i=0;i<m;i++)
    {
        int u=moved_from[i];
        int v=moved_to[i];
        ma.erase(u);
        ma[v]=1;
    }
    for(auto i:ma)
    {
        cout<<i.first<<" ";
    }
    cout<<endl;

}
*/
#include<bits/stdc++.h>
#include<unordered_map>

using namespace std;


int main(){
    
    vector<int> locations, movedFrom, moveTo;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        locations.push_back(x);
    }

    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        movedFrom.push_back(x);
    }

    for(int i=0; i<m; i++){
        int x;
        cin>>x;
        moveTo.push_back(x);
    }

    unordered_map<int,int> mp;
    for(int i=0; i<n; i++){
        mp[locations[i]]=1;
    }

    for(int i=0; i<m; i++){
        int u = movedFrom[i];
        int v = moveTo[i];
        mp.erase(u);
        mp[v]=1;
    }

    vector<int> ans;
    for(auto it: mp){
        ans.push_back(it.first);
    }

    sort(ans.begin(), ans.end());
    cout<<"solution :";
    for(int x: ans){
        cout<<x<<" ";
    }
    

    return 0;
}

/*
    4 3
    1 7 6 8
    1 7 2
    2 9 5
    
    */
