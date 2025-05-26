/*
test case 
1
0 0
100 100 
3
1 2 120 120 2
4 5 120 100 3
6 8 150 180 4

*/

#include<iostream>
using namespace std;

int n;
int ans;
bool visited[100];

struct hole{
    int x1,y1,x2,y2, cost;
};

struct point{
    int x, y;
};

int calculate(point src, point dest){
    return (abs(src.x-dest.x) + abs(src.y-dest.y));
}

void solve(point src, point dest, hole a[], int cost){
    
    int tempans = cost + calculate(src,dest); // direct path traveling time
    // cout<<tempans<<endl;
    ans = min(ans, tempans); // update the ans now as direct path time

    for(int i=0; i<n; i++){
        // check if you not visited the point
        if(!visited[i]){

            visited[i]=true; // mark visited

            point temp1, temp2; int val;

            temp1.x = a[i].x1; temp1.y = a[i].y1;
            temp2.x = a[i].x2; temp2.y = a[i].y2;

            val = calculate(src, temp1); // calculate sorce to holes mouth distace
            solve(temp2, dest, a, cost + val + a[i].cost); // make last of hole as dost and add the source to mouth dist and mouth to end distance
            
            // jab x1 le rha h to x2 k cordinates aur jab x1 le rha h to x1 k cordinates
            val = calculate(src, temp2);
            solve(temp1, dest, a, cost + val + a[i].cost); // make last of hole as dost and add the source to mouth dist and mouth to end distance

            visited[i] = false; // back track    


        }
    }
}


int main(){
    
    int t;
    cin>>t;
    while(t--){
        point src, dest;// write sorce and distination coordinate
        cin>>src.x>>src.y>>dest.x>>dest.y;
        cin>>n; // no of holes
        hole a[n];
        // take holes both coordinates and traveling cost
        for(int i=0; i<n; i++)
            cin>>a[i].x1>>a[i].y1>>a[i].x2>>a[i].y2>>a[i].cost;
        ans = 10000000; // initialize ans as maximum
        for(int i=0; i<100; i++) visited[i] = false;

        solve(src, dest, a, 0); // initialize cost with 0
        cout<<ans<<endl;
    }
}