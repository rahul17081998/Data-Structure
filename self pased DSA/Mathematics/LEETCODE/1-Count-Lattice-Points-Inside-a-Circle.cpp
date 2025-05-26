#include<bits/stdc++.h>
using namespace std;
/*Problem:
Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents 
the center (xi, yi) and radius ri of the ith circle drawn on a grid, return 
the number of lattice points that are present inside at least one circle.

Note:
A lattice point is a point with integer coordinates.
Points that lie on the circumference of a circle are also considered to be inside it
*/
class Solution {
public:
    bool isPoint_Lies_Inside_Circle(int x1, int y1, int x, int y, int r)
    {
        return ((x-x1)*(x-x1) + (y-y1)*(y-y1) <= r*r);
    }
    
    int countLatticePoints(vector<vector<int> >& circles) {
        // you can use map as well to do this 
      set<pair<int, int> > st; 
        
        for(auto circle: circles)
        {
            int x=circle[0], y=circle[1], r=circle[2];
            for(int i=x-r; i<=x+r; i++)
            {
                for(int j=y-r; j<=y+r; j++)
                {
                    if(isPoint_Lies_Inside_Circle(i, j, x, y, r))
                        st.insert(make_pair(i, j));
                }
            }
        }
        return (int)st.size();
        
    }
};

int main(){
    vector<vector<int> > circles;
    vector<int> level;
    level.push_back(2);
    level.push_back(2);
    level.push_back(2);
    circles.push_back(level);

    level.clear();
    level.push_back(3);
    level.push_back(4);
    level.push_back(1);
    circles.push_back(level);

    Solution ob;
    cout<<ob.countLatticePoints(circles)<<endl;
    return 0;
}

/*
Input: circles = [[2,2,2],[3,4,1]]
Output: 16
Explanation:
The figure above shows the given circles.
There are exactly 16 lattice points which are present inside at least one circle. 
Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).
*/