/*

Date: 23/08/2022
Problem Statement:
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, 
and so on until the 100th row.  Each glass holds one cup of champagne.
Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, 
any excess liquid poured will fall equally to the glass immediately to the left and right of it.  
When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, 
and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  
After two cups of champagne are poured, the two glasses on the second row are half full.  
After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  
After four cups of champagne are poured, the third row has the middle glass half full, and the two outside 
glasses are a quarter full, as pictured below.
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity : O(n2)
    // Space Complexity : O(n2)
    double champagneTower(int poured, int query_row, int query_glass) {
        
        double arr[101][101]={0};
        arr[0][0]=poured;
        // Simple idea:
        // If the glass >=1, we should split the diff (glass - 1) into next level.


        for(int i=0; i<query_row; i++)
        {
            for(int j=0; j<=query_glass; j++)
            {
                double remain = max(arr[i][j]-1.0, 0.0);
                arr[i+1][j] =arr[i+1][j] + remain/2.0;
                arr[i+1][j+1] =arr[i+1][j+1] + remain/2.0;
            }
        }
        
        return min(arr[query_row][query_glass], 1.0);
    }
};

int main(){
    // input
    int poured = 2;
    int query_row = 1;
    int query_glass = 1;
    Solution ob;
    
    cout<<ob.champagneTower(poured, query_row, query_glass)<<endl;
    return 0;
}

/*
Input: poured = 2, query_row = 1, query_glass = 1
Output: 0.50000
Explanation: We poured 2 cups of champange to the top glass of the tower 
(which is indexed as (0, 0)). There is one cup of excess liquid. The glass 
indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, 
and each will get half cup of champange. 
*/