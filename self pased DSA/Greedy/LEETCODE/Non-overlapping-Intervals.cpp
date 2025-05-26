/*Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

Example 1:

Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.*/

class Solution {
public:

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<int> prev = intervals[0];
        int remIntervalCount=0;

        for(int i=1; i<intervals.size(); i++){
            vector<int> currInterval=intervals[i];
            // prevEnd>currStart, we have to delete an intervel either prev or current
            if(prev[1]>currInterval[0]){
                // check which of these two interval have maximum end time, remove them
                if(prev[1]>currInterval[1]){
                    prev = currInterval;
                }
                // we are removing the current interval so prev reamin same
                remIntervalCount++;
            }
            else{
                // just update the prev interval as current interval continue
                prev = currInterval;
            }
        }
        return remIntervalCount;
    }
};