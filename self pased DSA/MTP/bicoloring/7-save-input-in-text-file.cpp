/*
We will run the program multiple time from for fixed no of elements but 
bicoloring will be different for each run 
For that we will generate m bicoloring for each run of n size 

*/

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

vector<int> balancing(vector<vector<int> > &subset, vector<vector<int> > &grid, int &imb)
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
    cout<<"Imbalance = "<<imbalance<<endl;
    imb = imbalance;
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
// print answer
void printAns(vector<int> ans)
{
    cout<<"Print best set S = ";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl<<endl;
}

// create text file
ofstream myfile;
// myfile.open ("example.txt");
/*
void createFile(vector<vector<int> > &grid, int imbalance1)
{
    for(int i=0; i<grid.size(); i++)
    {
        for(int j=0; j<grid[0].size(); j++)
        {
            myfile <<grid[i][j]<<" ";
        }
        myfile <<"\n";
        cout<<endl;
    }
    myfile <<"Imbalance1: "<<imbalance1<<endl;
    // myfile <<"Imbalance2: "<<imbalance2<<endl;
    myfile <<"\n\n";
    // myfile <<"Imbalance2: "<<imbalance2<<endl;
    myfile.close();
}*/

int solve(vector<vector<int> > &grid, int n, int &imb, vector<int> &res)
{
    
    print_2D_Array(grid);
    // generate all subset 
    // Create a array of n size
    // and initialize it with 0 to n-1
    vector<int> nums;
    for(int i=0; i<n; i++) 
        nums.push_back(i);

        // call subset function to generate all subset
    vector<vector<int> > subset;
    subset=subsets(nums); 
    
    vector<int> ans = balancing(subset, grid, imb);
    // createFile(grid, imb);
    // print ans
    res = ans;
    printAns(ans);
}
// random bicoloring input generator
void runProgram(int n, int m, int k)
{
    myfile.open ("example-7.txt");
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
        int imb=INT_MAX; // imbalance
        vector<int> ans;
        solve(grid, n, imb, ans);
        myfile <<"Imbalance: "<<imb<<"  ----------   S = ";
        for(int val: ans) myfile<<val+1<<" "; // 1 index follow
        myfile <<"\n\n";

        // cout<<"IMB = "<<imb;
        // createFile(grid, imb);
    }
}

 
int main(){
    
    int n, m, k; 
    cout << "Enter n: "; // Type a number and press enter
    cin >> n; // Get user input from the keyboard
    cout << "Enter m: "; // Type a number and press enter
    cin >> m; // Get user input from the keyboard
    cout << "How many times you want to run: "; // Type a number and press enter
    cin >> k;
    
    
    runProgram(n, m, k);

    return 0;
}

/*
input:
B0 = -1 1 -1 -1 -1 1 1 1 -1 -1 
B1 = 1 -1 1 -1 1 1 1 1 1 -1 
B2 = 1 1 1 -1 1 -1 -1 -1 -1 -1 
Print best set S: 
0 1 3 5 
*/