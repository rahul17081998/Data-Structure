#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>power;
    power.push_back(1);
    power.push_back(2);
    power.push_back(6);
    power.push_back(7);
    int armor=5;
    int sum=0;
    for(auto i:power)
    {
        sum+=i;
    }
    sum++; // add 1

    int min1=sum+1;
    // for(auto i:power)
    // {
    //     int diff=sum-min(power[i],armor);
    //     min1=min(min1,diff);
    // }
    // cout<<min1<<endl;

    int mini = sum+1;
    for(auto i: power){
        int diff = sum - min(power[i], armor);
        mini = min(mini, diff);
    }
    cout<<mini<<endl;
    // find maxElelemr
    // int maxi=0;
    // for(int i=0; i<power.size(); i++){
    //     maxi = max(maxi, power[i]);
    // }

    // cout<< sum - min(armor, maxi)<<endl;

}