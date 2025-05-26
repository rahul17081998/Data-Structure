#include<bits/stdc++.h>
using namespace std;

#define R 4 
#define C 4
// Efficient solution: TC = O(R*C)
int largestHist(int arr[],int n) 
{
    stack<int> result; 
    int top_val; 
    int max_area = 0;  
    int area = 0; 
    int i = 0; 
    while (i < n) { 
        if (result.empty() || arr[result.top()] <= arr[i]) 
            result.push(i++); 
  
        else {  
            top_val = arr[result.top()]; 
            result.pop(); 
            area = top_val * i; 
  
            if (!result.empty()) 
                area = top_val * (i - result.top() - 1); 
            max_area = max(area, max_area); 
        } 
    } 
    while (!result.empty()) { 
        top_val = arr[result.top()]; 
        result.pop(); 
        area = top_val * i; 
        if (!result.empty()) 
            area = top_val * (i - result.top() - 1); 
  
        max_area = max(area, max_area); 
    } 
    return max_area; 
}

int maxRectArea(int mat[R][C])
{
    int res=largestHist(mat[0], C);
    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if(mat[i][j]==1)
            {
                mat[i][j] += mat[i-1][j];
            }
        }
        res=max(res, largestHist(mat[i], C));
        
    }
    return res;
}

int main(){
    int r=4;
    int c=4;
    int mat[4][4]={ {0, 1, 1, 0},
                    {1, 1, 0, 1},
                    {1, 1, 1, 1},
                    {1, 1, 0, 0} };
    
    cout<<"Area of maximum rectangle: "<<maxRectArea(mat)<<endl;
    // for (int i = 0; i < r; i++)
    // {
    //     for(int j=0; j < c; j++)
    //     {
    //         cout<<mat[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}