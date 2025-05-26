#include<bits/stdc++.h>
using namespace std;
const int M=3001;
vector<int> solve(int t,int k);
vector<int> solve(int t,int k)
{
    if(t==0){
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(2);
        // return {1,2};
        return ans;
    }
    int a=1,b=2;
    int i;
    set<pair<int,int> > st;
    map<pair<int,int>,int> mpp;
    mpp.insert(make_pair(make_pair(a,b),0));
    st.insert(make_pair(a,b));
    vector<int> res;
    for(i=1;i<=t;i++)
    {
        int x=a;
        a=(k*b+a*a)%M;
        b=(k*x+b)%M;
        if(st.find(make_pair(a,b))!=st.end())
            break;
        st.insert(make_pair(a,b));
        mpp.insert(make_pair(make_pair(a,b),i));
    }
    if(i==t+1)
    {
        res.push_back(a);
        res.push_back(b);
        return res;
    }
    int id=mpp[make_pair(a,b)];
    t-=i;
    vector<int> v;
    for(auto it=mpp.begin();it!=mpp.end();it++)
    {
        if(it->second>=id)
        {
            v.push_back(it->second);
        }
    }
    sort(v.begin(),v.end());
    id=t%(v.size());
    pair<int,int> p=make_pair(0,0);
    for(auto it=mpp.begin();it!=mpp.end();it++)
    {
        if(it->second==id)
        {
            p=it->first;
            break;
        }
    }
    res.push_back(p.first);
    res.push_back(p.second);
    return res;
}
int main()
{

    int t,k;
    cin>>t>>k;
    vector<int> x=solve(t,k);
    cout<<x[0]<<" "<<x[1]<<"\n";
    return 0;
}



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
