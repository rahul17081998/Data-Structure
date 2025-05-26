#include<bits/stdc++.h>
using namespace std;

//write your function here
vector<int> findLis(vector<int> &nums)
{
    int n = nums.size();
    vector<int> lis(n, 1);
    
    for(int i=1; i<n; i++)
    {
        // find that number which can devide the current no
        // and compare lis[j]+1 with lis[i] if greater lis[j]+1 > lis[i]
        // keep it stored
        for(int j=0; j<i; j++)
        {
            if(nums[j]<nums[i])
                lis[i] = max(lis[i], lis[j]+1);
        }
    }
    // print lis
    // for(auto x: lis) cout<<x<<" ";
    return lis;
}

int main(){
    vector<int> nums;
    // 4 1 7 2 10
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(7);
    nums.push_back(2);
    nums.push_back(10);

    vector<int> lis = findLis(nums);
    for(int i=0; i<lis.size(); i++) cout<<lis[i]<<" ";
    return 0;
}