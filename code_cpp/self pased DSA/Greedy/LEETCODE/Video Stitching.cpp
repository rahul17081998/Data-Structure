/*You are given a series of video clips from a sporting event that lasted time seconds. These video clips can be overlapping with each other and have varying lengths.
Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti and ended at endi.
We can cut these clips into segments freely.

For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. If the task is impossible, return -1.*/

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        
        int min=0, max=0, total=0;
        while(max<time){
            // search the intervel which has end time maximum, consedring start time should be less than or equal to minimum time
            for(auto clip: clips){
                int s=clip[0];
                int e=clip[1];
                if(s<=min && e>=max){
                    max=e;
                }
            }
            
            if(min==max) return -1; // we can not reach the last
            min=max;
            total++;
        }
        return total;
    }
};