/* Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, 
return the maximum number of points that lie on the same straight line.
*/

time = O(N^2)
space = O(N)

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        // start from each point and take each and every other points see what is the slope 
        // store the each type of slope count into map
        // pich the maximum one and return

        int n = points.size();
        float maxPointOnLine=1; // default if we have only one points
        if(n==1) return 1;
        for(int i=0; i<n; i++){
            unordered_map<float,float> mp;
            float slop1=0;
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int x2 = points[j][0];
                int y2 = points[j][1];
                float a = y2-y1;
                float b = x2-x1;
                if(b==0.0){
                    slop1++;
                    maxPointOnLine=max(maxPointOnLine, slop1);
                }
                else{
                    float slope = a/b;
                    mp[slope]++;
                    cout<<slope<<" "<<mp[slope]<<endl;
                    maxPointOnLine=max(maxPointOnLine, mp[slope]);
                }
                
            }
        }
        return (int)(maxPointOnLine+1);
    }
};