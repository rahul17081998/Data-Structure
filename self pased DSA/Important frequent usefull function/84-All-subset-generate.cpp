#include<bits/stdc++.h>
using namespace std;

//write your function here
void generateSubsets(int index,vector<int>& nums, vector<int> &current, vector<vector<int> > &subset)
{
    if(index >= nums.size())
        return;
    
    for(int i=index; i<nums.size(); i++)
    {
        // taking the no
        current.push_back(nums[i]);
        subset.push_back(current);
        generateSubsets(i+1, nums, current, subset);
        // not taking the no
        current.pop_back();
    }
} 

vector<vector<int> > subsets(vector<int>& nums) {
    vector<vector<int> > subsets;
    vector<int> current;
    subsets.push_back(current); // empty subset
    generateSubsets(0, nums, current, subsets);
    return subsets;
}
void printGrid(vector<vector<int> > grid)
    {
        cout<<" Print grid";
        for (int i = 0; i < grid.size(); i++)
        {
            for(int j=0; j< grid[i].size(); j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

    }
int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    for(int i=0; i<3; i++) cout<<nums[i]<<" ";

    vector<vector<int> > allsub = subsets(nums);
    cout<<"\n"<<allsub.size()<<endl;
    printGrid(allsub);
    return 0;
}