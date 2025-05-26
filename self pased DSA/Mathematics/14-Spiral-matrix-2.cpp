#include<bits/stdc++.h>
using namespace std;

//write your function here
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
     
        
        // /*

        
        int left=0, right=n-1, top=0, down=n-1;
        int dir=0;
        
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        int k=1;
        
        while(top<=down && left<=right)
        {
            // left -> right
            if(dir==0)
            {
                for(int i=left; i<=right; i++)
                {
                    matrix[top][i]=k++;
                }
                top++;
            }
            
            // top -> down
            else if(dir==1)
            {
                for(int i=top; i<=down; i++)
                {
                    matrix[i][right]=k++;
                }
                right--;
            }
            
            // right -> left
            else if(dir==2)
            {
                for(int i=right; i>=left; i--)
                {
                    matrix[down][i]=k++;
                }
                down--;
            }
            
            // down -> top
            else if(dir==3)
            {
                for(int i=down; i>=top; i--)
                {
                    matrix[i][left]=k++;
                }
                left++;
            }
            
            dir = (dir+1)%4;
        }
        return matrix;
        // */
    }
};

int main(){
    
    return 0;
}