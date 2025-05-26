#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // tc = 100*NlogN
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        
        // method 2:
        // create map and insert element
        vector<vector<int>> map(101);
       
        // insert elements into map
        for(auto rect: rectangles){
            int l = rect[0];
            int h = rect[1];
            map[h].push_back(l);
        }
        
        // sort the x value for each corrosponding y value
        for (int i = 0; i < 101; i++) {
            sort(map[i].begin(), map[i].end());
        }
        
        vector<int> ans;
        
        for(auto p: points)
        {
            int count=0;
            for(int j=p[1]; j<101; j++)
            {
                int index = lower_bound(map[j].begin(), map[j].end(), p[0])-map[j].begin();
                count += map[j].size()-index;
            }
            ans.push_back(count);
        }
        return ans;
        
        
        
        /*
        // Method1: Gives TLE
        // take every points and check how many rectangle contain it
        vector<int> ans;
        
        for(auto point: points)
        {
            int px=point[0], py=point[1];
            // take every rectangle and check wether curretn points they are containing or not
            int count=0;
            for(auto rectangle : rectangles)
            {
                int rx=rectangle[0], ry=rectangle[1];
                if(px <= rx && py <= ry)
                    count++;
            }
            ans.push_back(count);
        }
        return ans;
        */
    }
};

int main(){
    
    return 0;
}