#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
// Declare globally variable
vector<int> b1, b2, b3;
unordered_map<string, int> mp;
int imb;
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
    if(mp["ppp"]>0 && mp["mmm"]>0) return 0;
    if(mp["ppm"]>0 && mp["mmp"]>0) return 0;
    if(mp["pmp"]>0 && mp["mpm"]>0) return 0;
    if(mp["pmm"]>0 && mp["ppp"]>0 && mp["mmp"]>0 && mp["mpm"]) return 0;
    if(mp["mpp"]>0 && mp["mmm"]>0 && mp["ppm"]>0 && mp["pmp"]) return 0;
    if(mp["ppp"]>0 && (mp["pmm"]>0 || mp["mpm"]>0 || mp["mmp"]>0)) return 2;
    if(mp["mmm"]>0 && (mp["mpp"]>0 || mp["pmp"]>0 || mp["ppm"]>0)) return 2;
    if(mp["ppm"]>0 && mp["mpp"]>0) return 2;
    if(mp["pmp"]>0 && mp["mpp"]>0) return 2;
    if(mp["mmp"]>0 && mp["mpm"]>0) return 2;
    if(mp["mmp"]>0 && mp["pmm"]>0) return 2;
    if(mp["pmm"]>0 && mp["mpm"]>0) return 2;
    return 3; // if all values are in a bicoloring
}

//write your function here
void balancing(vector<vector<int> > grid)
{
    b1 = grid[0], b2 = grid[1], b3 = grid[2];
    initializeMap(); // initialize map 
    countPattern(b1, b2, b3);   // count how many each patterns are present in bicoloring. Like ppp, ppm, mmp, ...etc coutnt
    imb = calculate_Imbalance(); // imbalance calculate
    cout<<"imbalance: "<<imb<<endl<<"\n\n";
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

// random bicoloring input generator
void runProgram(int n, int m, int k)
{
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
        balancing(grid);
        // createFile(grid, imb);
        myfile <<"Imbalance: "<<imb<<endl;
        myfile <<"\n\n";
    }
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
    
    myfile.open ("example2.txt");
    runProgram(n, m, k);


    /*
    vector<vector<int> > grid;
    vector<int> level;
    
    level.push_back(1);
    level.push_back(-1);
    level.push_back(1);
    level.push_back(-1);
    grid.push_back(level);
    level.clear();

    level.push_back(-1);
    level.push_back(1);
    level.push_back(1);
    level.push_back(-1);
    grid.push_back(level);
    level.clear();

    level.push_back(1);
    level.push_back(1);
    level.push_back(-1);
    level.push_back(-1);
    grid.push_back(level);
    level.clear();

    balancing(grid);
    */
    return 0;
}