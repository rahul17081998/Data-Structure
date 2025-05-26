#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Declare globally variable
vector<int> b1, b2, b3;
unordered_map<string, int> mp;
int imb;
int im2;
// initialize the map 
void initializeMap()
{
    mp["ppp"] = 0;
    mp["ppm"] = 0;
    mp["pmp"] = 0;
    mp["mpp"] = 0;
    mp["mpm"] = 0;
    mp["mmp"] = 0;
    mp["pmm"] = 0;
    mp["mmm"] = 0;
}

// count how many each patterns are present in bicoloring.
void countPattern(vector<int> &b1, vector<int> &b2, vector<int> &b3)
{
    for(int i=0; i<b1.size(); i++)
    {
        if(b1[i]==1 && b2[i]==1 && b3[i]==1) mp["ppp"]++;
        else if(b1[i]==1 && b2[i]==1 && b3[i]==-1) mp["ppm"]++;
        else if(b1[i]==1 && b2[i]==-1 && b3[i]==1) mp["pmp"]++;
        else if(b1[i]==-1 && b2[i]==1 && b3[i]==1) mp["mpp"]++;
        else if(b1[i]==-1 && b2[i]==1 && b3[i]==-1) mp["mpm"]++;
        else if(b1[i]==-1 && b2[i]==-1 && b3[i]==1) mp["mmp"]++;
        else if(b1[i]==1 && b2[i]==-1 && b3[i]==-1) mp["pmm"]++;
        else if(b1[i]==-1 && b2[i]==-1 && b3[i]==-1) mp["mmm"]++;
    }
}

// imbalance calculate
int  calculate_Imbalance()
{   
    // 14 cases
    if(mp["ppp"]>0 && mp["mmm"]>0) return 0;
    if(mp["ppm"]>0 && mp["mmp"]>0) return 0;
    if(mp["pmp"]>0 && mp["mpm"]>0) return 0;
    if(mp["pmm"]>0 && mp["mpp"]>0) return 0;
    if(mp["pmm"]>0 && mp["ppp"]>0 && mp["mmp"]>0 && mp["mpm"]) return 0;
    if(mp["mpp"]>0 && mp["mmm"]>0 && mp["ppm"]>0 && mp["pmp"]) return 0;
    
    if(mp["ppp"]>0 && (mp["pmm"]>0 || mp["mpm"]>0 || mp["mmp"]>0)) return 2;
    if(mp["mmm"]>0 && (mp["mpp"]>0 || mp["pmp"]>0 || mp["ppm"]>0)) return 2;
    if(mp["ppm"]>0 && mp["mpp"]>0) return 2;
    if(mp["pmp"]>0 && mp["mpp"]>0) return 2;
    if(mp["pmp"]>0 && mp["ppm"]>0) return 2;
    if(mp["mmp"]>0 && mp["mpm"]>0) return 2;
    if(mp["mmp"]>0 && mp["pmm"]>0) return 2;
    if(mp["pmm"]>0 && mp["mpm"]>0) return 2;
    return 3; // defalut
}

//write your function here
void balancing(vector<vector<int> > grid)
{
    b1 = grid[0], b2 = grid[1], b3 = grid[2];
    initializeMap(); // initialize map 
    countPattern(b1, b2, b3);   // count how many each patterns are present in bicoloring. Like ppp, ppm, mmp, ...etc coutnt
    imb = calculate_Imbalance(); // imbalance calculate
    cout<<"Effective Method: Imbalance = "<<imb<<endl<<"\n\n";
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

// create text file
ofstream myfile;
// myfile.open ("example.txt");
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
}
/// End of program 1 ///

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
    cout<<"BrutForce Method: Imbalance = "<<imbalance<<"   ";
    myfile <<"BrutForce Method: Imbalance = "<<imbalance<<" --------- S = ";
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
/*
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
    
}*/

// print answer
void printAns(vector<int> ans)
{
    cout<<"Print best set S = ";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl;
}

static bool cmp(vector<int> &a, vector<int> &b)
{
    return a.size() < b.size();
}
int solve(vector<vector<int> > &grid, int n, vector<int> &ans)
{
    
    // print_2D_Array(grid);
    // generate all subset 
    // Create a array of n size
    // and initialize it with 0 to n-1
    vector<int> nums;
    for(int i=0; i<n; i++) 
        nums.push_back(i);

        // call subset function to generate all subset
    vector<vector<int> > subset;
    subset=subsets(nums); 
    sort(subset.begin(), subset.end(), cmp);
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
        balancing(grid);
        // createFile(grid, imb);
        myfile <<"Effective Method: Imbalance = "<<imb<<endl;
        myfile <<"\n\n";
        // check imbalance
        if(imb != im2){
            missMatch++;
            temp = grid;
        }
    }
    cout<<"Miss_Match_count = "<<missMatch<<endl;
    myfile<<"Miss_Match_count = "<<missMatch<<endl;
    print_2D_Array(temp);
}

int main(){
    // input
    int n, m=3, k; 
    cout << "Enter n: "; // Type a number and press enter
    cin >> n; // Get user input from the keyboard
    // cout << "Enter m: "; // Type a number and press enter
    // cin >> m; // Get user input from the keyboard
    cout << "How many times you want to run: "; // Type a number and press enter
    cin >> k;
    
     
    myfile.open ("example-10-6.txt");
    runProgram(n, m, k);
    return 0;
}