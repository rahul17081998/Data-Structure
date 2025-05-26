// basic file operations
#include<bits/stdc++.h>
#include <fstream>
using namespace std;
ofstream myfile;
    // myfile.open ("example.txt");

// create text file
void createFile(vector<vector<int> > &grid, int imbalance1, int imbalance2)
{
    // ofstream myfile;
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
    myfile <<"Imbalance2: "<<imbalance2<<endl;
    myfile <<"\n\n";
    // myfile <<"Imbalance2: "<<imbalance2<<endl;
    myfile.close();
}

int main () {
    myfile.open ("example.txt");
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
    
    

    createFile(grid, 4, 3);

    vector<vector<int> > matrix;
    level.push_back(1);
    level.push_back(5);
    level.push_back(5);
    matrix.push_back(level);
    level.clear();
    
    level.push_back(2);
    level.push_back(1);
    level.push_back(1);
    matrix.push_back(level);
    level.clear();

    createFile(matrix, 1, 2);

//   ofstream myfile;
//   myfile.open ("example.txt");
//   myfile << "Writing this to a file.\n";
//   for(int i=0; i<10; i++)
//   {
//       for(int j=0; j<10; j++)
//       {
//           myfile <<i*j<<" ";
//       }
//       myfile <<"\n";
//       cout<<endl;
//   }
//   myfile.close();
  return 0;
}