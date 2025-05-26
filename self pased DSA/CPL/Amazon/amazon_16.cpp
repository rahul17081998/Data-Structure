#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>awards={1,13,6,8,9,3,5};
    int k=4;
    int group=1;
    sort(awards.begin(),awards.end());
    int min1=awards[0];
    int n=awards.size();
    for(int i=1;i<n;i++)
    {
        if(awards[i]-min1>k)
        {
            group++;
            min1=awards[i];
        }
    }
    cout<<group<<endl;
}