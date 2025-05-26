/*
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
*/

class Solution {
public:

    int merge(vector<vector<int>>& intervals) {
       vector<vector<int>> ans;
       sort(intervals.begin(), intervals.end());
       if(intervals.size()==0) return 0;
       // create a temp vector to store last intervel
       vector<int> temp = intervals[0]; // temp = [3,5]
    
       for(auto curr_intervel: intervals){
           if(curr_intervel[0]<= temp[1]){
               temp[1] = min(temp[1], curr_intervel[1]); // select the minimum end time here
               // but in minimum merge intervel we select maximum end time
           }
           else{
               ans.push_back(temp);
               temp = curr_intervel;
           }
       }

       ans.push_back(temp);
      
       return (int)ans.size();
    }


    int findMinArrowShots(vector<vector<int>>& points) {
        return merge(points);
    }
};