#include<bits/stdc++.h>
using namespace std;

//write your function here
int minTime(vector<int> ptime, vector<int> task)
{
    assert(ptime.size()*4==task.size());

    sort(ptime.begin(), ptime.end());
    sort(task.rbegin(), task.rend());

    int ans = 0;
    for(int i=0; i<task.size(); i=i+4){
        int j=i/4;
        ans = max(ans, ptime[j]+task[i]);
    }
    return ans;
}

int main(){
    vector<int> ptime, task;
    ptime.push_back(8);
    ptime.push_back(10);

    task.push_back(2);
    task.push_back(2);
    task.push_back(3);
    task.push_back(1);
    task.push_back(8);
    task.push_back(7);
    task.push_back(4);
    task.push_back(5);

    cout<<minTime(ptime, task);
    return 0;
}