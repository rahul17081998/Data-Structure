#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    bool isPalindrome(string a)
    {
        string b=a;
        reverse(b.begin(), b.end());
        return a==b;
    }
    
    vector<vector<string> > ans;
    // back tracking approach
    void solve(string s, int index, vector<string> &path)
    {
        // base case 
        if(index>=s.length()){
            ans.push_back(path);
            return;
        }
        
        
        for(int i=index; i<s.length(); i++)
        {
            if(isPalindrome(s.substr(index, i-index+1))== false) continue;
            path.push_back(s.substr(index, i-index+1));
            solve(s, i+1, path);
            path.pop_back();
                
        }
    }
    // main function
    vector<vector<string> > partition(string s) {
        
        vector<string> path;
        solve(s, 0, path);
        return ans;
    }
};
// print ans
void printGrid(vector<vector<string> > grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        cout<<"[";
        for(int j=0; j< grid[0].size(); j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<"]"<<endl;
    }
    
}
int main(){
    
    string s = "aab";
    Solution ob;
    vector<vector<string> > res=  ob.partition(s);
    printGrid(res);
    return 0;
}