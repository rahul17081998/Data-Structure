#include<bits/stdc++.h>
using namespace std;

void printGrid(vector<vector<int> > grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for(int j=0; j< grid[i].size(); j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
int main(){
    vector<vector<int> > grid;
  
    vector<int> level;
    

    level.push_back(3);
    level.push_back(1);
    level.push_back(1);
    grid.push_back(level);
    level.clear();
    
    level.push_back(2);
    level.push_back(5);
    level.push_back(1);
    grid.push_back(level);
    level.clear();
    
    level.push_back(1);
    level.push_back(5);
    level.push_back(5);
    grid.push_back(level);
    level.clear();
    
    level.push_back(2);
    level.push_back(1);
    level.push_back(1);
    grid.push_back(level);
    level.clear();
    
    printGrid(grid);
    return 0;
}