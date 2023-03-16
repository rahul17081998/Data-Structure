#include<bits/stdc++.h>
using namespace std;
/*
Note: we are giving the input(some fixed number of subsets) such that 
it is guranteed that only one bicolorings will balance all the subsets

When given a fixed number of subsets, there can be multiple bicolorings that could balance 
each of the subsets individually, but not all of them together. However, if it is guaranteed 
that there exists only one bicoloring that can balance all of the subsets, then the output 
of the program or algorithm should produce that unique bicoloring. This unique bicoloring 
could be obtained by considering the constraints and relationships between the subsets and 
finding a color assignment that satisfies all of them simultaneously. The process of finding 
this unique bicoloring could be achieved through various methods 
such as brute force search, heuristic search, or optimization algorithms.

Time Complexity = O(2^N)
*/



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
// generates all combinations
vector<vector<int> > AllCombination(int n){
    int t = pow(2, n);
    vector<vector<int> > allComb;
    for(int i=0; i<pow(2,n); i++){
        vector<int> bits = intToBits(i, n);
        allComb.push_back(bits);
    } 
    return allComb;
}

bool isBalanceAllsubsets(vector<int> &bicolor, vector<vector<int> > &subsets){

    for(auto subset: subsets){
        int sum=0;
        for(int i: subset){
            sum +=bicolor[i];
        }
        if(sum!=0) return false;
    }
    return true;
}

vector<int> findBicoloring(vector<vector<int> > &subsets){
    // find the maximum element from the subset and create all the possible bicolorings of size max+1 
    // which have elements either -1 or +1.
    int maxi = INT_MIN;
    for(auto subset: subsets){
        for(auto ele: subset){
            maxi = max(maxi, ele);
        }
    }
    // Create all the possible bicolorings of size max+1 
    // which have elements either -1 or +1.
    vector<vector<int> > allBicoloring = AllCombination(maxi+1);
    
    // now check which bicoloring could balance all subsets
    vector<int> ans;
    for(auto bicolor: allBicoloring){
        if(isBalanceAllsubsets(bicolor, subsets)){
            ans = bicolor;
            break;
        }
    }
    return ans;
}



int main(){
    vector<vector<int> > subsets; // inputs are given in the subsets
    vector<int> v1;
    v1.push_back(0);
    v1.push_back(1);
    v1.push_back(5);
    v1.push_back(9);
    subsets.push_back(v1);
    v1.clear();

    v1.push_back(3);
    v1.push_back(5);
    v1.push_back(6);
    v1.push_back(9);
    subsets.push_back(v1);
    v1.clear();

    v1.push_back(3);
    v1.push_back(9);
    subsets.push_back(v1);
    v1.clear();

    v1.push_back(0);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(8);
    subsets.push_back(v1);
    v1.clear();


    vector<int> bicolor;
    bicolor = findBicoloring(subsets);
    // print the bicoloring
    cout<<"The bicoloring which balance all the subsets is:\n";
    for(auto b: bicolor) cout<<b<<" ";
    
    return 0;
}

/*
i/p:
{0, 1, 5, 9},
{3, 5, 6, 9},
{3, 9},
{0, 2, 3, 5},

o/p: 
B = 1 -1 1 -1 1 -1 1 1 1 1 


// what could be an answer
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
{*, *, *, *, A ,*, *, A, A, *}
A = anything (+1 or -1).
*/
