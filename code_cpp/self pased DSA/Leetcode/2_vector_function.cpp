#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int> umap
vector<int> twoSum(vector<int>& nums, int target) 
{
    for( int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            if(nums[i]+nums[j]==target)
            {
                return (make_pair(i,j));
            }
        }
    }
    return -1;
}
int main(){
    vector<int> num={2,7,11,15};
    int target=9;
    cout<<twoSum(num,target);
    return 0;
}