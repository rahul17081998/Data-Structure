/*
We will run the program multiple time from for fixed no of elements but 
bicoloring will be different for each run 
For that we will generate m bicoloring for each run of n size 

*/

#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int im1, im2;
// Method 2: Linear method
// imbalance calculation for m=2 in linear time
unordered_set<int> pp, pm, mm, mp;
void findS(vector<int> &ans, bool same_color, bool opposite_color, bool none)
{
    if(same_color)
    {
        for(auto x: pp){
            ans.push_back(x);
            break;
        }
        for(auto x: mm){
            ans.push_back(x);
            break;
        }
        
    }

    
    if(opposite_color)
    {
        for(auto x: pm){
            ans.push_back(x);
            break;
        }
        for(auto x: mp){
            ans.push_back(x);
            break;
        }
        
    }

    if(none)
    {
        ans.push_back(0); // insert any one element    
    }


}

void twoBicolor( vector<vector<int> > &grid)
{
    int m = grid.size(); // no of bicoloring
    int n = grid[0].size(); // no of element
    int imbalance = -1;

    vector<int> b1=grid[0];
    vector<int> b2=grid[1];
    int pp_count=0; // plus_plus count
    int mm_count=0; // minus_minus count
    int pm_count=0; // plus_minus count
    int mp_count=0; // minus_plus count
    vector<int> ans;
    // unordered_set<int> pp, pm, mm, mp;
    // calculate plus_plus, plus_minus, minus_minus and minus_plus counts
    for(int i=0; i<n; i++)
    {
        if(b1[i]==1 && b2[i]==1){
            pp_count++; // increate the count
            pp.insert(i); // store the index if you find plus_plus combination
        }
        if(b1[i]==-1 && b2[i]==-1){
            mm_count++; // increate the count
            mm.insert(i); // store the index if you find minus_minus combination
        }
        if(b1[i]==1 && b2[i]==-1){
            pm_count++; // increate the count
            pm.insert(i); // store the index if you find plus_minus combination
        }
        if(b1[i]==-1 && b2[i]==1){
            mp_count++; // increate the count
            mp.insert(i); // store the index if you find minus_plus combination
        } 
    }

    bool same_color=false; 
    bool opposite_color=false;
    bool none=false; 
    // case 1: check if plus_plus and minus_minus count is greater than zero
    if(pp_count > 0 && mm_count > 0){
        same_color=true; // means we have at least one plus_plus and one minus_minus ---> imbalance =0
        imbalance = 0;
    }
    
    // case 2: check if plus_minus and minus_plus count is greater than zero
    else if(pm_count > 0 && mp_count > 0){
        opposite_color=true; // means we have at least one plus_plus and one minus_minus ---> imbalance =0
        imbalance = 0;
    }

    // case3: check if both case failed --> means imbalance will remains atleast 2 [ one element from each balanceing ]
    else{
        none=true;
        imbalance = 2;
    }

    // Now print the solution set S
    findS(ans, same_color, opposite_color, none);
    im1 = imbalance;
    cout<<"Optimized Method: Imbalance = "<<imbalance<<"   ";
    cout<<"Print best set S = ";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
    cout<<endl<<endl;

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
    cout<<"BrutForce Method: Imbalance = "<<imbalance<<"   ";
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
    cout<<endl;
}


int solve(vector<vector<int> > &grid, int n)
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

    vector<int> ans = balancing(subset, grid);
    // print ans
    printAns(ans);
}
// random bicoloring input generator
void runProgram(int n, int m, int k)
{
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
                if((rand() % 2) == 0)
                    v.push_back(-1);
                else
                    v.push_back(1);
            }
            grid.push_back(v);
        }
        solve(grid, n);
        twoBicolor(grid);
        // check imbalance
        
        if(im1 != im2)
        {
            missMatch++;
            temp = grid;

        }
    }
    cout<<"Miss_Match_count = "<<missMatch<<endl;
    print_2D_Array(temp);
}


int main(){
    
    int n, m, k; 
    cout << "Enter n: "; // Type a number and press enter
    cin >> n; // Get user input from the keyboard
    // cout << "Enter m: "; // Type a number and press enter
    // cin >> m; // Get user input from the keyboard
    m = 2;
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