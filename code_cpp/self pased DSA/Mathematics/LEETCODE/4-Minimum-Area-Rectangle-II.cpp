/*
You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. 
If there is not any such rectangle, return 0.

Answers within 10-5 of the actual answer will be accepted.
*/

class Solution {
public:
    double minAreaFreeRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto p: points){
            mp[p[0]].insert(p[1]); // x-->{y1,y2,..}
        }

        double area=DBL_MAX;
        for(int i=0; i<points.size(); i++){
            for(int j=i+1; j<points.size(); j++){
                for(int k=j+1; k<points.size(); k++){
                    // finds dx1, dx2, dy1, dy2
                    int dx1 = points[j][0]-points[i][0];
                    int dx2 = points[k][0]-points[i][0];
                    int dy1 = points[j][1]-points[i][1];
                    int dy2 = points[k][1]-points[i][1];
                    // check these three points can form a right traingle
                    if(dx1*dx2 + dy1*dy2 ==0){ // right traingle
                        // find the fourht point 
                        // intersection point of two digonal will have same points
                        // xm = xj+xk - xi, ym = yj+yk - yi
                        int xm = dx1 + points[k][0];
                        int ym = dy1 + points[k][1];
                        // check this point exist into the map
                        if(mp[xm].find(ym)!=mp[xm].end()){
                            double area1 = sqrt(dx1*dx1 + dy1*dy1)*sqrt(dx2*dx2 + dy2*dy2);
                            if(area>area1){
                                area = area1;
                            }
                        }
                    }
                }
            }
        }

        if(area == DBL_MAX) return 0.0;
        return area;
    }
};