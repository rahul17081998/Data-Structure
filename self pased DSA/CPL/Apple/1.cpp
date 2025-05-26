#include<bits/stdc++.h>
using namespace std;

//write your function here
void socialGraph(vector<int> counts)
{
    int n = counts.size();
    set<int> st;
    vector<int> g[200020];

    for(int i=0; i<n; i++){
        g[counts[i]].push_back(i);
        st.insert(counts[i]);
    }

    vector<vector<int> > op;
    for(auto xx: st)
    {
        int i=0;
        vector<int> temp;
        for(auto yy: g[xx])
        {
            // cout<<yy<<" ";
            temp.push_back(yy);
            i++;
            if(i % xx==0){
                i=0;
                op.push_back(temp);
                temp.clear();
            }
        }
    }


    sort(op.begin(), op.end());
    for(int i=0; i<op.size(); i++){
        for(auto x: op[i])
            cout<<x<<" ";
        cout<<endl;
    }
}

int main(){
    vector<int> counts;
    counts.push_back(3);
    counts.push_back(3);
    counts.push_back(3);
    counts.push_back(3);
    counts.push_back(3);
    counts.push_back(1);
    counts.push_back(3);
    socialGraph(counts);

    return 0;
}