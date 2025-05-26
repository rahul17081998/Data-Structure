
/*
Random m bicolring generator given n size

*/

#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;
ofstream myfile;

// we have to check all the subsets and if any subsets is balance in our bicolor, select them
vector<vector<int> > balancedSubset; // we will write this in text file
// vector<int> bicolor;
// vector<vector<int> > allSubsets;
int random(int nlow, int nhigh) {
    static bool initialized = false;
    if (!initialized) {
        srand(time(nullptr)); // initialize random seed using current time
        initialized = true;
    }
    int range = nhigh - nlow + 1; // get the size of the range
    int rand_num = rand() % range + nlow; // generate a random number within the range
    return rand_num;
}



bool isBalanced(vector<int> bicolor, vector<int>subset){
    int sum=0;
    for(int i : subset){
        sum += bicolor[i];
    }
     return sum==0? true:false;
}



// generate all subset of an array
void subsets( vector<int> bicolor) 
{
    vector<int> nums;
    int n = bicolor.size();
    for(int i=0; i<n; i++){
        nums.push_back(i);
    }

    vector<vector<int> > ans;
    
    vector<int> empty;
    ans.push_back(empty);
    
    for(int i=0; i<n; i++){
        int sz = ans.size();
        for(int j=0; j<sz; j++){
            vector<int> temp = ans[j];
            temp.push_back(nums[i]);
            // send this temp to check is it balanced our bicolor
            if(isBalanced(bicolor, temp)){
                balancedSubset.push_back(temp);
            }
            ans.push_back(temp);
        }
    }
    // return ans;
}


// random input (+1 and -1) generator
void random_Bicolor_Generator(int nLow, int nHigh, int m, vector<vector<int> > &bicolors){
    srand(time(0));  // Initialize random number generator.
    for(int j=0; j<m; j++){
        vector<int> v;
        // generate random number between nlow and nHigh
        int n = random(nLow, nHigh);
        for(int i=0; i<n; i++){
            if((rand() % 2) == 0){
                v.push_back(-1);
            }
            else{
                v.push_back(1);
            }
        }
        bicolors.push_back(v);
    }
}
// print 2D matrix 
void print2DArray(vector<vector<int> > grid){
   
    cout<<"Subsets are: "<<endl;
    myfile<<"Subsets are: "<<endl;
    for (int i = 0; i < grid.size(); i++){
        cout<<"{";
        myfile<<"{";

        for(int j=0; j < grid[i].size(); j++){
            if(j==grid[i].size()-1){
                cout<<grid[i][j];
                myfile<<grid[i][j];
            }
            else{
                cout<<grid[i][j]<<", ";
                myfile<<grid[i][j]<<", ";
            }
        }
        if(i==grid.size()-1){
             cout<<"}";
            myfile<<"}";
        }
        else{
            cout<<"},";
            myfile<<"},";
        }
        cout<<endl;
        myfile<<"\n";
    }
}

void printBicolor(vector<int> arr){
    cout<<"B = ";
    myfile<<"B = ";
    for(auto b:arr){
        cout<<b<<" ";
        myfile<<b<<" ";
    } 
    cout<<"\n\n\n";
    myfile<<"\n\n\n";
    
}
int main() 
{
    // input 
    int nlow=4, nHigh=14;
    int m=10;
    myfile.open ("2-inputGenerated.txt");
    vector<vector<int> > biColors;
    random_Bicolor_Generator(nlow, nHigh, m, biColors);
    // print_2D_Array(bicolor);
    int count=1;
    for(auto bicolor: biColors){
        cout<<"input"<<count<<endl;
        myfile<<"input"<<count<<endl;
        subsets(bicolor);
        // print the subsets and bicolor
        print2DArray(balancedSubset);
        printBicolor(bicolor);

        balancedSubset.clear();
        count++;
    }
    

    return 0; 
}