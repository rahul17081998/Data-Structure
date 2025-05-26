#include<bits/stdc++.h>
using namespace std;

int calImbalance(vector<int> set, vector<vector<int> > grid)
{
    // ignore empty set
    if(set.size()==0)
        return INT_MAX;

    // calculate imbalance sum
    int sum=0;
    for(int i=0; i<grid.size(); i++)
    {
        int level_sum=0;
        for(int x: set)
        {
            level_sum += grid[i][x];
        }
        sum = sum + abs(level_sum);
    }
    return sum;
}

vector<int> balancing(vector<vector<int> > &subset, vector<vector<int> > &grid)
{
    // select each subset and find imbalance for that
    int imbalance=1000000;
    vector<int> ans;
    for(int i=1; i<subset.size(); i++)
    {
        // set=[0,2,3,4]
        vector<int> set=subset[i];
        int temp_imbalance = calImbalance(set, grid);
        if(temp_imbalance < imbalance){
            imbalance = temp_imbalance;
            ans = set;
        }
        
    }
    return ans;
}
// generate all subset of an array
vector<vector<int> > subsets(vector<int>& nums) 
{
    vector<vector<int> > ans;
    int n = nums.size();
    vector<int> empty;
    ans.push_back(empty);
    
    for(int i=0; i<n; i++)
    {
        int sz = ans.size();
        for(int j=0; j<sz; j++)
        {
            vector<int> temp = ans[j];
            temp.push_back(nums[i]);
            ans.push_back(temp);
        }
    }
    
    return ans;
}

// print all subsets
void printSub(vector<vector<int> > grid)
{
    cout<<"Your subsets are: \n";
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[i].size(); j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"\n";
    }
}
// print all colorings
void prinAllColoring(vector<vector<int> > grid)
{
    cout<<"coloring are: \n";
    for(int j=0; j<grid.size(); j++)
    {
        cout<<"B"<<j<<" = ";
        for(int i=0; i<grid[j].size(); i++)
        {
            cout<<grid[j][i]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    
    int n; 
    // n=4;
    cout << "Enter n: "; // Type a number and press enter
    cin >> n; // Get user input from the keyboard
    int m;
    cout << "Enter m: "; // Type a number and press enter
    cin >> m; // Get user input from the keyboard

    // create a 2d array to strore colorings
    vector<vector<int> >grid;
    for(int j=0; j<m; j++)
    {
        vector<int> level;
        cout<<"Please Enter the coloring\n";
        for(int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            level.push_back(a);
        }
        grid.push_back(level);
        prinAllColoring(grid); // to print the grid
    }

    
    // Create a array of n size
    // and initialize it with 0 to n-1
    vector<int> nums;
    for(int i=0; i<n; i++) 
        nums.push_back(i);
    
    // call subset function to generate all subset
    vector<vector<int> > subset;
    subset=subsets(nums); 

    // print all subsets
    // printSub(subset);
    // cout<<"No of subsets generated: "<<subset.size()<<endl;

    vector<int> ans;
    ans = balancing(subset, grid);
    // print ans
    cout<<"Print best set S: \n";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    return 0;
}
/*
input:
// 

8
3 
1 -1 1 -1 -1 -1 -1 -1
1 1 -1 -1 -1 -1 -1 -1
-1 1 1 -1 -1 -1 -1 -1

*/