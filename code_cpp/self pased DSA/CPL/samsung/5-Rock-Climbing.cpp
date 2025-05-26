#include<iostream>
using namespace std;

int n,m, l=0, f=0;
int a[15][15];
int v[15][15];


void dfs(int i, int j){

    
    if(i<0 || j<0 || i>=n || j>=m) return ; // check boundry
    if(v[i][j]) return ; // check if alredy visited
    v[i][j] = 1; // mark visited
    
    if(a[i][j] == 3){ // reach the destination
        f=1;
        return ;
    }

    if(j+1<m && (a[i][j+1]==1 || a[i][j+1]==3) && !v[i][j+1])
        dfs(i, j+1);
    if(j-1>=0 && (a[i][j-1]==1 || a[i][j-1]==3) && !v[i][j-1])
        dfs(i, j-1);
    
    int h=1;
    for(h=1; h<=l; h++)
    {
        if(h<=l && i-h>=0 && (a[i-h][j]==1 || a[i-h][j]==3) && !v[i-h][j])
            dfs(i-h, j);
        if(h<=l && i+h<n && (a[i+h][j]==1 || a[i+h][j]==3) && !v[i+h][j])
            dfs(i+h, j);
    }
}

int main(){

    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>> a[i][j];
        }
    }

    for(l=0; l<n; l++)
    {
        // mark visited array false
        for(int i=0; i<15; i++){
            for(int j=0; j<15; j++){
                v[i][j]=0;
            }
        }
        // call dfs
        f = 0;
        dfs(n-1, 0); // passing row and col/ start from left most bottom coorner
        if(f==1){
            cout<<l<<endl;
            break;
        }
    }
    return 0;
}

/*
5 8
1 1 1 1 0 0 0 0
0 0 0 3 0 1 1 1
1 1 1 0 0 1 0 0
0 0 0 0 0 0 1 0
1 1 1 1 1 1 1 1
*/