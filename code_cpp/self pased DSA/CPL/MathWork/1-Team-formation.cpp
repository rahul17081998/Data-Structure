// Sol link1: https://github.com/naz-mul94/company-Based-question/blob/master/mathworks/2020/teamFormation.cpp
// Sol link1: https://github.com/marioyc/Online-Judge-Solutions/blob/master/hackerrank/101aug14/team-formation.cpp


/*
** any suggestion highly appreciated
** feel free to modify.
*/

#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;

long long int teamFromation(vector<int> score, int noMember, int m)
{
    long long int ans=0;
    int n=score.size();
    priority_queue<pair<int, int> > memberScore;
    for(int i=0;i<m;i++)memberScore.push(make_pair(score[i], i));
    for(int i=n-m;i<n;i++)memberScore.push(make_pair(score[i], i));    
    int low=m-1;
    int high=n-m;
    while(high>low && noMember)
    {
        pair<int, int> temp=memberScore.top();
        memberScore.pop();
        ans+=temp.first;
        noMember--;
        if(temp.second<=low)
        {
            low++;
            if(low < high)
                memberScore.push(make_pair(score[low], low));
        }
        else if(temp.second>=high)
        {
            high--;
            if(high>low)memberScore.push(make_pair(score[high], high));
        }
    } 
    while(!memberScore.empty() && noMember)
    {
        ans+=memberScore.top().first;
        memberScore.pop();
        noMember--;
    }   
    return ans;
}


int main()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        int noSore,noMember, m;
        cin>>noSore>>noMember>>m;
        vector<int> score(noSore);
        for(int i=0;i<noSore;i++)
            cin>>score[i];
        cout<<teamFromation(score, noMember, m)<<endl;
    }
}