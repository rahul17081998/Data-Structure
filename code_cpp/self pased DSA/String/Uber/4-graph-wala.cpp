#include <bits/stdc++.h>
using namespace std;
int G[1001][1001];

bool checkOddCycle(int src, int V){  // checking bipartiteness
    int colorArr[V];
    for(int i=0;i<V;i++){
        colorArr[i]=-1;
    }
    colorArr[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        if(G[u][u]==1){
            return true;
        }
        for(int v=0;v<V;v++){
            if(G[u][v]==1 && colorArr[v]==-1){
                colorArr[v]=1-colorArr[u];
                q.push(v);
            }
            else if(G[u][v]==1 && colorArr[v]==colorArr[u]){
                return true;
            }
        }
    }
    return false;
}

int findX(int n){
    if(checkOddCycle(0,n)==true){
        return -1;
    }
    int res=0;
    for(int i=0;i<n;i++){  // taking each node as source and getting max X
        vector<int> group(n,0);
        vector<bool> vis(n,false);
        queue<int> q;
        q.push(i);
        group[i]=1;
        vis[i]=true;
    
        while(!q.empty()){
            int size=q.size();
            while(size--){
                int node=q.front();
                q.pop();
                for(int nei=0;nei<n;nei++){
                    if(G[node][nei]==1 && vis[nei]==false){
                        q.push(nei);
                        vis[nei]=true;
                        group[nei]=group[node]+1;
                    }
                }
            }
        }
        res=max(res,*max_element(group.begin(),group.end()));
    }
    return res;
}

int main() {
    memset(G,0,sizeof(G));
    G[0][8]=1;
    G[0][1]=1;
    G[0][6]=1;
    G[0][3]=1;
    
    G[1][2]=1;
    G[1][0]=1;
    
    G[2][6]=1;
    G[2][1]=1;
    
    G[3][4]=1;
    G[3][7]=1;
    G[3][0]=1;
    
    G[4][8]=1;
    G[4][5]=1;
    G[4][3]=1;
    
    G[5][4]=1;
    G[5][7]=1;
    
    G[6][0]=1;
    G[6][2]=1;
    G[6][7]=1;
    
    G[7][3]=1;
    G[7][6]=1;
    G[7][5]=1;
    
    G[8][4]=1;
    G[8][0]=1;
    cout<<findX(9)<<endl;   // ANSWER=4 (OUTPUT) 
 /*----------------------------------------------------------*/   
    
    memset(G,0,sizeof(G));
    G[0][1]=1;
    G[1][0]=1;
    cout<<findX(2)<<endl;   // ANSWER=2 (OUTPUT)
/*----------------------------------------------------------*/   
    
    memset(G,0,sizeof(G));
    G[0][1]=1;
    G[0][2]=1;
    
    G[1][0]=1;
    
    G[2][0]=1;
    cout<<findX(3)<<endl; 
 /*----------------------------------------------------------*/  
    
    memset(G,0,sizeof(G));
    G[0][1]=1;
    G[0][2]=1;
    G[0][3]=1;
    
    G[1][0]=1;
    G[1][2]=1;
    G[1][3]=1;
    
    G[2][0]=1;
    G[2][1]=1;
    G[2][3]=1;
    
    G[3][0]=1;
    G[3][1]=1;
    G[3][2]=1;
    cout<<findX(4); // ANSWER=-1 , CAN NOT BE COLOURED USING 2 COLORS
    return 0;
}
