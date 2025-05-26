#include<iostream>
using namespace std;

int n;
int a[100][100];

// check current path is valid or not
bool valid(int r, int c){
    if(r>=0 && r<n && c>=0 && c<5) return true;
    return false;
}

int solve(int r, int c, int power, int effect){

    // base 
    if(r<0) return 0;
    
    
    int ans = 0;
    int p = 0;
    // traverse in all 3 direction
    for(int i=-1; i<=1; i++){
        int x = r-1;
        int y = c+i; // c-1, c, c+1

        // check (x,y) cooreinate is valid 
        if(valid(x,y)){
            // enemy: check if currecnt cell have enemy
            if(a[x][y]==2){
                // if you have already bombused and have effect
                if(power==0 && effect>0)
                    p = solve(x,y,power,effect-1);
                // you have bomb
                if(power==1){
                    p = solve(x, y, power-1, 5);
                }
            }
            // not enemy: there is no enemy in current cell
            if(a[x][y]==1 || a[x][y]==0){
                // power used then defcrease effect to nect upper row
                if(power==0)
                    p = solve(x,y,power,effect-1);
                else
                    p = solve(x,y,power,effect); // 5->effect
            }
        }
        ans = max(ans,p);
    }
    if(a[r][c]==1) ans++;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    int z = 1;
    while(t--)
    {
        cin>>n;
        // initialize a array
        for(int i=0; i<100; i++) for(int j=0; j<100; j++) a[i][j]=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                cin >> a[i][j];
            }
        }

        cout<<"#"<<z <<" "<<solve(n, 2, 1, 0)<<endl;
        z++;
    }
    return 0;

 
}
/*
5
7
1 2 0 0 1
2 0 0 1 0
0 1 2 0 1
1 0 0 2 1
0 2 1 0 1
0 1 2 2 2
1 0 1 1 0
5
1 1 0 0 0
1 2 2 2 1
1 1 2 2 1
2 2 2 1 2
2 2 0 2 0
6
2 2 2 2 2
0 0 0 0 0
0 0 2 0 0
2 0 0 0 2
0 0 0 0 0
1 2 2 2 1
10
2 2 2 2 0
1 2 0 0 2
0 2 0 0 0
2 2 0 2 2
0 2 2 2 0
0 0 0 0 0
1 0 0 0 2
0 0 0 0 0
0 2 0 2 1
0 2 2 2 0
12
2 2 0 2 2
0 1 0 2 1
0 2 0 1 0
2 1 2 1 0
0 2 2 1 2
0 1 2 2 2
0 2 1 0 2
2 0 1 1 2
2 1 1 0 1
0 2 2 0 0
2 0 1 2 2
2 2 1 2 1


*/
