#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Declare globally variable
int mFactor;
vector<int> b1, b2, b3;
unordered_map<string, int> mp;
unordered_map<string, vector<int> > mpo; // if a pattern found than store index
vector<int> res;
int imb;
int im2;
ofstream myfile;
// print all bicoloring
void print_2D_Array(vector<vector<int> > bicolor)
{
    for (int i = 0; i < bicolor.size(); i++)
    {
        cout<<"B"<<i<<" = ";
        for(int j=0; j < bicolor[0].size(); j++)
        {
            cout<<bicolor[i][j]<<" ";
        }
        cout<<endl;
    }
    
}




// Method 1: imbalance calculation by using subset generating method
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
    im2 = imbalance;
    cout<<"BrutForce Method: Imbalance = "<<imbalance;
    myfile <<"BrutForce Method: Imbalance = "<<imbalance<<" --------- S = ";
    return ans;
}
// generate all subset of an array
void subsets(vector<int>& nums, vector<vector<int> > &ans) 
{
    // vector<vector<int> > ans;
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
            if(temp.size()<= mFactor)
                ans.push_back(temp);
            else{
                return;
            }
        }
    }
    // return ans;
}
/*
vector<vector<int> > subsets(vector<int>& nums) 
{
    // vector<vector<int> > ans;
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
            if(temp.size()<= mFactor)
                ans.push_back(temp);
            else{
                return;
            }
        }
    }
    return ans;
}*/

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

// print answer
void printAns(vector<int> ans)
{
    cout<<"  -------  S = ";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;
}


int solve(vector<vector<int> > &grid, int n, vector<int> &ans)
{
    
    // print_2D_Array(grid);
    
    // Create a array of n size and initialize it with 0 to n-1
    vector<int> nums;
    for(int i=0; i<n; i++) 
        nums.push_back(i);

    
    vector<vector<int> > subset;
    // generate all subset 
    // subset=subsets(nums); 
    subsets(nums, subset);

    ans = balancing(subset, grid);
    // print ans
    printAns(ans);
}

// random bicoloring input generator
void runProgram(int n, int m, int k)
{
    myfile<<"n = "<<n<<"   ";
    myfile<<"m = "<<m<<"   ";
    myfile<<"k = "<<k<<"\n\n\n";
    int missMatch=0;
    vector<vector<int> > temp;
    srand(time(0));  // Initialize random number generator.
    for(int x=0; x<k; x++)
    {
        vector<vector<int> > grid;
        for(int j=0; j<m; j++){
            vector<int> v;
            for(int i=0; i<n; i++)
            {
                if((rand() % 2) == 0){
                    v.push_back(-1);
                    myfile <<-1<<" ";
                }
                else{
                    v.push_back(1);
                    myfile <<1<<" ";
                }
            }
            myfile <<"\n";
            grid.push_back(v);
        }
        print_2D_Array(grid);
        // int imb=INT_MAX; // imbalance
        vector<int> ans;
        solve(grid, n, ans);
        for(int val: ans) myfile<<val+1<<" "; // 1 index follow
        myfile <<"\n";
        // balancing(grid);
        // createFile(grid, imb);
        // myfile <<"Effective Method: Imbalance = "<<imb<<endl;
        // myfile<<"Effective Method: Imbalance = "<<imb<<"  -------  S = ";
        // for(int i=0; i<res.size(); i++) myfile<<res[i]+1<<" ";
        myfile <<"\n\n\n";
        res.clear();
        // check imbalance
        if(imb != im2){
            missMatch++;
            temp = grid;
        }
    }
    // cout<<"Miss_Match_count = "<<missMatch<<endl;
    // myfile<<"Miss_Match_count = "<<missMatch<<endl;
    print_2D_Array(temp);
}

int main(){
    // input
    int n, m, k; 
    cout << "Enter n: "; // Type a number and press enter
    cin >> n; // Get user input from the keyboard
    cout<< "Enter m: ";
    cin >> m; // Get user input from the keyboard
    // cout << "Enter m: "; // Type a number and press enter
    // cin >> m; // Get user input from the keyboard
    cout << "How many times you want to run: "; // Type a number and press enter
    cin >> k;
    
    string s = "m_"+to_string(m) + "_ans_n_"+ to_string(n) +"_example.txt";
    mFactor = 2*m;
    // myfile.open ("12-exp.txt");
    myfile.open (s);
    runProgram(n, m, k);
    return 0;
}