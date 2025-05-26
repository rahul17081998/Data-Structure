#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

// ************* Initialize Some Global Veriable and vectors ********************//
vector<vector<int> > allComb;
vector<vector<vector<int> > > triplets;
vector<int> b1, b2, b3;
unordered_map<string, int> mp;
unordered_map<string, vector<int> > mpo;
vector<int> res;
int imb1; // For bruteForce Method 
int imb2; // For Effective Method
// ************* End : Initialize Some Global Veriable and vectors ********************//
 


// ************* BruteForce : imbalance calculation by using subset generating method ********************//
int calImbalance(vector<int> vset)
{
    vector<vector<int> > grid;
    grid.push_back(b1);
    grid.push_back(b2);
    grid.push_back(b3);
    // ignore empty set
    if(vset.size()==0)
        return INT_MAX;

    // calculate imbalance sum
    int sum=0;
    for(int i=0; i<grid.size(); i++)
    {
        int level_sum=0;
        for(int x: vset)
        {
            level_sum += grid[i][x];
        }
        sum = sum + abs(level_sum);
    }
    return sum;
}

vector<int> balancing(vector<vector<int> > &subset)
{
    // select each subset and find imbalance for that
    int imbalance=1000000;
    vector<int> ans;
    for(int i=1; i<subset.size(); i++)
    {
        // set=[0,2,3,4]
        vector<int> set=subset[i];
        int temp_imbalance = calImbalance(set);
        if(temp_imbalance < imbalance){
            imbalance = temp_imbalance;
            ans = set;
        }
        
    }
    imb1 = imbalance;
    cout<<"BrutForce Method: Imbalance = "<<imbalance;
    // myfile <<"BrutForce Method: Imbalance = "<<imbalance<<" --------- S = ";
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
// print answer
void printAns(vector<int> ans)
{
    cout<<"  -------  S = ";
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]+1<<" ";
    cout<<endl;
}
void solve(int n)
{
    vector<int> nums;
    for(int i=0; i<n; i++) 
        nums.push_back(i);

    // call subset function to generate all subset
    vector<vector<int> > subset = subsets(nums); 
    vector<int> ans = balancing(subset);
    // // print ans
    printAns(ans);
}
// ************* End : BruteForce : Imbalance calculation by using subset generating method ********************//



// ************* Effective Approach : imbalance calculation by using subset generating method ********************//
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
void countPattern()
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
void balancing()
{
    initializeMap(); // initialize map 
    countPattern();   // count how many each patterns are present in bicoloring. Like ppp, ppm, mmp, ...etc coutnt
    // vector<int> res;
    imb2 = calculate_Imbalance(); // imbalance calculate
    cout<<"Effective Method: Imbalance = "<<imb2;
    // for(int i=0; i<res.size(); i++) cout<<res[i]+1<<" ";
    // cout<<"\n\n\n";
    // cout<<"Effective Method: Imbalance = "<<imb<<endl<<"\n\n";
}
// ************* End : Effective Approach : imbalance calculation by using subset generating method ********************//


 
// ************* Generating All inputs ********************//
// convert number into bits
vector<int> intToBits(int a, int n)
{
    // string s="";
    vector<int> s;
    while(a){
        if(a%2==0)
            s.push_back(-1);
        else
            s.push_back(1);
        a = a/2;
    }
    while(s.size() < n){
        s.push_back(-1);
    }
    reverse(s.begin(), s.end());
    return s;
}
void printBi(vector<int> B1, vector<int> B2, vector<int> B3){
    for(int i=0; i<B1.size(); i++) cout<<B1[i]<<" ";
    cout<<endl;
    for(int i=0; i<B2.size(); i++) cout<<B2[i]<<" ";
    cout<<endl;
    for(int i=0; i<B3.size(); i++) cout<<B3[i]<<" ";
    cout<<endl;
}
// Generates all triplets
void generateTriplets(int n){
    // int t = pow(2, n);
    int CountMissMatch=0;
    int t = allComb.size();
    for(int i=0; i<t-2; i++){
        b1 = allComb[i];
        for(int j=i+1; j<t-1; j++){
            b2 = allComb[j];
            for(int k=j+1; k<t; k++){
                b3 = allComb[k];
                printBi(b1, b2, b3);
                solve(n); // BruteForce
                balancing(); // Effective Approach
                if(imb1!=imb2) CountMissMatch++;
                cout<<endl<<endl;
            }   
        }
    }
    cout<<"Miss Match Count = "<<CountMissMatch<<endl;
}
// generates all combinations
void AllCombination(int n){
    int t = pow(2, n);

    for(int i=0; i<pow(2,n); i++){
        vector<int> bits = intToBits(i, n);
        allComb.push_back(bits);
    } 
    
}
// print 2D vector
void printGrid(vector<vector<int> > grid){

    for (int i = 0; i < grid.size(); i++){
        for(int j=0; j< grid[i].size(); j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
// print all triplets
void Print3Dvector(){
    cout<<"All triplets are:-\n";
    cout<<"Triplets size: "<<triplets.size()<<endl;
    for(int i=0; i<triplets.size(); i++)
    {
        cout<<i+1<<"th Triplet\n";
        printGrid(triplets[i]);
        cout<<endl<<endl<<endl;
    }
}
// ************* End : Generating All inputs ********************//

int main(){
    
    int n = 6;
    AllCombination(n);
    // print 2D vector allcomb
    printGrid(allComb);
    generateTriplets(n);
    // Print3Dvector();
    return 0;
}
/*
0000000001101
*/