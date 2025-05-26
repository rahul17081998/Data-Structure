/*Problem Statement:
There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right 
and each car is present at a unique point.

You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting 
whether the ith car is moving towards the left, 
towards the right, or staying at its current point respectively. Each moving car has the same speed.

The number of collisions can be calculated as follows:

When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
When a moving car collides with a stationary car, the number of collisions increases by 1.
After a collision, the cars involved can no longer move and will stay at the point where they collided. Other 
than that, cars cannot change their state or direction of motion.

Return the total number of collisions that will happen on the road.

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        string s = directions;
        int n = directions.length();
        int ans=0;
        
        for(int i=0; i<n; i++)
        {
            // Two corner case
            if(i==0 && s[i]=='L') continue;
            if(i==n-1 && s[i]=='R') continue;
            
            // check is current char is 'S'
            if(s[i]=='S') continue;
            // check if current char is 'L'
            if(s[i]=='L')
            {
                if(s[i-1]=='S') 
                {
                    s[i]='S';
                    ans++;
                }
            }
            else{ // s[i]=='R'
                int j=i;
                // check consecutive R
                while(j<n && s[j]=='R'){
                    s[j]='S';
                    j++;
                }
                if(j==n) return ans;
                if(s[j]=='S') ans++;
                else if(s[j]=='L') 
                {
                    ans=ans+2;
                    s[j]='S';
                }
                int between = j-i-1;
                ans = ans + between;
                i=j;
            }
            
        }
        return ans;
        
    }
};

int main(){
    string directions = "RLRSLL";
    Solution ob;
    cout<<ob.countCollisions(directions)<<endl;
    return 0;
}

/*
Input: directions = "RLRSLL"
Output: 5
*/