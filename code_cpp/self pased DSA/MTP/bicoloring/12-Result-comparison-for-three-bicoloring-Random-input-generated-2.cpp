#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Declare globally variable
vector<int> b1, b2, b3;
unordered_map<string, int> mp;
unordered_map<string, vector<int> > mpo; // if a pattern found than store index
vector<int> res;
int imb;
int im2;
 
vector<int> fun1(string x1, string x2)
{
    vector<int> tempAns;
    // vector<int> temp1 = mpo[x];
    tempAns.push_back(mpo[x1][0]);
    tempAns.push_back(mpo[x2][0]);
    return tempAns;
}

vector<int> fun2(string x1, string x2, string x3, string x4)
{
    vector<int> tempAns;
    tempAns.push_back(mpo[x1][0]);
    tempAns.push_back(mpo[x2][0]);
    tempAns.push_back(mpo[x3][0]);
    tempAns.push_back(mpo[x4][0]);
    return tempAns;
}
vector<int> fun3(string x1, string x2, string x3, string x4)
{
    vector<int> tempAns;
    tempAns.push_back(mpo[x1][0]);
    // take from any one of three
    if(mpo[x2].size()>0) tempAns.push_back(mpo[x2][0]);
    else if(mpo[x3].size()>0) tempAns.push_back(mpo[x3][0]);
    else if(mpo[x4].size()>0) tempAns.push_back(mpo[x4][0]);
    return tempAns;
}

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
        if(b1[i]==1 && b2[i]==1 && b3[i]==1) {mp["ppp"]++; mpo["ppp"].push_back(i);}
        else if(b1[i]==1 && b2[i]==1 && b3[i]==-1) {mp["ppm"]++; mpo["ppm"].push_back(i);}
        else if(b1[i]==1 && b2[i]==-1 && b3[i]==1) {mp["pmp"]++; mpo["pmp"].push_back(i);}
        else if(b1[i]==-1 && b2[i]==1 && b3[i]==1) {mp["mpp"]++; mpo["mpp"].push_back(i);}
        else if(b1[i]==-1 && b2[i]==1 && b3[i]==-1) {mp["mpm"]++; mpo["mpm"].push_back(i);}
        else if(b1[i]==-1 && b2[i]==-1 && b3[i]==1) {mp["mmp"]++; mpo["mmp"].push_back(i);}
        else if(b1[i]==1 && b2[i]==-1 && b3[i]==-1) {mp["pmm"]++; mpo["pmm"].push_back(i);}
        else if(b1[i]==-1 && b2[i]==-1 && b3[i]==-1) {mp["mmm"]++; mpo["mmm"].push_back(i);}
    }
}

// imbalance calculate
int  calculate_Imbalance()
{
    if(mp["ppp"]>0 && mp["mmm"]>0) {res=fun1("ppp", "mmm"); return 0;}
    if(mp["ppm"]>0 && mp["mmp"]>0) {res=fun1("ppm", "mmp"); return 0;}
    if(mp["pmp"]>0 && mp["mpm"]>0) {res=fun1("pmp", "mpm"); return 0;}
    if(mp["pmm"]>0 && mp["mpp"]>0) {res=fun1("pmm", "mpp"); return 0;}

    if(mp["pmm"]>0 && mp["ppp"]>0 && mp["mmp"]>0 && mp["mpm"]) {res=fun2("pmm", "ppp", "mmp", "mpm"); return 0;}
    if(mp["mpp"]>0 && mp["mmm"]>0 && mp["ppm"]>0 && mp["pmp"]) {res=fun2("mpp", "mmm", "ppm", "pmp"); return 0;}
    if(mp["ppp"]>0 && (mp["pmm"]>0 || mp["mpm"]>0 || mp["mmp"]>0)) {res=fun3("ppp", "pmm", "mpm", "mmp"); return 2;}
    if(mp["mmm"]>0 && (mp["mpp"]>0 || mp["pmp"]>0 || mp["ppm"]>0)) {res=fun3("mmm", "mpp", "pmp", "ppm"); return 2;}
    if(mp["ppm"]>0 && mp["mpp"]>0) {res=fun1("ppm", "mpp"); return 2;}
    if(mp["pmp"]>0 && mp["mpp"]>0) {res=fun1("pmp", "mpp"); return 2;}
    if(mp["pmp"]>0 && mp["ppm"]>0) {res=fun1("pmp", "ppm"); return 2;}
    if(mp["mmp"]>0 && mp["mpm"]>0) {res=fun1("mmp", "mpm"); return 2;}
    if(mp["mmp"]>0 && mp["pmm"]>0) {res=fun1("mmp", "pmm"); return 2;}
    if(mp["pmm"]>0 && mp["mpm"]>0) {res=fun1("pmm", "mpm"); return 2;}
    else {res.push_back(0); return 3;} // if all values are in a bicoloring
}

//write your function here
void balancing(vector<vector<int> > grid)
{
    b1 = grid[0], b2 = grid[1], b3 = grid[2];
    initializeMap(); // initialize map 
    countPattern(b1, b2, b3);   // count how many each patterns are present in bicoloring. Like ppp, ppm, mmp, ...etc coutnt
    // vector<int> res;
    imb = calculate_Imbalance(); // imbalance calculate
    cout<<"Effective Method: Imbalance = "<<imb<<"  -------  S = ";
    for(int i=0; i<res.size(); i++) cout<<res[i]+1<<" ";
    cout<<"\n\n\n";
    // cout<<"Effective Method: Imbalance = "<<imb<<endl<<"\n\n";
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
    cout<<"BrutForce Method: Imbalance = "<<imbalance;
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
    // generate all subset 
    // Create a array of n size
    // and initialize it with 0 to n-1
    vector<int> nums;
    for(int i=0; i<n; i++) 
        nums.push_back(i);

        // call subset function to generate all subset
    vector<vector<int> > subset;
    subset=subsets(nums); 

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
    
    // myfile.open ("12-exp.txt");
    myfile.open (s);
    runProgram(n, m, k);
    return 0;
}