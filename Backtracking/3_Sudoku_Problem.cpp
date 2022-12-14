// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends
class Solution 
{
    public:
    
    bool isSafe(int grid[N][N], int i, int j,int n){
        for(int k = 0; k < N; k++){
            if(grid[i][k] == n || grid[k][j] == n){
                return false;
            }
        }
        int s = sqrt(N);
        int rs = i - (i % s);
        int ts = j - (j % s);
        for(int i = 0; i < s; i++){
            for(int j = 0; j < s; j++){
                if(grid[rs + i][ts + j] == n){
                    return false;
                }
            }
        }
        return true;
    }
    
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        
        int i, j;
        bool found = 0;
        // find the empty cell
        for(i=0; i<N; i++){
            for(j=0; j<N; j++){
                if(grid[i][j] == 0){
                    found=1;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        
        
        // if you traverse the whole grid that means
        // you don't find empty cell
        if(i==N && j==N){
            return true;
        }
         
        // if you find a empty cell
        // we try putting all the no in empy cell
        for(int n = 1; n <=  N ; n++){
            if(isSafe(grid, i, j, n)){
                grid[i][j] = n;
                if(SolveSudoku(grid)){
                    return true;
                }
                grid[i][j] = 0;
            }
        }
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                cout<<grid[i][j]<<" ";       
            }
            cout<<"\n";
        }
        // return ;
    }
};

// { Driver Code Starts.

int main() {
    Solution obj;
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
	if (obj.SolveSudoku(grid) == true) 
		obj.printGrid(grid); 
	else
		cout << "No solution exists"; 



	return 0;
		
}
	
