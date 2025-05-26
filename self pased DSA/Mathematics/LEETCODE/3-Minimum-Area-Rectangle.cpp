/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. 
If there is not any such rectangle, return 0.
*/

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto p: points){
            mp[p[0]].insert(p[1]);// x -->{y1,y2,y3,..}
        }
        int area = INT_MAX;

        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                // check if these two points could be an digonal
                if(x1!=x2 && y1!=y2){
                    // find two more points that could be an digonal
                    if((mp[x1].find(y2)!=mp[x1].end()) && (mp[x2].find(y1)!=mp[x2].end())){
                        area = min(area, abs(x1-x2)*abs(y1-y2));
                    }
                }
            }
        }
        // check if there is not possible to form rectange
        if(area == INT_MAX) return 0;
        return area;
    }
};